#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include"add.h"

//int add(int a, int b)
//{
//	return a + b;
//}

//��������
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


//auto:�Զ������Ƶ�
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
//	//����ָ��:* �ɼӿɲ���
//	auto* pa = &a;
//	auto pb = &a;
//
//	//��������: & �����
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
//	//һ�ж���������ʱ�����ʽ�Ƴ������ͱ���һ��
//	auto e = 10, f = 30, g = 2.0;
//}


//��Χfor:  ��ǰ������:ѭ���ķ�Χ
//��ʼֻ������ʼ�����ݣ�����λ�ÿ����Լ�ȷ��
//void test()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
//	//for (int e : arr)
//	//{
//	//	cout << e << " ";
//	//}
//	//cout << endl;
//
//	//��Ҫ�ı������ֵ������ʹ��&
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
//	//�����ı������ֵ��ʹ��const
//	//for (const int& e : arr)
//	//������ʹ���Զ�����
//	for (const auto& e : arr)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}

//nullptr:ָ���ֵ
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



//c++�г��õĶ�����ķ�ʽ��class���������еĳ�Ա��
//public:���еĳ�Ա������ɼ�
//private:˽�еĳ�Ա�����ⲻ�ɼ�,protectedĿǰ������Ϊ˽��
//����Ȩ�޷�ֻ�����Ƴɣ�Ա������ķ��ʣ������ڲ�����Ա֮����Ի�����ʣ����ܷ������η�������
//����Ȩ�����η������򣺴����η���ʼ������һ�����η�����
//class Student
//{//public://	//��Ա����
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
//	//��Ա����
//	char _name[20];
//	char _gender[3];
//	int _age;//
//};


void test()
{
	Student stu;
	stu.SetStudentInfo("����", "Ů", 20);
	stu.PrintStudentInfo();
	//cout << stu._age << endl;
}


int main()
{
	test();
	return 0;
}