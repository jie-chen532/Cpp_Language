#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
	string str;
	getline(cin, str);//getline��һ��

	//���������ַ���
	reverse(str.begin(), str.end());

	auto start = str.begin();

	//�ҿո�����ÿ������
	while (start != str.end())
	{
		auto end = start;
		//�ҿո�
		while (end != str.end() && *end != ' ')
			end++;
		//�ҵ��ո�����ߵ�str.end(), ���õ���
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