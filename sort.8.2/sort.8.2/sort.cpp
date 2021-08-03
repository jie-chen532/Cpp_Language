#include<iostream>
using namespace std;
#include<time.h>
#include<vector>
#include<stack>

//插入排序
//最坏时间复杂度：o(n^2)逆序
//数据有序时：o(n)
//数据稳定性：稳定的
void insertSort(int *arr, int n)
{
	//假设第一个数据有序，从下标为1的数据开始插入
	int idx = 1;
	while (idx < n)
	{
		int end = idx - 1;
		int data = arr[idx];
		while (end >= 0 && arr[end] > data)
		{
			arr[end + 1] = arr[end];
			end--;
		}
		arr[end + 1] = data;
		idx++;
	}
}


//时间复杂度：o(n^1.3) --o(n^2)
//稳定性：不稳定
void shellSort(int *arr, int n)
{
	int gap = n;
	while (gap > 1)//gap等于1，排序完数据就会有序，就结束循环
	{
		//最后一次排序的gap必须为1，才能保证数据有序排列
		gap = gap / 3 + 1;
		for (int i = gap; i < n; i++)
		{
			//同一组的最后一个有序数据
			int end = i - gap;
			//待插入的数据
			int data = arr[i];
			//找到第一个比插入数据小的值结束
			while (end >= 0 && arr[end] > data)
			{
				arr[end + gap] = arr[end];
				end -= gap;
			}
			arr[end + gap] = data;
		}
	}
}


//选择排序
//时间复杂度：o(n^2)
//稳定性：不稳定排序
void selectSort(int *arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int index = i;
		for (int j = i + 1; j < n; j++)
		{
			//一次遍历得到一个最小的值
			if (arr[j] < arr[index])
				index = j;
		}
		//放在没有排序的数据的头部
		int tmp = arr[i];
		arr[i] = arr[index];
		arr[index] = tmp;
	}
}

void swap(int *arr, int pos1, int pos2)
{
	int tmp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = tmp;
}


//选择排序
//遍历次数减少了一半，量级还是o(n^2)
void selectSort2(int *arr, int  n)
{
	int start = 0;
	int end = n - 1;
	while (start < end)
	{
		//一次遍历可以找出最大值和最小值的下标
		//最大值放在未排序数据的末尾，最小值放在未排序数据的头部
		int minIdx = start;
		int maxIdx = start;
		for (int i = start + 1; i <= end; i++)
		{
			if (arr[minIdx] > arr[i])
				minIdx = i;
			if (arr[maxIdx] < arr[i])
				maxIdx = i;
		}
		swap(arr, start, minIdx);
		//会出现一种问题:如果最大值是放在头部的位置
		//例如说：100 2 4 5
		//最小值的下标为1，和100进行交换，此时就变成：2 100 4 5
		//此时最大值下标就在1的位置了，所以要判断最大值是否在头部
		if (maxIdx == start)
			maxIdx = minIdx;
		swap(arr, end, maxIdx);
		start++;
		end--;
	}
}


//向下调整算法(递增)
void shiftDown(int* arr, int n, int pos)
{
	int children = 2 * pos + 1;
	while (children < n)
	{
		if (children + 1 < n && arr[children + 1] > arr[children])
			++children;
		if (arr[pos] < arr[children])
		{
			swap(arr, pos, children);
			pos = children;
			children = 2 * pos + 1;
		}
		else
			break;
	}
}

//堆的复杂度：o(nlogn)
void heapSort(int *arr, int n)
{
	//建堆：从最后一个非叶子节点开始向下调整
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		shiftDown(arr, n, i);
	}
	//此时就是一个大根堆，最大值在堆顶，把它与最后一个元素交换，然后再次进行向下调整算法
	int end = n - 1;
	while (end > 0)
	{
		swap(arr, 0, end);
		shiftDown(arr, end, 0);
		end--;
	}
}


