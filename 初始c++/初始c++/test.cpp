#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<iostream>

//�����ռ䶨��
//namespace + �����ռ�����{����������}
namespace N1
{
	int a = 10;
	int b = 20;
	void fun1()
	{
		printf("N1::fun1\n");
	}
	//�����ռ��Ƕ��
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

//�ֶζ���
namespace N1
{
	int d = 10;
	int add(int a, int b)
	{
		return a + b;
	}
}

int a = 100;//ȫ�ֱ���

//void test()
//{
//	//�����ռ��г�Ա�ķ��ʷ�ʽ
//	//1.�����ռ� + :: + ��Ա
//	printf("N1::a->%d\n", N1::a);//�����ռ�N1�е�a
//	N1::fun1();
//	printf("N1::N2::c->%d\n", N1::N2::c);
//	N1::N2::fun2();
//	printf("a + b = %d\n", N1::add(10, 20));
//	printf("\n");
//	//2.using  �����ռ� :: ��Ա
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
//	//3.չ�������ռ�:using namespace �����ռ�
//	//�����ռ��µ����г�Աȫ������¶��ȫ���������У����ȫ�����еĳ�Ա��������
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
//	//c++ͷ�ļ��ж�������г�Ա������std�����ռ�
//	std::cin >> a >> b >> c;
//	std::cout << a <<std::endl;
//}


//ȱʡ����
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

//ȫȱʡ:���в�������Ĭ��ֵ
void fun4(int a = 10, int b = 20, int c = 40)
{
	cout << a << " " << b << " " << c << endl;
}


//��ȱʡ����:���ֲ�������Ĭ��ֵ
//����Ĭ��ֵ��������������������ֵ���м䲻���м��
void fun5(int a, int b = 10, int c = 20)
{
	cout << a << " " << b << " " << c << endl;
}

//����
//void fun6(int a, int b = 10, int c);
//void fun7(int a = 10, int b, int c = 10);


//�����Ͷ��壬ֻ����һ���ط�����Ĭ��ֵ������ͬʱ����
//��������
void fun6(int a);
//��������
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


//��������
//    ��������ͬ,������ͬ�������������������ͣ�����˳��
//ֻ�з���ֵ���Ͳ�ͬ�����ܹ��ɺ�������
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
