#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
using namespace std;

bool isNum(int a, int b)
{
	int c;
	while (c = a % b)
	{
		a = b;
		b = c;
	}
	if (b == 1)
		return false;
	return true;
}

int jump(int n, int m)
{
	int count = 0;
	int tmp = n;
	int sum = n;
	while (1)
	{
		tmp++;
		if (isNum(n, tmp))
		{
			n = tmp;
			count++;
		}
		if (n == m)
			break;
		else if (n > m)
			return -1;
	}
	return count;
}

int main()
{
	int N, M;
	cin >> N >> M;
	int ret = jump(N, M);
	cout << ret << endl;
	return 0;
}

//#include<iostream>
//using namespace std;
//#include<string>
//#include<vector>
//
//int main()
//{
//	string str;
//	vector<string> arr;
//	string ret;
//
//	while (getline(cin, str))
//	{
//		bool flag = false;
//		int count = 0;
//		for (int i = 0; i < str.size(); i++)
//		{
//			if (str[i] == '"')
//			{
//				count++;
//				if (count % 2 == 1)
//					flag = true;
//				else
//					flag = false;
//			}
//			else if (str[i] == ' ' && !flag)//如果是空格，并且不在""中，则结束
//			{
//				arr.push_back(ret);
//				ret.clear();
//			}
//			else
//			{
//				ret += str[i];
//			}
//		}
//		arr.push_back(ret);
//		cout << arr.size() << endl;
//		for (const auto& e : arr)
//			cout << e << endl;
//	}
//	return 0;
//}



//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int i, a[10];
//	for (int i = 9; i >= 0; i--)
//	{
//		a[i] = 10 - i;
//	}
//	cout << a[2] << a[5] << a[8];
//	return 0;
//}

//int main()
//{
//	int i = 0, a = 1, b = 2, c = 3;
//	i = ++a || ++b || ++c;
//	cout << i << " " << a << " " << b << " " << c << " " << endl;
//	return 0;
//}

//class A
//{
//public:
//	virtual void print()
//	{
//		cout << "A::print()" << "\n";
//	}
//};
//
//
//class B:public A
//{
//public:
//	virtual void print()
//	{
//		cout << "B::print()" << "\n";
//	}
//};
//
//class C :public A
//{
//public:
//	virtual void print()
//	{
//		cout << "C::print()" << "\n";
//	}
//};
//
//void print(A a)
//{
//	a.print();
//}
//
//int main()
//{
//	A a, *aa, *ab, *ac;
//	B b;
//	C c;
//	aa = &a;
//	ab = &b;
//	ac = &c;
//	a.print();
//	b.print();
//	c.print();
//	aa->print();
//	ab->print();
//	ac->print();
//	print(a);
//	print(b);
//	print(c);
//	return 0;
//}


//class B{
//public:
//	B()
//	{
//		cout << "default constructor" << " ";
//	}
//	~B()
//	{
//		cout << "destructed" << " ";
//	}
//	B(int i) :data(i)
//	{
//		cout << "constructed by parameter" << data << " ";
//	}
//private:
//	int data;
//};
//
//B Play(B b)
//{
//	return b;
//}
//
//int main()
//{
//	B tmp = Play(5);
//	return 0;
//}