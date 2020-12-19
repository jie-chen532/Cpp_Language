#define _CRT_SECURE_NO_WARNINGS 1

//
//#include<iostream>
//#include<string>
//
//using namespace std;
//
//
//class Building {
//public:
//	Building(const string ad = "", int num = 0)
//	{
//		_address = ad;
//		_houseNum = num;
//	}
//
//	void printInfo()
//	{
//		cout << "地址为：" << _address << endl;
//		cout << "楼号为：" << _houseNum << endl;
//	}
//
//protected:
//	string _address;             //地址
//	int _houseNum;              //楼号
//};
//
//
//class House : public Building {
//public:
//	House(int num = 0, int ar = 100) {
//		_roomNum = num;
//		_area = ar;
//	}
//
//	void printInfo() {
//		cout << "房号：" << _roomNum << endl;
//		cout << "面积：" << _area << "平方米" << endl;
//	}
//
//protected:
//	int _roomNum;          //房号
//	int _area;               //面积
//};
//
//class Office :public Building {
//public:
//	Office(const string name = "1", string num = "110") {
//		_officeName = name;
//		_telNum = num;
//	}
//
//	void printInfo() {
//		cout << "办公室名称：" << _officeName << endl;
//		cout << "电话号码：" << _telNum << endl;
//	}
//
//protected:
//	string _officeName;		//办公室名称
//	string _telNum;			//电话号码
//};
//
//
//
//
//int main() {
//	Building building("八一小区", 3);
//	House house(502, 186);
//	Office office("逸夫楼", "1008611");
//
//	building.printInfo();
//	house.printInfo();
//	office.printInfo();
//
//	return 0;
//}



//#include <iostream>
//#include <string>
//#define N 32
//
//using namespace std;
//
//class MyString
//{
//	char *d;
//	int len;
//public:
//	MyString() { d = new char[N]; len = 0; }
//	MyString(const char* a);
//	MyString& operator + (MyString & a);
//	MyString& operator + (char * a);
//	MyString& operator + (const char *a);
//
//	MyString& operator = (MyString & a);
//	MyString& operator = (char * a);
//	MyString& operator = (const char *a);
//
//	int strLen(void) { return len; }
//	char * D(void) { return d; }
//	friend ostream & operator << (ostream &os, MyString &a);
//};
//
//MyString::MyString(const char *a)
//{
//	d = new char[strlen(a) + 1];
//	strcpy(d, a);
//	len = strlen(a);
//}
//
//MyString& MyString::operator + (MyString & a)
//{
//	if (len + a.strLen() > (N - 1))
//	{
//		char *tmp = new char[len + a.strLen() + 1];
//		strcpy(tmp, d);
//		strcat(tmp, a.D());
//		d = tmp;
//	}
//	else
//	{
//		strcat(d, a.D());
//	}
//	len += a.strLen();
//	return *this;
//}
//
//MyString& MyString::operator + (char * a)
//{
//	if (len + strlen(a) > (N - 1))
//	{
//		char *tmp = new char[len + strlen(a) + 1];
//		strcpy(tmp, d);
//		strcat(tmp, a);
//		d = tmp;
//	}
//	else
//	{
//		strcat(d, a);
//	}
//	len += strlen(a);
//	return *this;
//}
//
//MyString& MyString::operator + (const char *a)
//{
//	if (len + strlen(a) > (N - 1))
//	{
//		char *tmp = new char[len + strlen(a) + 1];
//		strcpy(tmp, d);
//		strcat(tmp, a);
//		d = tmp;
//	}
//	else
//	{
//		strcat(d, a);
//	}
//	len += strlen(a);
//	return *this;
//}
//
//MyString& MyString::operator = (MyString & a)
//{
//	if (&a != this && len > 0 && len < a.strLen())
//	{
//		delete[] d;
//		d = new char[a.strLen() + 1];
//	}
//	strcpy(d, a.D());
//	len = a.strLen();
//	return *this;
//}
//
//MyString& MyString::operator = (char * a)
//{
//    	if (d != NULL && (len < strlen(a)))
//	{
//		delete[] d;
//		d = new char[strlen(a) + 1];
//	}
//	strcpy(d, a);
//	len = strlen(a);
//	return *this;
//}
//
//
//
//MyString& MyString::operator = (const char *a)
//{
//	if (d != NULL && (len < strlen(a)))
//	{
//		delete[] d;
//		d = new char[strlen(a) + 1];
//	}
//	strcpy(d, a);
//	len = strlen(a);
//	return *this;
//}
//
//ostream & operator << (ostream &os, MyString &a)
//{
//	os << a.D();
//	return os;
//}
//
//
//
//int main(void)
//{
//	MyString str("我从海边来 ");
//	str = str + "深蓝的是天";
//	cout << str << endl;
//
//	str = str + " 浅蓝的是水 灰蓝的是海岸线";
//	cout << str << endl;

