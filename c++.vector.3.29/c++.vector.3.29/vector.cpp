#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<vector>
using namespace std;

void test()
{
	vector<int> v(5, 3);
	vector<int>::iterator it = v.begin();
	cout << *it << endl;
	v.erase(it);
	cout << *it << endl;
}

//void test()
//{
//	vector<int> v(5, 2);
//	vector<int>::iterator it = v.begin();
//	cout << *it << endl;
//	v.reserve(30);
//	it = v.begin();
//	cout << *it << endl;
//}

//template<class T>
//void printIterator(const vector<T>& vec)
//{
//	vector<T>::const_iterator it = vec.begin();
//	while (it != vec.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//}
//
//template<class T>
//void printReverseIterator(const vector<T>& vec)
//{
//	vector<T>::const_reverse_iterator it = vec.rbegin();
//	while (it != vec.rend())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//}
//
//template<class T>
//void printFor(const vector<T>& vec)
//{
//	for (const auto& e : vec)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}
//
//template<class T>
//void printFor1(const vector<T>& vec)
//{
//	for (size_t i = 0; i < vec.size(); i++)
//	{
//		cout << vec[i] << " ";
//	}
//	cout << endl;
//}


//void test()
//{
//	//迭代器失效
//	vector<int> v(2, 3);
//	vector<int>::iterator it = v.begin();
//	v.resize(30);
//	it = v.begin();
//}

//void test()
//{
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(4);
//	v.push_back(3);
//	v.push_back(6);
//	v.push_back(9);
//	v.push_back(7);
//	v.push_back(5);
//
//	printFor(v);
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		if (*it % 2 == 0)
//		{
//			it = v.erase(it);
//		}
//		else
//			it++;
//	}
//	printFor(v);
//}


//class A
//{
//public:
//	A(int a, int b)
//		:_a(a)
//		, _b(b)
//	{}
//	friend ostream& operator<<(ostream& out, A& a);
//private:
//	int _a;
//	int _b;
//};
//
//ostream& operator<<(ostream& out, A& a)
//{
//	out << "a:" << a._a << "   " << "b:" << a._b << endl;
//	return out;
//}


//void test()
//{
//	vector<A> v;
//	v.insert(v.begin(), A(20, 30));
//	A a(1, 2);
//	v.insert(v.begin(), a);
//	
//	//emplace--->自定义类型比较方便
//	v.emplace(v.end(), a);
//	v.emplace(v.begin() + 1, 100, 200);
//
//	vector<A> v1;
//	v1.swap(v);
//	v1.clear();
//}

//void test()
//{
//	vector<int> v(2, 3);
//	vector<int> v1(3, 4);
//	vector<int> v2(4, 7);
//	printFor(v);
//	printFor(v1);
//	v.swap(v1);
//	printFor(v);
//	printFor(v1);
//	v1.swap(v2);
//	printFor(v1);
//	printFor(v2);
//}

//void test()
//{
//	//void assign(InputIterator first, InputIterator last);
//	//void assign(size_type n, const value_type& val);
//	vector<int> v(3, 2);
//	printFor(v);
//	v.assign(5, 5);
//	printFor(v);
//
//	vector<int> v1(v.begin(), v.end());
//	printFor(v1);
//
//	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'h', 'i', 'j', 'k', 'l', 'm', 'n'};
//	vector<char> v3(arr, arr + sizeof(arr) / sizeof(arr[0]));
//	printFor(v3);
//	v3.pop_back();
//	printFor(v3);	
//	v3.pop_back();
//	printFor(v3);
//	v3.pop_back();
//	printFor(v3);
//	v3.pop_back();
//	printFor(v3);
//	v3.pop_back();
//	printFor(v3);	
//	v3.pop_back();
//	printFor(v3);
//
//
//	//iterator insert(iterator position, const value_type& val);
//	v3.insert(v3.begin(), 'z');
//	printFor(v3);
//	v3.insert(v3.end(), 'a');
//	printFor(v3);
//	//void insert(iterator position, size_type n, const value_type& val);
//	v3.insert(v3.begin() + 2, 4, 'q');	
//	printFor(v3);
//		//template <class InputIterator>
//	//void insert(iterator position, InputIterator first, InputIterator last);
//	vector<char> v4(4, 'a');
//	v3.insert(v3.begin() + 4, v4.begin(), v4.end());
//	printFor(v3);
//
//	//erase前闭后开
//	//iterator erase(iterator position);
//	v3.erase(v3.begin());
//	printFor(v3);
//	//iterator erase(iterator first, iterator last);
//	v3.erase(v3.begin() + 3, v3.end() - 6);
//	printFor(v3);
//}

