#include<iostream>
#include<string>
using namespace std;

struct A
{
	int _a;
};

struct B : virtual public A
{
	int _b;
};

struct C : virtual public A
{
	int _c;
};

struct D : public B, public C
{
	int _d;
};

void test()
{
	/*D d;
	d.B::_a = 1;
	d._b = 2;
	d.C::_a = 3;
	d._c = 4;
	d._d = 5;
*/
}

//class Person
//{
//public:
//	string _name; // 姓名
//};
//
//class Student : virtual public Person
//{
//protected:
//	int _num; //学号
//};
//class Teacher : virtual public Person
//{
//protected:
//	int _id; // 职工编号
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // 主修课程
//};
//
//void test()
//{
//	Assistant a;
//	a._name = "lisa";
//}

//class Person
//{
//public:
//	string _name; // 姓名
//};
//
//class Student : public Person
//{
//protected:
//	int _num; //学号
//};
//class Teacher : public Person
//{
//protected:
//	int _id; // 职工编号
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // 主修课程
//};
//
//void test()
//{
//	Assistant a;
//}

//class A
//{
//public:
//	void fun()
//	{
//		++_a;
//	}
//public:
//	static int _a;
//};
//int A::_a = 0;
//
//class B : public A
//{};
//
//class C :public B
//{};
//
//void test()
//{
//	A a;
//	a.fun();
//	B b;
//	C c;
//	cout << a._a << endl;
//	cout << b._a << endl;
//	cout << c._a << endl;
//	cout << &a._a << endl;
//	cout << &b._a << endl;
//	cout << &c._a << endl;
//}

//class Person
//{
//public:
//	Person(string name = "", int age = 20)
//		:_name(name)
//		,_age(age)
//	{
//		//cout << "Person(string, int)" << endl;
//	}
//
//	Person(const Person& per)
//		:_name(per._name)
//		,_age(per._age)
//	{
//		cout << "Person(const Person&)" << endl;
//	}
//
//	Person& operator=(const Person& per)
//	{
//		if (this != &per)
//		{
//			_name = per._name;
//			_age = per._age;
//		}
//		cout << "Person& operator=(const Person&)" << endl;
//		return *this;
//	}
//
//	~Person()
//	{
//		cout << "~Person" << endl;
//	}
//
//protected:
//	string _name;
//	int _age;
//};
//
//class Student : public Person
//{
//public:
//	Student(string name, int age, int id)
//		:_id(id)
//	{}
//
//	Student(const Student& stu)
//		:Person(stu._name, stu._age)
//		,_id(stu._id)
//	{}
//
//	Student& operator=(const Student& stu)
//	{
//		if (this != &stu)
//		{
//			_name = stu._name;
//			_id = stu._id;
//			_age = stu._age;
//		}
//		cout << "Student& operator=(const Student&)" << endl;
//		return *this;
//	}
//
//	~Student()
//	{
//		Person::~Person();
//		cout << "~Student" << endl;
//	}
//
//private:
//	int _id;
//};
//
//void test()
//{
//	Student s("lisa", 20, 1111);
//}

//void test()
//{
//	Student s("lisa", 20, 1111);
//	Student s1(s);
//	s = s1;
//}

//class Person
//{
//public:
//
//	Person(string name = "", int age = 20)
//		:_name(name)
//		,_age(age)
//	{
//		cout << "Person(string, int)" << endl;
//	}
//protected:
//	string _name;
//	int _age;
//};
//
//class Student : public Person
//{
//public:
//	Student(string name, int age, int id)
//		:_id(id)
//	{}
//private:
//	int _id;
//};

//void test()
//{
//	Student s("lisa", 20, 1112);
//}

//class Person
//{
//public:
//	void fun()
//	{
//		cout << "Person" << endl;
//	}
//protected:
//	string _name = "lisa";
//	int _age = 20;
//};
//
//class Student : public Person
//{
//public:
//	void fun()
//	{
//		cout << "Student" << endl;
//	}
//protected:
//	string _id;
//};
//
//void test()
//{
//	Student s;
//	s.fun();
//	s.Person::fun();
//}

//void test()
//{
//	Person p;
//	Student s;
//	//s = p; //错误，父类对象不能直接赋值给子类对象
//
//	//父类指针可以通过强制类型转换赋值给子类指针
//	Person *pc = &p;
//	Student *ps = (Student*)pc;
//
//	string ret = ps->_id;
//
//	//父类引用可以通过强制类型转换赋值给子类引用
//	Person &rc = p;
//	Student &rs = (Student&)rc;
//}

//void test()
//{
//	Person p;
//	Student s;
//	p = s;
//
//	Person &rs = s;
//	Person *ps = &s;
//
//
//}

//class Person
//{
//public:
//	int age = 20;
//
//private:
//	string _name = "lisa";
//};
//
//class Student : private Person
//{
//public:
//	void Print()
//	{
//		age = 18;
//		cout << age << endl;
//	}
//private:
//	string _id = "1111";
//};
//
//void test()
//{
//	Student s;
//	s.Print();
//}

//void test()
//{
//	Student s;
//	s.age = 20;
//}

//void test()
//{
//	Student s;
//	s.age = 18
//}

//void test()
//{
//	Student s;
//	s.Print();
//	s.age = 10;
//}

int main()
{
	test();
	return 0;
}