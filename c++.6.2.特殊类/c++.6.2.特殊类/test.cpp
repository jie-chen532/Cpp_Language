#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
using namespace std;
#include<mutex>

//������ֻ���ڶ���
//��ֹ���캯���ĵ��ã�˽��
class HeapObj
{
public:
	//���ù��캯����������
	static HeapObj* getObj()
	{
		return new HeapObj;
	}

	//������
	HeapObj(const HeapObj& H) = delete;

	//����ֵ
	HeapObj& operator=(const HeapObj& H) = delete;

private:
	HeapObj()//���캯��˽��
	{}
};

//�����ڶ��ϴ�������
//class StackObj
//{
//public:
//	static StackObj getStackObj()
//	{
//		return StackObj();
//	}
//private:
//	//���캯��˽��
//	StackObj()
//	{}
//};
//
//StackObj so = StackObj::getStackObj();//ȫ�ֱ����������ݶΣ����ܽ�ֹ�������

class StackObj
{
public:
	//��ֹ����operator new
	void* operator new(size_t n) = delete;
};

//���ܼ̳е���
//���ඨ��Ϊfinal��
//class A final
//{};

//�ѻ��ඨ��Ϊ˽��
//class A
//{
//private:
//	A()
//	{}
//};

//����ģʽ
//1.����ģʽ����ʹ��֮ǰ�Ѿ���������
//a.����ֻ�ܱ�����һ��
//class Singleton
//{
//public:
//	Singleton* getSingleton()
//	{
//		//��ȡ�Ѵ�ȡ����ĵ�ַ
//		&s;
//	}
//	//ȫ�ֱ�����static�����ڳ�������֮ǰ�Ѿ���������
//private:
//	//���캯��˽��
//	Singleton()
//	{}
//	static Singleton s;//�Ƿ��ھ�̬������,�൱��������е�ȫ�ֱ���
//
//	//������
//	Singleton(const Singleton& s) = delete;
//};
//
//Singleton Singleton::s;


//2.����ģʽ����һ��ʹ����ȥ����
class Singleton
{
public:
	static Singleton* getSingleton()
	{
		//��һ��ʹ��ʱ����
		//�̰߳�ȫ
		//��һ���飬���Ч��
		if (_sin == nullptr)
		{
			//�̰߳�ȫ
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

	//������
	Singleton(const Singleton&) = delete;

	static Singleton *_sin;//��ʼ�����ڹ��캯���ĳ�ʼ���б��ʼ��

	static mutex m;
};

Singleton* Singleton::_sin = nullptr;
mutex Singleton::m;

void test()
{
	int a = 10;
	double f = 2.3;

	int *pa = &a;

	a = f; //��ʽ����ת��

	//c++����ת����
	//1.static_cast:֧�����е���ʽ����ת������֧������ǿת
	//���⣺Ҳ֧�ָ���ָ�롢���õ�����ָ�롢���õ�ת��������û�а�ȫ���

	a = static_cast<int>(f);

	//2.reinterpret_cast:֧��ǿ������ת��
	a = reinterpret_cast<int>(pa);

	//3.const_cast:ȥ��������const����
	const int c = 20;
	
	//int *pc = &c;//error
	int *pc = const_cast<int*>(&c);

	//4.dynamic_cast:ֻ���ڶ�̬�����µ��������á�ָ�����������á�ָ��ת������ȥ���ת���Ƿ�ȫ
	//ֻ�а�ȫ�Ż�ת���ɹ�������ȫ������nullptr
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