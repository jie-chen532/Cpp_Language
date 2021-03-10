#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void cinn()
//	{
//		cin >> _year >> _month >> _day;
//	}
//
//	bool is_leap(int year)
//	{
//		return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
//	}
//
//	int getDay(int year, int month)
//	{
//		int day[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//		if (is_leap(_year) && _month == 2)
//		{
//			++day[_month];
//		}
//		return day[month];
//	}
//
//	Date& operator+= (int days)
//	{
//
//
//		_day += days;
//		while (_day > getDay(_year, _month))
//		{
//			_day -= getDay(_year, _month);
//			++_month;
//
//			if (_month > 12)
//			{
//				_month = 1;
//				++_year;
//			}
//		}
//		return *this;
//	}
//
//	void print()
//	{
//		cout << _year << "-";
//		if (_month < 10)
//		{
//			cout << 0 << _month << "-";
//		}
//		else
//			cout << _month << "-";
//		if (_day < 10)
//		{
//			cout << 0 << _day << endl;
//		}
//		else
//			cout << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//
//int main()
//{
//	int m = 0;
//	cin >> m;
//	while (m--)
//	{
//		int days = 0;
//		Date d;
//		d.cinn();
//		cin >> days;
//		d += days;
//		d.print();
//	}
//	return 0;
//}


//class Date
//{
//public:
//	Date(int year = 0, int month = 0, int day = 0)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	bool is_leap(int year)
//	{
//		return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
//	}
//
//	int getDay(int year, int month)
//	{
//		int day[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//		if (is_leap(_year) && _month == 2)
//		{
//			++day[_month];
//		}
//		return day[month];
//	}
//
//	Date& sDate(int year, int day)
//	{
//		_year = year;
//		_month = 1;
//		while (day > getDay(_year, _month))
//		{
//			day -= getDay(_year, _month);
//			_month++;
//		}
//		_day = day;
//		return *this;
//	}
//
//	void print()
//	{
//		cout << _year << "-";
//		if (_month < 10)
//		{
//			cout << 0 << _month << "-";
//		}
//		else
//			cout << _month << "-";
//		if (_day < 10)
//		{
//			cout << 0 << _day << endl;
//		}
//		else
//			cout << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	int year = 0;
//	int day = 0;
//	while (1)
//	{
//		cin >> year >> day;
//		Date d;
//		d.sDate(year, day);
//		d.print();
//	}
//	return 0;
//}


//int main()
//{
//	int year = 0;
//	int month = 0;
//	cin >> year >> month;
//	cout << year << month;
//	return 0;
//}


int main()
{
	char date[8];
	cin >> date;
	return 0;
}