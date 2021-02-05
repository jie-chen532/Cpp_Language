#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;


//日历类
class Date
{
public:
	//构造函数
	Date(int year = 1, int month = 1, int day = 1)
	{
		if (year <= 0 || month <= 0 || month > 12 || day <= 0
			|| day > getDays(year, month))
		{
			_year = 1;
			_month = 1;
			_day = 1;
			cout << "年月份输入有错误" << endl;
		}
		else
		{
			_year = year;
			_month = month;
			_day = day;
		}
	}


	//getDays
	int getDays(int year, int month)
	{
		static int day[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };  //二月是平年
		
		int d = day[month];
		//判断是闰年，并且是2月
		if (((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) && month == 2)
			++d;

		return d;
	}

	//Date + day
	//2021.2.4 + 30 --->34-->2021.3.6
	//2020.12.3 + 30 --->33--->2020.13.2--->2021.1.2
	Date& operator+=(int day)
	{
		//如果day是负数
		if (day < 0)
		{
			*this -= -day;
		}
		_day += day;
		while (_day > getDays(_year, _month))
		{
			_day -= getDays(_year, _month);
			++_month;

			if (_month > 12)
			{
				_month = 1;
				++_year;
			}
		}
		return *this;
	}

	//Date + 30
	Date operator+(int day)
	{
		 Date d(*this);
		 d += day;
		 return d;
	}

	//前置++
	Date& operator++()
	{
		return *this += 1;
	}

	//后置++
	Date operator++(int)
	{
		Date d(*this);
		*this += 1;
		return d;
	}
	//Date -= day
	//2020.12.31 - 32---> -1 --->2020.11.30
	//2021.1.30 -32---->-2--->2020.12.29
	Date& operator-=(int day)
	{
		//如果day是负数
		if (day < 0)
		{
			return *this += -day;
		}

		_day -= day;
		while (_day < 0)
		{
			--_month;

			if (_month == 0)
			{
				_month = 12;
				_year -= 1;
			}
			_day += getDays(_year, _month);
		}
		return *this;
	}


	//Date - day
	Date operator-(int day)
	{
		Date d(*this);
		d -= day;
		return d;
	}

	//--Date
	Date& operator--()
	{
		return *this -= 1;
	}

	//Date--
	Date operator--(int)
	{
		Date d(*this);
		*this -= 1;
		return d; 
	}

	//==
	bool operator==(const Date& d2)
	{
		if (_year == d2._year && _month == d2._month && _day == d2._day)
			return true;
		else
			return false;
	}
	//!=
	bool operator!=(const Date& d2)
	{
		return !(*this == d2);
	}
	//>
	bool operator>(const Date& d2)
	{
		if (_year > d2._year)
			return true;
		else if (_year == d2._year)
		{
			if (_month > d2._month)
				return true;
			else if (_month == d2._month)
			{
				if (_day > d2._day)
					return true;
			}
		}
		return false;
	}
	//>=
	bool operator>=(const Date& d2)
	{
		return *this > d2 || *this == d2;
	}
	//<
	bool operator<(const Date& d2)
	{
		return !(*this >= d2);
	}
	//<=
	bool operator<=(const Date& d2)
	{
		return !(*this > d2);
	}

	void printDate()
	{
		cout << _year << "." << _month << "." << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};


void test()
{
	Date d1(2020, 1, 2);
	d1 += 365;
	Date d2;
	d2 = d1 + 50;
	d2 = d1++;
	d1.printDate();
	d2.printDate();
}

int main()
{
	test();
	return 0;
}