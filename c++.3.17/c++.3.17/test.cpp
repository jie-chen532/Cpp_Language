#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

template<typename T>
T Add(const T& a, const T& b)
{
	return a + b;
}

void test()
{
	int a = 10;
	double b = 1.0;
	//强制类型转化，两个参数类型一致
	Add(a, (int)b);

	//显示实例化
	//告诉编译器，生成int类型的Add函数
	Add<int>(a, b);
}

//template<class T>
//class seqList
//{
//public:
//	seqList(int n)
//		:_data(new T[n])
//		, _size(0)
//		, _capacity(n)
//	{}
//	T seqListAt(size_t pos);
//private:
//	T* _data;
//	size_t _size;
//	size_t _capacity;
//};
//
////类外定义函数:需要加泛型声明
//template<class T>
//T seqList<T>::seqListAt(size_t pos)
//{
//	return _data[pos];
//}
//
//void test()
//{
//	seqList<int> seq1(10);
//	seqList<char> seq2(10);
//	seqList<double> seq3(10);
//}

//template<typename T, typename T1>
//void print(const T& a, const T1& b)
//{
//	cout << "print(const T& a, const T1& b)" << endl;
//}
//
//void print(int a, double b)
//{
//	cout << "print(int a, double b)" << endl;
//}
//
//
//void test()
//{
//	int a = 10;
//	double b = 2.0;
//	print<int>(a, b);
//}

//void test()
//{
//	int a = 10;
//	int b = 10;
//	print(a, b);
//}

//void test()
//{
//	int a = 10;
//	double b = 1.2;
//	print(a, b);
//}

//template<typename T>
//T Add(const T& a, const T& b)
//{
//	return a + b;
//}
//
//void test()
//{
//	int a = 10;
//	double b = 1.0;
//	//强制类型转化，两个参数类型一致
//	Add(a, (int)b);
//
//	//显示实例化
//	//告诉编译器，生成int类型的Add函数
//	Add<int>(a, b);
//}

//void test()
//{
//	int a = 10;
//	int b = 10;
//	Add(a, b);
//}

//template<typename T>
//void Swap(T& a, T& b)
//{
//	T tmp = a;
//	a = b; 
//	b = tmp;
//}
//
//void test()
//{
//	int a = 10;
//	int b = 20;
//	Swap(a, (int)b);
//}

//
//class A
//{
//public:
//	A(int a)
//		:_a(a)
//	{}
//private:
//	int _a;
//};
//
//void test()
//{
//	int a = 10;
//	int b = 20;
//	Swap(a, b);
//
//	double c = 1.0;
//	double d = 2.1;
//	Swap(c, d);
//
//	char e = 'c';
//	char f = 'f';
//	Swap(e, f);
//
//	A a1(10);
//	A a2(20);
//	Swap(a1, a2);
//}

//void test()
//{
//	char* ptr = new char[10];
//	delete[] ptr;
//}

//class A
//{
//public:
//	A(int a)
//		:_a(a)
//	{
//		cout << "A(int)" << endl;
//	}
//
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int _a;
//};
//
//void test()
//{
//	A* ptr = (A*)malloc(sizeof(A));
//	new (ptr) A(10);
//	ptr->~A();
//	free(ptr);
//
//	//A* ptr1 = (A*)malloc(sizeof(A)* 5);
//	//for (int i = 0; i < 5; i++)
//	//{
//	//	new (ptr1 + i) A(10);
//	//}
//
//	//for (int i = 0; i < 5; i++)
//	//{ 
//	//	(ptr1 + i)->~A(); 
//	//}
//
//	//free(ptr1);
//}

int main()
{
	test();
	return 0;
}