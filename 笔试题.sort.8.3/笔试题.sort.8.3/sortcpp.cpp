#include<iostream>
using namespace std;
#include<time.h>

//插入排序
void insertSort(int *arr, int n) //arr是待排序的数组，n是数组中有n个元素
{
	//第一个数据有序，从下标为1的数据开始插入
	int index = 1;
	while (index < n)
	{
		//保存插入的数据
		int data = arr[index];
		int end = index - 1;
		//找到第一个小于插入数据的位置
		while (end >= 0 && arr[end] > data)
		{
			//将大于插入数据的数向后移动
			arr[end + 1] = arr[end];
			--end;
		}

		//找到第一个小于插入数据的位置，在这个位置后面插入数据
		arr[end + 1] = data;
		index++;
	}
}

//希尔排序
void shellSort(int *arr, int n)
{
	int gap = n;
	//gap=1时，排序完就会有序，结束循环
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		//第一个插入数据的位置为gap
		int index = gap;
		while (index < n)
		{
			//待插入的数据
			int data = arr[index];
			//同一组数据的最后一个有序位置
			int end = index - gap;

			//找到第一个小于待插入数据的值
			while (end >= 0 && arr[end] > data)
			{
				//将大于待插入数据的值向后移动gap个位置，保证操作的是同一组数据
				arr[end + gap] = arr[end];
				end -= gap;
			}

			arr[end + gap] = data;
			index++;
		}
	}
}


void Swap(int *arr, int pos1, int pos2)
{
	int tmp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = tmp;
}

//向下调整算法：大堆
void shiftDown(int *arr, int n, int pos)//pos是向下调整的位置
{
	//左孩子
	int children = 2 * pos + 1;
	while (children < n)
	{
		//比较左右孩子，选择数值较大的孩子
		//首先判断右孩子是否存在
		if (children + 1 < n && arr[children + 1] > arr[children])
		{
			//如果右孩子存在，并且右孩子的值比较大，那么选择右孩子
			++children;
		}
		//待调整位置的数据小于孩子
		if (arr[pos] < arr[children])
		{
			//和孩子节点进行交换
			Swap(arr, pos, children);
			//待调整的位置就变成了孩子的位置
			pos = children;
			children = 2 * pos + 1;
		}
		else
			break;
	}
}

//堆排序
void heapSort(int *arr, int n)
{
	//建堆:从最后一个非叶子节点开始向下调整
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		//向下调整
		shiftDown(arr, n, i);
	}

	int end = n - 1;
	while (end > 0)
	{
		//建堆完成后，堆顶元素是最大的，将其和最后一个元素交换，最大的数据已经排好序
		Swap(arr, 0, end);
		//从堆顶开始向下调整，让堆顶成为未排序数据的最大值
		shiftDown(arr, end, 0);
		--end;
	}
}


//三数取中法
int getMid(int *arr, int begin, int end)
{
	//获取begin、mid、end位置的中间值，返回中间值的下标
	int mid = begin + (end - begin) / 2;
	if (arr[begin] > arr[mid])
	{
		if (arr[mid] > arr[end])
			return mid;
		else if (arr[end] < arr[begin])
			return end;
		return begin;
	}
	else
	{
		if (arr[begin] > arr[end])
			return begin;
		else if (arr[end] > arr[mid])
			return mid;
		else
			return end;
	}
}


//快排划分
int paration(int *arr, int begin, int end)
{
	//若数据是有序的，调用层数过大，会造成栈溢出
	//采用三数取中法，取一个大小较为中间的下标
	int mid = getMid(arr, begin, end);
	//与begin位置数据交换，这样基准值就是较为中间的数据，避免了调用层数过大
	Swap(arr, begin, mid);

	//取基准值
	int key = arr[begin];
	//保存基准值的位置
	int start = begin;
	while (begin < end)
	{
		//从后向前找小于基准值的位置
		while (begin < end && arr[end] >= key)
			--end;
		//从后向前找大于基准值的位置
		while (begin < end && arr[begin] <= key)
			++begin;
		//找到之后，交换
		Swap(arr, begin, end);
	}
	Swap(arr, start, begin);
	return begin;
}


//快排
void quickSort(int *arr, int begin, int end)
{
	if (begin >= end)
		return;
	//进行划分，找出划分区间
	int div = paration(arr, begin, end);
	//对左部分进行快排
	quickSort(arr, begin, div - 1);
	//对右部分进行划分
	quickSort(arr, div + 1, end);
}


//两个有序序列合并
void merge(int *arr, int begin, int mid, int end, int *tmp)
{
	int begin1 = begin;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = end;

	//辅助空间的开始位置
	int index = begin;

	while (begin1 <=end1 && begin2 <=end2)
	{
		if (arr[begin1] <= arr[begin2])
			tmp[index++] = arr[begin1++];
		else
			tmp[index++] = arr[begin2++];
	}

	//将剩余元素拷贝到辅助空间
	if (begin1 <=end1)
		memcpy(tmp + index, arr + begin1, sizeof(int) *(end1 - begin1 + 1));
	if (begin2 <=end2)
		memcpy(tmp + index, arr + begin2, sizeof(int) * (end2 - begin2 + 1));

	//将排好序的数据拷回原来的数组中
	memcpy(arr + begin, tmp + begin, sizeof(int) * (end - begin + 1));
}


void _mergeSort(int *arr, int begin, int end, int *tmp)
{
	if (begin >= end)
		return;
	int mid = begin + (end - begin) / 2;

	//把数据均衡的分解
	_mergeSort(arr, begin, mid, tmp);
	_mergeSort(arr, mid + 1, end, tmp);

	//合并两个有序数据
	merge(arr, begin, mid, end, tmp);
}

//归并排序
void mergeSort(int *arr, int n)
{
	int *tmp = new int[n];
	_mergeSort(arr, 0, n - 1, tmp);
	delete[] tmp;
}


//计数排序
void countSort(int *arr, int n)
{
	int max = arr[0];
	int min = arr[0];

	//找出最大值与最小值
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}

	//开辟一个计数数组,并且全部初始化为0
	int range = max - min + 1;
	int *countArr = (int*)calloc(range, sizeof(int));

	for (int i = 0; i < n; i++)
	{
		countArr[arr[i] - min]++;
	}

	int index = 0;
	for (int i = 0; i < range; i++)
	{
		while (countArr[i]--)
		{
			arr[index++] = i + min;
		}
	}
	delete[] countArr;
}
