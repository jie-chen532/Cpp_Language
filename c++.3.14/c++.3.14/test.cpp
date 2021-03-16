#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;


struct ListNode
{
public:
	void* operator new(size_t n)
	{
		cout << "operator new" << endl;
		//采用内存池的方式
		allocator<ListNode> alloc;
		return alloc.allocate(1);
	}

	void operator delete(void* ptr)
	{
		cout << "operator delete" << endl;
		allocator<ListNode> alloc;
		alloc.deallocate((ListNode*)ptr, 1);
	}

	ListNode(int data = 1)
		:_data(data)
	{
		cout << "ListNode(int)" << endl;
	}

	~ListNode()
	{
		cout << "ListNode" << endl;
	}

private:
	int _data = 0;
	ListNode* _next = nullptr;
};

void test()
{

}

//void test()
//{
//	//new: 调用operator new ---> malloc，再调用构造函数
//	A* ptr = new A;
//	//delete: 先调用析构函数，进行资源清理，再调用operator delete ---> free
//	delete ptr;
//
//	//new[]: 调用operator new[]---> operator new ---> malloc，再调用N次构造函数
//	A* ptr1 = new A[3];
//	//delete[]: 调用N次析构，进行资源清理，再调用operator delete[]--->operator delete--->free
//	delete[] ptr1;
//
//}

//void test()
//{
//	//new: new ---> operator new ----> malloc
//	int* ptr = new int;
//	//delete: delete---> operator delete---> free
//	delete ptr;
//
//	//new[]: new[] ---> operator new[] ---> operator new ---> malloc
//	int* ptr1 = new int[10];
//	//delete[]: delete[] ---> operator delete[] ---> operator delete --->free
//	delete[] ptr1;
//}

//void test()
//{
//	int* m_ptr = (int*)malloc(0x7fffffff);
//	free(m_ptr);
//}

//void test()
//{
//	int* o_ptr = (int*)operator new(0x7fffffff);
//	operator delete(o_ptr);
//}

//void test()
//{
//	//operator new
//	//void* operator new(size_t n)
//	int* o_ptr = (int*)operator new(sizeof(int));
//
//	//malloc
//	int* m_ptr = (int*)malloc(sizeof(int));
//
//	//new
//	int* n_ptr = new int;
//
//}

//class A
//{
//public:
//	A(int a = 10, int b = 10)
//		:_a(a)
//		, _b(b)
//	{
//		cout << "A()" << endl;
//	}
//
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int _a;
//	int _b;
//};
//
//void test()
//{
//	A* ptr = new A[3];
//	delete[] ptr;
//}

//class A
//{
//public:
//	A(int a, int b, int c = 10)
//		:_a(a)
//		, _b(b)
//		, _c(c)
//	{}
//private:
//	int _a;
//	int _b;
//	int _c;
//};
//
//void test()
//{
//	A* ptr = new A(20 ,10);
//	delete ptr;
//}

//class A
//{
//public:
//	A()
//	{
//		cout << "A()" << endl;
//	}
//private:
//	int _a;
//	int _b;
//};
//
//void test()
//{
//	//要调用默认构造
//	A* ptr = new A;
//	delete ptr;
//}

//class A
//{
//public:
//	A(int a = 10)
//	:_a(a)
//	{
//		cout << "A()" << endl;
//	}
//
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int _a;
//};

//void test()
//{
//	//A* ma = (A*)malloc(sizeof(A));
//	//free(ma);
//	A* ptr = new A;
//	delete ptr;
//}

//void test()
//{ 
//	//类型指针 指针变量 = new 类型
//	//开辟int类型空间
//	int* ptr = new int;
//	delete ptr;
//	//类型指针 指针变量 = new 类型（初始值）
//	//开辟int类型空间，并初始化
//	int* ptr2 = new int(10);
//	delete ptr2;
//	//类型指针 指针变量 = new 类型[元素个数]
//	//开辟int类型数组,元素个数为10个
//	int* ptr3 = new int[10];
//	delete[] ptr3;
//}

int main()
{
	test();
	return 0;
}