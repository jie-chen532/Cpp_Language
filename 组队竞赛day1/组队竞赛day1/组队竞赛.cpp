#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int n;//������
	while (cin >> n)
	{
		long long sum = 0;
		vector<int> arr;
		arr.resize(3 * n);
		for (int i = 0; i < 3 * n; i++)
		{
			cin >> arr[i];
		}

		//����
		sort(arr.begin(), arr.end());

		//����ڶ���ֵ���
		for (int i = 0; i < n; i++)
		{
			sum += arr[arr.size() - 2 * (i + 1)];
		}
		cout << sum << endl;
	}
	return 0;
}