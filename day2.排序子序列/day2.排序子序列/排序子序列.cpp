#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
using namespace std;
#include<vector>

int main()
{
	int n;
	cin >> n;
	vector<int> arr;
	arr.resize(n + 1);

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int count = 0;
	int i = 0;
	while (i < n)
	{
		if (arr[i] < arr[i + 1])
		{
			//即将进入非递减序列
			while (i < n && arr[i] <= arr[i + 1])
				i++;
			count++;
			i++;
		}
		else if (arr[i] == arr[i + 1])
			i++;
		else
		{
			//即将进入非递增序列
			while (i < n && arr[i] >= arr[i + 1])
				i++;
			count++;
			i++;
		}
	}
	cout << count << endl;
	return 0;
}
