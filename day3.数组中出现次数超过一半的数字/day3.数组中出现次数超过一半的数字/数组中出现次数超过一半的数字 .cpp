#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

//�ⷨһ������
//class Solution {
//public:
//	int MoreThanHalfNum_Solution(vector<int> numbers) {
//		//���ж�numbers�Ƿ��ǿյ�
//		if (numbers.empty()) return 0;
//
//		//����
//		sort(numbers.begin(), numbers.end());
//
//		//ȡ�м���
//		int midNum = numbers[numbers.size() / 2];
//
//		//������������
//		int count = 0;
//		for (int i = 0; i < numbers.size(); i++)
//		{
//			if (numbers[i] == midNum)
//				count++;
//		}
//
//		//�ж��Ƿ񳬹����鳤�ȵ�һ��
//		if (count > numbers.size() / 2)
//			return midNum;
//		return 0;
//	}
//};


//�ⷨ������ϣ
//class Solution {
//public:
//	int MoreThanHalfNum_Solution(vector<int> numbers) {
//		//���ж�numbers�Ƿ��ǿյ�
//		if (numbers.empty()) return 0;
//
//		//����hash����
//		int hash[10] = { 0 };
//
//		//��¼numbers�и������ֳ��ֵĴ���
//		for (int i = 0; i < numbers.size(); i++)
//		{
//			hash[numbers[i]]++;
//		}
//
//		//����hash�����ҳ���������������
//		for (int i = 0; i < 10; i++)
//		{
//			if (hash[i] > numbers.size() / 2)
//				return i;
//		}
//		return 0;
//	}
//};


//�ⷨ��
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		//���ж�numbers�Ƿ��ǿյ�
		if (numbers.empty()) return 0;

		int result = numbers[0];//����
		int times = 1;//���ֵĴ���
		for (int i = 1; i < numbers.size(); i++)
		{
			if (times > 0)//˵��������
			{
				if (numbers[i] == result)
					times++;
				else
					times--;
			}
			else //û����������Ҫ����ѡȡ
			{
				result = numbers[i];
				times = 1;
			}
		}

		//����
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