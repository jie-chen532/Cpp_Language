#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;


//��������
//һ��������ֻ��һ��������������δ��ʽ���壬ϵͳ���Զ�����Ĭ�ϵ�����������
//����ʾ�������������������Զ�����Ĭ�ϵ���������
typedef int DataType;
class SeqList
{
public:
	SeqList(int capacity = 10)
	{
		_pData = (DataType*)malloc(capacity * sizeof(DataType));

		_size = 0;
		_capacity = capacity;	}

	//�������ٵ�ʱ�򣬱������Զ����������������Դ����
	//�������Զ���������������Ϊ�գ�����malloc��������Դ��������free�ͷŵ�
	~SeqList()
	{
		if (_pData)
		{
			free(_pData); // �ͷŶ��ϵĿռ�
			_pData = NULL; // ��ָ����Ϊ��
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
//	//Ұָ��  �Ƿ�����
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

	//������������
	//�������ʾ���忽�����죬���������Զ����ɿ�������
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
	//���������Զ������Զ����Ա����������������Զ����Ա����Դ����
	SeqList sq;
};

void test()
{
	Date d2;
	//���ÿ������죬����copy�������ݺ�d2��ȫ��ͬ
	Date copy(d2);
}



//class A
//{
//public:
//	int a;
//};
//
////���캯��
////�����������
////�޲Σ�Ĭ�Ϲ���
////�������Զ����ɵĹ��캯��ҲΪ�޲εĹ��캯������Ҳ��Ĭ�Ϲ���
////û����ʽ�����κ�һ�����캯�������������Զ������޲ι��죬���򲻻��Զ�����
////ֻ����һ��Ĭ�Ϲ��캯��
//class Date
//{
//public:
//	//�޲ι���
//	//Date()
//	//{
//
//	//}
//
//	//ȫȱʡ
//	//Ĭ�Ϲ���
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
//	//�κ�һ�����캯��(�����������Զ����ɵ�)�����Զ������Զ����Ա��Ĭ�Ϲ���
//	//�Զ������ͳ�Ա
//	A a;
//};
//void test()
//{
//	//�������ڴ�������ʱ���Զ����ù��캯��
//	//��ɶ������ݵĳ�ʼ���������Ǵ�������
//	Date d1(2021,2,3);
//	d1.Display();
//
//	//�޲ι���
//	Date d2;
//	d2.Display();
//
//	//���ô��εĹ���
//	Date d3(2010,1,1,12);
//
//
//	//����һ���޲ι��죬����һ����������
//	//����ֵ��Date
//	//�������޲�
//	//������d4
//	Date d4();
//}


//class A
//{
//public:
//	void PrintA()  //this = NULL
//	{
//		cout << _a << endl;
//		//this->_a  NULL���ܽ��н�����
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
////this��ջ��
////this��Ϊ�գ�Ҳ����Ϊ��
////this��Ҫ�������õ�ʱ����Ϊ�գ������������Ϊ��
//void test()
//{
//	A* p = NULL;
//	p->PrintA();
//	//p->Show();//��ʱ����p�Ľ����ã����Ǹ�Show��this��NULLֵ
//}


//this
//ÿһ���Ǿ�̬��Ա�����У�����һ��this����
//ֻ�����ڳ�Ա������
//��Ϊ�����ĵ�һ���β�
//thisָ��ǰ���ô˺����Ķ���
//this���ͣ�������* const this
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
//	int _year; // ��
//	int _month; // ��
//	int _day; // ��
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

////���С��
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
//		cout << "С��" << endl;
//	}
//	else
//		cout << "���" << endl;
//}

//���С��
//void test()
//{
//	int a = 1;
//	//0x00 00 00 01
//	//С�ˣ�0x10 00 00 00
//	//��ˣ�0x00 00 00 01
//	char* p = (char*)(&a);
//	if (*p)
//	{
//		cout << "С��" << endl;
//	}
//	else
//		cout << "���" << endl;
//}

//����Ĭ�϶�����
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
//	//����ƫ��λ��
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