#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<vector>
#include<assert.h>

class String
{
public:

	typedef char* iterator;
	typedef const char* const_iterator;

	iterator begin()
	{
		return _data;
	}

	iterator end()
	{
		return _data + _size;
	}

	const_iterator begin() const
	{
		return _data;
	}

	const_iterator end() const
	{
		return _data + _size;
	}

	//���캯��
	String(const char* str = "")
	{
		_size = strlen(str);
		_data = new char[_size + 1];
		_capacity = _size; 
		strcpy(_data, str);
	}

	void Swap(String& str)
	{
		swap(_data, str._data);
		swap(_size, str._size);
		swap(_capacity, str._capacity);
	}

	//��������
	String(const String& str)
		:_data(nullptr)
		, _size(0)
		, _capacity(0)
	{
		String tmp(str._data);
		Swap(tmp);
	}

	//���ظ�ֵ�����
	String& operator=(String str)
	{
		Swap(str);
		return *this;
	}

	//����
	~String()
	{
		if (_data)
		{
			delete[] _data;
			_data = nullptr;
			_size = 0;
			_capacity = 0;
		}
	}

	size_t size() const
	{
		return _size;
	}

	//����[]
	char& operator[](size_t pos)
	{
		assert(pos < _size);
		return *(_data + pos);
	}

	const char& operator[](size_t pos) const
	{
		assert(pos < _size);
		return _data[pos];
	}

	void reserve(size_t size)
	{

	}

	//β���ַ�
	void push_back(const char& ch)
	{
		if (_size == _capacity)
		{
			size_t newC = _capacity == 0 ? 15 : 2 * _capacity;
			reserve(newC);
		}
		_data[_size++] = ch;
		_data[_size] = '\0';
	}

private:
	char* _data;
	int _size; //��ЧԪ�صĸ���
	int _capacity;//��Ч����
};

void test()
{
	String str("123");
	String str2("456");
	String str1(str);
	str2 = str;
}

int main()
{
	test();
	return 0;
}
//
//class String
//{
//public:
//	//���캯��
//	String(const char* str = "")
//		:_data(new char[strlen(str) + 1])  //����Ҫ��'\0����λ��
//	{
//		strcpy(_data, str);
//	}
//
//	//�������쾭��д��
//	//String(const String& str)
//	//	:_data(new char[strlen(str._data) + 1])
//	//{
//	//	strcpy(_data, str._data);
//	//}
//
//	//���������ִ�д��
//	String(const String& str)
//		:_data(nullptr)
//	{
//		String tmp(str._data);
//		swap(_data, tmp._data);
//	}
//
//	////���ظ�ֵ�����
//	//String& operator=(const String& str)
//	//{
//	//	if (str._data != this->_data)
//	//	{
//	//		delete[] _data;
//	//		_data = new char[strlen(str._data) + 1];
//	//		strcpy(_data, str._data);
//	//	}
//	//	return *this;
//	//}
//
//	//���ظ�ֵ������ִ�д��
//	String& operator=(String str)
//	{
//		swap(_data, str._data);
//		return *this;
//	}
//
//	//~��������
//	~String()
//	{
//		if (_data)
//		{
//			delete[] _data;
//			_data = nullptr;
//		}
//	}
//private:
//	char* _data;
//};
//
//void test()
//{
//	String str("123");
//	String str1("456");
//	str = str1;
//}
//
//int main()
//{
//	test();
//	return 0;
//}

//void test()
//{
//	vector<int> v(5, 3);
//	vector<int>::iterator it = v.begin();
//	cout << *it << endl;
//	it = v.erase(it);
//	cout << *it << endl;
//}

//void test()
//{
//	int arr[] = { 1, 2, 3, 4, 7, 8, 12 };
//	vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		if (*it % 2 == 0)
//			it = v.erase(it);
//		else
//			it++;
//	}
//}
//
//int main()
//{
//	test();
//	return 0;
//}