//	return 0;
//}



//#include <iostream>
//#define PIE 3.1415
//
//using namespace std;
//
////圆，接口类
//class Circle
//{
//protected:
//	double radius;
//public:
//	//表面积
//	virtual double area(void) = 0;
//	//体积
//	virtual double volume(void) = 0;
//};
//
////球
//class Sphere :public Circle
//{
//public:
//	Sphere(double r = 0) { radius = r; }
//	//表面积
//	virtual double area(void)
//	{
//		return 4.0 * PIE * radius * radius;
//	}
//	//体积
//	virtual double volume(void)
//	{
//		return (4.0 / 3.0) * PIE * radius * radius * radius;
//	}
//};
//
////圆柱
//class Column :public Circle
//{
//private:
//	double height;
//public:
//	Column(double r = 0, double h = 0) { radius = r; height = h; }
//	//表面积
//	virtual double area(void)
//	{
//		if (0 == height)
//		{
//			//底面积
//			return PIE * radius * radius;
//		}
//		return 2.0* PIE * radius * radius + PIE * 2.0 * radius * height;
//	}
//	//体积
//	virtual double volume(void)
//	{
//		if (0 == height)
//		{
//			return 0;
//		}
//		return PIE * radius * radius * height;
//	}
//};
//
//
//int main(void)
//{
//	double rS, rC, h;
//	while (true)
//	{
//		cout << "请输入球体的半径：";
//		cin >> rS;
//		if (rS <= 0)
//		{
//			cout << "请输入大于0的数据！\n\n";
//		}
//		else
//			break;
//	}
//
//	while (true)
//	{
//		cout << "请输入圆柱体的半径：";
//		cin >> rC;
//		if (rC <= 0)
//		{
//			cout << "请输入大于0的数据！\n\n";
//		}
//		else
//			break;
//	}
//
//	while (true)
//	{
//		cout << "请输入圆柱体的高：";
//		cin >> h;
//		if (h <= 0)
//		{
//			cout << "请输入大于0的数据！\n\n";
//		}
//		else
//			break;
//	}
//
//	Sphere sphere(rS);
//	Column column(rC, h);
//	cout << "球体的半径为：" << rS << endl
//		<< "球体的表面积为：" << sphere.area() << endl
//		<< "球体的体积为：" << sphere.volume() << endl << endl;
//	cout << "圆柱体的半径为：" << rC << endl
//		<< "圆柱体的表面积为：" << column.area() << endl
//		<< "圆柱体的体积为：" << column.volume() << endl << endl;
//
//	system("pause");
//	return 0;
//}




#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	string str;
	ofstream outFile("../outText.txt");
	ofstream filego("./here", ios::binary);
	cout << "请输入想要写入Text中的文字:";
	cin >> str;
	outFile << str;
	cout << "成功将\"" << str << "\"写入到文件中!\n";
	outFile.close();

	outFile.open("../outText.txt", ios::app);
	cout << "请输 入想要追加的文字：";
	cin >> str;
	outFile << str;
	cout << "成功将\"" << str << "\"写入到文件中!\n";
	outFile.close();

	return 0;
}
 