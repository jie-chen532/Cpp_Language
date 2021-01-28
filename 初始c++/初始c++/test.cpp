#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<iostream>

//命名空间定义
//namespace + 命名空间名称{变量，函数}
namespace N1
{
	int a = 10;
	int b = 20;
	void fun1()
	{
		printf("N1::fun1\n");
	}
	//命名空间可嵌套
	namespace N2
	{
		int c = 10;
		int d = 20;
		void fun2()
		{
			printf("N1::N2::fun2\n");
		}
		namespace N3
		{
			void fun3()
			{
				printf("N1::N2::N3::fun3\n");
			}
		}
	}
}

//分段定义
namespace N1
{
	int d = 10;
	int add(int a, int b)
	{
		return a + b;
	}
}

int a = 100;//全局变量

//void test()
//{
//	//命名空间中成员的访问方式
//	//1.命名空间 + :: + 成员
//	printf("N1::a->%d\n", N1::a);//命名空间N1中的a
//	N1::fun1();
//	printf("N1::N2::c->%d\n", N1::N2::c);
//	N1::N2::fun2();
//	printf("a + b = %d\n", N1::add(10, 20));
//	printf("\n");
//	//2.using  命名空间 :: 成员
//	using N1::b;
//	printf("N1::b->%d\n", b);
//	using N1::fun1;
//	fun1();
//	using N1::N2::c;
//	printf("%d\n", c);
//	using N1::N2::fun2;
//	using N1::add;
//	printf("a + b = %d\n", add(10, 20));
//	fun2();
//	printf("\n");
//	//3.展开命名空间:using namespace 命名空间
//	//命名空间下的所有成员全部都暴露在全局作用域中，会和全局域中的成员发生混淆
//	using namespace N1;
//	using namespace N2;
//	using namespace N3;
//	printf("%d\n", c);
//	fun1();
//	fun2();
//	fun3();
//	printf("a + b = %d\n", add(10, 20));
//	//printf("%d\n", a);
//}


using namespace std;
//void test()
//{
//	int a = 10;
//	int b = 0;
//	int c = 0;
//	//c++头文件中定义的所有成员都属于std命名空间
//	std::cin >> a >> b >> c;
//	std::cout << a <<std::endl;
//}


//缺省参数
void fun1(int a = 10)
{
	cout << a << endl;
}

void fun2(int a)
{
	cout << a << endl;
}

void fun3(int a = 20)
{
	cout << a << endl;
}

//全缺省:所有参数都有默认值
void fun4(int a = 10, int b = 20, int c = 40)
{
	cout << a << " " << b << " " << c << endl;
}


//半缺省参数:部分参数设置默认值
//设置默认值，从右向左依次连续赋值，中间不能有间隔
void fun5(int a, int b = 10, int c = 20)
{
	cout << a << " " << b << " " << c << endl;
}

//错误
//void fun6(int a, int b = 10, int c);
//void fun7(int a = 10, int b, int c = 10);


//声明和定义，只能有一个地方设置默认值，不能同时设置
//函数声明
void fun6(int a);
//函数定义
void fun6(int a = 10)
{
	cout << a << endl;
}


void test()
{
	fun1();
	fun2(20);
	fun3(30);
	fun4();
	fun4(20);
	fun5(10);
	fun5(10, 40, 50);
}


//函数重载
//    函数名相同,参数不同：参数个数，参数类型，参数顺序
//只有返回值类型不同，不能构成函数重载
int add(int a, int b)
{
	return a + b;
}

char add(char a, int b)
{
	return a + b;
}

double add(double a, double b)
{
	return a + b;
}

void fun7(char a, int b)
{
	cout << "fun7(char,int)" << endl;
}

void fun7(int a, char b)
{
	cout << "fun7(int,char)" << endl;
}

void fun7(int a, char b,char c)
{
	cout << "fun7(int,char,char)" << endl;
}

int fun7(int a, int b)
{
	return 0;
}

void test1()
{
	int ret = add(10, 20);
	printf("int add()->%d\n", ret);
	
	double ret1 = add(12.3, 10.1);
	printf("double add()->%lf\n", ret1);
	fun7('c', 1);
	fun7(1, 'b');
	fun7(1, 'c', 'y');
	cout << fun7(1, 0) << endl;
}

int main()
{
	test();
	test1();
	return 0;
}
