#include<iostream>
using namespace std;
#include<time.h>
#include<vector>
#include<stack>

//��������
//�ʱ�临�Ӷȣ�o(n^2)����
//��������ʱ��o(n)
//�����ȶ��ԣ��ȶ���
void insertSort(int *arr, int n)
{
	//�����һ���������򣬴��±�Ϊ1�����ݿ�ʼ����
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


//ʱ�临�Ӷȣ�o(n^1.3) --o(n^2)
//�ȶ��ԣ����ȶ�
void shellSort(int *arr, int n)
{
	int gap = n;
	while (gap > 1)//gap����1�����������ݾͻ����򣬾ͽ���ѭ��
	{
		//���һ�������gap����Ϊ1�����ܱ�֤������������
		gap = gap / 3 + 1;
		for (int i = gap; i < n; i++)
		{
			//ͬһ������һ����������
			int end = i - gap;
			//�����������
			int data = arr[i];
			//�ҵ���һ���Ȳ�������С��ֵ����
			while (end >= 0 && arr[end] > data)
			{
				arr[end + gap] = arr[end];
				end -= gap;
			}
			arr[end + gap] = data;
		}
	}
}


//ѡ������
//ʱ�临�Ӷȣ�o(n^2)
//�ȶ��ԣ����ȶ�����
void selectSort(int *arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int index = i;
		for (int j = i + 1; j < n; j++)
		{
			//һ�α����õ�һ����С��ֵ
			if (arr[j] < arr[index])
				index = j;
		}
		//����û����������ݵ�ͷ��
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


//ѡ������
//��������������һ�룬��������o(n^2)
void selectSort2(int *arr, int  n)
{
	int start = 0;
	int end = n - 1;
	while (start < end)
	{
		//һ�α��������ҳ����ֵ����Сֵ���±�
		//���ֵ����δ�������ݵ�ĩβ����Сֵ����δ�������ݵ�ͷ��
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
		//�����һ������:������ֵ�Ƿ���ͷ����λ��
		//����˵��100 2 4 5
		//��Сֵ���±�Ϊ1����100���н�������ʱ�ͱ�ɣ�2 100 4 5
		//��ʱ���ֵ�±����1��λ���ˣ�����Ҫ�ж����ֵ�Ƿ���ͷ��
		if (maxIdx == start)
			maxIdx = minIdx;
		swap(arr, end, maxIdx);
		start++;
		end--;
	}
}


//���µ����㷨(����)
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

//�ѵĸ��Ӷȣ�o(nlogn)
void heapSort(int *arr, int n)
{
	//���ѣ������һ����Ҷ�ӽڵ㿪ʼ���µ���
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		shiftDown(arr, n, i);
	}
	//��ʱ����һ������ѣ����ֵ�ڶѶ������������һ��Ԫ�ؽ�����Ȼ���ٴν������µ����㷨
	int end = n - 1;
	while (end > 0)
	{
		swap(arr, 0, end);
		shiftDown(arr, end, 0);
		end--;
	}
}


//ð������
//ʱ�临�Ӷȣ�����o(n^2)
//��������o(n)
//�ȶ��ԣ��ȶ�
void bubbleSort(int *arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int flag = 0;//��ʾһ���������Ƿ����˽���
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

//����ȡ��
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



//���֣�����ֵ���ֵĻ�׼ֵ
//hore:
int paration(int *arr, int begin, int end)
{
	//ѡ���׼ֵ
	//����ȡ�л�ȡ��׼ֵ
	int mid = getMid(arr, begin, end);
	//��ȡ��������begin����
	swap(arr, begin, mid);
	int key = arr[begin];
	int start = begin;
	while (begin < end)
	{
		//�Ӻ���ǰѡ��С�ڻ�׼��ֵ
		while (begin < end && arr[end] >= key)
			end--;
		//��ǰ���ѡ����ڻ�׼��ֵ
		while (begin < end && arr[begin] <= key)
			begin++;
		//����
		swap(arr, begin, end);
	}
	//������׼ֵ������λ�õ�ֵ
	swap(arr, start, begin);
	return begin;
}


//�ڿӷ���
int paration1(int *arr, int begin, int end)
{
	//����ȡ��
	int mid = getMid(arr, begin, end);
	//�м�ֵ��beginλ�ý��н���
	swap(arr, mid, begin);
	int key = arr[begin];
	while (begin < end)
	{
		//�Ӻ���ǰ��С�ڻ�׼ֵ��λ��
		while (begin < end && arr[end] >= key)
			--end;
		arr[begin] = arr[end];
		//��ǰ�����Ҵ��ڻ�׼ֵ��λ��
		while (begin < end && arr[begin] <= key)
			++begin;
		arr[end] = arr[begin];
	}
	arr[begin] = key;
	return begin;
}


//ǰ��ָ�뷨��
int paration2(int *arr, int begin, int end)
{
	//����ȡ��
	int mid = getMid(arr, begin, end);
	//�м�ֵ��beginλ�ý��н���
	swap(arr, mid, begin);
	int key = arr[begin];

	int prev = begin;
	int cur = begin + 1;
	while (cur <= end)
	{
		//cur�ҵ�С�ڻ�׼ֵ��λ��,�ж�prev��cur�Ƿ�����
		if (arr[cur] < key && ++prev != cur)
		{
			swap(arr, prev, cur);
		}
		cur++;
	}
	swap(arr, prev, begin);
	return prev;
}


//��������
//ʱ�临�Ӷȣ�o(nlogn)
//��������ʱ�临�Ӷ�---o(n^2)
//��������ʱ��û���Ż����ܻᵼ��ջ�������Ϊջ�ĵ��ò��� Լ���� ���ݵĸ���
//�Ż�֮�󣬻��ֱȽϾ��⣬���Ӷ�o(nlogn),ջ�ĵ��ò��� Լ���� logn
//�ȶ��ԣ����ȶ�
void quickSort(int *arr, int begin, int end)
{
	//begin��end֮��û������
	if (begin >= end)
		return;
	//һ�λ���֮�󣬻�׼ֵλ��
	//int base = paration(arr, begin, end);
	/*int base = paration1(arr, begin, end);*/
	int base = paration2(arr, begin, end);
	//��߽�������
	quickSort(arr, begin, base - 1);
	//�ұ߽�������
	quickSort(arr, base + 1, end);
}


//�ǵݹ����
void quickSort2(int* arr, int n)
{
	stack<int> st;
	//�Ȱ������������
	//�ȷ��ұߣ��ٷ����
	st.push(n - 1);
	st.push(0);
	while (!st.empty())
	{
		//���õ����
		int left = st.top();
		st.pop();
		int right = st.top();
		st.pop();

		//���л���
		int div = paration(arr, left, right);

		//�»��ֵ�����
		//�������������������Ϸ���ջ��
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


//�ϲ���������
void merge(int *arr, int begin,int mid, int end, int* tmp)
{
	int begin1 = begin;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = end;

	int index = begin;//�����ռ�Ŀ�ʼλ��

	while (begin1 <= end1 && begin2 <= end2)
	{
		if (arr[begin1] <= arr[begin2])
			tmp[index++] = arr[begin1++];
		else
			tmp[index++] = arr[begin2++];
	}

	//ʣ��Ԫ�ؿ�����tmp��
	if (begin1 <= end1)
	{
		memcpy(tmp + index, arr + begin1, sizeof(int) * (end1 - begin1 + 1));
	}
	else if(begin2 <= end2)
	{
		memcpy(tmp + index, arr + begin2, sizeof(int) * (end2 - begin2 + 1));
	}

	//���ϲ�֮������ݿ���ԭ����������
	memcpy(arr + begin, tmp + begin, sizeof(int) * (end - begin + 1));
}


void _mergeSort(int *arr, int begin, int end, int* tmp)
{
	//begin��end֮��ֻ��һ��Ԫ�ػ���û��Ԫ��
	if (begin >= end)
		return;

	int mid = begin + (end - begin) / 2;

	//���зֽ�
	_mergeSort(arr, begin, mid, tmp);
	_mergeSort(arr, mid + 1, end, tmp);

	//���������н��кϲ�
	merge(arr, begin, mid, end, tmp);
}


//�鲢����ݹ飺
//ʱ�临�Ӷȣ�o(nlogn)
void mergeSort(int *arr, int n)
{
	int *tmp = new int[n];
	_mergeSort(arr, 0, n - 1, tmp);
	delete[] tmp;
}


//�鲢�ǵݹ�
void mergeSortNor(int* arr, int n)
{
	int *tmp = new int[n];
	int step = 1;
	while (step < n)
	{
		int index = 0;
		while (index < n)
		{
			//�ҵ��������ϲ�������������
			int begin = index;
			int mid = index + step - 1;
		    //�ж��Ƿ���ڵڶ���������
			if (mid + 1 >= n)
			{
				break;
			}
			int end = index + 2 * step - 1;
			//�жϵڶ����������Ƿ�Խ��
			if (end >= n)
			{
				end = n - 1;
			}
			merge(arr, begin, mid, end, tmp);
			index += 2 * step;
		}
		//���²���
		step = 2 * step;
	}
	delete[] tmp;
}


void test()
{
	int n;
	cout << "��������";
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
	cout << "mergeSort��" << end - begin << endl;

	//begin = clock();
	//quickSort(copy1, 0, n - 1);
	//end = clock();
	//cout << "sort quickSort��" << end - begin << endl;
	for (int i = 0; i < n; i++)
	{
		cout <<  copy1[i] << " ";
	}

	//begin = clock();
	//shellSort(copy2, n);
	//end = clock();
	//cout << "ϣ������" << end - begin << endl;

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