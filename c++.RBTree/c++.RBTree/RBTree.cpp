#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

//ϴ�ƺ���
//vector<int> sort(vector<int>& arr)
//{
//	int end = arr.size() - 1;
//	int mid = end / 2;
//	int tmp = mid;
//	vector<int> s;
//	while (mid >= 0)
//	{
//		if (end > tmp)
//		{
//			s.push_back(arr[end]);
//			end--;
//		}
//		s.push_back(arr[mid]);
//		mid--;
//	}
//	reverse(s.begin(), s.end());
//	return s;
//}
//
//int main()
//{
//	int time;
//	cin >> time;
//	while (time)
//	{
//		int n, k;//n������ϴk��
//		cin >> n >> k;
//		vector<int> arr(2 * n);
//		for (int i = 0; i < 2 * n; i++)
//		{
//			cin >> arr[i];
//		}
//		while (k)
//		{
//			arr = sort(arr);
//			k--;
//		}
//		for (int i = 0; i < arr.size(); i++)
//		{
//			if (i != arr.size() - 1)
//				cout << arr[i] << " ";
//			else
//				cout << arr[i];
//		}
//		cout << endl;
//		time--;
//	}
//	return 0;
//}


//�����������
//template<class V>
//struct RBTreeIterator
//{
//	typedef RBNode<V> Node;
//	typedef RBTreeIterator<V> Self;
//
//	Node* _node;
//
//	RBTreeIterator(Node* node)
//		; _node(node)
//	{}
//
//	//*
//	V& operator*()
//	{
//		return _node->val;
//	}
//
//	//�������
//	//�����
//	Self& operator++()
//	{
//		if (_node->right)
//		{
//			//���ұߵ������
//			_node = _node->right;
//			while (_node->left)
//			{
//				_node = _node->_left;
//			}
//		}
//		else
//		{
//			Node* parent = _node->_parent;
//			while (parent->_right == _node)
//			{
//				_node = parent;
//				parent = parent->_parent;
//			}
//			if (_node->_right != parent)
//				_node = parent;
//		}
//	}
//
//	//�Ҹ���
//	Self& operator--()
//	{
//		if (_node->left)
//		{
//			//�ߵ������������ұ�
//			_node = _node->_left;
//			while (_node->_right)
//			{
//				_node = node->right;
//			}
//		}
//		else
//		{
//			Node* parent = _node->_parent;
//			while (parent->_left == _node)
//			{
//				_node = parent;
//				parent = _node->_parent;
//			}
//			if (_node->left != parent)
//				_node = parent;
//		}
//		return *this;
//	}
//};

#include<unordered_map>
//void test()
//{
//	//���map�������ܸ��ߣ�o(1)
//	unordered_map<int, int> m;
//	m.insert(make_pair(1, 1));
//	m[3] = 2;
//
//	for (int i = 3; i < 10; i++)
//	{
//		m.insert(make_pair(i, i));
//	}
//
//	//�����map/set,unordered_map/setֻ�����������
//	//unordered_map�ı������������
//	auto it = m.begin();
//	while (it != m.end())
//	{
//		cout << it->first << " ";
//		it++;
//	}
//	cout << endl;
//}
//
//int main()
//{
//	test();
//	return 0;
//}



//��ϣ������̽��

enum STATE
{
	EXIST,
	DELETE,
	EMPTY,
};

template<class K, class V>
struct HashNode
{
	pair<K, V> _kv;
	STATE _state = EMPTY;
};

//˳���ʵ�ֹ�ϣ̽��
template<class K, class V>
class HashTable
{
public:
	typedef HashNode<K, V> Node;

	HashTable(size_t n = 10)
		; hTable(n)
		:_size(0)
	{}

	//�������ӣ���ЧԪ�صĸ���/��ЧԪ��
	bool insert(const pair<K, V>& kv)
	{
		//1.�����ϣ��λ��
		int index = kv.first % hTable.size();
		//2.�ж�k�Ƿ����
		while (_hTable[index]._state != EMPTY)
		{
			if (_hTable[index].state == EXIST && _hTable[index]._kv.first == kv.first)
				return false;
			++index;
			if (index == _hTable.size())
				index = 0;
		}
		_hTable[index]._kv = kv;
		_hTable[index]._state = EXIST;
		++_size();
	}

private:
	vector<Node> _hTable;
	size_t _size;//��ЧԪ�صĸ���
};
