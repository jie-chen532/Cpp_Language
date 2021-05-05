#define _CRT_SECURE_NO_WARNINGS 1

#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
	int StrToInt(string str) {
		if (str.empty())//如果是空字符串，返回0
			return 0;
		int flag = 1;
		int sum = 0;
		if (str[0] == '-')
		{
			flag = -1;
			str[0] = '0';
		}
		else if (str[0] == '+')
		{
			str[0] = '0';
		}
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] < '0' || str[i] > '9')
			{
				sum = 0;
				break;
			}
			sum = sum * 10 + str[i] - '0';
		}
		return flag*sum;
	}
};

int main()
{
	Solution s;
	int ret = s.StrToInt("123");
	cout << ret << endl;
	return 0;
}