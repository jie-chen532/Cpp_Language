#include<iostream>
using namespace std;


//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Func1()" << endl;
//	}
//private:
//	int _b = 1;
//};
//
//void test()
//{
//	Base b;
//	cout << sizeof(Base) << endl;
//}

//class A
//{};
//
//class B : public A
//{};
//
////�����ࣺ����ʵ����
//class Car
//{
//public:
//	//���麯��
//	virtual void carPrint() = 0;
//};
//
//class Benz : public Car
//{
//public:
//	virtual void carPrint()
//	{
//		cout << "Benz" << endl;
//	}
//};
//
//class BMW : public Car
//{
//public:
//	virtual void carPrint()
//	{
//		cout << "BMW" << endl;
//	}
//};
//
//void fun(Car &car)
//{
//	car.carPrint();
//}
//
//void test()
//{
//	Benz benz;
//	fun(benz);
//
//	BMW bmw;
//	fun(bmw);
//}

//class Person
//{
//public:
//
//	virtual void buyTicket()
//	{
//		cout << "ȫƱ" << endl;
//	}
//};
//
//class Children : public Person
//{
//public:
//
//	virtual void buyTicket() 
//	{
//		cout << "���" << endl;
//	}
//};


//class Person
//{
//public:
//	//�麯��
//	virtual A* fun()
//	{
//		cout << "A*" << endl;
//		return new A;
//	}
//
//	//virtual ~Person()
//	//{
//	//	cout << "~Person" << endl;
//	//}
//};
//
////�̳�
//class Child : public Person
//{
//public:
//
//	/*virtual */B* fun()
//	{
//		cout << "B*" << endl;
//		return new B;
//	}
//
//	//virtual ~Child()
//	//{
//	//	cout << "~Child" << endl;
//	//}
//};

//void fun(Person &p)
//{
//	p.buyTicket();
//}
//
//void test()
//{
//	Person p;
//	fun(p);
//
//	Children _ch;
//	fun(_ch);
//}

//void test()
//{
//	Person *p = new Person;
//	delete p;
//
//	Person *child = new Child;
//	delete child;
//}


//class Person
//{
//public:
//	//�麯��
//	virtual void BuyTicket()
//	{
//		cout << "ȫƱ" << endl;
//	}
//};
//
////�̳�
//class Child : public Person
//{
//public:
//	//��д�麯��
//	virtual void BuyTicket()
//	{
//		cout << "���" << endl;
//	}
//};
//
//void fun(Person &p)
//{
//	//�������õ����麯��
//	/*p.BuyTicket();*/
//	p.fun();
//}
//
//void test()
//{
//	Person p;
//	fun(p);
//
//	Child child;
//	fun(child);
//}


int main()
{
	test();
	return 0;
}