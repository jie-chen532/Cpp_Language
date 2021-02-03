#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;


//析构函数
//一个类有且只有一个析构函数。若未显式定义，系统会自动生成默认的析构函数。
//不显示定义析构，编译器会自动生成默认的析构函数
typedef int DataType;
class SeqList
{
public:
	SeqList(int capacity = 10)
	{
		_pData = (DataType*)malloc(capacity * sizeof(DataType));

		_size = 0;
		_capacity = capacity;	}

	//对象销毁的时候，编译器自动调用析构，完成资源清理
	//编译器自动创建的析构函数为空，若有malloc创建的资源，必须用free释放掉
	~SeqList()
	{
		if (_pData)
		{
			free(_pData); // 释放堆上的空间
			_pData = NULL; // 将指针置为空
			_capacity = 0;
			_size = 0;
		}
	}

public:
	int* _pData;
	size_t _size;
	size_t _capacity;
};

void test()
{
	SeqList sq(100);
	SeqList copy(sq);
}

//int* p = nullptr;
//void test()
//{
//	SeqList sq(1000);
//	//野指针  非法访问
//	p = sq._pData;
//}




class Date
{
public:
	Date(int year = 2021, int month = 1, int day = 2)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	//创建拷贝构造
	//如果不显示定义拷贝构造，编译器会自动生成拷贝构造
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}


	void Display()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
	//析构函数自动调用自定义成员的析构函数，完成自定义成员的资源清理
	SeqList sq;
};

void test()
{
	Date d2;
	//调用拷贝构造，创建copy对象，内容和d2完全相同
	Date copy(d2);
}



//class A
//{
//public:
//	int a;
//};
//
////构造函数
////构造可以重载
////无参：默认构造
////编译器自动生成的构造函数也为无参的构造函数，它也是默认构造
////没有显式定义任何一个构造函数，编译器会自动生成无参构造，否则不会自动生成
////只能有一个默认构造函数
//class Date
//{
//public:
//	//无参构造
//	//Date()
//	//{
//
//	//}
//
//	//全缺省
//	//默认构造
//	Date(int year = 2021, int month = 1, int day = 2)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	Date(int year, int month, int day,int num)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Display()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//	//任何一个构造函数(包括编译器自动生成的)都会自动调用自定义成员的默认构造
//	//自定义类型成员
//	A a;
//};
//void test()
//{
//	//编译器在创建对象时，自动调用构造函数
//	//完成对象内容的初始化，并不是创建对象
//	Date d1(2021,2,3);
//	d1.Display();
//
//	//无参构造
//	Date d2;
//	d2.Display();
//
//	//调用带参的构造
//	Date d3(2010,1,1,12);
//
//
//	//不是一个无参构造，而是一个函数声明
//	//返回值：Date
//	//参数：无参
//	//函数名d4
//	Date d4();
//}


//class A
//{
//public:
//	void PrintA()  //this = NULL
//	{
//		cout << _a << endl;
//		//this->_a  NULL不能进行解引用
//	}
//
//	void Show()  //this = NULL
//	{
//		cout << "Show()" << endl;
//	}
//private:
//	int _a;
//};
//
////this在栈中
////this可为空，也不可为空
////this需要做解引用的时候不能为空，其他情况可以为空
//void test()
//{
//	A* p = NULL;
//	p->PrintA();
//	//p->Show();//此时不是p的解引用，而是给Show中this传NULL值
//}


//this
//每一个非静态成员函数中，都有一个this函数
//只存在于成员函数中
//作为函数的第一个形参
//this指向当前调用此函数的对象
//this类型：类类型* const this
//class Date
//{
//public:
//	void Display()  //void Display(Date* const this)
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//	void SetDate(int year, int month, int day)//void SetDate(this, int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year; // 年
//	int _month; // 月
//	int _day; // 日
//};
//
//void test()
//{
//	Date d1, d2;
//	d1.SetDate(2018, 5, 1);
//	d2.SetDate(2018, 7, 1);
//	d1.Display();
//	d2.Display();
//}

////大端小端
//union A
//{
//	char a;
//	int b;
//};
//
//void test()
//{
//	A a;
//	a.b = 1;
//	a.a = 'a';
//	cout << a.b << endl;
//}

//void test()
//{
//	A a;
//	a.b = 1;
//	if (a.a)
//	{
//		cout << "小端" << endl;
//	}
//	else
//		cout << "大端" << endl;
//}

//大端小端
//void test()
//{
//	int a = 1;
//	//0x00 00 00 01
//	//小端：0x10 00 00 00
//	//大端：0x00 00 00 01
//	char* p = (char*)(&a);
//	if (*p)
//	{
//		cout << "小端" << endl;
//	}
//	else
//		cout << "大端" << endl;
//}

//设置默认对齐数
//#pragma pack(1)
//struct A
//{
//	char a;//1  1   0
//	int b;//4   1    1-4
//	double c;// 8  1    5-12
//};
//
//void test()
//{
//	struct A b;
//	cout << sizeof(A) << endl;//13
//	//计算偏移位置
//	cout << (char*)(&b.c) - (char*)(&b) << endl;//5
//}


//struct A
//{
//	char a;//1  8   0
//	int b;//4   8   4-7  
//	double c;// 8  8    8-15
//};
//
//
//struct B
//{
//	int a; //0-3
//	char b;//4
//	double c;//8-15
//	float d;//16-19
//	struct A e;//24-39
//};
//
//
//void test()
//{
//	cout << sizeof(A) << endl;//16
//	cout << sizeof(B) << endl; //40
//}



int main()
{
	test();
	return 0;
}