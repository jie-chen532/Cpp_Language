#define _CRT_SECURE_NO_WARNINGS 1

#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

//class Solution {
//public:
//	/**
//	*  ����λ�϶�����������ż��λ�϶���ż��
//	*  ���룺����arr�����ȴ���2
//	*  len��arr�ĳ���
//	*  ��arr����������λ�϶�����������ż��λ�϶���ż��
//	*/
//	void oddInOddEvenInEven(vector<int>& arr, int len) {
//		for (int i = 0; i < len; i++)
//		{
//			if (i % 2 == 0) //iΪż��
//			{
//				if (arr[i] % 2 != 0)//arr[i]Ϊ����
//				{
//					int idx = len - 1;
//					//�ҵ�iΪ������arr[i]Ϊż����
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
//			else//iΪ����
//			{
//				if (arr[i] % 2 == 0)//iΪ������arr[i]��ż��
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
//struct HashFun<string>//��keyת��Ϊ���� 
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



//λͼ
class BitSet
{
public:
	BitSet(size_t range)
		:_bit(range / 32 + 1)
	{}

	//�洢
	void set(size_t num)
	{
		int index = num / 32;
		int bitIndex = num % 32;
		_bit[index] |= (1 << bitIndex);
	}
	//����
	bool Find(size_t num)
	{
		int index = num / 32;
		int bitIndex = num % 32;
		return (_bit[index] >> bitIndex) & 1;
	}
	//ɾ��
	void reset(size_t num)
	{
		int index = num / 32;
		int bitIndex = num % 32;
		_bit[index] &= ~(1 << bitIndex);
	}

private:
	vector<int> _bit;
};

//n����Ԫ�ظ���
//m:��Ҫ��bitΪ��С
//k:��ϣ�����ĸ���
//����λ������k = m * n * ln2   m = k * n * 1.4
//ʹ�ó�������Ÿ������ݵļ���Ϣ
//�������������жϴ��ڣ������һ����ȷ�������ڣ����һ������ȷ
//һ��û��ɾ���Ĳ�����������ɾ�����
//ʱ�临�Ӷȣ�o(k)
//��¡������
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

		return true;//���ܴ���
	}

private:
	BitSet _bit;
	size_t _bitCount;//bitΪ�ĸ���
};



