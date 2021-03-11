#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
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
//		if (is_leap(year) && month == 2)
//		{
//			++day[month];
//		}
//		return day[month];
//	}
//
//	void div(char s[])
//	{
//		_year = (s[0] - '0') * 1000 + (s[1] - '0') * 100 +
//			(s[2] - '0') * 10 + (s[3] - '0');
//		_month = (s[4] - '0') * 10 + (s[5] - '0');
//		_day = (s[6] - '0') * 10 + (s[7] - '0');
//	}
//
//	//ÅÐ¶Ïd1ÊÇ·ñ´óÓÚd
//	bool is_big(Date d)
//	{
//		if (_year > d._year)
//			return true;
//		if (_year == d._year && _month > d._month)
//			return true;
//		if (_year == d._year && _month == d._month && _day > d._day)
//			return true;
//		return false;
//	}
//
//	int count = 0;
//	int operator-(Date d)
//	{
//		//ÈÃ*this>d
//		if (!is_big(d))
//		{
//			Date tmp = *this;
//			*this = d;
//			d = tmp;
//		}
//
//		while (!(_year == d._year && _month == d._month))
//		{
//			count += _day;
//			--_month;
//			if (_month <= 0)
//			{
//				_month = 12;
//				--_year;
//			}
//			_day = getDay(_year, _month);
//		}
//		return count += (_day - d._day) + 1;
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
//	char date[8];
//	char date1[8];
//	for (int i = 0; i < 8; i++)
//	{
//		cin >> date[i];
//	}
//	for (int i = 0; i < 8; i++)
//	{
//		cin >> date1[i];
//	}
//	Date d;
//	d.div(date);
//	Date d1;
//	d1.div(date1);
//	int ret = d - d1;
//	cout << ret << endl;
//	return 0;
//}


//#include<iostream>
//using namespace std;
//
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
//		if (is_leap(year) && month == 2)
//		{
//			++day[month];
//		}
//		return day[month];
//	}
//
//
//	int count_day()
//	{
//		int month = 1;
//		int c_day = 0;
//		if (_month > 12 || _day > getDay(_year, _month))
//			return -1;
//		while (month != _month)
//		{
//			c_day += getDay(_year, month);
//			++month;
//		}
//		return c_day += _day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//int main()
//{
//	Date d;
//	d.cinn();
//	int ret = d.count_day();
//	cout << ret << endl;
//	return 0;
//}


#include<iostream>
using namespace std;

class Solution {
public:

	Solution()
	{
		i++;
		count += i;
	}

	int Sum_Solution(int n) {
		i = 0;
		count = 0;
		Solution d[n];
		return count;
	}
private:
	static int i;
	static int count;
};

int Solution::i = 0;
int Solution::count = 0;
