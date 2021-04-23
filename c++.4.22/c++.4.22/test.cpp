#define _CRT_SECURE_NO_WARNINGS 1

//#include<iostream>
//using namespace std;

//int cnt = 0;
//int fib(int n)
//{
//	cnt++;
//	if (n == 0)
//		return 1;
//	else if (n == 1)
//		return 2;
//	else
//		return fib(n - 1) + fib(n - 2);
//}
//
//int main()
//{
//	fib(8);
//	cout << cnt << endl;
//	return 0;
//}


//int main()
//{
//	int a[5] = { 1, 3, 5, 7, 9 };
//	int *p = (int*)(&a + 1);
//	printf("%d,%d\n", *(a + 1), *(p - 1));
//	return 0;
//}

//#include<iostream>
//using namespace std;
//#include <algorithm>
//#include<string>
//
//int main()
//{
//	string ret;//存放结果
//	int num;
//	int n; //进制
//	cin >> num >> n;
//	int flag = 0;
//	if (num < 0)
//	{
//		//如果是负数
//		flag = 1;
//		num = -1 * num;
//	}
//
//	int tmp = 0;
//	while (num)
//	{
//		tmp = num % n;
//		if (tmp > 9)
//		{
//			ret += (tmp - 10 + 'A');
//		}
//		else
//			ret += (tmp + '0');
//		num = num / n;
//	}
//
//	if (flag == 1)
//	{
//		ret.push_back('-');
//	}
//	reverse(ret.begin(), ret.end());
//	cout << ret << endl;
//	return 0;
//}


//#include<iostream>
//using namespace std;
//int func()
//{
//	int i, j, k = 0;
//	for (i = 0, j = -1; j = 0; i++, j++)
//	{
//		k++;
//	}
//	return k;
//}
//
//
//int main()
//{
//	cout << (func());
//}



//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main(void)
//{
//	vector<int> arry;
//	arry.push_back(100);
//	arry.push_back(300);//删除
//	arry.push_back(300);
//	arry.push_back(300);//删除
//	arry.push_back(300);
//	arry.push_back(500);
//	vector<int>::iterator itor;
//	for (itor = arry.begin(); itor != arry.end(); itor++)
//	{
//		if (*itor == 300)
//		{
//			itor = arry.erase(itor);
//		}
//	}
//	for (itor = arry.begin(); itor != arry.end(); itor++)
//	{
//		cout << *itor << endl;
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	char a[10] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', 0 }, *p; int i;
//	i = 8;
//	p = a + i;
//	printf("%s\n", p - 3);
//	return 0;
//}


//#include<iostream>
//using namespace std;
//#include<string>
//int main()
//{
//	string str;
//	cin >> str;
//	string str1;
//	int count = 0;
//	for (int i = 0; i < str.size(); i++)
//	{
//		int index = i;
//		count = 0;
//		while (i < str.size() && str[i] >= '0' && str[i] <= '9')
//		{
//			count++;
//			i++;
//		}
//
//		if (count > str1.size())
//		{
//			int tmp = index + count;
//			str1.clear();
//			for (; index < tmp; index++)
//			{
//				str1 += str[index];
//			}
//		}
//	}
//	cout << str1;
//	return 0;
//}

#include<iostream>
using namespace std;
//#pragma pack(8)
//struct One
//{
//	double d;
//	char c;
//	int i;
//};

//#pragma pack(8)
//struct Two
//{
//	char c;
//	double d;
//	int i;
//};
//
//int main()
//{
//	cout << sizeof(struct Two) << endl;
//	return 0;
//}


//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int n[][3] = { 10, 20, 30, 40, 50, 60 };
//	int(*p)[3];
//	p = n;
//	cout << p[0][0] << ", " << *(p[0] + 1) << "," << (*p)[2] << endl;
//}


//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char p1[15] = "abcd", *p2 = "ABCD", str[50] = "xyz";
//	strcpy(str + 2, strcat(p1 + 2, p2 + 1));
//	printf("%s\n", str);
//	return 0;
//}

//#include<iostream>
//using namespace std;
//#include<string>
//
//bool isper(string& str)
//{
//	int left = 0;
//	int right = str.size() - 1;
//	while (left <= right)
//	{
//		if (str[left] == str[right])
//		{
//			left++;
//			right--;
//		}
//		else
//			return false;
//	}
//	return true;
//}
//
//int main()
//{
//	string str1;
//	string str2;
//	cin >> str1 >> str2;
//	int count = 0;
//	string tmp(str1);
//	for (int i = 0; i <= tmp.size(); i++)
//	{
//		str1 = tmp;
//		str1.insert(i, str2);
//		if (isper(str1))
//		{
//			count++;
//		}
//	}
//	cout << count << endl;
//	return 0;
//}


#include<iostream>
using namespace std;

int main()
{
	char *x = "abc";
	char *y = "bcd";
	x = "cde";
}