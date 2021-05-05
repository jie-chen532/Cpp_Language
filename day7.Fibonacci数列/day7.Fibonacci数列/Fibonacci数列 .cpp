#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
using namespace std;
#include <algorithm>

int main()
{
	int N;
	cin >> N;
	int f1 = 0, f2 = 1, f;
	int left = 0, right = 0;
	while (1)
	{
		f = f1 + f2;
		f1 = f2;
		f2 = f;
		if (f < N)
			left = f;//找到离左边最大的值
		if (f >= N)
		{
			right = f;//找到离右边最大的值
			break;
		}
	}
	int ret = min(N - left, right - N);
	cout << ret << endl;
	return 0;
}