#define _CRT_SECURE_NO_WARNINGS 1



//#include<iostream>
//using namespace std;

//int main()
//{
//	string str;
//	string delestr;
//	getline(cin, str);
//	getline(cin, delestr);
//	string::iterator it = str.begin();
//	for (int i = 0; i < delestr.size(); i++)
//	{
//		char tmp = delestr[i];
//		it = str.begin();
//		while (it != str.end())
//		{
//			if (*it == tmp)
//			{
//				it = str.erase(it);
//			}
//			else
//				it++;
//		}
//	}
//	cout << str;
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//
//void Sort(vector<int>& arr, int len)
//{
//	int index = 1;
//	while (index < len)
//	{
//		int end = index - 1;
//		int tmp = arr[index];
//		while (end >= 0 && arr[end] > tmp)
//		{
//			arr[end + 1] = arr[end];
//			end--;
//		}
//		arr[end + 1] = tmp;
//		index++;
//	}
//}
//
//int main()
//{
//	int team;
//	//输入队伍数
//	cin >> team;
//	vector<int> arr;
//	arr.resize(3 * team);
//	for (int i = 0; i < 3 * team; i++)
//	{
//		cin >> arr[i];
//	}
//	//排序---插入排序
//	Sort(arr, 3 * team);
//
//	int sum = 0;
//	//计算水平值
//	for (int i = 1; i <= team; i++)
//	{
//		sum += arr[3 * team - i * 2];
//	}
//	cout << sum << endl;
//}


//int main()
//{
//	int a[] = { 1, 2, 3, 4 };
//	int  *b = a;
//	*b += 2;
//	*(b + 2) = 2;
//	b++;
//	printf("%d,%d\n", *b, *(b + 2));
//	return 0;
//}

//int main()
//{
//	unsigned a = 10;
//	printf("%d\n", sizeof(a));
//	return 0;
//}


//#include<iostream>
//using namespace std;
//#include<string>
//#include <algorithm>
//
//
//int main()
//{
//	string str;
//	getline(cin, str);
//	//将字符串倒置
//	string::iterator it = str.begin();
//	string::iterator tmp = str.begin();
//	reverse(it, str.end());
//	//.hnijieb ekil I
//	//以空格分开的每串字符进行倒置
//	while (it != str.end())
//	{
//		while (it != str.end() && *it != ' ')
//			it++;
//		reverse(tmp, it);
//		if (it != str.end())
//			tmp = ++it;
//	}
//	cout << str << endl;
//	return 0;
//}



#include<iostream>
using namespace std;
#include<vector>

int main()
{
	int n;
	//输入n
	cin >> n;
	vector<int> arr;
	arr.resize(n + 1);//最后一个位置处理1 2 1 2 1的问题
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	//问题：没有解决1 2 1 2 1的问题
	//1 2 1 2 1 0
	int count = 0;
	int i = 0;
	while (i < n)
	{
		//递增子序列
		if (i < n && arr[i + 1] > arr[i])
		{
			while (i < n && arr[i + 1] > arr[i])
				i++;
			count++;
			i++;
		}
		else if (i < n && arr[i + 1] == arr[i])
		{
			i++;
		}
		//递减子序列
		else if (i < n && arr[i + 1] < arr[i])
		{
			while (i < n && arr[i + 1] < arr[i])
				i++;
			count++;
			i++;
		}
	}

	cout << count << endl;
}