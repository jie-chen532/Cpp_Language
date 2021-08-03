#include<iostream>
using namespace std;
#include<time.h>

//��������
void insertSort(int *arr, int n) //arr�Ǵ���������飬n����������n��Ԫ��
{
	//��һ���������򣬴��±�Ϊ1�����ݿ�ʼ����
	int index = 1;
	while (index < n)
	{
		//������������
		int data = arr[index];
		int end = index - 1;
		//�ҵ���һ��С�ڲ������ݵ�λ��
		while (end >= 0 && arr[end] > data)
		{
			//�����ڲ������ݵ�������ƶ�
			arr[end + 1] = arr[end];
			--end;
		}

		//�ҵ���һ��С�ڲ������ݵ�λ�ã������λ�ú����������
		arr[end + 1] = data;
		index++;
	}
}

//ϣ������
void shellSort(int *arr, int n)
{
	int gap = n;
	//gap=1ʱ��������ͻ����򣬽���ѭ��
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		//��һ���������ݵ�λ��Ϊgap
		int index = gap;
		while (index < n)
		{
			//�����������
			int data = arr[index];
			//ͬһ�����ݵ����һ������λ��
			int end = index - gap;

			//�ҵ���һ��С�ڴ��������ݵ�ֵ
			while (end >= 0 && arr[end] > data)
			{
				//�����ڴ��������ݵ�ֵ����ƶ�gap��λ�ã���֤��������ͬһ������
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

//���µ����㷨�����
void shiftDown(int *arr, int n, int pos)//pos�����µ�����λ��
{
	//����
	int children = 2 * pos + 1;
	while (children < n)
	{
		//�Ƚ����Һ��ӣ�ѡ����ֵ�ϴ�ĺ���
		//�����ж��Һ����Ƿ����
		if (children + 1 < n && arr[children + 1] > arr[children])
		{
			//����Һ��Ӵ��ڣ������Һ��ӵ�ֵ�Ƚϴ���ôѡ���Һ���
			++children;
		}
		//������λ�õ�����С�ں���
		if (arr[pos] < arr[children])
		{
			//�ͺ��ӽڵ���н���
			Swap(arr, pos, children);
			//��������λ�þͱ���˺��ӵ�λ��
			pos = children;
			children = 2 * pos + 1;
		}
		else
			break;
	}
}

//������
void heapSort(int *arr, int n)
{
	//����:�����һ����Ҷ�ӽڵ㿪ʼ���µ���
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		//���µ���
		shiftDown(arr, n, i);
	}

	int end = n - 1;
	while (end > 0)
	{
		//������ɺ󣬶Ѷ�Ԫ�������ģ���������һ��Ԫ�ؽ��������������Ѿ��ź���
		Swap(arr, 0, end);
		//�ӶѶ���ʼ���µ������öѶ���Ϊδ�������ݵ����ֵ
		shiftDown(arr, end, 0);
		--end;
	}
}


//����ȡ�з�
int getMid(int *arr, int begin, int end)
{
	//��ȡbegin��mid��endλ�õ��м�ֵ�������м�ֵ���±�
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


//���Ż���
int paration(int *arr, int begin, int end)
{
	//������������ģ����ò������󣬻����ջ���
	//��������ȡ�з���ȡһ����С��Ϊ�м���±�
	int mid = getMid(arr, begin, end);
	//��beginλ�����ݽ�����������׼ֵ���ǽ�Ϊ�м�����ݣ������˵��ò�������
	Swap(arr, begin, mid);

	//ȡ��׼ֵ
	int key = arr[begin];
	//�����׼ֵ��λ��
	int start = begin;
	while (begin < end)
	{
		//�Ӻ���ǰ��С�ڻ�׼ֵ��λ��
		while (begin < end && arr[end] >= key)
			--end;
		//�Ӻ���ǰ�Ҵ��ڻ�׼ֵ��λ��
		while (begin < end && arr[begin] <= key)
			++begin;
		//�ҵ�֮�󣬽���
		Swap(arr, begin, end);
	}
	Swap(arr, start, begin);
	return begin;
}


//����
void quickSort(int *arr, int begin, int end)
{
	if (begin >= end)
		return;
	//���л��֣��ҳ���������
	int div = paration(arr, begin, end);
	//���󲿷ֽ��п���
	quickSort(arr, begin, div - 1);
	//���Ҳ��ֽ��л���
	quickSort(arr, div + 1, end);
}


//�����������кϲ�
void merge(int *arr, int begin, int mid, int end, int *tmp)
{
	int begin1 = begin;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = end;

	//�����ռ�Ŀ�ʼλ��
	int index = begin;

	while (begin1 <=end1 && begin2 <=end2)
	{
		if (arr[begin1] <= arr[begin2])
			tmp[index++] = arr[begin1++];
		else
			tmp[index++] = arr[begin2++];
	}

	//��ʣ��Ԫ�ؿ����������ռ�
	if (begin1 <=end1)
		memcpy(tmp + index, arr + begin1, sizeof(int) *(end1 - begin1 + 1));
	if (begin2 <=end2)
		memcpy(tmp + index, arr + begin2, sizeof(int) * (end2 - begin2 + 1));

	//���ź�������ݿ���ԭ����������
	memcpy(arr + begin, tmp + begin, sizeof(int) * (end - begin + 1));
}


void _mergeSort(int *arr, int begin, int end, int *tmp)
{
	if (begin >= end)
		return;
	int mid = begin + (end - begin) / 2;

	//�����ݾ���ķֽ�
	_mergeSort(arr, begin, mid, tmp);
	_mergeSort(arr, mid + 1, end, tmp);

	//�ϲ�������������
	merge(arr, begin, mid, end, tmp);
}

//�鲢����
void mergeSort(int *arr, int n)
{
	int *tmp = new int[n];
	_mergeSort(arr, 0, n - 1, tmp);
	delete[] tmp;
}


//��������
void countSort(int *arr, int n)
{
	int max = arr[0];
	int min = arr[0];

	//�ҳ����ֵ����Сֵ
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}

	//����һ����������,����ȫ����ʼ��Ϊ0
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
