#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str;
	cin >> str;
	string cur;//��ǰ�����������ַ�
	string ret;//��ǰ��������ַ���

	for (int i = 0; i <= str.size(); i++)
	{
		//abcd12345ed125ss123456789
		//���������ִ������i�����꣬cur����������ִ���
		//���Ǵ�ʱi == size(), �����ڽ���ѭ�����޷�����ret,
		//����ʹi <= size(),���ٴν���ѭ������'\0'���������ַ����ͻ����else����ret
		if (str[i] >= '0' && str[i] <= '9')
			cur += str[i];
		else
		{
			if (cur.size() > ret.size())
				ret = cur;
			else
				cur.clear();//���cur
		}
	}
	cout << ret << endl;
	return 0;
}