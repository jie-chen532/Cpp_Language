#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

template<class T>
struct ListNode{
	T _data;
	struct ListNode<T>* _prev;
	struct ListNode<T>* _next;

	ListNode(const T& val = T())
		:_data(val)
		, _prev(nullptr)
		, _next(nullptr)
	{
	}
};

template<class T, class Ref, class Ptr>
struct ListIterator
{
	typedef ListNode<T> Node;
	typedef ListIterator<T, Ref, Ptr> Self;

	Node* _node;

	ListIterator(Node* node)
		:_node(node)
	{}

	//*iterator
	//T& operator*()
	Ref operator*()
	{
		return _node->_data;
	}

	//T* operator->()
	Ptr operator->()
	{
		return &_node->_data;
	}

	//++iterator
	Self& operator++()
	{
		_node = _node->_next;
		return *this;
	}

	//iterator++
	Self operator++(int)
	{
		Self tmp(_node);
		_node = _node->_next;
		return tmp;
	}

	//--iterator
	Self& operator--()
	{
		_node = _node->_prev;
		return *this;
	}

	//!=
	bool operator!=(const Self& it)
	{
		return _node != it._node;
	}
	//==
	bool operator==(const Self& it)
	{
		return _node == it._node;
	}
};

template<class T>
class List
{
public:
	typedef ListNode<T> Node;
	//typedef ListIterator<T> iterator;

	typedef ListIterator<T, T&, T*> iterator;

	typedef ListIterator<T, const T&, const T*> const_iterator;

	iterator begin()
	{
		return iterator(_head->_next);
	}

	iterator end()
	{
		return iterator(_head);
	}

	const_iterator begin() const
	{
		return const_iterator(_head->_next);
	}

	const_iterator end() const
	{
		return const_iterator(_head); 
	}

	List()
		:_head(new Node)
	{
		//循环结构
		_head->_next = _head->_prev = _head;
	}

	List(size_t n, const T& val = T())
		:_head(new Node)
	{
		//循环结构
		_head->_next = _head->_prev = _head;
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
			++first;
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

	void insert(iterator pos, const T& val)
	{
		Node* newNode = new Node(val);

		Node* cur = pos._node;
		Node* prev = cur->_prev;
		
		prev->_next = newNode;
		newNode->_prev = prev;

		newNode->_next = cur;
		cur->_prev = newNode;
	}

	iterator erase(iterator pos)
	{
		if (pos._node == _head)
			return pos;
		Node* cur = pos._node;

		Node* prev = cur->_prev;
		Node* next = cur->_next;

		delete cur;

		prev->_next = next;
		next->_prev = prev;

		return iterator(next);
	}

	void popBack()
	{
		erase(--end());
	}

	void popFront()
	{
		erase(begin());
	}


	void pushFront(const T& val)
	{
		insert(begin(), val);
	}

	//深拷贝
	List(const List<T>& lst)
		:_head(new Node)
	{
		//循环结构
		_head->_prev = _head->_next = _head;

		/*Node* cur = lst._head->_next;
		while (cur != lst._head)
		{
			pushBack(cur->_data);
			cur = cur->_next;
		}*/

		for (const auto& e : lst)
		{
			pushBack(e);
		}
	}

	List<T>& operator=(List<T> list)
	{
		swap(_head, list._head);
		return *this;
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
void printList(const List<T>& lst)
{
	List<T>::const_iterator it = lst.begin();
	while (it != lst.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}


void test()
{
	List<int> ls1;
	ls1.pushBack(1);
	ls1.pushBack(2);
	ls1.pushBack(3);
	ls1.pushBack(4);
	ls1.pushBack(5);
	cout << "ls1:";
	printList(ls1);

	List<int> ls2;
	ls2.pushBack(4);
	ls2.pushBack(5);
	ls2.pushBack(6);
	ls2.pushBack(7);
	ls2.pushBack(8);
	cout << "ls2:";
	printList(ls2);

	List<int> ls3;
	ls3.pushBack(1);
	ls3.pushBack(2);
	cout << "ls3:";
	printList(ls3);

	ls1 = ls3 = ls2;
	cout << "ls3:";
	printList(ls3);
	cout << "ls1:";
	printList(ls1);
}

//void test()
//{
//	List<int> lst;
//	lst.pushBack(1);
//	lst.pushBack(2);
//	lst.pushBack(3);
//	lst.pushBack(4);
//	cout << "lst:";
//	printList(lst);
//	List<int> lst2(lst);
//	cout << "lst2:";
//	printList(lst2);
//}

//void test()
//{
//	List<int> lst;
//	lst.pushFront(5);
//	lst.pushFront(4);
//	lst.pushFront(3);
//	lst.pushFront(2);
//	lst.pushFront(1);
//	lst.pushFront(7);
//	lst.pushFront(8);//8 7 1 2 3 4 5
//	printList(lst);
//	List<int>::iterator it = lst.begin();
//	it = lst.erase(++it);//8 1 2 3 4 5
//	printList(lst);
//	it = lst.erase(++it);//8 1 3 4 5
//	printList(lst);
//	it = lst.erase(++it);//8 1 3 5
//	printList(lst);
//	it = lst.end();
//	lst.erase(it);
//	printList(lst);
//}

//void test()
//{
//	List<int> lst;
//	List<int>::iterator it = lst.end();
//	lst.insert(it, 5);//5
//	lst.insert(it, 4);//5 4
//	lst.insert(it, 3);//5 4 3
//	lst.insert(it, 2);//5 4 3 2
//	printList(lst);
//}

//void test()
//{
//	List<int> lst;
//	lst.pushBack(1);
//	lst.pushBack(2);
//	lst.pushBack(3);
//	lst.pushBack(4);
//	printList(lst);
//}

struct A
{
	int _b;
	int _c;

	A(int b = 10, int c = 5)
		:_b(b)
		, _c(c)
	{}
};

//void test()
//{
//	List<A> lst;
//	A a;
//	lst.pushBack(a);
//	List<A>::iterator it = lst.begin();
//	//想要访问自定义结构体中的成员
//	//cout << (*it)._b << endl;
//	cout << it->_b << endl;
//	
//	it->_b;
//	it.operator->()->_b;
//	it->_b;
//
//	//A* pa = &a;
//	//cout << pa->_b << endl;
//}

//void test()
//{
//	List<int> v1;
//	List<int> v2((size_t)3, 2);
//	int arr[] = { 1, 2, 3, 4 };
//	List<int> v3(arr, arr + sizeof(arr) / sizeof(arr[0]));
//	printList(v3);
//}

int main()
{
	test();
	return 0;
}