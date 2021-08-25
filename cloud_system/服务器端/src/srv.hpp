#pragma once   
#include<unordered_map>
#include<sstream>
#include<math.h>
#include<iostream>
#include<string>
#include<vector>
#include<pthread.h>
#include<fstream>
#include<experimental/filesystem>
#include<sys/stat.h>
#include<unistd.h>
#include"httplib.h"
#include"bundle.h"

using namespace std;

namespace cloud_system
{
  class ScanDir
  {
    private:
      string _path;
    public:
      ScanDir(string path)
        :_path(path)
      {
        //如果不存在目录则创建
        if(!std::experimental::filesystem::exists(_path))
          std::experimental::filesystem::create_directories(_path);
        if(_path.back() != '/')
          _path += '/';
      }

      bool Scan(vector<string> &arry)
      {
        //遍历目录
        for(auto &e : std::experimental::filesystem::directory_iterator(_path))
        {
          if(std::experimental::filesystem::is_directory(e.path()))
            continue;
          else 
          {
            string str = _path + e.path().filename().string();
            arry.push_back(str);
          }
        }
        return true;
      }
  };

  class Common
  {
    public:
      static bool ReadFile(const string& path, string& body)
      {
        //打开文件
        ifstream infile;
        infile.open(path, ios::binary);
        if(!infile.is_open())
        {
          cout << "ReadFile:open file failed" << endl;
          return false;
        }
        size_t size = std::experimental::filesystem::file_size(path);
        body.resize(size);
        infile.read(&(body[0]),size);
        if(infile.good() == false)
        {
          cout << "ReadFile:read file failed" << endl;
          return false;
        }
        infile.close();
        return true;
      }

      static bool WriteFile(const string& file, const string& body)
      {
        ofstream onfile;
        onfile.open(file, ios::binary);
        if(onfile.is_open() == false)
        {
          cout << "WriteFile:open file failed" << endl;
          return false;
        }
        onfile.write(&(body[0]), body.size());
        if(onfile.good() == false)
        {
          cout << "WriteFile:write file failed" << endl;
          return false;
        }
        onfile.close();
        return true;
      }
       
      static bool ReadRangeFile(const string &path, int *start, int *end, string &body)
      {
        int size = std::experimental::filesystem::file_size(path);
        ifstream ifile;
        ifile.open(path, ios::binary);
        if(ifile.is_open() == false)
        {
          cout << "ReadRangeFile:open file failed";
          return false;
        }
        if(*end == -1)
          *end = size - 1;
        int rlen = *end - *start + 1;
        body.resize(rlen);
        ifile.seekg(*start, ios::beg);
        ifile.read(&(body[0]), rlen);
        if(ifile.good() == false)
        {
          cout << "ReadRangeFile:read file failed";
          return false;
        }
        ifile.close();
        return true;
      }

      static int Split(const string& str, const string sp, vector<string> &arry)
      {
        int count = 0;
        size_t index = 0;
        size_t pos = 0;
        while(1)
        {
          pos = str.find(sp, index);
          if(pos == string::npos)
            break;
          string tmp = str.substr(index, pos - index);
          arry.push_back(tmp);
          index = pos + sp.size();
          count++;
        }
        if(index < str.size())
        {
          arry.push_back(str.substr(index));
          count++;
        }
        return count;
      }
  };


  class DataManager
  {
    private:
      string _path;
      unordered_map<string,string> _map;
      //map涉及多线程访问，为了解决安全问题需要加锁
      //互斥锁只能互斥访问，效率太低
      //因此采用读写锁--读共享、写互斥
      pthread_rwlock_t _rwlock;
    public:
      DataManager(const string& path)
        :_path(path)
      {
        pthread_rwlock_init(&_rwlock, NULL); //读写锁初始化
      }

      ~DataManager()
      {
        pthread_rwlock_destroy(&_rwlock);//析构函数读写锁销毁
      }

      bool Read()
      {
        string body;
        if(Common::ReadFile(_path, body) == false)
        {
          cout << "DataManager:Read:read failed" << endl;
          return false;
        }
        vector<string> arry; 
        Common::Split(body, "\n", arry);
        for(auto &e : arry)
        {
          vector<string> kv;
          Common::Split(e, "=", kv);
          pthread_rwlock_wrlock(&_rwlock);
          _map[kv[0]] = kv[1];
          pthread_rwlock_unlock(&_rwlock);
        }
        return true;
      }

      bool Write()
      {
        stringstream ss;
        ss.clear();
        pthread_rwlock_rdlock(&_rwlock);
        for(auto &kv : _map)
        {
          ss << kv.first << "=" << kv.second << "\n";
        }
        pthread_rwlock_unlock(&_rwlock); 
        if(Common::WriteFile(_path, ss.str()) == false)
        {
          cout << "DataManager:Write:write failed";
          return false;
        }
        return true;
      }      

