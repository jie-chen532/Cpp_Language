#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//class Date
//{
//public:
//	friend istream& operator>>(istream& _cin, Date& d);
//	Date(int year, int month, int day)
//	:_year(year)
//	, _month(month)
//	, _day(day)
//	{}
//private:
//	friend ostream& operator<<(ostream& _cout, const Date& d);
//	int _year;
//	int _month;
//	int _day;
//};
//
//ostream& operator<<(ostream& _cout, const Date& d)
//{
//	_cout << d._year << "-" << d._month << "-" << d._day << endl;
//	return _cout;
//}
//
//istream& operator>>(istream& _cin, Date& d)
//{
//	_cin >> d._year >> d._month >> d._day;
//	return _cin;
//}
//
//void test()
//{
//	Date d(2021, 3, 13);
//	cout << d << d;
//	cin >> d >> d;
//	cout << d << endl;
//	
//}

//class Date
//{
//public:
//	Date(int year, int month, int day)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{}
//
//	void operator<<(ostream& _cout)
//	{
//		_cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//void test()
//{
//	Date d(2021, 3, 13);
//	d.operator<<(cout);
//	d << cout;
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
//	A(int a)
//		:_a(a)
//	{}
//	//friend void fun();
//private:
//	int _a;
//};
//
//class B
//{
//public:
//	B(int b)
//		:_b(b)
//	{}
//	friend void fun(B b);
//private:
//	int _b;
//};
//
//void fun(B b)
//{
//	cout << "B::b" << b._b << endl;
//}
//
//int main()
//{
//	A a(10);
//	B b(20);
//	fun(b);
//	return 0;
//}


//class Date;
//class Time;
//class Time
//{
//public:
//	friend class Date;
//	Time(int hour, int minute, int second)
//		:_hour(hour)
//		, _minute(minute)
//		, _second(second)
//	{}
//
//private:
//	int _hour;
//	int _minute;
//	int _second;
//	static int b ;
//};
//
//int Time::b = 0;
//
//class Date
//{
//public:
//	Date(int year, int month, int day)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//		, _t(18, 22, 30)
//	{}
//
//	void setTime(int hour, int minute, int second)
//	{
//		_t._hour = hour;
//		_t._minute = minute;
//		_t._second = second;
//		_t.b = 0;
//		Time::b = 3;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//};


//int main()
//{
//	Date d(2021, 3, 13);
//	d.setTime(18, 31, 20);
//	return 0;
//}


class A
{
public:
	class B
	{
	public:
		void setA(A& a)
		{
			a._a = 2;
		}
	private:
		int _a = 10;
	public:
		int _c = 20;
	};
private:
	int _a = 1;
};


int main()
{
	int size_A = sizeof(A);
	int size_B = sizeof(A::B);
}