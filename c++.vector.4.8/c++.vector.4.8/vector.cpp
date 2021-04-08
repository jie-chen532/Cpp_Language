#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string.h>
#include<assert.h>
using namespace std;

class String
{
public:
	String(const char* str = "")
		:_start(new char[strlen(str) + 1])
	{
		strcpy(_start, str);
	}

	//��������
	String(const String& str)
		:_start(nullptr)
	{
		String tmp(str._start);
		swap(tmp._start, _start);
	}

	//��ֵ
	String& operator=(String str)
	{
		swap(str._start, _start);
		return *this;
	}

	~String()
	{
		if (_start)
		{
			delete[] _start;
			_start = nullptr;
		}
	}
private:
	char* _start;
};

template<class T>
class Vector
{
public:
	typedef T* iterator;
	typedef const T* const_iterator;

	Vector()
		:_start(nullptr)
		, _finish(nullptr)
		, _endOfStorage(nullptr)
	{}

	Vector(size_t n, const T& val = T())
		:_start(new T[n])
		, _finish(_start + n)
		, _endOfStorage(_start + n)
	{
		for (size_t i = 0; i < n; i++)
		{
			_start[i] = val;
		}
	}

	template<class InputIterator>
	Vector(InputIterator first, InputIterator last)
		:_start(nullptr)
		, _finish(nullptr)
		, _endOfStorage(nullptr)
	//��Ϊ�еĵ�������֧�ּ������������Բ�֪��first��last֮���ж��ٸ�Ԫ�أ���̬���ٵĿռ��С�Ͳ�֪��
	//���Գ�ʼ������ָ�붼��Ϊnullptr���ȵ�pushBack�ھ��忪�ռ�
	{
		while (first != last)
		{
			pushBack(*first);
			first++;
		}
	}

	//β��
	void pushBack(const T& val)
	{
		//�������
		if (_finish == _endOfStorage)
		{
			size_t newC = _endOfStorage == nullptr ? 1 : 2 * capacity();
			//��������
			reserve(newC);
		}

		*_finish = val;
		//��ЧԪ�ظ�����1
		_finish++;
	}

	//��������
	void reserve(size_t n)
	{
		if (n > capacity())
		{
			//��¼����֮ǰ����ЧԪ�ظ���
			size_t count = size();
			//�ȿ�n����С�Ŀռ�
			T* tmp = new T[n];
			if (_start)
			{
				//��ԭ�����ݿ��������пռ�
				//ǳ��������vector�д�ŵ���string������ֶ����ͷŵ�����
				//memcpy(tmp, _start, sizeof(T)* size());
				//���
				for (size_t i = 0; i < count; i++)
				{
					tmp[i] = _start[i];
				}
				//�ͷ�ԭ�пռ�
				delete[] _start;
			}
			_start = tmp;
			//��ʱ����ʹ��size(),��Ϊ���ڵ�_finish��Ұָ��
			_finish = _start + count;
			_endOfStorage = _start + n;
		}
	}

	size_t size() const
	{
		return _finish - _start;
	}

	size_t capacity() const
	{
		return _endOfStorage - _start;
	}

	iterator begin()
	{
		return _start;
	}

	iterator end()
	{
		return _finish;
	}

	const_iterator begin() const
	{
		return _start;
	}

	const_iterator end() const
	{
		return _finish;
	}

	T& operator[](size_t pos)
	{
		assert(pos < size());
		return _start[pos];
	}

	const T& operator[](size_t pos) const
	{
		assert(pos < size());
		return _start[pos];
	}

	void resize(size_t n, const T& val = T())
	{
		//n > capacity
		if (n > capacity())
		{
			//reserve�л��������ָ���λ�ã��������ⲻ�ÿ������ݵ�����ʧЧ������
			reserve(n);
		}
		// capacity> n > size()
		if (n > size())
		{
			while (_finish != _start + n)
			{
				*_finish = val;
				_finish++;
			}
		}
		//n < size()
		_finish = _start + n;
	}

	void insert(iterator pos, const T& val)
	{
		assert(pos >= _start && pos <= _finish);
			//�������
			if (_finish == _endOfStorage)
			{
				//��¼pos��ƫ����
				size_t offset = pos - _start;
				//�������������ܻᵼ��pos��λ��ʧЧ
				size_t newC = _endOfStorage == nullptr ? 1 : 2 * capacity();
				reserve(newC);
				pos = _start + offset;
			}

			iterator tail = _finish;
			while (tail != pos)
			{
				*(tail) = *(tail - 1);
				--tail;
			}
			*pos = val;
			++_finish;
	}

	//����ֵ��ָ��ɾ������һ��Ԫ�ص�λ��
	iterator erase(iterator pos)
	{
		assert(pos >= _start && pos < _finish);
			iterator index = pos + 1;
			while (index != _finish)
			{
				*(index - 1) = *index;
				++index;
			}
			_finish--;
			return pos;
	}


	//βɾ
	void popBack()
	{
		if (size() > 0)
		{
			erase(end() - 1);
		}
	}


	//����
	~Vector()
	{
		if (_start)
		{
			delete[] _start;
			_start = nullptr;
			_finish = nullptr;
			_endOfStorage = nullptr;
		}
	}

private:
	//��һ��Ԫ�ص��׵�ַ
	iterator _start;
	//���һ����ЧԪ�صĽ�β
	iterator _finish;
	//�ռ�Ľ�β
	iterator _endOfStorage;
};

template<class T>
void printVector(const Vector<T>& vec)
{
	Vector<T>::const_iterator it = vec.begin();
	while (it != vec.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}

template<class T>
void printForVector(const Vector<T>& vec)
{
	for (const auto& e : vec)
	{
		cout << e << " ";
	}
	cout << endl;
}

template<class T>
void printOVector(const Vector<T>& vec)
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
}

void test()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	Vector<int> v1(arr, arr + sizeof(arr) / sizeof(arr[0]));
	Vector<int> v2(v1.begin(), v1.end());
	//printForVector(v2);
	//printVector(v2);
	printOVector(v2);
}

//void test()
//{
//	Vector<int> v1((size_t)3, 4);//4 4 4
//	v1.insert(v1.begin() + 1, 5);//4 5 4 4
//	v1.insert(v1.begin() + 1, 2);//4 2 5 4 4
//	v1.insert(v1.begin() + 1, 1);//4 1 2 5 4 4 
//	v1.insert(v1.begin() + 1, 0);//4 0 1 2 5 4 4
//	v1.pushBack(13);
//	v1.pushBack(10);
//	v1.pushBack(2);
//	v1.pushBack(1);
//	v1.popBack();
//	v1.popBack();
//	v1.popBack();
//	v1.erase(v1.begin() + 2);
//	//v1.resize(20,3);
//	printVector(v1);
//}

//void test()
//{
//	vector<int> v1(3, 4);
//	v1.insert(v1.begin() + 1, 5);
//}

//void test()
//{
//	Vector<string> v1;
//	v1.pushBack("abc");
//	v1.pushBack("def");
//	//β��������ַ����ͻ������Ϊ����������������ǳ����
//	v1.pushBack("hig");
//	v1.pushBack("lmn");
//}

//void test()
//{
//	vector<int> v2(5);
//	v2.reserve(20);
//}

//void test()
//{
//	Vector<int> v1;
//	Vector<char> v2;
//	Vector<int*> v3;
//}

int main()
{
	test();
	return 0;
}