      bool Exists(const string& key)
      {
        pthread_rwlock_rdlock(&_rwlock);  
        auto it = _map.find(key);
        if(it == _map.end())
        {
          cout << key << "is not exists" <<endl;
          pthread_rwlock_unlock(&_rwlock);
          return false;
        }
        pthread_rwlock_unlock(&_rwlock);
        return true;
      }

      bool AddOrMod(const string& key, const string& value)
      {
        pthread_rwlock_wrlock(&_rwlock);
        _map[key] = value;
        pthread_rwlock_unlock(&_rwlock);
        return true;
      }

      bool Del(const string& key)
      {
        pthread_rwlock_wrlock(&_rwlock); 
        if(Exists(key) != true)
        {
          cout << key << "is not exists" << endl;
          pthread_rwlock_unlock(&_rwlock);
          return false;
        }
        _map.erase(key);
        pthread_rwlock_unlock(&_rwlock);
        return true;
      }

      bool GetValue(const string &key, string &val)
      {
        pthread_rwlock_rdlock(&_rwlock);
        if(Exists(key) != true)
        {
          cout << key << "is not exists" << endl;
          pthread_rwlock_unlock(&_rwlock);
          cout << false;
        }
        val =  _map[key];
        pthread_rwlock_unlock(&_rwlock);
        return true;
      }
      bool GetAll(vector<string> &arry)
      {
        pthread_rwlock_rdlock(&_rwlock);
        for(auto &e : _map)
        {
          arry.push_back(e.first);
        }
        pthread_rwlock_unlock(&_rwlock);
        return true;
      }
  };

#define BACKUP "./backup/"
#define PACK_UP "./pack/"
  class Bundle{
    public:
      static bool Pack(const string& pathname, const string &packname)
      {
        string body;
        if(Common::ReadFile(pathname, body) == false)
        {
          cout << "pack:read file failed" << endl;
          return false;
        }

        //压缩
        string ret = bundle::pack(bundle::LZIP, body);

        //写入文件
        if(Common::WriteFile(packname, ret) == false)
        {
          cout << "Pack:write file failed" << endl;
          return false;
        }
        return true;
      }

      static bool UnPack(const string &filename, const string& packname)
      {
        string body;
        if(Common::ReadFile(packname, body) == false)
        {
          cout << "UnPack:read file failed" << endl;
          return false;
        }
        string str = bundle::unpack(body);
        if(Common::WriteFile(filename, str) == false)
        {
          cout << "UnPack:write file failed" << endl;
          return false;
        }
        return true;
      }
  };
#define FILE_CONF "./file.conf"
#define FILE_SIZE "./size.conf"
  DataManager g_data(FILE_CONF);
  DataManager g_size(FILE_SIZE);
  class Server
  {
    private:
      httplib::Server _srv;

    private:

      static double Round(double dSrc, int iBit)
      {
        double retVal = 0.0;
        int intTmp = 0;
        intTmp = (int)((dSrc + 0.5 / pow(10.0, iBit))*pow(10.0, iBit));
        retVal = (double)intTmp / pow(10.0, iBit);
        return retVal;
      }

      //获取文件大小
      static string GetSize(const string& path)
      {
        auto ret = std::experimental::filesystem::file_size(path);
        stringstream ss;
        if(ret < 1024)
        {
          ss << ret << " B";
        }
        else if(ret >= 1024 && ret < pow(1024, 2))
        {
          double num = 1.0 * ret / 1024;
          ss << Round(num, 1) <<" KB";
        }
        else if(ret >= pow(1024, 2) && ret < pow(1024, 3))
        {
          double num = ret / pow(1024,2);
          ss << Round(num, 1) << " MB";
        }
        else if(ret >= pow(1024, 3))
        {
          double num = ret / pow(1024, 3);
          ss << Round(num, 1) << " GB";  
        }
        return ss.str();
      }

      static void Upload(const httplib::Request &req, httplib::Response &rsp)
      {
        bool ret = req.has_file("file");
        if(ret == false)
        {
          rsp.status = 400;
          return;
        }
        //如果目录不存在则创建
        if(!std::experimental::filesystem::exists(BACKUP))
          std::experimental::filesystem::create_directories(BACKUP);
        const auto &file = req.get_file_value("file");
        string pathname = BACKUP + file.filename;
        if(Common::WriteFile(pathname, file.content) == false)
        {
          rsp.status = 500;
          cout << "Upload file failed" << endl;
          return;
        }
        rsp.status = 200;
        //上传成功，更新备份文件信息表
        g_data.AddOrMod(file.filename, file.filename);
        g_data.Write();
        g_size.AddOrMod(file.filename, GetSize(pathname));
        g_size.Write();
        return ;
      }


