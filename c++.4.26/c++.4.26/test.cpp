#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;


//int Go(int m, int n)
//{
//	if (n == 0 && m == 0)
//		return 0;
//	else if (n == 0 || m == 0)
//		return 1;
//	return Go(m, n - 1) + Go(m - 1, n);
//}
//
//int main()
//{
//	int n;
//	int m;
//	cin >> n >> m;
//	int ret = Go(m, n);
//	cout << ret << endl;
//	return 0;
//}

//class Test
//{
//public:
//	int a; 
//	int b;
//	virtual void fun() {}
//	Test(int temp1 = 0, int temp2 = 0)
//	{
//		a = temp1;
//		b = temp2;
//	}
//
//	int getA()
//	{
//		return a;
//	}
//
//	int getB()
//	{
//		return b;
//	}
//};
//
//int main()
//{
//	Test obj(5, 10);
//	int *pINT = (int*)&obj;
//	*(pINT + 0) = 100;
//	*(pINT + 1) = 200;
//	cout << obj.getA() << endl;
//	cout << obj.getB() << endl;
//	return 0;
//}


//class Test
//{
//public:
//	int a; 
//	int b;
//	virtual void fun() {}
//	Test(int temp1 = 0, int temp2 = 0)
//	{
//		a = temp1;
//		b = temp2;
//	}
//
//	int getA()
//	{
//		return a;
//	}
//
//	int getB()
//	{
//		return b;
//	}
//};
//
//int main()
//{
//	Test obj(5, 10);
//	int *pINT = (int*)&obj;
//	*(pINT + 0) = 100;
//	*(pINT + 1) = 200;
//	cout << obj.getA() << endl;
//	cout << obj.getB() << endl;
//	return 0;
//}

//int fun(int a)
//{
//	a ^= (1 << 5) - 1;
//	return a;
//}
//
//int main()
//{
//	int ret = fun(21);
//	cout << ret << endl;
//}

//class MyClass
//{
//public:
//	MyClass(int i = 0){ cout << 1; }
//	MyClass(const MyClass& x) { cout << 2; }
//	MyClass& operator=(const MyClass& x){ cout << 3; return *this; }
//	~MyClass() { cout << 4; }
//};
//
//int main()
//{
//	MyClass obj1(1), obj2(2), obj3(obj1);
//	return 0;
//}

//void fun(char **m)
//{
//	++m;
//	cout << *m << endl;
//}
//
//int main()
//{
//	static char* a[] = { "morning", "afternoon", "evening" };
//	char **p;
//	p = a;
//	fun(p);
//	return 0;
//}

//int main()
//{
//	int N;
//	cin >> N;
//	int a = 0;
//	int b = 1;
//	int c = 1;
//	int step = N - c;
//	while (1)
//	{
//		//ÇófiboÊý
//		a = b;
//		b = c;
//		c = a + b;
//
//		if (step >= abs(N - c))
//			step = abs(N - c);
//		else
//			break;
//	}
//	cout << step << endl;
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int a = 1; int b = 2, c = 3, d = 0;
//	if (a == 1 && b++ == 2)
//	if (b != 2 || c-- != 3)
//		printf("%d,%d,%d\n", a, b, c);
//	else
//		printf("%d,%d,%d\n", a, b, c);
//	else
//		printf("%d,%d,%d\n", a, b, c);
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class parent
//{
//	int i; 
//protected:
//	int x;
//public:
//	parent(){ x = 0; i = 0; }
//	void change(){ x++; i++; }
//	void display();
//};
//
//class son : public parent
//{
//public:
//	void modify();
//};
//
//void parent::display(){ cout << "x=" << x << endl; }
//void son::modify(){ x++;  }
//
//int main()
//{
//	son A; 
//	parent B;
//	A.display();
//	A.change();
//	A.modify();
//	A.display();
//	B.change();
//	B.display();
//	return 0;
//}
//int main()
//{
//	int a = 1, b = 0, c = -1, d = 0;
//	d = ++a || ++b && ++c;
//	cout << d << endl;
//	return 0;
//}