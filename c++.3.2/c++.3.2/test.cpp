#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//void test()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
//	for (int e : arr)
//	{
//		cout << e << " ";
//	}
//}

//void test()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
//	for (int e : arr)
//	{
//		e = 10;
//	}
//
//	for (int e : arr)
//	{
//		cout << e << " ";
//	}
//}

//void test()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
//	for (const auto& e : arr)
//	{
//		cout << e << " ";
//	}
//}

//void fun(int arr[])
//{
//	for (auto& e : arr)
//	{
//		cout << e << " ";
//	}
//}
//
//void test()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
//	fun(arr);
//}

//void test()
//{
//	cout << sizeof(long long) << endl;
//}

//void test()
//{
//	int a = 0;
//	a = 5 + 1.6;
//	cout << a << endl;
//	cout << typeid(a).name() << endl;
//}

//int main()
//{
//	int i = 0, a = 0;
//	while (i<20)
//	{
//		for (;;)
//		{
//			if ((i % 10) == 0) break;
//			else i--;
//		}
//		i += 11; a += i;
//	}
//	printf("%d\n", a);
//	return 0;
//}//
//void test()
//{
//	cout << sizeof(float) << endl;
//}
//
//
//
//int main()
//{
//	test();
//	return 0;



//#define N 2
//#define M N+1
//#define NUM (M+1)*M/2
//int main()
//{
//	printf("%d\n", NUM);
//}

//int func(int a)
//{
//	int b;
//	switch (a)
//	{
//	case 1: b = 30;
//	case 2: b = 20;
//	case 3: b = 16;
//	default: b = 0;
//	}
//	return b;
//}////void test()//{//	int ret = func(1);//	cout << ret << endl;//}////int main()//{//	test();//	return 0;//}
//void sort(int* arr, int numsSize)
//{
//	int i = 1;
//	while (i < numsSize)
//	{
//		int index = i - 1;
//		int tmp = arr[i];
//		while (index >= 0 && arr[index] > tmp)
//		{
//			arr[index + 1] = arr[index];
//			index--;
//		}
//		arr[index + 1] = tmp;
//		i++;
//	}
//}
//
//bool containsDuplicate(int* nums, int numsSize){
//	sort(nums, numsSize);
//	int i = 0;
//	for (i = 0; i < numsSize - 1; i++)
//	{
//		int j = i + 1;
//		if (nums[i] == nums[j])
//		{
//			return true;
//		}
//	}
//	return false;
//}
void test()
{
	int n = 2;
	n += n -= n*n;
	cout << n << endl;
}

int main()
{
	test();
	return 0;
}