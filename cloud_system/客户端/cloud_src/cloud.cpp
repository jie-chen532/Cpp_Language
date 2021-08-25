#include "cloud.hpp"


int main()
{
	string host = "192.168.134.144";
	cloud_system::Cloud_Client cli(host, 9000);
	cli.start();
	return 0;
}