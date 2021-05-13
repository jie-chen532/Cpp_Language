#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//void RotateR(Node* parent)
//{
//	Node* subL = parent->left;
//	Node* subLR = subL->right;
//
//	subL->right = parent;
//	parent->left = subLR;
//
//	if (subLR)
//		subLR->parent = parent;
//
//	if (_root == parent)
//	{
//		_root = subL;
//		subL->parent = nullptr;
//	}
//	else
//	{
//		Node* pparent = parent->parent;
//		if (pparent->left == parent)
//			pparent->left = subL;
//		else
//			pparent->right = subL;
//
//		subL->parent = pparent;
//	}
//	parent->parent = subL;
//
//	subL->bf = parent->bf = 0;
//}

//void RotateL(Node* parent)
//{
//	Node* subR = parent->right;
//	Node* subRL = subR->left;
//
//	subR->left = parent;
//	parent->right = subRL;
//
//	if (subRL)
//		subRL->parent = parent;
//
//	if (parent == root)
//	{
//		_root = subR;
//		subR->parent = nullptr;
//	}
//	else
//	{
//		Node* pparent = parent->parent;
//		if (pparent->left = parent)
//			pparent->left = subR;
//		else
//			pparent->right = subR;
//		subR->parent = pparent;
//	}
//	parent->parent = subR;
//	parent->bf = subR->bf = 0; 
//}

//static int a = 1;
//void fun1()
//{
//	a = 2;
//}
//
//void fun2()
//{
//	int a = 3;
//}
//
//void fun3()
//{
//	static int a = 4;
//}
//
//int main()
//{
//	printf("%d ", a);
//	fun1();
//	printf("%d ", a);
//	fun2();
//	printf("%d ", a);
//	fun3();
//	printf("%d ", a);
//}
//bool isLeap(int year)
//{
//	return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
//}
//
//int getDay(int year, int Month, int Day)
//{
//	int day[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	if (isLeap(year))
//		day[2] = 29;
//	if (year <= 0 || Month <= 0 || Month > 12 || Day <= 0 || Day > day[Month])
//		return -1;
//	int sum_day = 0;
//	int month_count = 1;
//	while (month_count < Month)
//	{
//		sum_day += day[month_count];
//		month_count++;
//	}
//	return (sum_day + Day);
//}
//
//int main()
//{
//	int year, Month, Day;
//	cin >> year >> Month >> Day;
//	int ret = getDay(year, Month, Day);
//	cout << ret << endl;
//	return 0;
//}

//int main()
//{
//	char dog[] = "wang\0miao";
//	cout << sizeof(dog) << endl;
//	cout << strlen(dog) << endl;
//}

//int main()
//{
//	char ccString1[] = "Is Page Fault??";
//	char ccString2[] = "No Page Fault??";
//	strcpy(ccString1, "No");
//	if (strcmp(ccString1, ccString2) == 0)
//		cout << ccString2;
//	else
//		cout << ccString1;
//}

//int main()
//{
//	char str[] = "glad to test something";
//	char *p = str;
//	p++;
//	int *p1 = reinterpret_cast<int*> (p);
//	p1++;
//	p = reinterpret_cast<char*> (p1);
//	printf("result is %s\n", p);
//	return 0;
//}