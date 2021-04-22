#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<string>

int main()
{
	string str1;
	string str2;//删除的字符串
	getline(cin, str1);//getline读一行，cin读到空格就会结束
	getline(cin, str2);

	//str2映射hash数组
	int hash[256] = { 0 };
	for (int i = 0; i < str2.size(); i++)
	{
		hash[str2[i]]++;
	}

	//遍历str1，判断str1中的字符是否在str2中,并添加到新的字符串中
	string ret;
	for (int i = 0; i < str1.size(); i++)
	{
		if (hash[str1[i]] == 0)
		{
			ret += str1[i];
		}
	}
	cout << ret << endl;
	return 0;
}