      static void List(const httplib::Request &req, httplib::Response &rsp)
      {
        //请求的文件名
        vector<string> files;
        g_data.GetAll(files);
        stringstream ss;
        ss << "<html><head><title>文件下载</title><meta charset='utf-8'></head>";
        ss << "<body><h2>文件下载列表</h2>";
        ss << "<table border='1' cellpadding='1' cellspacing='0' width='400' height='20'>";
        ss << "<tr><th>文件名称</th><th>文件大小</th></tr>";
        for(auto &file : files)
        {
          ss << "</tr>";
          ss << "<td align='center'><a href='/backup/" << file << "'>" << file << "</a></td>";
          string size;
          g_size.GetValue(file, size);
          ss << "<td align='center'>" << size << "</td></tr>"; 
        }
        ss << "</table></body></html>";
        rsp.body = ss.str();
        rsp.set_header("Content-Type", "text/html");
        return;
      }

      static string getIden(const string& path)
      {
        uint64_t size = std::experimental::filesystem::file_size(path);
        uint64_t c_time;
        auto time_type = std::experimental::filesystem::last_write_time(path);
        c_time = decltype(time_type)::clock::to_time_t(time_type);

        stringstream ss;
        ss << size << c_time;
        return ss.str();
      }

      static void Download(const httplib::Request &req, httplib::Response &rsp)
      {
        string filename = req.matches[1];
        string val;
        g_data.GetValue(filename, val);

        string pathname = BACKUP + filename;
        string packname = PACK_UP + filename + ".pack";
        if(filename != val)
        {
          //文件被压缩，需要解压
          Bundle::UnPack(pathname, packname);
          //修改文件备份信息
          g_data.AddOrMod(filename, filename);
          g_data.Write();

          //删除源文件
          unlink(packname.c_str());
        }

        string newEtag = getIden(pathname);
        int size = std::experimental::filesystem::file_size(pathname);

        //判断是否有Range字段
        if(req.has_header("If-Range"))
        {
          string oldEtag = req.get_header_value("If-Range");
          if(oldEtag == newEtag)
          {
            //断点续传
            int start = req.ranges[0].first;
            int end = req.ranges[0].second;
            cout << start << "-" << end << endl;
            if(Common::ReadRangeFile(pathname, &start, &end, rsp.body) == false)
            {
              cout << "Download ReadRangeFile file failed" << endl;
              return;
            }
            rsp.set_header("Content-Type", "application/octet-stream");
            stringstream ss;
            ss.clear();

            ss << "bytes " << start << "-" << end << "/" << size;
            cout << ss.str() << endl;
            rsp.set_header("Content-Range", ss.str());
            rsp.set_header("ETag", newEtag);
            rsp.status = 206;
            return;
          }
        }

        //传完整的文件
      if(Common::ReadFile(pathname, rsp.body) == false)
      {
         rsp.status = 500;
         cout << "Download:read file failed" << endl;
         return;
      }
      rsp.set_header("Content-Type", "application/octet-stream");
      //表示自己支持断点续传
      rsp.set_header("Accept-Range", "bytes");
      rsp.set_header("ETag", newEtag);
      rsp.status = 200;
      return;
      }

    public:
      void start(int port = 9000)
      {
        g_data.Read();
        g_size.Read();
        _srv.Post("/multipart", Upload);
        _srv.Get("/list", List);
        _srv.Get("/backup/(.*)", Download);
        _srv.listen("0.0.0.0", port);
      }
  };

  class FileManager
  {
    private:
      ScanDir _scan; 
      time_t _hot_time = 120;

      time_t LastAccessTime(const string& file)
      {
        struct stat st;
        stat(file.c_str(), &st);
        return st.st_atime;
      }

    public:
      FileManager()
        :_scan(BACKUP)
      {}

      bool HotFile()
      {
        while(1)
        {
          //浏览目录
          vector<string> files;
          _scan.Scan(files);
          for(const auto&file : files)
          {
            time_t atime = LastAccessTime(file);
            time_t ctime = time(NULL);
            if(ctime - atime > _hot_time)
            {
              //非热点文件进行压缩
              std::experimental::filesystem::path p(file);
              string packname = PACK_UP + p.filename().string() + ".pack";
              Bundle::Pack(file, packname);//压缩文件
              string filename = p.filename().string() + ".pack";
              g_data.AddOrMod(p.filename().string(), filename);//文件信息备份
              g_data.Write();
              unlink(file.c_str());
            }
        }
          sleep(1);
      }
        return false;
    }
  };
}
