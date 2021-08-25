#include"srv.hpp"
#include<thread>
#include<iostream>

using namespace std;

void thread_hotFile()
{
  cloud_system::FileManager file;
  file.HotFile();
}

int main()
{
  thread hotFile(thread_hotFile);
  hotFile.detach();
  cloud_system::Server srv;
  srv.start();
  return 0;
}
