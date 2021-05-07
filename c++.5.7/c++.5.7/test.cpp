#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
using namespace std;
#include<vector>

int main()
{
	int n;
	cin >> n;
	vector<int> arr(8);
	for (int i = 0; i < 8; i++)
	{
		arr[i] = (n >> i) & 1;
	}

	int count = 0;
	int max = 0;
	int prev = 1;
	int index = 0;
	while (prev < 8)
	{
		count = 0;
		while (prev < 8 && arr[index] == 1 && arr[prev] == 1)
		{
			prev++;
			count++;
		}

		while (prev < 8 && arr[prev] != 1)
			prev++;

		if (count + 1  > max)
			max = count + 1;
		index = prev;
		prev++;
	}
	cout << max << endl;
	return 0;
}