#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<set>
#include<map>
#include<functional>

void test()
{
	//multimap:key和value都可以重复
	//multimap没有[]的操作，因为有多个key，不知道给哪个value赋值
}

//void test()
//{
//	int arr[] = { 1, 10, 2, 5, 7, 5, 3, 10, 9 };
//	//multiset:可以存放重复的数据
//	multiset<int> s(arr, arr + sizeof(arr) / sizeof(arr[0]));
//	for (const auto e : s)
//		cout << e << " ";
//	cout << endl;
//}

//template<class T1, class T2>
//void printMap(const map<T1, T2>& m)
//{
//	for (const auto& e : m)
//		cout << e.first << "--->" << e.second << endl;
//}

//template <class T1, class T2>
//void printMap(const map<T1, T2>& m)
//{
//	auto it = m.begin();
//
//}
//
//void test()
//{
//	//map中的数据是pair,不能直接输出pair，因为pair没有重载<<
//	pair<int, int> arr[] = { pair<int, int>(3, 5), pair<int, int>(1, 4), pair<int, int>(2, 5),
//		                     pair<int, int>(3,6)};
//	map<int, int> m(arr, arr + sizeof(arr) / sizeof(arr[0]));
//	printMap(m);
//	//迭代器访问的顺序：key按照中序遍历
//	//map中key不能重复，value可以重复
//	//map不能修改key，可以修改value
//
//	//operator[]:读、写、插入
//	//at接口和operator[]区别：at执行插入操作，如果key值不存在，则抛异常
//
//	//两种常见的插入方式
//	//1.调用pair构造函数创建对象
//	auto ret = m.insert(pair<int, int>(7, 6));
//	cout << ret.first->first << "--->" << ret.first->second << "  insert:" << ret.second << endl;
//
//	//2.调用make_pair函数创建对象
//	ret = m.insert(make_pair(4, 6));
//	cout << ret.first->first << "--->" << ret.first->second << "  insert:" << ret.second << endl;
//
//	ret = m.insert(make_pair(4, 5));
//	cout << ret.first->first << "--->" << ret.first->second << "  insert:" << ret.second << endl;
//
//	//size_type erase(const key_type& k);
//	size_t num = m.erase(4);
//	cout << num << endl;
//	cout << m.erase(4 )<< endl;
//
//	//查找按key查找
//	auto it = m.find(4);
//	cout << (it == m.end()) << endl;
//	it = m.find(7);
//	cout << (it == m.end()) << endl;
//}

//template<class T>
//void printSet(const set<T>& s)
//{
//	for (const auto& e : s)
//		cout << e << " ";
//	cout << endl;
//
//}

//template<class T>
//void printSet(const set<T, greater<T>>& s)
//{
//	for (const auto& e : s)
//		cout << e << " ";
//	cout << endl;
//}
//
//void test()
//{
//	int arr[] = { 1, 9, 13, 10, 15, 6, 7, 8, 8 };
//	set<int, greater<int>> s2(arr, arr + sizeof(arr) / sizeof(arr[0]));
//	printSet(s2);
//}

//void test()
//{
//	set<int> s;
//	int arr[] = { 1, 9, 13, 10, 15, 6, 7, 8, 8};
//	//set不存放重复数据，天然去重
//	set<int> s2(arr, arr + sizeof(arr) / sizeof(arr[0]));
//
//	//set迭代器不支持修改，底层是搜索树，若修改可能会改变搜索树的结构
//	set<int>::iterator it = s2.begin();
//	//set迭代器遍历，数据天然有序：本质迭代器进行中序遍历
//	while (it != s2.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	//正序逆序都是有序
//	set<int>::reverse_iterator rit = s2.rbegin();
//	while (rit != s2.rend())
//	{
//		cout << *rit << " ";
//		++rit;
//	}
//	cout << endl;
//
//
//	//pair<iterator,bool> insert (const value_type& val);
//	//插入成功：已有数据迭代器，false
//	pair<set<int>::iterator, bool> ret = s2.insert(5);
//	cout << *ret.first << " " << ret.second << endl;
//	//插入失败：插入数据迭代器，true
//	ret = s2.insert(0);
//	cout << *ret.first << " " << ret.second << endl;
//
//	//iterator insert(iterator position, const value_type& val);
//	//position只是建议，插入的数据不一定在position位置之前
//	auto it1 = s2.insert(s2.end(), 3);
//	printSet(s2);
//	cout << *it1 << endl;
//	//template <class InputIterator>
//	//void insert(InputIterator first, InputIterator last);
//	int arr1[] = { 2, 89, 56, 78 };
//	s2.insert(arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]));
//	printSet(s2);
//
//
//	//void erase (iterator position);
//	//s2.erase(s2.end());出错
//	//erase:不能传非法位置：比如end
//	s2.erase(s2.begin());
//	printSet(s2);
//
//	//size_type erase(const value_type& val);
//	size_t re = s2.erase(2);
//	cout << re << endl;
//	re = s2.erase(1000);
//	cout << re << endl;
//
//	//void erase (iterator first, iterator last);
//	//erase:前闭后开
//	s2.erase(++s2.begin(), --s2.end());
//	printSet(s2);
//
//	//find
//	//iterator find (const value_type& val) const;
//	//返回的迭代器等于end就说明没有，如果不等于迭代器就说明map中有这个元素,返回的就是元素所在位置
//	if (s2.find(20) == s2.end())
//		cout << "没有找到20" << endl;
//	else
//		cout << *(s2.find(20)) << endl;
//
//	if (s2.find(1) == s2.end())
//		cout << "没有找到1" << endl;
//	else
//		cout << *(s2.find(1)) << endl;
//
//	//count
//	//size_type count(const value_type& val) const;
//	//如果找到返回1，找不到返回0
//	cout << s2.count(20) << endl;
//	cout << s2.count(89) << endl;
//}

int main()
{
	test();
	return 0;
}