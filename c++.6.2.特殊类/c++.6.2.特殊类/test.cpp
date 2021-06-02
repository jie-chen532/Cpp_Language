#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
using namespace std;
#include<mutex>

//创建类只能在堆上
//禁止构造函数的调用：私有
class HeapObj
{
public:
	//调用构造函数创建对象
	static HeapObj* getObj()
	{
		return new HeapObj;
	}

	//防拷贝
	HeapObj(const HeapObj& H) = delete;

	//防赋值
	HeapObj& operator=(const HeapObj& H) = delete;

private:
	HeapObj()//构造函数私有
	{}
};

//不能在堆上创建对象
//class StackObj
//{
//public:
//	static StackObj getStackObj()
//	{
//		return StackObj();
//	}
//private:
//	//构造函数私有
//	StackObj()
//	{}
//};
//
//StackObj so = StackObj::getStackObj();//全局变量，在数据段，不能禁止这种情况

class StackObj
{
public:
	//禁止调用operator new
	void* operator new(size_t n) = delete;
};

//不能继承的类
//把类定义为final类
//class A final
//{};

//把基类定义为私有
//class A
//{
//private:
//	A()
//	{}
//};

//单例模式
//1.饿汉模式：在使用之前已经被创建好
//a.对象只能被创建一次
//class Singleton
//{
//public:
//	Singleton* getSingleton()
//	{
//		//获取已存取对象的地址
//		&s;
//	}
//	//全局变量、static变量在程序启动之前已经创建好了
//private:
//	//构造函数私有
//	Singleton()
//	{}
//	static Singleton s;//是放在静态数据区,相当于这个类中的全局变量
//
//	//防拷贝
//	Singleton(const Singleton& s) = delete;
//};
//
//Singleton Singleton::s;


//2.懒汉模式：第一次使用再去创建
class Singleton
{
public:
	static Singleton* getSingleton()
	{
		//第一次使用时创建
		//线程安全
		//第一层检查，提高效率
		if (_sin == nullptr)
		{
			//线程安全
			m.lock();
			if (_sin == nullptr)
			{
				_sin = new Singleton;
			}
			m.unlock();
		}
		return _sin;
	}
private:
	Singleton()
	{}

	//防拷贝
	Singleton(const Singleton&) = delete;

	static Singleton *_sin;//初始化会在构造函数的初始化列表初始化

	static mutex m;
};

Singleton* Singleton::_sin = nullptr;
mutex Singleton::m;

void test()
{
	int a = 10;
	double f = 2.3;

	int *pa = &a;

	a = f; //隐式类型转换

	//c++类型转换：
	//1.static_cast:支持所有的隐式类型转换，不支持其他强转
	//特殊：也支持父类指针、引用到子类指针、引用的转换，但是没有安全检查

	a = static_cast<int>(f);

	//2.reinterpret_cast:支持强制类型转换
	a = reinterpret_cast<int>(pa);

	//3.const_cast:去除变量的const属性
	const int c = 20;
	
	//int *pc = &c;//error
	int *pc = const_cast<int*>(&c);

	//4.dynamic_cast:只用于多态场景下的用于引用、指针向子类引用、指针转换，会去检查转换是否安全
	//只有安全才会转换成功，不安全，返回nullptr
}

//class A
//{
//private:
//	int a;
//	static int b;
//};
//
//void test()
//{
//	cout << sizeof(A) << endl;
//}

//void test()
//{
//	HeapObj *ptr = HeapObj::getObj();
//	//HeapObj copy(*ptr); //error
//	HeapObj *ptr1 = HeapObj::getObj();
//	//*ptr = *ptr1; //error
//	delete ptr;
//	delete ptr1;
//}

int main()
{
	test();
	return 0;
}