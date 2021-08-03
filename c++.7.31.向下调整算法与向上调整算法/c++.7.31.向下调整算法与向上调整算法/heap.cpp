#include<iostream>
using namespace std;

//���µ����㷨
//ǰ�᣺�ӽṹ�����Ƕ�
//���µ����㷨�����ӽṹ�Ǵ�ѣ���ֻ�ܵ���Ϊ�����ӽṹ��С�ѣ���ֻ�ܵ���ΪС��

//void shiftDown(���飬Ԫ�ظ���������λ��)
//С�ѵĵ���
void shiftDown(int *arr, int n, int curPos)
{
	//����
	int children = 2 * curPos + 1;

	while (children < n)
	{
		//�������Һ��ӱȽ�
		if (children + 1 < n && arr[children + 1] < arr[children])
			++children;

		if (arr[curPos] > arr[children])
		{
			int tmp = arr[children];
			arr[children] = arr[curPos];
			arr[curPos] = tmp;

			curPos = children;
			children = 2 * curPos + 1;
		}
		else
			break;
	}
}


//�ѵĴ���
//�ӵ�����һ����Ҷ�ӽڵ㿪ʼ���µ�����֪�����һ����Ҷ�ӽڵ�
//��Ҷ�ӽڵ㣺(n-2)/2
void createHeap(int *arr, int n)
{
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		shiftDown(arr, n, i);
	}
}


//void test()
//{
//	int arr[] = { 10, 7, 8, 12, 14, 16 ,15 };
//	shiftDown(arr, sizeof(arr) / sizeof(arr[0]), 0);
//	for (auto e : arr)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}


void test()
{
	int arr[] = { 12,3,4,5,2,16 };
	createHeap(arr, sizeof(arr) / sizeof(arr[0]));
	for (auto e : arr)
	{
		cout << e << " ";
	}
	cout << endl;
}

int main()
{
	test();
	return 0;
}