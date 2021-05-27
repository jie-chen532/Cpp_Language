#define _CRT_SECURE_NO_WARNINGS 1

#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

//class Solution {
//public:
//	/**
//	*  奇数位上都是奇数或者偶数位上都是偶数
//	*  输入：数组arr，长度大于2
//	*  len：arr的长度
//	*  将arr调整成奇数位上都是奇数或者偶数位上都是偶数
//	*/
//	void oddInOddEvenInEven(vector<int>& arr, int len) {
//		for (int i = 0; i < len; i++)
//		{
//			if (i % 2 == 0) //i为偶数
//			{
//				if (arr[i] % 2 != 0)//arr[i]为奇数
//				{
//					int idx = len - 1;
//					//找到i为奇数，arr[i]为偶数的
//					while (idx > i)
//					{
//						if (arr[idx] % 2 == 0)
//						{
//							if (idx % 2 == 0)
//								idx--;
//							else
//								break;
//						}
//						else
//							idx--;
//					}
//					swap(arr[idx], arr[i]);
//				}
//			}
//			else//i为奇数
//			{
//				if (arr[i] % 2 == 0)//i为奇数，arr[i]是偶数
//				{
//					int idx = len - 1;
//					while (idx > i)
//					{
//						if (arr[idx] % 2 != 0)
//						{
//							if (idx % 2 != 0)
//								idx--;
//							else
//								break;
//						}
//						else
//							idx--;
//					}
//					swap(arr[idx], arr[i]);
//				}
//			}
//		}
//	}
//};


//class Solution {
//public:
//	void oddInOddEvenInEven(vector<int>& arr, int len) {
//		int i = 0, j = 1;
//		while (i < len && j < len){
//			if (arr[len - 1] % 2 == 0){
//				swap(arr[len - 1], arr[i]);
//				i += 2;
//			}
//			else{
//				swap(arr[len - 1], arr[j]);
//				j += 2;
//			}
//		}
//	}
//};
//
//
//
//int main()
//{
//	Solution s;
//	int arr[] = { 7, 7, 9, 5, 1, 6, 7, 9, 3, 2, 6 };
//	vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
//	s.oddInOddEvenInEven(vec, sizeof(arr) / sizeof(arr[0]));
//	for (auto& e : vec)
//	{
//		cout << e << endl;
//	}
//}


//template<class K>
//struct HashFun
//{
//	size_t operator()(const K& K)
//	{
//		return key;
//	}
//};
//
//struct HashFun<string>//把key转换为数字 
//{
//	size_t operator()(const string& k)
//	{
//		size_t hash = 0;
//		for (const auto& e : k)
//		{
//			hash = hash * 131 + e;
//		}
//		return hash;
//	}
//};



//位图
class BitSet
{
public:
	BitSet(size_t range)
		:_bit(range / 32 + 1)
	{}

	//存储
	void set(size_t num)
	{
		int index = num / 32;
		int bitIndex = num % 32;
		_bit[index] |= (1 << bitIndex);
	}
	//查找
	bool Find(size_t num)
	{
		int index = num / 32;
		int bitIndex = num % 32;
		return (_bit[index] >> bitIndex) & 1;
	}
	//删除
	void reset(size_t num)
	{
		int index = num / 32;
		int bitIndex = num % 32;
		_bit[index] &= ~(1 << bitIndex);
	}

private:
	vector<int> _bit;
};

//n：是元素个数
//m:需要的bit为大小
//k:哈希函数的个数
//比特位个数：k = m * n * ln2   m = k * n * 1.4
//使用场景：存放各种数据的简单信息
//概率型容器：判断存在，结果不一定正确，不存在，结果一定不正确
//一般没有删除的操作：会有误删的情况
//时间复杂度：o(k)
//布隆过滤器
template<class T, class Hash1, class Hash2, class Hash3>
class BloomFilter
{
public:
	BloomFilter(size_t num)
		:_bit(5 * num)
		, _bitCount(5 * num)
	{}

	void set(const T& val)
	{
		Hash h1;
		Hash h2;
		Hash h3;

		int idx1 = _bit.set(h1(val) % _bitCount);
		int idx2 = _bit.set(h2(val) % _bitCount);
		int idx3 = _bit.set(h3(val) % _bitCount);
	}

	bool test(const T& val)
	{
		Hash h1;
		Hash h2;
		Hash h3;

		int idx1 = h1(val) % _bitCount;
		int idx2 = h2(val) % _bitCount;
		int idx3 = h3(val) % _bitCount;

		if (!_bit.Find(idx1))
			return false;
		if (!_bit.Find(idx2))
			return false;
		if (!_bit.Find(idx3))
			return false;

		return true;//可能存在
	}

private:
	BitSet _bit;
	size_t _bitCount;//bit为的个数
};