//冒泡排序
//时间复杂度：逆序o(n^2)
//数据有序：o(n)
//稳定性：稳定
void bubbleSort(int *arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int flag = 0;//表示一轮排序中是否发生了交换
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr, j, j + 1);
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}

//三数取中
int getMid(int *arr, int begin, int end)
{
	int mid = begin + (end - begin) / 2;
	if (arr[begin] > arr[mid])
	{
		if (arr[mid] > arr[end])
			return mid;
		else if (arr[begin] > arr[end])
			return end;
		else
			return begin;
	}
	else
	{
		if (arr[begin] > arr[end])
			return begin;
		else if (arr[mid] > arr[end])
			return end;
		else
			return mid;
	}
}



//划分：返回值划分的基准值
//hore:
int paration(int *arr, int begin, int end)
{
	//选择基准值
	//三数取中获取基准值
	int mid = getMid(arr, begin, end);
	//将取中数据与begin交换
	swap(arr, begin, mid);
	int key = arr[begin];
	int start = begin;
	while (begin < end)
	{
		//从后向前选择小于基准的值
		while (begin < end && arr[end] >= key)
			end--;
		//从前向后选择大于基准的值
		while (begin < end && arr[begin] <= key)
			begin++;
		//交换
		swap(arr, begin, end);
	}
	//交换基准值与相遇位置的值
	swap(arr, start, begin);
	return begin;
}


//挖坑法：
int paration1(int *arr, int begin, int end)
{
	//三数取中
	int mid = getMid(arr, begin, end);
	//中间值与begin位置进行交换
	swap(arr, mid, begin);
	int key = arr[begin];
	while (begin < end)
	{
		//从后往前找小于基准值的位置
		while (begin < end && arr[end] >= key)
			--end;
		arr[begin] = arr[end];
		//从前往后找大于基准值的位置
		while (begin < end && arr[begin] <= key)
			++begin;
		arr[end] = arr[begin];
	}
	arr[begin] = key;
	return begin;
}


//前后指针法：
int paration2(int *arr, int begin, int end)
{
	//三数取中
	int mid = getMid(arr, begin, end);
	//中间值与begin位置进行交换
	swap(arr, mid, begin);
	int key = arr[begin];

	int prev = begin;
	int cur = begin + 1;
	while (cur <= end)
	{
		//cur找到小于基准值的位置,判断prev与cur是否相连
		if (arr[cur] < key && ++prev != cur)
		{
			swap(arr, prev, cur);
		}
		cur++;
	}
	swap(arr, prev, begin);
	return prev;
}


//快速排序
//时间复杂度：o(nlogn)
//数据有序时间复杂度---o(n^2)
//数据有序时，没有优化可能会导致栈溢出，因为栈的调用层数 约等于 数据的个数
//优化之后，划分比较均衡，复杂度o(nlogn),栈的调用层数 约等于 logn
//稳定性：不稳定
void quickSort(int *arr, int begin, int end)
{
	//begin与end之间没有数据
	if (begin >= end)
		return;
	//一次划分之后，基准值位置
	//int base = paration(arr, begin, end);
	/*int base = paration1(arr, begin, end);*/
	int base = paration2(arr, begin, end);
	//左边进行排序
	quickSort(arr, begin, base - 1);
	//右边进行排序
	quickSort(arr, base + 1, end);
}


//非递归快排
void quickSort2(int* arr, int n)
{
	stack<int> st;
	//先把整个区间放入
	//先放右边，再放左边
	st.push(n - 1);
	st.push(0);
	while (!st.empty())
	{
		//先拿到左边
		int left = st.top();
		st.pop();
		int right = st.top();
		st.pop();

		//进行划分
		int div = paration(arr, left, right);

		//新划分的区间
		//如果区间存在两个数以上放入栈中
		if (left < div - 1)
		{
			st.push(div - 1);
			st.push(left);
		}

		if (div + 1 < right)
		{
			st.push(right);
			st.push(div + 1);
		}
	}
}


