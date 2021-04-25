#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str;
	cin >> str;
	string cur;//当前遍历的数字字符
	string ret;//当前最长的数字字符串

	for (int i = 0; i <= str.size(); i++)
	{
		//abcd12345ed125ss123456789
		//如果最长的数字串在最后，i遍历完，cur中是最长的数字串，
		//但是此时i == size(), 不会在进入循环，无法更新ret,
		//所以使i <= size(),会再次进入循环，而'\0'不是数字字符，就会进入else更新ret
		if (str[i] >= '0' && str[i] <= '9')
			cur += str[i];
		else
		{
			if (cur.size() > ret.size())
				ret = cur;
			else
				cur.clear();//清空cur
		}
	}
	cout << ret << endl;
	return 0;
}