#include<iostream>
#include<mutex>
using namespace std;

//���һ���ֻ࣬���ڶ��ϴ���
class HeapOnly
{
public:

	//�ڶ��ϴ�������
	static HeapOnly* HeapCreate()
	{
		return new HeapOnly;
	}

private:
	//���캯��˽��
	HeapOnly()
	{}

	//������
	HeapOnly(const HeapOnly&) = delete;
};

//���һ���ֻ࣬����ջ�ϴ�������
//class StackOnly
//{
//public:
//	static StackOnly CreateObj()
//	{
//		return StackOnly();
//	}
//private:
//	//���캯��˽��
//	StackOnly()
//	{}
//};

class StackOnly
{
public:
	StackOnly()
	{}
private:
	void* operator new(size_t size) = delete;
	void operator delete(void *p) = delete;
};

//class SingleIeton
//{
//public:
//	
//	//���еĻ�ȡ����
//	static SingleIeton* getObj()
//	{
//		return &sigle;
//	}
//
//private:
//
//	//���캯��˽�л�
//	SingleIeton()
//	{}
//
//	//������
//	SingleIeton(const SingleIeton&) = delete;
//	SingleIeton& operator=(const SingleIeton&) = delete;
//
//	static SingleIeton sigle;
//};
//SingleIeton SingleIeton::sigle;


class SingleIeton
{
public:

	static SingleIeton* getObj()
	{
		if (single == nullptr)
		{
			_mutex.lock();
			if (single == nullptr)
			{
				single = new SingleIeton;
			}
			_mutex.unlock();
		}
		return single;
	}

private:
	//���캯��˽�л�
	SingleIeton()
	{}

	//������
	SingleIeton(const SingleIeton&) = delete;
	SingleIeton& operator=(const SingleIeton&) = delete;

	static SingleIeton* single;
	static mutex _mutex;
};
SingleIeton* SingleIeton::single = nullptr;
mutex SingleIeton::_mutex;

//class A
//{
//public:
//	A() {}
//};
//
//class B : public A
//{
//public:
//	B() {}
//};

class A
{
public:
	virtual void fun() {}
};

class B : public A
{
};

void test()
{
	A* pb = new A;
	B* pb2 = static_cast<B*> (pb);
	B* pb3 = dynamic_cast<B*>(pb);
	cout << pb2 << endl;
	cout << pb3 << endl;

	pb = new B;
	pb2 = static_cast<B*> (pb);
	pb3 = dynamic_cast<B*>(pb);
	cout << pb2 << endl;
	cout << pb3 << endl;
}

//void test()
//{
//	volatile const int a = 10;
//	int *p = const_cast<int*>(&a);
//	*p = 20;
//	cout << "a: " << a << endl;
//	cout << "*p: " << *p << endl;
//}

//void test()
//{
//	const char t = 'a';
//	int *p = const_cast<int*>(&t);
//
//
//	//const int a = 10;
//	//int *p = const_cast<int*>(&a);
//
//	//int a = 10;
//	//int *b = reinterpret_cast<int*>(a);
//
//	//int a = 10;
//	//int *b = static_cast<int*>(a);
//}

//void test()
//{
//	//����ָ�뵽����ָ���ת��,����ȫ
//	A* a = new A;
//	B* b = static_cast<B*> (a);
//}

//void test()
//{
//	float a = 2.3;
//	int b = static_cast<int>(a);
//	cout << b << endl;
//}

//class A
//{
//public:
//	A() {}
//
//private:
//	int _a;
//	A _a;
//};
//
//void test()
//{
//	cout << "sizeof(A):" << sizeof(A) << endl;
//}

//class NonIn final
//{
//public:
//	NonIn()
//	{
//		cout << "NonIn" << endl;
//	}
//};
//
//class A : public NonIn
//{
//public:
//	A() {}
//private:
//	int _a;
//};
//
//void test()
//{
//	A a;
//}

//class A : public NonIn
//{
//public:
//	A() {}
//private:
//	int _a;
//};
//
//void test()
//{
//	A a;
//}

//void test()
//{
//	StackOnly *so = new StackOnly;
//}

//void test()
//{
//	HeapOnly* hp = HeapOnly::HeapCreate();
//	cout << hp << endl;
//}

int main()
{
	test();
	return 0;
}