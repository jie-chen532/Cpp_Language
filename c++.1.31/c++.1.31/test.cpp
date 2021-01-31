#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include"add.h"

//int add(int a, int b)
//{
//	return a + b;
//}

//内联函数
//inline int add(int a, int b)
//{
//	return a + b;
//}

//inline int fun(int n)
//{
//	if (n <= 1)
//		return 1;
//	return fun(n - 1)*n;
//}
//
//void test()
//{
//	int a = 10;
//	int b = 20;
//	int ret = add(a, b);
//	int n = 1000;
//	int ret1 = fun(n);
//}


//auto:自动类型推导
//void test()
//{
//	auto a = 10;
//	auto b = 2.3;
//	auto c = 's';
//	auto d = 'a' + b;
//
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//}


//void test()
//{
//	int a = 10;
//
//	//定义指针:* 可加可不加
//	auto* pa = &a;
//	auto pb = &a;
//
//	//定义引用: & 必须加
//	auto b = a;
//	auto& rb = a;
//
//	cout << typeid(pa).name() << endl;
//	cout << typeid(pb).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(rb).name() << endl;
//
//	rb = 2;
//	b = 100;
//
//
//	int a, b, c, d;
//	//一行定义多个变量时，表达式推出的类型必须一致
//	auto e = 10, f = 30, g = 2.0;
//}


//范围for:  当前的数据:循环的范围
//开始只能是起始的数据，结束位置可以自己确定
//void test()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
//	//for (int e : arr)
//	//{
//	//	cout << e << " ";
//	//}
//	//cout << endl;
//
//	//若要改变数组的值，可以使用&
//	//for (int& e : arr)
//	//{
//	//	cout << e << " ";
//	//	e = 10;
//	//}
//	//cout << endl;
//	//for (int e : arr)
//	//{
//	//	cout << e << " ";
//	//}
//	//cout << endl;
//
//	//若不改变数组的值，使用const
//	//for (const int& e : arr)
//	//还可以使用自动变量
//	for (const auto& e : arr)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}

//nullptr:指针空值
//void fun(int a)
//{
//	cout << "fun(int a)" << endl;
//}
//
//void fun(int* a)
//{
//	cout << "fun(int* a)" << endl;
//}
//
//void test()
//{
//	int* p = NULL;//int* p = 0;
//	fun(NULL);
//	fun((int*)NULL);
//	fun(nullptr);
//	cout << typeid(nullptr).name() << endl;
//}



//c++中常用的定义类的方式：class类名（所有的成员）
//public:共有的成员在类外可见
//private:私有的成员在类外不可见,protected目前可以认为私有
//访问权限符只能限制成；员在类外的访问，在类内部，成员之间可以互相访问，不受访问修饰符的限制
//访问权限修饰符作用域：从修饰符开始，到下一个修饰符结束
//class Student
//{//public://	//成员函数
	//void SetStudentInfo(const char* name, const char* gender, int age)
	//{
	//	strcpy(_name, name);
	//	strcpy(_gender, gender);
	//	_age = age;
	//}
//
//	void PrintStudentInfo()
//	{
//		cout << _name << " " << _gender << " " << _age << endl;
//	}
//
//private:
//	//成员变量
//	char _name[20];
//	char _gender[3];
//	int _age;//
//};


void test()
{
	Student stu;
	stu.SetStudentInfo("张三", "女", 20);
	stu.PrintStudentInfo();
	//cout << stu._age << endl;
}


int main()
{
	test();
	return 0;
}