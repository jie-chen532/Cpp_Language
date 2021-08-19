#include<iostream>
using namespace std;
#include<mutex>

struct Date
{
	int _year = 2021;
	int _month = 8;
	int _day = 19;

	Date()
	{
		cout << "Date()" << endl;
	}

	~Date()
	{
		cout << "~Date()" << endl;
	}
};

template<class T>
struct Delete
{
	void operator()(T* ptr)
	{
		delete ptr;
	}
		
};

template <class T>
struct Free
{
	void operator()(T* ptr)
	{
		free(ptr);
	}
		
};

template<class T>
struct DeleteArr
{
	void operator()(T* ptr)
	{
		delete[] ptr;
	}
		
};



//template<class T>
//class SharedPtr
//{
//public:
//	SharedPtr(T* ptr)
//		:_ptr(ptr)
//		,_count(new int(1))
//		,_mutex(new mutex)
//	{}
//
//	SharedPtr(const SharedPtr<T> &sp)
//		:_ptr(sp._ptr)
//		,_count(sp._count)
//		,_mutex(sp._mutex)
//	{
//		//�������ۼ�
//		AddCount();
//	}
//
//	SharedPtr& operator=(const SharedPtr<T> &sp)
//	{
//		//�жϹ�����Ƿ���ͬһ����Դ
//		if (_ptr != sp._ptr)
//		{
//			//����-1���ж�֮ǰ�������Դ�Ƿ���Ҫ�ͷ�
//			if (SubCount() == 0)
//			{
//				delete _ptr;
//				delete _count;
//				delete _mutex;
//			}
//			
//			_ptr = sp._ptr;
//			_count = sp._count;
//			_mutex = sp._mutex;
//
//				//�������ۼ�
//			AddCount();
//		}
//		return *this;
//	}
//
//	//�̰߳�ȫ���ۼ���
//	int AddCount()
//	{
//		//����
//		_mutex->lock();
//		++(*_count);
//		_mutex->unlock();
//		return *_count;
//	}
//
//	int SubCount()
//	{
//		_mutex->lock();
//		--(*_count);
//		_mutex->unlock();
//		return *_count;
//	}
//
//	T* operator->()
//	{
//		return _ptr;
//	}
//	
//	T& operator*()
//	{
//		return *_ptr;
//	}
//
//	~SharedPtr()
//	{
//		if (SubCount() == 0)
//		{
//			delete _ptr;
//			delete _count;
//			delete _mutex;
//			_ptr = nullptr;
//			_count = nullptr;
//			_mutex = nullptr;
//		}
//	}
//
//	int usecount()
//	{
//		return *_count;
//	}
//
//private:
//	T* _ptr;
//	int* _count;//��ÿ����Դ����һ��������
//	mutex* _mutex; //ÿһ����Դ��һ����������
//};

//struct ListNode
//{
//	int _data; 
//    weak_ptr<ListNode> _prev;
//	weak_ptr<ListNode> _next;
//	~ListNode() { cout << "~ListNode()" << endl; }
//};
//
//void test()
//{
//	//weak_ptr����ʹ��
//	weak_ptr<ListNode> node1(new ListNode);
//
//	//weak_ptr��ȷʹ��
//	shared_ptr<ListNode> node2(new ListNode);
//	weak_ptr<ListNode> node3(node2);
//
//
//	//shared_ptr<ListNode> node1(new ListNode);
//	//shared_ptr<ListNode> node2(new ListNode);
//
//	//node1->_next = node2;
//	//node2->_prev = node1;
//} 

//void test()
//{
//	SharedPtr<Date> sp(new Date);
//	cout << sp.usecount() << endl; //1
//	SharedPtr<Date> sp1(sp);
//	cout << sp1.usecount() <<endl; //2
//	cout << sp.usecount() << endl;  //2
//	SharedPtr<Date> sp2(new Date);
//	cout << sp2.usecount() <<endl; //1
//	sp2 = sp1;
//	cout << sp2.usecount() << endl; //3
//	cout << sp1.usecount() << endl; //3
//}