//void test()
//{
//	vector<int> v1;
//	cout << v1.size() << endl;
//	cout << v1.capacity() << endl;
//
//	v1.reserve(30);
//	v1.resize(10);
//	v1.shrink_to_fit();
//	cout << v1.size() << endl;
//	cout << v1.capacity() << endl;
//
//	v1.reserve(1000);
//	v1.resize(50);
//	/*v1.shrink_to_fit();*/
//	cout << v1.size() << endl;
//	cout << v1.capacity() << endl;
//}

//void test()
//{
//	vector<int> v1;
//	vector<char> v2;
//	vector<int*> v3;
//	vector<double> v4;
//
//	cout << v1.max_size() << endl;
//	cout << v2.max_size() << endl;
//	cout << v3.max_size() << endl;
//	cout << v4.max_size() << endl;
//
//	//void resize (size_type n, value_type val = value_type());
//	v1.resize(3, 4);
//	printFor(v1);
//	cout << v1.size() << endl;
//	v1.resize(5, 10);
//	printFor(v1);
//	cout << v1.size() << endl;
//	v2.resize(10, 'a');
//	printFor(v2);
//	cout << v2.size() << endl;
//	v2.resize(3, 'b');
//	printFor(v2);
//	cout << v2.size() << endl;
//}

//void test()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 5, 7, 8, 9, 10 };
//	vector<int> v1(arr, arr + sizeof(arr)/sizeof(arr[0]));
//	for (size_t i = 0; i < v1.size(); i++)
//	{
//		//简写
//		v1[i] = 2;
//		cout << v1.operator[](i) << " ";
//	}
//	cout << endl;
//	//[]越界：debug版本assert错误，release版本不会检查错误
//	//cout << v1[13] << endl;
//	//at越界，抛异常
//	v1.at(100) = 30;
//}

//void test()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 5, 7, 8, 9, 10 };
//	vector<int> v1(arr, arr + sizeof(arr)/sizeof(arr[0]));
//	vector<int> v2(v1.begin() + 2, v1.end());
//	printIterator(v1);
//	printIterator(v2);
//	printReverseIterator(v1);
//	printReverseIterator(v2);
//	printFor(v1);
//	printFor(v2);
//
//	//A a(10, 20);
//	//cout << a;
//
//	printFor1(v1);
//}

//void test()
//{
//	vector<int> v1;
//	vector<char> v3;
//	vector<int> v2(3);
//	vector<int> v4(3, 2);
//
//	vector<A> v5;
//	vector<A> v6(3, A(10, 20));
//
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
//	vector<int> v7(arr, arr + sizeof(arr)/sizeof(arr[0]));
//	vector<int*> v8(5);
//
//	vector<int> v9(v7.begin(), v7.end());
//
//	vector<int>::iterator it = v7.begin();
//	while (it != v7.end())
//	{
//		cout << *it << " ";
//		//*it = 5;
//		it++;
//	}
//	cout << endl;
//
//	vector<int>::reverse_iterator it1 = v7.rbegin();
//	while (it1 != v7.rend())
//	{
//		cout << *it1 << " ";
//		it1++;
//	}
//	cout << endl;
//
//	vector<int>::const_reverse_iterator it2 = v7.rbegin();
//	while (it2 != v7.rend())
//	{
//		cout << *it2 << " ";
//		it2++;
//		//*it2 = 100;
//	}
//	cout << endl;
//}

int main()
{
	test();
	return 0;
}
