#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<vector>

int GetMax(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int sum = arr[0];
	int max = arr[0];

	for (int i = 1; i < n; i++)
	{
		//��ȡdp[i - 1] + arr[i]��arr[i]�Ľϴ�ֵ�������к����ֵ
		sum = GetMax(sum + arr[i], arr[i]);
		if (sum > max)
			max = sum;
	}
	cout << max << endl;
	return 0;
}