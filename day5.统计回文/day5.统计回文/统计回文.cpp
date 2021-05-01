#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<string>

bool IsCircle(const string& s)
{
	int begin = 0;
	int end = s.size() - 1;
	while (begin < end)
	{
		if (s[begin] != s[end])
			return false;
		begin++;
		end--;
	}
	return true;
}

int main()
{
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);
	int count = 0;//计数器
	//将str2插入str1的每一个位置
	for (int i = 0; i <= str1.size(); i++)
	{
		string str = str1;
		str.insert(i, str2);
		//判断是否是回文
		if (IsCircle(str))
			count++;
	}
	cout << count << endl;
	return 0;
}