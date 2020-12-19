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
//		cout << "��ַΪ��" << _address << endl;
//		cout << "¥��Ϊ��" << _houseNum << endl;
//	}
//
//protected:
//	string _address;             //��ַ
//	int _houseNum;              //¥��
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
//		cout << "���ţ�" << _roomNum << endl;
//		cout << "�����" << _area << "ƽ����" << endl;
//	}
//
//protected:
//	int _roomNum;          //����
//	int _area;               //���
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
//		cout << "�칫�����ƣ�" << _officeName << endl;
//		cout << "�绰���룺" << _telNum << endl;
//	}
//
//protected:
//	string _officeName;		//�칫������
//	string _telNum;			//�绰����
//};
//
//
//
//
//int main() {
//	Building building("��һС��", 3);
//	House house(502, 186);
//	Office office("�ݷ�¥", "1008611");
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
//	MyString str("�ҴӺ����� ");
//	str = str + "����������";
//	cout << str << endl;
//
//	str = str + " ǳ������ˮ �������Ǻ�����";
//	cout << str << endl;

//	return 0;
//}



//#include <iostream>
//#define PIE 3.1415
//
//using namespace std;
//
////Բ���ӿ���
//class Circle
//{
//protected:
//	double radius;
//public:
//	//�����
//	virtual double area(void) = 0;
//	//���
//	virtual double volume(void) = 0;
//};
//
////��
//class Sphere :public Circle
//{
//public:
//	Sphere(double r = 0) { radius = r; }
//	//�����
//	virtual double area(void)
//	{
//		return 4.0 * PIE * radius * radius;
//	}
//	//���
//	virtual double volume(void)
//	{
//		return (4.0 / 3.0) * PIE * radius * radius * radius;
//	}
//};
//
////Բ��
//class Column :public Circle
//{
//private:
//	double height;
//public:
//	Column(double r = 0, double h = 0) { radius = r; height = h; }
//	//�����
//	virtual double area(void)
//	{
//		if (0 == height)
//		{
//			//�����
//			return PIE * radius * radius;
//		}
//		return 2.0* PIE * radius * radius + PIE * 2.0 * radius * height;
//	}
//	//���
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
//		cout << "����������İ뾶��";
//		cin >> rS;
//		if (rS <= 0)
//		{
//			cout << "���������0�����ݣ�\n\n";
//		}
//		else
//			break;
//	}
//
//	while (true)
//	{
//		cout << "������Բ����İ뾶��";
//		cin >> rC;
//		if (rC <= 0)
//		{
//			cout << "���������0�����ݣ�\n\n";
//		}
//		else
//			break;
//	}
//
//	while (true)
//	{
//		cout << "������Բ����ĸߣ�";
//		cin >> h;
//		if (h <= 0)
//		{
//			cout << "���������0�����ݣ�\n\n";
//		}
//		else
//			break;
//	}
//
//	Sphere sphere(rS);
//	Column column(rC, h);
//	cout << "����İ뾶Ϊ��" << rS << endl
//		<< "����ı����Ϊ��" << sphere.area() << endl
//		<< "��������Ϊ��" << sphere.volume() << endl << endl;
//	cout << "Բ����İ뾶Ϊ��" << rC << endl
//		<< "Բ����ı����Ϊ��" << column.area() << endl
//		<< "Բ��������Ϊ��" << column.volume() << endl << endl;
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
	cout << "��������Ҫд��Text�е�����:";
	cin >> str;
	outFile << str;
	cout << "�ɹ���\"" << str << "\"д�뵽�ļ���!\n";
	outFile.close();

	outFile.open("../outText.txt", ios::app);
	cout << "���� ����Ҫ׷�ӵ����֣�";
	cin >> str;
	outFile << str;
	cout << "�ɹ���\"" << str << "\"д�뵽�ļ���!\n";
	outFile.close();

	return 0;
}
 