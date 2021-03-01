#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<time.h>

//void test()
//{
//	//const int a = 10;
//	//const int& ra = a;
//
//	////100是常量
//	//const int& rb = 100;
//
//	double b = 2.5;
//	int a = 10;
//	a = b;
//
//	const int& ra = b;
//
//}


//void swap(int& a, int& b)
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//
//
//void test()
//{
//	int a = 10;
//	int b = 20;
//	swap(a, b);
//	cout << "a:" << a << endl;
//	cout << "b:" << b << endl;
//}

//int& add(int& a, int& b)
//{
//	return a += b;
//}
//
//void test()
//{
//	int a = 10;
//	int b = 20;
//	int ret = add(a, b);
//	cout << ret << endl;
//}

//struct A
//{
//	int arr[10000];
//};
//
//void fun1(A a)
//{}
//
//void fun2(A& a)
//{}
//
//void test()
//{
//	A a;
//	//以值作为函数参数
//	size_t begin1 = clock();
//	for (int i = 0; i < 1000000; i++)
//	{
//		fun1(a);
//	}
//	size_t end1 = clock();
//
//	//以引用作为函数参数
//	size_t begin2 = clock();	
//	for (int i = 0; i < 1000000; i++)
//	{
//		fun2(a);
//	}
//	size_t end2 = clock();
//
//	cout << "以值作为函数参数:" << end1 - begin1 << endl;
//	cout << "以引用作为函数参数:" << end2 - begin2 << endl;
//}



//struct A
//{ 
//	int a[10000]; 
//};
//
//A a;
//
//A fun1() 
//{ 
//	return a; 
//}
//
//A& fun2()
//{ 
//	return a; 
//}
//
//void test()
//{
//	// 以值作为函数的返回值类型
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 1000000; ++i)
//		fun1();
//	size_t end1 = clock();
//
//	// 以引用作为函数的返回值类型
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 1000000; ++i)
//		fun2();
//	size_t end2 = clock();
//
//	cout << "值作为返回值类型:" << end1 - begin1 << endl;
//	cout << "引用作为返回值类型:" << end2 - begin2 << endl;
//}

//void test()
//{
//	int a = 10;
//	int& ra = a;
//	ra = 20;
//
//	int a1 = 10;
//	int* pa = &a1;
//	*pa = 20;
//}

//void test()
//{
//	double a = 2.5;
//	double& ra = a;
//	cout << "ra：" << sizeof(ra) << endl;
//
//	double* pa = &a;
//	cout << "pa：" << sizeof(pa) << endl;
//}


//inline int add(int a, int b)
//{
//	return a  + b;
//}

//inline int fun(int n)
//{
//	if (n <= 1)
//		return 1;
//	return fun(n - 1)*n;
//}

//void test()
//{
//	int a = 10;
//	auto b = a;
//	auto c = 'a';
//	auto d = 'a' + 2.0;
//
//	//可以通过typeid(变量名).name()查看变量类型
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//}

//void test()
//{
//	int a = 10;
//	auto pa = &a;
//	auto* pb = &a;
//
//	cout << typeid(pa).name() << endl;
//	cout << typeid(pb).name() << endl;
//}


//void test()
//{
//	int a = 10;
//	auto& ra = a;
//}

//void test()
//{
//	auto a = 2, b = 3, c = 4;
//	auto d = 2, e = 2.0;
//
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//}

//void test()
//{
//	int a[] = { 1, 2, 3 };
//	//错误
//	auto b[] = { 4, 5, 6 };
//}

//#include"add.h"
int main()
{
	//int ret = add(10, 20);
	//test();
	return 0;
}