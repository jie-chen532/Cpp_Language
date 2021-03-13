#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//class A
//{
//public:
//	A(int a)
//		:_b(_a)
//		,_a(a)
//	{}
//
//	void print()
//	{
//		cout << "_a:" << _a << endl;
//		cout << "_b:" << _b << endl;
//	}
//
//private:
//	int _a;
//	int _b;
//};
//
//int main()
//{
//	A aa(1);
//	aa.print();
//	return 0;
//}


//class A
//{
//public:
//	A(int a)
//		:_a1(a)
//		, _a2(_a1)
//	{}
//
//	void Print() {
//		cout << _a1 << " " << _a2 << endl;
//	}
//private:
//	int _a2;
//	int _a1;
//};
//
//int main() 
//{
//	A aa(1);
//	aa.Print();
//	return 0;
//}


//class A
//{
//public:
//	explicit A(int a)
//	:_a(a)
//	{}
//
//private:
//	int _a;
//};
//
//int main()
//{
//	A a(1);
//	a = 40;
//	return 0;
//}


//class A
//{
//public:
//	A() { ++_scount; }
//	A(const A& t) { ++_scount; }
//	static int GetACount() { return _scount; }
//private:
//	static int _scount;
//};
//int A::_scount = 0;
//
//void TestA()
//{
//	cout << A::GetACount() << endl;
//	A a1, a2;
//	A a3(a1);
//	cout << A::GetACount() << endl;
//}
//
//int main()
//{
//	TestA();
//	return 0;
//}


//class A
//{
//public:
//	A() 
//	{ 
//		++_scount; 
//	}
//
//	A(const A& t) 
//	{
//		++_scount;
//	}
//
//	static int GetACount() 
//	{ 
//		return _scount;
//	}
////private:
//	static int _scount;
//};
//
//int A::_scount = 0;
//
//void TestA()
//{
//	A a1;
//	cout << A::_scount << endl;
//
//
//	cout << a1._scount << endl;
//
//}
//
//
//int main()
//{
//	TestA();
//	return 0;
//}


//class A
//{
//public:
//	int getCount()
//	{
//		return count;
//	}
//private:
//	static int count;
//};
//
//int A::count = 0;
//
//void test()
//{
//	A a1;
//	A a2;
//	A a3;
//}
//
//int main()
//{
//	test();
//	return 0;
//}


//class A
//{
//public:
//	A()
//	{
//		count++;
//	}
//
//	static int getCount()
//	{
//		return count;
//	}
//	
//	void fun()
//	{
//		getCount();
//	}
//private:
//	static int count;
//};


class A
{
public:
	A()
	{}
private:
	int _a = 10;
	int _b = 10;
	int _c = 0;
};

int main()
{
	A a;
	return 0;
}
