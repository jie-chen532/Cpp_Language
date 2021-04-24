#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<string>

#include<iostream>
using namespace std;

#include<iostream>
using namespace std;

//int StrToInt(string str) {
//	//先判断是否合法
//	for (int i = 0; i < str.size(); i++)
//	{
//		if (str[0] == '+' || str[0] == '-');
//		else if (str[i] == ' ');
//		else if (!(str[i] >= '0' && str[i] <= '9'))
//			return 0;
//	}
//
//	//计算值
//	int flag = 0;//为正数
//
//	int sum = 0;
//	for (int i = 0; i < str.size(); i++)
//	{
//		//先跳过空
//		while (i < str.size() && str[i] == ' ')
//			i++;
//		if (str[i] == '-')
//		{
//			flag = 1;
//			i++;
//		}
//		else if (str[i] == '+')
//			i++;
//		sum += (str[i] - '0') * (int)pow(10, str.size() - 1 - i);
//	}
//
//	if (flag == 1)
//	{
//		sum = -1 * sum;
//	}
//	return sum;
//}
//
//int main()
//{
//	string str("+2147483647");
//	int ret = StrToInt(str);
//	cout << ret << endl;
//}

//#include<stdio.h>
//int main()
//{
//	char a = 0, ch;
//	while ((ch = getchar()) != '\n')
//	{
//		if (a % 2 != 0 && (ch >= 'a' && ch <= 'z'))
//			ch = ch - 'a' + 'A';
//		a++;
//		putchar(ch);
//	}
//	printf("\n");
//	return 0;
//}

//struct A
//{
//	long a1;
//	short a2;
//	int a3;
//	int *a4;
//};
//
//int main()
//{
//	cout << sizeof(struct A) << endl;
//	return 0;
//}

//int main()
//{
//	int m = 0123, n = 123;
//	printf("%o,%o\n", m, n);
//	return 0;
//}

//int f(int n)
//{
//	if (n == 1)
//		return 1;
//	else
//		return (f(n - 1) + n*n*n);
//}
//
//int main()
//{
//	int s = f(3);
//	cout << s << endl;
//	return 0;
//}

//char fun(char x, char y)
//{
//	if (x < y)
//		return x;
//	return y;
//}
//
//int main()
//{
//	int a = '1', b = '1', c = '2';
//	cout << fun(fun(a, b), fun(b, c));
//	return 0;
//}