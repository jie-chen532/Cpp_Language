#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<stack>
#include<string>
using namespace std;

class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		//遍历字符串
		stack<char> sc;
		for (auto& ch : A)
		{
			switch (ch)
			{
			case '(':
				sc.push(ch);//若是左括号入栈
				break;
			case ')':
				if (sc.empty())//如果栈为空，多出右括号
					return false;
				sc.pop();//栈不为空，则左括号出栈匹配
				break;
			default://若不是括号字符，则直接返回false
				return false;
			}
		}
		return sc.empty();//遍历完之后，如果栈不为空，多出左括号
	}
};

int main()
{
	Parenthesis p;
	cout << p.chkParenthesis("()(())(()", 9) << endl;
	return 0;
}