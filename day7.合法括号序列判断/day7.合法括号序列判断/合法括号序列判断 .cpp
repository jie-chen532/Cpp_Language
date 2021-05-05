#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<stack>
#include<string>
using namespace std;

class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		//�����ַ���
		stack<char> sc;
		for (auto& ch : A)
		{
			switch (ch)
			{
			case '(':
				sc.push(ch);//������������ջ
				break;
			case ')':
				if (sc.empty())//���ջΪ�գ����������
					return false;
				sc.pop();//ջ��Ϊ�գ��������ų�ջƥ��
				break;
			default://�����������ַ�����ֱ�ӷ���false
				return false;
			}
		}
		return sc.empty();//������֮�����ջ��Ϊ�գ����������
	}
};

int main()
{
	Parenthesis p;
	cout << p.chkParenthesis("()(())(()", 9) << endl;
	return 0;
}