#pragma once   
#include<unordered_map>
#include<sstream>
#include<iostream>
#include<string>
#include<vector>
#include<time.h>
#include<fstream>
#include<utility>
#include<filesystem>
#include"httplib.h"
#include<windows.h>


using namespace std;

namespace cloud_system {
	class ScanDir
	{
	private:
		string _path;
	public:
		ScanDir(string path)
			:_path(path)
		{
			if (!std::experimental::filesystem::exists(_path))
				std::experimental::filesystem::create_directories(_path);
			if (_path.back() != '/')
				_path += '/';
		}

		bool Scan(vector<string> &arry)
		{
			for (auto &e : std::experimental::filesystem::directory_iterator(_path))
			{
				if (std::experimental::filesystem::is_directory(e.path()))
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
			ifstream infile;
			infile.open(path, ios::binary);
			if (!infile.is_open())
			{
				cout << "ReadFile:open file failed" << endl;
				return false;
			}
			auto size = std::experimental::filesystem::file_size(path);
			body.resize(size);
			infile.read(&(body[0]), size);
			if (infile.good() == false)
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
			if (onfile.is_open() == false)
			{
				cout << "WriteFile:open file failed";
				return false;
			}
			onfile.write(&(body[0]), body.size());
			if (onfile.good() == false)
			{
				cout << "WriteFile:write file failed" << endl;
				return false;
			}
			onfile.close();
			return true;
		}

		static int Split(const string& str, const string sp, vector<string> &arry)
		{
			int count = 0;
			size_t index = 0;
			size_t pos = 0;
			while (1)
			{
				pos = str.find(sp, index);
				if (pos == string::npos)
					break;
				string tmp = str.substr(index, pos - index);
				arry.push_back(tmp);
				index = pos + sp.size();
				count++;
			}
			if (index < str.size())
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
		unordered_map<string, string> _map;
	public:
		DataManager(const string& path)
			:_path(path) {}

		bool Read()
		{
			string body;
			if (Common::ReadFile(_path, body) == false)
			{
				cout << "DataManager:Read:read failed" << endl;
				return false;
			}
			vector<string> arry;
			Common::Split(body, "\n", arry);
			for (auto &e : arry)
			{
				vector<string> kv;
				Common::Split(e, "=", kv);
				_map[kv[0]] = kv[1];
			}
			return true;
		}

		bool Write()
		{
			stringstream ss;
			ss.clear();
			for (auto &kv : _map)
			{
				ss << kv.first << "=" << kv.second << "\n";
			}
			if (Common::WriteFile(_path, ss.str()) == false)
			{
				cout << "DataManager:Write:write failed";
				return false;
			}
			return true;
		}

		bool Exists(const string& key)
		{
			auto it = _map.find(key);
			if (it == _map.end())
			{
				cout << key << " is not exists" << endl;
				return false;
			}
			return true;
		}

		bool AddOrMod(const string& key, const string& value)
		{
			_map[key] = value;
			return true;
		}

		bool Del(const string& key)
		{
			if (Exists(key) != true)
			{
				cout << key << "is not exists" << endl;
				return false;
			}
			_map.erase(key);
			return true;
		}

		bool GetValue(const string &key, string &val)
		{
			if (Exists(key) != true)
			{
				cout << key << "is not exists" << endl;
				cout << false;
			}
			val = _map[key];
			return true;
		}
	};

#define LISTEN_DIR "./scandir"
#define CONFIG_FILE "./data.conf"

	class Cloud_Client
	{
	private:
		ScanDir _scan;
		DataManager _data;
		httplib::Client *_client;
	public:
		Cloud_Client(const string& host, int port)
			:_scan(LISTEN_DIR)
			, _data(CONFIG_FILE)
			, _client(new httplib::Client(host, port)) {}


		string getIden(const string& path)
		{
			uint64_t size;
			uint64_t time;
			size = std::experimental::filesystem::file_size(path);

			auto time_type = std::experimental::filesystem::last_write_time(path);

			time = decltype(time_type)::clock::to_time_t(time_type);

			stringstream ss;
			ss << size << time;
			return ss.str();
		}

		bool scan(vector<pair<string, string>> &arry)
		{

			vector<string> files;
			_scan.Scan(files);

			for (auto &file : files)
			{
				if (_data.Exists(file) == false)
				{
					string identify = getIden(file);
					arry.push_back(make_pair(file, identify));
				}
				else
				{

					string oldIdentify;
					_data.GetValue(file, oldIdentify);
					string newIdentify = getIden(file);

					if (oldIdentify != newIdentify)
					{

						arry.push_back(make_pair(file, newIdentify));
					}
				}
			}
			return true;
		}

		bool upload(const string& path)
		{

			httplib::MultipartFormData file;
			file.name = "file";
			file.content_type = "application/octet-stream";
			std::experimental::filesystem::path p(path);
			file.filename = p.filename().string();
			Common::ReadFile(path, file.content);
			httplib::MultipartFormDataItems items;

			items.push_back(file);
			auto res = _client->Post("/multipart", items);

			if (res && res->status == 200)
			{
				return true;
			}
			return false;
		}

		bool start()
		{

			_data.Read();
			while (1)
			{

				vector<pair<string, string>> files;
				scan(files);

				for (auto &file : files)
				{
					cout << file.first << " need to backup" << endl;

					if (upload(file.first) == false)
	        		{
						continue;
					}

					_data.AddOrMod(file.first, file.second);

					_data.Write();
				}
				Sleep(1000);
			}
		}

	};
}