#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

template<class T>
struct BNode
{
	T _data;
	typedef BNode<T> Node;
	Node* left;
	Node* right;

	BNode(const T& data)
		:_data(data)
		, left(nullptr)
		, right(nullptr)
	{
	}
};

template<class T>
class BTree
{
	typedef BNode<T> Node;

public:
	BTree()
		:_root(nullptr)
	{}

	//拷贝二叉搜索树
	Node* copy(Node* root)
	{
		if (root == nullptr)
			return nullptr;

		Node* newNode = new Node(root->_data);
		newNode->left = copy(root->left);
		newNode->right = copy(root->right);

		return newNode;
	}

	BTree(const BTree<T>& btree)
		:_root(copy(btree._root))
	{}

	//搜索
	Node* find(const T& val)
	{
		Node* cur = _root;
		while (cur)
		{
			if (val == cur->_data)
				return cur;
			else if (val > cur->_data)
				cur = cur->right;
			else
				cur = cur->left;
		}
		return nullptr;
	}

	//插入
	bool insert(const T& val)
	{
		if (_root == nullptr)
		{
			_root = new Node(val);
			return true;
		}
		//一般不会插入重复的节点
		//先找到叶子节点
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (cur->_data == val)
				return false;
			else if (cur->_data > val)
				cur = cur->left;
			else
				cur = cur->right;
		}

		Node* newNode = new Node(val);
		if (val > parent->_data)
			parent->right = newNode;
		else
			parent->left = newNode;
		return true;
	}

	//中序遍历
	void inOrder()
	{
		_inOrder(_root);
		cout << endl;
	}

	void _inOrder(Node* root)
	{
		if (root)
		{
			_inOrder(root->left);
			cout << root->_data << " ";
			_inOrder(root->right);
		}
	}


	//销毁
	void destory(Node* root)
	{
		if (root)
		{
			destory(root->left);
			destory(root->right);
			delete root;
		}
	}

	~BTree()
	{
		if (_root)
		{
			destory(_root);
			_root = nullptr;
		}
	}
private:
	Node* _root;
};

void test()
{
	BTree<int> b;
	b.insert(20);
	b.insert(5);
	b.insert(25);
	b.insert(10);
	b.insert(80);
	b.insert(4);

	b.inOrder();
}

int main()
{
	test();
	return 0;
}