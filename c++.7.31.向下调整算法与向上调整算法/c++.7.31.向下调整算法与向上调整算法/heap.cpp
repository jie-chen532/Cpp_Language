#include<iostream>
using namespace std;

//向下调整算法
//前提：子结构必须是堆
//向下调整算法：若子结构是大堆，就只能调整为；若子结构是小堆，就只能调整为小堆

//void shiftDown(数组，元素个数，调整位置)
//小堆的调整
void shiftDown(int *arr, int n, int curPos)
{
	//左孩子
	int children = 2 * curPos + 1;

	while (children < n)
	{
		//左孩子与右孩子比较
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


//堆的创建
//从倒数第一个非叶子节点开始向下调整，知道最后一个非叶子节点
//非叶子节点：(n-2)/2
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