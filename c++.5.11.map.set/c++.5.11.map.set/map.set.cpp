#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<set>
#include<map>
#include<functional>

void test()
{
	//multimap:key��value�������ظ�
	//multimapû��[]�Ĳ�������Ϊ�ж��key����֪�����ĸ�value��ֵ
}

//void test()
//{
//	int arr[] = { 1, 10, 2, 5, 7, 5, 3, 10, 9 };
//	//multiset:���Դ���ظ�������
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
//	//map�е�������pair,����ֱ�����pair����Ϊpairû������<<
//	pair<int, int> arr[] = { pair<int, int>(3, 5), pair<int, int>(1, 4), pair<int, int>(2, 5),
//		                     pair<int, int>(3,6)};
//	map<int, int> m(arr, arr + sizeof(arr) / sizeof(arr[0]));
//	printMap(m);
//	//���������ʵ�˳��key�����������
//	//map��key�����ظ���value�����ظ�
//	//map�����޸�key�������޸�value
//
//	//operator[]:����д������
//	//at�ӿں�operator[]����atִ�в�����������keyֵ�����ڣ������쳣
//
//	//���ֳ����Ĳ��뷽ʽ
//	//1.����pair���캯����������
//	auto ret = m.insert(pair<int, int>(7, 6));
//	cout << ret.first->first << "--->" << ret.first->second << "  insert:" << ret.second << endl;
//
//	//2.����make_pair������������
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
//	//���Ұ�key����
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
//	//set������ظ����ݣ���Ȼȥ��
//	set<int> s2(arr, arr + sizeof(arr) / sizeof(arr[0]));
//
//	//set��������֧���޸ģ��ײ��������������޸Ŀ��ܻ�ı��������Ľṹ
//	set<int>::iterator it = s2.begin();
//	//set������������������Ȼ���򣺱��ʵ����������������
//	while (it != s2.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	//��������������
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
//	//����ɹ����������ݵ�������false
//	pair<set<int>::iterator, bool> ret = s2.insert(5);
//	cout << *ret.first << " " << ret.second << endl;
//	//����ʧ�ܣ��������ݵ�������true
//	ret = s2.insert(0);
//	cout << *ret.first << " " << ret.second << endl;
//
//	//iterator insert(iterator position, const value_type& val);
//	//positionֻ�ǽ��飬��������ݲ�һ����positionλ��֮ǰ
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
//	//s2.erase(s2.end());����
//	//erase:���ܴ��Ƿ�λ�ã�����end
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
//	//erase:ǰ�պ�
//	s2.erase(++s2.begin(), --s2.end());
//	printSet(s2);
//
//	//find
//	//iterator find (const value_type& val) const;
//	//���صĵ���������end��˵��û�У���������ڵ�������˵��map�������Ԫ��,���صľ���Ԫ������λ��
//	if (s2.find(20) == s2.end())
//		cout << "û���ҵ�20" << endl;
//	else
//		cout << *(s2.find(20)) << endl;
//
//	if (s2.find(1) == s2.end())
//		cout << "û���ҵ�1" << endl;
//	else
//		cout << *(s2.find(1)) << endl;
//
//	//count
//	//size_type count(const value_type& val) const;
//	//����ҵ�����1���Ҳ�������0
//	cout << s2.count(20) << endl;
//	cout << s2.count(89) << endl;
//}

int main()
{
	test();
	return 0;
}