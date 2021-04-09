#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
using namespace std;

template<class T>
struct ListNode
{
	struct ListNode<T>* _prev;
	struct ListNode<T>* _next;
	T _data;

	ListNode(const T& val = T())
		: _data(val)
	    , _prev(nullptr)
	    ,_next(nullptr)
	{}
};

template<class T>
struct ListIterator
{
	typedef ListNode<T> Node;

	//因为指针不能满足我们的需求，所以要封装一个迭代器
	//本质就是迭代器对象
	Node* _node;

	ListIterator(Node* node)
		:_node(node)
	{}

	//*iterator
	T& operator*()
	{
		return _node->_data;
	}

	//++iterator
	ListIterator<T>& operator++()
	{
		_node = _node->_next;
		return *this;
	}


	//iterator++
	ListIterator<T> operator++(int)
	{
		ListIterator<T> tmp(_node);
		_node = _node->_next;
		return tmp;
	}

	//--iterator
	ListIterator<T> operator--()
	{
		_node = _node->_prev;
		return *this;
	}

	//主要针对于自定义结构
	T* operator->()
	{
		return &_node->_data;
	}

	bool operator!=(const ListIterator<T>& iterator)
	{
		return _node != iterator._node;
	}

	bool operator==(const ListIterator<T>& iterator)
	{
		return _node == iterator._node;
	}
};


template<class T>
class List
{
public:
	typedef ListNode<T> Node;
	typedef ListIterator<T> iterator;

	iterator begin()
	{
		return iterator(_head->_next);
	}

	iterator end()
	{
		return iterator(_head);
	}

	List()
		:_head(new Node)
	{
		//构造循环结构
		_head->_next = _head->_prev = _head;
	}

	List(size_t n, const T& val = T())
		:_head(new Node)
	{
		//构造循环结构
		_head->_next = _head->_prev = _head;
		//list增加容量，不会导致迭代器失效，因为指针指向不会发生变化
		for (size_t i = 0; i < n; i++)
		{
			pushBack(val);
		}
	}

	template<class InputIterator>
	List(InputIterator first, InputIterator last)
		:_head(new Node)
	{
		//循环结构
		_head->_next = _head->_prev = _head;
		while (first != last)
		{
			pushBack(*first);
			first++;
		}
	}

	void pushBack(const T& val)
	{
		Node* newNode = new Node(val);

		Node* tail = _head->_prev;
		tail->_next = newNode;
		newNode->_prev = tail;

		_head->_prev = newNode;
		newNode->_next = _head;
	}

	~List()
	{
		if (_head)
		{
			Node* cur = _head->_next;
			while (cur != _head)
			{
				Node* next = cur->_next;
				delete cur;
				cur = next;
			}
			delete _head;
			_head = nullptr;
		}
	}


private:
	Node* _head;
};


template<class T>
void printList(List<T>& lst)
{
	List<T>::iterator it = lst.begin();
	while (it != lst.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

struct A
{
	A(int a = 5)
		:_a(a)
	{}
	int _a;
};

void test()
{
	List<A> lst;
	A a;
	lst.pushBack(a);
	lst.pushBack(a);
	List<A>::iterator it = lst.begin();
	cout << it->_a << endl;
}

//void test()
//{
//	//List<int> lst;
//	List<int> lst((size_t)3, 5);
//	lst.pushBack(6);
//	lst.pushBack(7);
//	lst.pushBack(8);
//	lst.pushBack(9);
//	printList(lst);
//}

int main()
{
	test();
	return 0;
}