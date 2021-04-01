#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<string>
#include<assert.h>

class String
{
public:
	//迭代器
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

	//构造函数
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

	//拷贝构造
	String(const String& str)
		:_data(nullptr)
		, _size(0)
		,_capacity(0)
	{
		String tmp(str._data);
		Swap(tmp);
	}

	//重载赋值运算符
	String& operator=(String str)
	{
		Swap(str);
		return *this;
	}

	//析构函数
	~String()
	{
		if (_data)
		{
			delete[] _data;
			_data = nullptr;
			_size = _capacity = 0;
		}
	}

	//重载[]
	char& operator[](size_t pos)
	{
		assert(pos < _size);
		return _data[pos];
	}

	const char& operator[](size_t pos) const
	{
		assert(pos < _size);
		return _data[pos];
	}

	size_t size() const
	{
		return _size;
	}

	//增容
	void reserve(size_t n)
	{
		if (n > _capacity)
		{
			char* tmp = new char[n + 1]; // 也要给'\0'留位置
			strcpy(tmp, _data);
			delete[] _data;
			_data = tmp;
			_capacity = n;
		}
	}

	//尾插一个字符
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

	//增加有效元素
	void resize(size_t n, const char& ch = '\0')
	{
		if (n > _capacity)
		{
			reserve(n);
		}
		// _size > n && _size <= _capacity
		if (n > _size)
		{
			//while (_size < n)
			//{
			//	_data[_size] = ch;
			//	_size++;
			//}
			memset(_data + _size, ch, sizeof(char)* (n - _size));
		}
		//n < _size;
		_size = n;
		_data[_size] = '\0';
	}

	//追加
	void append(const char* str)
	{
		size_t len = strlen(str);
		if (_capacity < _size + len)
		{
			reserve(_size + len);
		}
		memcpy(_data + _size, str, len * sizeof(char));
		_size = _size + len;
		_data[_size] = '\0';
	}

    //+=
	String& operator+=(const String& str)
	{
		append(str._data);
		return *this;
	}

	String& operator+=(const char* str)
	{
		append(str);
		return *this;
	}

	String& operator+=(const char ch)
	{
		push_back(ch);
		return *this;
	}

	//插入字符
	void insert(size_t pos, const char& ch)
	{
		assert(pos <= _size);
		if (_size == _capacity)
		{
			size_t newC = _capacity == 0 ? 15 : 2 * _capacity;
			reserve(newC);
		}

		size_t end = _size;
		while (end > pos)
		{
			_data[end] = _data[end - 1];
			end--;
		}
		_data[pos] = ch;
		_size++;
		_data[_size] = '\0';
	}

	//插入字符串
	void insert(size_t pos, const char* ptr)
	{
		assert(pos <= _size);
		//检查容量
		size_t len = strlen(ptr);
		if (_size + len > _capacity)
		{
			reserve(_size + len);
		}
		size_t end = _size + len;
		while (end > pos + len - 1)
		{
			_data[end] = _data[end - len];
			end--;
		}
		memcpy(_data + pos, ptr, len * sizeof(char));
		_size += len;
	}

	//erase
	void erase(size_t pos, size_t len)
	{
		assert(pos < _size);
		if (len + pos >= _size)
		{
			_size = pos;
			_data[_size] = '\0';
		}
		else 
		{
			size_t end = pos + len;
			while (end <= _size)
			{
				_data[end - len] = _data[end];
				end++;
			}
			_size -= len;
		}
	}

	//find
	size_t find(const char& ch, size_t pos = 0)
	{
		for (size_t i = pos; i < _size; i++)
		{
			if (_data[i] == ch)
				return i;
		}
		return npos;
	}

	//查找字符串
	size_t find(const char* str, size_t pos = 0)
	{
		//strstr找到返回字符串的指针，没有找到返回nullptr
		char* ptr = strstr(_data + pos, str);
		if (ptr == nullptr)
			return npos;
		else
			return ptr - _data;
	}

	const char* c_str() const
	{
		return _data;
	}

private:
	char* _data;
	size_t _size;
	size_t _capacity;
	static const size_t npos;
};

const size_t String::npos = -1;

ostream& operator<<(ostream& out, const String& str)
{
	for (const auto& e : str)
		cout << e;
	return out;
}

istream& operator>>(istream& _cin, String& str)
{
	while (char ret = getchar())
	{
		if (ret == '\t' || ret == '\n' || ret == ' ')
			break;
		str += ret;
	}
	return _cin;
}

bool operator>(const String& str1, const String& str2)
{
	if (strcmp(str1.c_str(), str2.c_str()) > 0)
		return true;
	return false;
}

String operator+(const String& str1, const String& str2)
{
	String tmp = str1;
	tmp += str2;
	return tmp;
}

String operator+(const String& str1, const char* str2)
{
	String str = str1;
	str += str2;
	return str;
}

String operator+(const char& ch, const String& str2)
{
	String str;
	str += ch;
	str += str2;
	return str;
}

void printFor(const String& str)
{
	for (const auto& e : str)
	{
		cout << e;
	}
	cout << endl;
}


void printIterator(const String& str)
{
	String::const_iterator it = str.begin();
	while (it != str.end())
	{
		cout << *it;
		it++;
	}
	cout << endl;
}



void test()
{
	String str;
	String str1("123");
	str = 'a' + str1;
	//cout << str << endl;
	printFor(str);
	printIterator(str);
}

//void test()
//{
//	String str = "123";
//	str = str + "456";
//	cout << str << endl;
//	str =  'a' + str;
//	cout << str << endl;
//}

//void test()
//{
//	String str("123");
//	String str1("abc");
//	String str2;
//	str2 = str + str1;
//	cout << str2;
//}

//void test()
//{
//	String str;
//	cin >> str;
//	cout << str;
//}

//void printStr(const String& str)
//{
//	for (const auto& e : str)
//	{
//		cout << e;
//	}
//	cout << endl;
//}

//void test()
//{
//	String str("abcdefabcabcs");
//	//size_t ret = str.find('a', 4);
//	//cout << ret << endl;
//	size_t ret = str.find("abc", 9);
//	cout << ret << endl;
//}
//void test()
//{
//	String str("1234");
//	str.insert(2, '5');//12534
//	printStr(str);
//	str.insert(0, '5');//512534
//	printStr(str);
//	str.insert(6, '5');//5125345
//	printStr(str);
//	str.insert(1, "123");//5123125345
//	printStr(str);
//	str.erase(1, 3);//5125345
//	printStr(str);
//	str.erase(1, 8);//5125345
//	printStr(str);
//}

int main()
{
	test();
	return 0;
}