#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<assert.h>
using namespace std;

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

	String(const char* str = "")
	{
		_size = strlen(str);
		_data = new char[_size + 1];
		_capacity = _size;

		strcpy(_data, str);
	}

	//String(const String& str)
	//{
	//	_size = str._size;
	//	//开辟空间
	//	_data = new char[_size + 1];
	//	_capacity = str._capacity;

	//	//拷贝
	//	strcpy(_data, str._data);
	//}

	void Swap(String& str)
	{
		swap(_data, str._data);
		swap(_size, str._size);
		swap(_capacity, str._capacity);
	}

	String(const String& str)
		:_data(nullptr)
		, _size(0)
		, _capacity(0)
	{
		String tmp(str._data);
		Swap(tmp);
	}

	String& operator=(String str)
	{
		Swap(str);
		return *this;
	}

	//String& operator=(const String& str)
	//{
	//	if (this != &str) //保证不是自己给自己赋值
	//	{
	//		//先释放原有空间资源
	//		delete[] _data;
	//		//开辟新空间
	//		_size = str._size;
	//		_capacity = str._capacity;
	//		_data = new char[_size + 1];

	//		//将字符串拷贝到新空间
	//		strcpy(_data, str._data);
	//	}
	//	return *this;
 //	}
	
	~String()
	{
		if (_data)
		{
			delete[] _data;
			_data = nullptr;
			_size = _capacity = 0;
		}
	}

	size_t size() const
	{
		return _size;
	}

	size_t capacity() const
	{
		return _capacity;
	}

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

	void reserve(size_t n)
	{
		//增容
		if (n > _capacity)
		{
			//申请空间，要有'\0'的位置
			char *tmp = new char[n + 1];
			//将原有空间的内容拷贝到现有空间中
			strcpy(tmp, _data);
			//释放原有空间
			delete[] _data;
			_data = tmp;
			_capacity = n;
		}
	}

	void pushBack(const char& ch)
	{
		if (_size == _capacity)
		{
			size_t newC = _size == 0 ? 15 : 2 * _capacity;
			//增容
			reserve(newC);
		}
		_data[_size++] = ch;
		//添加结束字符'\0'
		_data[_size] = '\0';
	}

	void resize(size_t n, const char& ch)
	{
		//n > _capacity
		if (n > _capacity)
		{
			reserve(n);
		}
		//_capacity > n > _size
		if (n > _size)
		{
			memset(_data + _size, ch, sizeof(char)* (n - _size));
		}
		//_size > n
		_size = n;
		//末尾添加'\0'
		_data[_size] = '\0';
	}

	void append(const char* str)
	{
		//检查容量
		size_t len = strlen(str);
		if (_size + len > _capacity)
		{
			reserve(_size + len);
		}
		//尾插字符串
		memcpy(_data + _size, str, sizeof(char)* len);
		//更新_size
		_size = _size + len;
		//末尾添加'\0'
		_data[_size] = '\0';
	}

	//
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

	String& operator+=(const char& ch)
	{
		pushBack(ch);
		return *this;
	}

	void insert(size_t pos, const char& ch)
	{
		//检查位置有效性
		assert(pos <= _size);
		//检查容量
		if (_size == _capacity)
		{
			size_t newC = _capacity == 0 ? 15 : 2 * _capacity;
			reserve(newC);
		}
		
		//移动元素:从后向前移动
		size_t end = _size + 1;
		while (end > pos)
		{
			_data[end] = _data[end - 1];
			--end;
		}
		//插入字符
		_data[pos] = ch;
		//更新_size
		_size++;
	}

	void insert(size_t pos, const char* ptr)
	{
		//检查位置
		assert(pos <= _size);
		//检查容量
		size_t len = strlen(ptr);
		if (_size + len > _capacity)
		{
			reserve(_size + len);
		}
		//移动字符串：从后向前
		size_t end = _size + len;
		while (end >= pos + len)
		{
			_data[end] = _data[end - len];
			--end;
		}
		//插入字符串
		memcpy(_data + pos, ptr, sizeof(char)* len);
		_size = _size + len;
	}

	void erase(size_t pos, size_t len)
	{
		//检查位置有效性
		assert(pos < _size);
		if (pos + len > _size)
		{
			_size = pos;
			_data[_size] = '\0';
		}
		else
		{
			//移动元素：从前向后移动
			size_t end = pos + len;

			while (end <= _size)
			{
				_data[end - len] = _data[end];
				++end;
			}
			//更新位置
			_size -= len;
		}
	}

	size_t find(const char& ch, size_t pos = 0)
	{
		for (size_t i = pos; i < _size; i++)
		{
			if (ch == _data[i])
				return i;
		}
		return npos;
	}

	size_t find(const char* str, size_t pos = 0)
	{
		for (size_t i = pos; i < _size; i++)
		{
			char* ptr = strstr(_data + pos, str);
			if (ptr)
			{
				return ptr - _data;
			}
		}
		return npos;
	}

private:
	char* _data;
	size_t _size;
	size_t _capacity;
	static const size_t npos;
};

const size_t String::npos = -1;

istream& operator>>(istream& in, String& str)
{
	char ch;
	while (ch = getchar())
	{
		if (ch == ' ' || ch == '\n' || ch == '\t')
			break;
		str += ch;
	}
	return in;
}

ostream& operator<<(ostream& out, const String& str)
{
	for (const auto& e : str)
	{
		out << e;
	}
	return out;
}

void printFor(const String& str)
{
	for (const auto& e : str)
	{
		cout << e;
	}
	cout << endl;
}

void test()
{
	String str;
	cin >> str;
	cout << str;
}

//void test()
//{
//	String str("hello is world is");
//	size_t ret = str.find("o", 6);
//	cout << ret << endl;
//}

//void test()
//{
//	String str("hello is world is");
//	size_t ret = str.find("is", 8);
//	cout << ret << endl;
//}

//void test()
//{
//	String str("1234helloworld");
//	str.erase(3, 5);
//	printFor(str);
//	str.erase(3, 8);
//	printFor(str);
//}

//void test()
//{
//	String str("123");
//	str.insert(1, "hello");
//	printFor(str);
//}

//void test()
//{
//	String str("abc");
//	str.insert(1, '2');
//}



//void test()
//{
//	String str("abc");
//	String str1;
//	str1 = str + "cde" + "def";
//
//}

//void test()
//{
//	String str("hello");
//	str += 'a';
//}

//void test()
//{
//	String str("abc");
//	str += "def";
//}

//void test()
//{
//	String str("123");
//	String str1("456");
//	str += str1;
//}

//void test()
//{
//	String str("abcd");
//	str.append("efd");
//}

//void test()
//{
//	String str("abcd");
//	str.resize(10, 'z');
//}

//void test()
//{
//	String str("abc");
//	str.pushBack('a');
//	str.pushBack('b');
//	str.pushBack('c');
//	str.pushBack('d');
//}

//void test()
//{
//	String str("abc");
//	cout << str.capacity() << endl;
//	str.reserve(20);
//	cout << str.capacity() << endl;
//}

//void test()
//{
//	String str("abc");
//	for (size_t i = 0; i < str.size(); i++)
//	{
//		cout << str[i] << " ";
//	}
//	cout << endl;
//}

//void test()
//{
//	String str("abcd");
//	for (const auto& e : str)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}

//void test()
//{
//	String str("abc");
//	String str1("abcd");
//	str = str1;
//}

//void test()
//{
//	String str("abc");
//}

//void test()
//{	String str1("abc");
//	String str2(str1);
//}


int main()
{
	test();
	return 0;
}