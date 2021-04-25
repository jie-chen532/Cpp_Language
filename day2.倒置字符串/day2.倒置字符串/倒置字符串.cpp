#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
	string str;
	getline(cin, str);//getline读一行

	//逆置整个字符串
	reverse(str.begin(), str.end());

	auto start = str.begin();

	//找空格，逆置每个单词
	while (start != str.end())
	{
		auto end = start;
		//找空格
		while (end != str.end() && *end != ' ')
			end++;
		//找到空格或者走到str.end(), 逆置单词
		reverse(start, end);

		if (end == str.end())
		{
			start = end;
		}
		else
		{
			start = end + 1;
		}
	}
	cout << str;
	return 0;
}