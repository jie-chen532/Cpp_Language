#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<string>

//int main()
//{
//
//	string strText = "How are you?";
//
//	string strSeparator = " ";
//
//	string strResult;
//
//	int size_pos = 0;
//
//	int size_prev_pos = 0;
//
//	while ((size_pos = strText.find_first_of(strSeparator, size_pos)) != string::npos)
//
//	{
//
//		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);
//
//		cout << strResult << " ";
//
//		size_prev_pos = ++size_pos;
//
//	}
//
//	if (size_prev_pos != strText.size())
//
//	{
//
//		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);
//
//		cout << strResult << " ";
//
//	}
//
//	cout << endl;
//
//	return 0;
//
//}


//#include<iostream>
//using namespace std;
//#include<string>
//
//
//int main()
//{
//	string str;
//	while (getline(cin, str))
//	{
//		int arr[26] = { 0 };
//		int flag = 0;
//		int i = 0;
//		for (i = 0; i < str.size(); i++)
//		{
//			arr[str[i] - 'a']++;
//		}
//
//		for (i = 0; i < str.size(); i++)
//		{
//			if (arr[str[i] - 'a'] == 1)
//			{
//				flag = 1;
//				break;
//			}
//		}
//		if (flag)
//			cout << str[i] << endl;
//		else
//			cout << -1 << endl;
//	}
//	return 0;
//}


//class Solution {
//public:
//	void swap(char& a, char& b)
//	{
//		char tmp = a;
//		a = b;
//		b = tmp;
//	}
//
//
//	string reverseWords(string s) {
//		int i = 0;
//		int index = 0;
//		while (i < s.size() + 1)
//		{
//			while (i < s.size() + 1 &&
//				s[i] != ' ' && s[i] != '\0')
//				++i;
//			int left = index;
//			int right = i - 1;
//			while (left < right)
//			{
//				swap(s[left], s[right]);
//				left++;
//				right--;
//			}
//			index = ++i;
//		}
//		return s;
//	}
//};


