#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<functional>
#include<algorithm>
#include<string>
#include<vector>
#include<memory>
#include<thread>
#include<mutex>

template<class T>
class Shared_ptr
{
public:
	Shared_ptr(T* ptr = nullptr)
		:_ptr(ptr)
		, _cptr(new size_t(1))
		, _mutex(new mutex)
	{}

	Shared_ptr(const Shared_ptr<T>& sp)
		:_ptr(sp._ptr)
		, _cptr(sp._cptr)
		, _mutex(sp._mutex)
	{
		//++(*_cptr);
		addRef();
	}

	Shared_ptr<T>& operator=(const Shared_ptr<T>& sp)
	{
		//if (this != &sp)
		if (sp._ptr != _ptr)
		{
			//if (--(*_cptr) == 0)
			if (subRef() == 0)
			{
				delete _cptr;
				delete _ptr;
				delete _mutex;
			}

			_cptr = sp._cptr;
			_ptr = sp._ptr;
			_mutex = sp._mutex;
			//++(*_cptr);
			addRef();
		}
		return *this;
	}

	size_t addRef()
	{
		_mutex->lock();
		++(*_cptr);
		_mutex->unlock();
		return *_cptr;
	}

	size_t subRef()
	{
		_mutex->lock();
		--(*_cptr);
		_mutex->unlock();
		return *_cptr;
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

	~Shared_ptr()
	{
		if (subRef() == 0)
		{
			delete _ptr;
			delete _cptr;
			delete _mutex;
		}
	}
private:
	T* _ptr;
	size_t* _cptr;
	mutex* _mutex;
};

void test()
{
	Shared_ptr<int> sp(new int);
	Shared_ptr<int> sp2(new int);
	Shared_ptr<int> sp3(new int);

	Shared_ptr<int> copy(sp); 
	Shared_ptr<int> copy2(sp2);
	Shared_ptr<int> copy3(sp3);

	sp2 = copy;
	copy = sp3;
}

//void test()
//{
//	//���Կ���
//	//���Ը�ֵ
//	shared_ptr<int> sp(new int);
//	shared_ptr<int> sp2(sp);
//	sp = sp2;
//	*sp = 2;
//}

//template<class T>
//class Unique_ptr
//{
//public:
//	Unique_ptr(T* ptr)
//		:_ptr(ptr)
//	{}
//
//	Unique_ptr(Unique_ptr<T>&) = delete;
//	Unique_ptr& operator = (Unique_ptr<T>&) = delete;
//
//	T& operator*()
//	{
//		return *_ptr;
//	}
//
//	T* operator->()
//	{
//		return _ptr;
//	}
//
//	~Unique_ptr()
//	{
//		if (_ptr)
//		{
//			delete _ptr;
//		}
//	}
//private:
//	T* _ptr;
//};




//int main()
//{
//	return 0;
//}

//#include<iostream>
//using namespace std;
//#include<string>
//#include<vector>
//
//
//int main()
//{
//	string str;
//	vector<char> vc(26);
//	vc[0] = 'A';
//	for (int i = 1; i < 26; i++)
//	{
//		vc[i] = 'A' + i;
//	}
//
//	while (getline(cin, str))
//	{
//		for (int i = 0; i < str.size(); i++)
//		{
//			if (str[i] != ' ')
//			{
//				int idx = str[i] - 'A' - 5;
//				if (idx < 0)
//				{
//					idx = 25 + idx;
//				}
//				str[i] = vc[idx];
//			}
//		}
//		cout << str << endl;
//	}
//	return 0;
//}

//void fun(int a)
//{
//	cout << "fun(int a)" << endl;
//}
//
//struct sum
//{
//	void operator()()
//	{
//		cout << "operator()" << endl;
//	}
//};
//
////�߳̿�
//void test()
//{
//	thread t(fun, 10);
//
//	t.joinable();//�ж��߳��Ƿ����
//
//	t.join();//�ȴ��߳�
//
//	//�º�������
//	sum s;
//	thread t1(s);
//	t1.join();
//
//	//lambda���ʽ
//	thread t2([](){cout << "lambda" << endl; });
//	t2.join();
//}

//void test()
//{
//	//lambda���ʽ��[��׽�б�]{�����б�}��mutable��ѡ��-> ����ֵ����{������}
//	//lambda���ʽ�����ܽ��и�ֵ
//	//������
//	//auto f3(f2);
//	//���Ը�ֵ������ָ��
//	//int *ptr = f3;
//	//lambda���ʽ���ײ��Ƿº�����
//}

//struct A
//{
//	A(int age = 1, int id = 1, string name = "")
//	:_age(age)
//	, _id(id)
//	, _name(name)
//	{}
//
//	int _age;
//	int _id;
//	string _name;
//};
//
//
//
//void test()
//{
//	vector<A> vec = { { 1, 1, "zhangsan" }, { 2, 2, "lisi" } };
//}

//int fun(int a)
//{
//	return a;
//}
//
////��ֵ����&&��ֻ��������ֵ
////��ֵ���ò���������ֵ
//void test()
//{
//	int a = 10;
//	//int&& rra = a;//error
//	int&& rri = 10;
//	int&& rri2 = fun(a);
//}
//
//void test()
//{
//	int a = 10;
//	int b = 10;
//	auto d = 1.9;
//	decltype(a + b) c;
//	cout << typeid(decltype(fun(a))).name() << endl; //������������
//	cout << typeid(decltype(fun)).name() << endl;  //����ָ������
//}

//int main()
//{
//	test();
//	return 0;
//}