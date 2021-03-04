#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//float func(float a, int b)
//{
//	float m = 1, n = 1;
//	int i;
//	for (i = 1; i < b; i++)
//	{
//		m *= a / i;
//		n += m;
//	}
//	return n;
//}
//
//int main()
//{
//	float ret = func(3.0, 4);
//	cout << ret << endl;
//	return 0;
//}

//class A
//{
//public:
//	int a;
//	int b;
//};
//
//void test()
//{
//	A a;
//	cin >> a.a >> a.b;
//}
//
//int main()
//{
//	test();
//	return 0;
//}


//void sort(int* nums, int size)
//{
//	int idx = 1;
//	while (idx < size)
//	{
//		int end = idx - 1;
//		int tmp = nums[idx];
//		while (end >= 0 && nums[end] < tmp)
//		{
//			nums[end + 1] = nums[end];
//			end--;
//		}
//		nums[end + 1] = tmp;
//		idx++;
//	}
//}
//
//
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5 };
//	sort(arr, 5);
//	for (int i = 0; i < 5; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//	return 0;
//}


//int f(int n)
//{
//	if (n) return f(n - 1) + n;
//	else return n;
//}
//
//int main()
//{
//	int ret = f(4);
//	cout << ret << endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int fun(int x, int y)
//{
//	if (x == y)
//		return (x);
//	else
//		return ((x + y) / 2);
//}
//int main()
//{
//	int a = 4, b = 5, c = 6;
//	printf("%d\n", fun(2 * a, fun(b, c)));
//}

//char * addBinary(char * a, char * b){
//	int i = strlen(a) - 1;
//	int j = strlen(b) - 1;
//	int length = strlen(a) > strlen(b) ? strlen(a) : strlen(b);
//	char *arr = (char*)malloc(sizeof(char)*(length + 2));
//	arr[length + 1] = '\0';
//	int flag = 0;
//	int tmp = 0;
//	while (i >= 0 || j >= 0)
//	{
//		if (i < 0)
//		{
//			tmp = b[j] + flag - '0';
//		}
//		else if (j < 0)
//		{
//			tmp = a[i] + flag - '0';
//		}
//		else
//		{
//			tmp = a[i] + b[j] + flag - 2 * '0';
//		}
//
//		if (tmp >= 2)
//		{
//			arr[length--] = tmp % 2 + '0';
//			flag = 1;
//		}
//		else
//		{
//			arr[length--] = tmp + '0';
//			flag = 0;
//		}
//		i--;
//		j--;
//	}
//	if (flag)
//		arr[0] = '1';
//	else
//		arr++;
//	return arr;
//}

//int thirdMax(int* nums, int numsSize){
//	long firMax = LONG_MIN;
//	long secMax = LONG_MIN;
//	long thiMax = LONG_MIN;
//	for (int i = 0; i < numsSize; i++)
//	{
//		if (nums[i] > firMax)
//		{
//			thiMax = secMax;
//			secMax = firMax;
//			firMax = nums[i];
//		}
//		if (nums[i] < firMax && nums[i] > secMax)
//		{
//			thiMax = secMax;
//			secMax = nums[i];
//		}
//		if (nums[i] < firMax && nums[i] < secMax &&
//			nums[i] > thiMax)
//			thiMax = nums[i];
//	}
//	if (thiMax == LONG_MIN)
//		return firMax;
//	return thiMax;
//}
//
//int main()
//{
//	//addBinary("11", "1");
//	return 0;
//}

int func(int i, int j)
{
	if (i <= 0 || j <= 0)
		return 1;
	return 2 * func(i - 3, j / 2);
}int main(){	int ret = func(15, 20);	cout << ret << endl;	return 0;}