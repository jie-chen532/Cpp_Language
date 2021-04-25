#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

//解法一：排序
//class Solution {
//public:
//	int MoreThanHalfNum_Solution(vector<int> numbers) {
//		//先判断numbers是否是空的
//		if (numbers.empty()) return 0;
//
//		//排序
//		sort(numbers.begin(), numbers.end());
//
//		//取中间数
//		int midNum = numbers[numbers.size() / 2];
//
//		//遍历整个数组
//		int count = 0;
//		for (int i = 0; i < numbers.size(); i++)
//		{
//			if (numbers[i] == midNum)
//				count++;
//		}
//
//		//判断是否超过数组长度的一半
//		if (count > numbers.size() / 2)
//			return midNum;
//		return 0;
//	}
//};


//解法二：哈希
//class Solution {
//public:
//	int MoreThanHalfNum_Solution(vector<int> numbers) {
//		//先判断numbers是否是空的
//		if (numbers.empty()) return 0;
//
//		//定义hash数组
//		int hash[10] = { 0 };
//
//		//记录numbers中各个数字出现的次数
//		for (int i = 0; i < numbers.size(); i++)
//		{
//			hash[numbers[i]]++;
//		}
//
//		//遍历hash数组找出符合条件的数字
//		for (int i = 0; i < 10; i++)
//		{
//			if (hash[i] > numbers.size() / 2)
//				return i;
//		}
//		return 0;
//	}
//};


//解法三
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		//先判断numbers是否是空的
		if (numbers.empty()) return 0;

		int result = numbers[0];//众数
		int times = 1;//出现的次数
		for (int i = 1; i < numbers.size(); i++)
		{
			if (times > 0)//说明有众数
			{
				if (numbers[i] == result)
					times++;
				else
					times--;
			}
			else //没有众数，需要重新选取
			{
				result = numbers[i];
				times = 1;
			}
		}

		//遍历
		times = 0;
		for (int i = 0; i < numbers.size(); i++)
		{
			if (numbers[i] == result)
				times++;
		}

		if (times > numbers.size() / 2)
			return result;
		return 0;
	}
};


int main()
{
	Solution s;
	int arr[] = { 1, 2, 2, 3, 4, 2, 2 };
	vector<int> a(arr, arr + sizeof(arr) / sizeof(arr[0]));
	int ret = s.MoreThanHalfNum_Solution(a);
	cout << ret << endl;
	return 0;
}