//void test()
//{
//	shared_ptr<Date> sp(new Date);
//	cout << sp.use_count() << endl; //1
//	shared_ptr<Date> sp1(sp);
//	cout << sp1.use_count() <<endl; //2
//	cout << sp.use_count() << endl;  //2
//	shared_ptr<Date> sp2(new Date);
//	cout << sp2.use_count() <<endl; //1
//	sp2 = sp1;
//	cout << sp2.use_count() << endl; //3
//	cout << sp1.use_count() << endl; //3
//}

//template<class T>
//class UniquePtr
//{
//public:
//
//	UniquePtr(T* ptr)
//		:_ptr(ptr)
//	{}
//
//	// C++11�������ķ�ʽ��delete
//	UniquePtr(const UniquePtr<T> &) = delete;
//
//	UniquePtr& operator=(const UniquePtr<T>&) = delete;
//
//	T* operator->()
//	{
//		return _ptr;
//	}
//
//	T& operator*()
//	{
//		return *_ptr;
//	}
//
//	~UniquePtr()
//	{
//		if (_ptr)
//		{
//			delete _ptr;
//			_ptr = nullptr;
//		}
//	}
//
//private:
//
//	//C++98�������ķ�ʽ��ֻ������ʵ��+������˽��
//	//UniquePtr(UniquePtr<T> const &);
//	//UniquePtr& operator=(UniquePtr<T> const &);
//
//	T* _ptr;
//};
//
//void test()
//{
//	UniquePtr<Date> up(new Date);
//	UniquePtr<Date> up1(up);
//	up1 = up;
//} 

//void test()
//{
//	unique_ptr<Date> up(new Date);
//	unique_ptr<Date> up1(up);
//	up1 = up;
//} 

//template<class T>
//class AutoPtr
//{
//public:
//	AutoPtr(T* ptr)
//		:_ptr(ptr)
//	{}
//
//	//����������Ȩת��
//	AutoPtr(AutoPtr<T> &sp)
//		:_ptr(sp._ptr)
//	{
//		sp._ptr = nullptr;
//	}
//
//	//��ֵ������Ȩת��
//	AutoPtr& operator=(AutoPtr<T> &sp)
//	{
//		if (this != &sp)
//		{
//			if (_ptr)
//				delete _ptr;
//			_ptr = sp._ptr;
//			sp._ptr = nullptr;
//		}
//		return *this;
//	}
//
//	~AutoPtr()
//	{
//		if (_ptr)
//		{
//			delete _ptr;
//			_ptr = nullptr;
//		}
//	}
//
//	T* operator->()
//	{
//		return _ptr;
//	}
//
//	T& operator*()
//	{
//		return *_ptr;
//	}
//
//private:
//	T* _ptr;
//};
//
//void test()
//{
//	AutoPtr<Date> sp(new Date);
//	AutoPtr<Date> sp1(sp);
//	sp->_year = 2000;
//}

//void test()
//{
//	auto_ptr<Date> sp(new Date);
//	auto_ptr<Date> sp1(sp);
//	sp->_year = 2022;
//}

//
//template <class T>
//class SmartPtr
//{
//public:
//	SmartPtr(T* ptr)
//		:_ptr(ptr)
//	{}
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
//    ~SmartPtr()
//	{
//		if (_ptr)
//		{
//			delete _ptr;
//			_ptr = nullptr;
//		}
//	}
//
//private:
//	T* _ptr;
//};
//
//void test()
//{
//	SmartPtr<Date> sp(new Date);
//	//*����
//	cout << "-------(*)--------" << endl;;
//	cout << "(*sp)._year:" <<(*sp)._year << endl;
//	cout << "(*sp)._month:" << (*sp)._month << endl;
//	cout << "(*sp)._day:" << (*sp)._day << endl;
//
//	//->����
//	cout << "-------(->)--------" << endl;
//	cout << "sp->_year:" << sp->_year << endl;
//	cout << "sp->_month:" << sp->_month << endl;	
//	cout << "sp->_day:" << sp->_day << endl;
//}

//void test()
//{
//	SmartPtr<int> sp(new int);
//}

int main()
{
	//test();
	return 0;
}