#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<string>

int main()
{
	string str1;
	string str2;//ɾ�����ַ���
	getline(cin, str1);//getline��һ�У�cin�����ո�ͻ����
	getline(cin, str2);

	//str2ӳ��hash����
	int hash[256] = { 0 };
	for (int i = 0; i < str2.size(); i++)
	{
		hash[str2[i]]++;
	}

	//����str1���ж�str1�е��ַ��Ƿ���str2��,����ӵ��µ��ַ�����
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