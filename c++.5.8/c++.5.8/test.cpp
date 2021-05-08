#define _CRT_SECURE_NO_WARNINGS 1


//#include<iostream>
//using namespace std;
//
//class BinInsert {
//public:
//	int binInsert(int n, int m, int j, int i) {
//		return n | (m << j);
//	}
//};
//
//int main()
//{
//	BinInsert bin;
//	int ret = bin.binInsert(1024, 19, 2, 6);
//	cout << ret << endl;
//	return 0;
//}

//#include<math.h>
//#include<vector>
//
//bool isPrime(int a)
//{
//	for (int i = 2; i <= (int)sqrt(a); i++)
//	{
//		if (a % i == 0)
//			return false;
//	}
//	return true;
//}
//
//int main()
//{
//	int n;
//	vector<int> arr(2);
//	while (cin >> n)
//	{
//		int min = n;
//		int i = 1;
//		while (i <= n / 2)
//		{
//			if (isPrime(i) && isPrime(n - i))
//			{
//				if (n - i - i < min)
//				{
//					arr[0] = i;
//					arr[1] = n - i;
//				}
//			}
//			i++;
//		}
//		cout << arr[0] << endl;
//		cout << arr[1] << endl;
//	}
//	return 0;
//}

//#define SQR(A) A*A
//int main()
//{
//	int x = 6, y = 3, z = 2;
//	x /= SQR(y + z) / SQR(y + z);
//	cout << x;
//	return 0;
//}

//int main()
//{
//	int n[][3] = { 10, 20, 30, 40, 50, 60 };
//	int(*p)[3];
//	p = n;
//	cout << p[0][0] << " " << *(p[0] + 1) << " " << (*p)[2] << endl;
//}

//class Base
//{
//public:
//	int Bar(char x)
//	{
//		return (int)x;
//	}
//	virtual int Bar(int x)
//	{
//		return (2 * x);
//	}
//};
//
//class Derived :public Base
//{
//public:
//	int Bar(char x)
//	{
//		return (int)(-x);
//	}
//	int Bar(int x)
//	{
//		return (x / 2);
//	}
//};
//
//int main()
//{
//	Derived Obj;
//	Base *pObj = &Obj;
//	cout << pObj->Bar((char)100);
//	cout << pObj->Bar(100);
//	return 0;
//}