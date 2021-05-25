#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<vector>

//enum STATE
//{
//	EXIST,
//	DELETE,
//	EMPTY,
//};
//
//template<class K,class V>
//struct HashNode
//{
//	pair<K, V> _kv;
//	STATE _state = EMPTY;
//};
//
//template<class K, class V>
//class HashTable
//{
//public:
//	typedef HashNode<K, V> Node;
//
//	HashTable(size_t n = 10)
//		:_hash(n)
//		, _size(0)
//	{}
//
//	//负载因子：有效元素的个数/有效元素
//	//_size / _hash.size()
//	void checkCapacity()
//	{
//		//负载因子：0.6-0.8
//		//因为浮点数会有精度损失
//		if (_hash.size() == 0 || _size * 10 / _hash.size() >= 7)
//		{
//			//重新开辟表
//			int newC = _hash.size() == 0 ? 10 : 2 * _hash.size();
//			HashTable<K, V> newHt(newC);
//
//			for (int i = 0; i < _size; i++)
//			{
//				//把状态为EXIST的数插入新表中
//				if (_hash[i]._state == EXIST)
//					newHt.insert(_hash[i]._kv)
//			}
//			Swap(newHt);
//		}
//	}
//
//	void Swap(HashTable<K, V>& hs)
//	{
//		swap(_hash, hs._hash);
//		swap(_size, hs._size);
//	}
//
//	bool insert(const pair<K, V>& kv)
//	{
//		//容量检查
//		checkCapacity();
//		int idx = kv.first % _hash.size();
//		while (_hash[idx]._state != EMPTY)
//		{
//			if (_hash[idx] == EXIST && _hash[idx] == kv.first)
//				return false;
//			++idx;
//			//如果走到hash表的末尾，在重新开始查找
//			if (idx == _hash.size())
//				idx = 0;
//		}
//		_hash[idx]._kv = kv;
//		_hash[idx]._state = EXIST;
//		_size++;
//	}
//
//private:
//	//typedef HashNode<K, V> Node;
//	vector<Node> _hash;
//	size_t _size; //有效元素
//};


//开散列
//指针数组+单链表

//单链表的结点
template<class V>
struct HashNode
{
	V _val;
	HashNode<V>* _next;

	HashNode(const V& val)
		:_val(val)
		, _next(nullptr);
	{}
};

template<class K, class V, class KeyOfValue>
class HTable;

//iterator
//哈希表只有++，因为是单链表
template<class K, class V, class KeyOfValue>
struct HashIterator
{
	typedef HashIterator<V> Self;
	typedef HashNode<V> Node;
	typedef HTable<class K, class V, class KeyOfValue> ht;
	ht* _hptr;
	Node* _node;

	HashIterator(Node* node, ht* hptr)
		:_node(node)
		, _hptr(hptr)
	{}

	Self& operator++()
	{
		if (_node->_next)
			_node = _node->_next;
		else
		{
			//下一个非空链表的头结点
			KeyOfValue kov;
			int idx = kov(_node->_val) % _hptr->_ht.size();
			idx++;
			for (; idx < _hptr->_ht.size(); idx++)
			{
				if (_hptr->_ht[idx])
				{
					_node = _hptr->_ht[idx];
					break;
				}
			}
			if (idx == _hptr->_ht.size())
				_node = nullptr;
		}
	}
};


template<class K, class V, class KeyOfValue>
class HTable
{
public:
	typedef HashNode<V> Node;
	HTable(int n = 10)
		:_ht(n)
		, _size(0)
	{}

	void checkCapacity()
	{
		if (_ht.size() == _size)
		{
			int newC = _ht.size() == 0 ? 10 : 2 * _ht.size();
			vector<Node*> newht(newC);

			KeyOfValue kov;
			//遍历旧链表
			for (int i = 0; i < _ht.size(); i++)
			{
				Node* cur = _ht[i];
				while (cur)
				{
					Node* next = cur->_next;
					int idx = kov(cur->_val) % newC;

					cur->_next = newht[idx];
					newht[idx] = cur;
					
					cur = next;
				}
				//旧表置空
				_ht[i] = nullptr;
			}
			//新表旧表交换
			swap(_ht, newht);
		}
	}

	bool insert(const V& val)
	{
		//检查容量
		checkCapacity();
		//计算哈希位置
		KeyOfValue kov;
		int idx = kov(val) % _ht.size();
		//查找是否有重复元素
		Node* cur = _ht[idx];
		while (cur)
		{
			if (kov(cur->_val) == kov(val))
			{
				return false;
			}
			cur = cur->_next;
		}
		//插入:头插
		cur = new Node(val);
		cur->_next = _ht[idx];
		_ht[idx] = cur;
		++_size;
	}

	Node* find(const V& val);
	bool Erase(const V& val);
private:
	vector<Node*> _ht;
	size_t _size;
};