//合并有序序列
void merge(int *arr, int begin,int mid, int end, int* tmp)
{
	int begin1 = begin;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = end;

	int index = begin;//辅助空间的开始位置

	while (begin1 <= end1 && begin2 <= end2)
	{
		if (arr[begin1] <= arr[begin2])
			tmp[index++] = arr[begin1++];
		else
			tmp[index++] = arr[begin2++];
	}

	//剩余元素拷贝到tmp中
	if (begin1 <= end1)
	{
		memcpy(tmp + index, arr + begin1, sizeof(int) * (end1 - begin1 + 1));
	}
	else if(begin2 <= end2)
	{
		memcpy(tmp + index, arr + begin2, sizeof(int) * (end2 - begin2 + 1));
	}

	//将合并之后的数据拷回原来的数组中
	memcpy(arr + begin, tmp + begin, sizeof(int) * (end - begin + 1));
}


void _mergeSort(int *arr, int begin, int end, int* tmp)
{
	//begin与end之间只有一个元素或者没有元素
	if (begin >= end)
		return;

	int mid = begin + (end - begin) / 2;

	//进行分解
	_mergeSort(arr, begin, mid, tmp);
	_mergeSort(arr, mid + 1, end, tmp);

	//对有序序列进行合并
	merge(arr, begin, mid, end, tmp);
}


//归并排序递归：
//时间复杂度：o(nlogn)
void mergeSort(int *arr, int n)
{
	int *tmp = new int[n];
	_mergeSort(arr, 0, n - 1, tmp);
	delete[] tmp;
}


//归并非递归
void mergeSortNor(int* arr, int n)
{
	int *tmp = new int[n];
	int step = 1;
	while (step < n)
	{
		int index = 0;
		while (index < n)
		{
			//找到两个待合并的子序列区间
			int begin = index;
			int mid = index + step - 1;
		    //判断是否存在第二个子序列
			if (mid + 1 >= n)
			{
				break;
			}
			int end = index + 2 * step - 1;
			//判断第二个子序列是否越界
			if (end >= n)
			{
				end = n - 1;
			}
			merge(arr, begin, mid, end, tmp);
			index += 2 * step;
		}
		//更新步长
		step = 2 * step;
	}
	delete[] tmp;
}


void test()
{
	int n;
	cout << "数据量：";
	cin >> n;
	srand(time(NULL));
	
	int *arr = (int*)malloc(sizeof(int) * n);
	int *copy1 = (int*)malloc(sizeof(int) * n);
	int *copy2 = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand();
	}

	memcpy(copy1, arr, sizeof(int)* n);
	memcpy(copy2, arr, sizeof(int)* n);


	time_t begin = clock();
	//selectSort2(copy1, n);
	//heapSort(copy1, n);
	/*quickSort(copy1, 0, n - 1);*/
	/*quickSort2(copy1, n);*/
	/*mergeSort(copy1, n);*/
	mergeSortNor(copy1, n);
	//bubbleSort(copy1, n);
	time_t end = clock();
	cout << "mergeSort：" << end - begin << endl;

	//begin = clock();
	//quickSort(copy1, 0, n - 1);
	//end = clock();
	//cout << "sort quickSort：" << end - begin << endl;
	for (int i = 0; i < n; i++)
	{
		cout <<  copy1[i] << " ";
	}

	//begin = clock();
	//shellSort(copy2, n);
	//end = clock();
	//cout << "希尔排序：" << end - begin << endl;

	free(arr);
	free(copy1);
	free(copy2);
}


//void test()
//{
//	int arr[] = { 10,2,4,5,6,8,9 };
//	//insertSort(arr, sizeof(arr) / sizeof(arr[0]));
//	shellSort(arr, sizeof(arr) / sizeof(arr[0]));
//	for (auto& e : arr)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}

int main()
{
	test();
	return 0;
}