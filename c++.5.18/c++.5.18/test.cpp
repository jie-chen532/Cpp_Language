#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

enum COLOR
{
	BLACK,
	RED,
};

template<class K, class V>
struct RBNode
{

	RBNode<K, V>* _parent;
	RBNode<K, V>* _left;
	RBNode<K, V>* _right;

	pair<K, V> _kv;

	//颜色
	COLOR _color;

	RBNode(const pair<K, V>& kv = pair<K, V>())
		:_parent(nullptr)
		, _left(nullptr)
		, _right(nullptr)
		, _kv(kv)
		, _color(RED)
	{}
};

template<class K, class V>
class RBTree
{
public:
	typedef RBNode<K, V> Node;

	RBTree()
		:_header(new Node)
	{
		//创建空树，默认是红色
		_header->left = _header->_right = _header;
	}

	bool insert(const pair<K, V>& kv)
	{
		//1.搜索树的插入
		//空树：_header->parent = nullptr
		if (_header->_parent == nullptr)
		{
			Node* root = new Node(kv);
			_header->_parent = root;
			_header->_left = _header->_right = root;
			root->_parent = _header;

			//修改颜色
			root->_color = BLACK;
			return true;
		}

		//从根节点开始搜索
		Node* cur = _header->_parent;
		Node* parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (cur->_kv.first == kv.first)
				return false;
			else if (kv.first > cur->_kv.first)
				cur = cur->_right;
			else if
				cur = cur->_left;
		}

		cur = new  Node(kv);
		if (parent->_kv.first > cur->_kv.first)
			parent->_left = cur;
		else
			parent->_right = cur;
		cur->_parent = parent;
		//2.修改颜色或者调整结构
		//判断是否有连续红色结点
		while (cur != _header->_parent && cur->_parent->_color == RED)
		{
			parent = cur->_parent;
			Node* gparent = parent->_parent;

			//有uncle结点,并且是红色
			if (gparent->_left == parent)
			{
				Node* uncle = gparent->right;
				if (uncle && uncle->_color == RED)
				{
					parent->_color = uncle->_color = BLACK;
					gparent->_color = RED;
					cur = gparent;
				}
				else
				{
					//没有uncle结点或者uncle结点为黑色

					//1.判断是否是双旋场景,左边的右边为红色
					if (parent->_right == cur)
					{
						//左旋
						RotateL(cur);
						swap(cur, parent);
					}
					//左边的左边为红色，uncle为黑色
					RotateR(gparent);
					parent->_color = BLACK;
					gparent->_color = RED;
					break;
				}
			}
			else
			{
				Node* uncle = gparent->left;
				if (uncle && uncle->_color == RED)
				{
					uncle->_color = parent->_color = BLACK;
					gparent->_color = RED;
					cur = gparent;
				}
				else
				{
					//判断是否双旋
					//右边的左边是连续红色
					if (parent->_left == cur)
					{
						RotateR(parent);
						swap(cur, parent);
					}
					//
					RotateL(gparent);
					parent->_color = BLACK;
					gparent->_color = RED;
					break;
				}
			}
		}
		_header->_parent->_color = BLACK;
		_header->_left = leftMost();
		_header->_right = rightMost();
		return true; 
	}

	//红黑树：
	//1.根是黑色
	//2.每条路径黑色个数相同
	//3.红色不能连续
	bool isBalance()
	{
		if (_header->_parent == nullptr)
			return true;
		Node* root = _header->_parent;
		if (root->_color == RED)
			return false;
		//统计一条路径上的黑色结点个数，如果其他路径上的黑色结点与统计的黑色结点个数相同，
		//就说明每条路径黑色结点相同
		Node* cur = root;
		int bCount = 0;
		while (cur)
		{
			if (cur->_color == BLACK)
				bCount++;
			cur = cur->_left;
		}
		int curCount = 0;
		return _isBalance(root, bCount, curCount);
	}

	bool _isBalance(Node* root, int& bCount, int curCount)
	{
		//一条路径结束
		if (root == nullptr)
		{
			if (curCount != bCount)
				return false;
			else
				return true;
		}

		//如果是黑色结点
		if (root->_color == Black)
			++curCount;

		//判断是否有连续两个红色结点
		if (root != _header->_parent && root->_parent->_color == RED
			&& root->_color == RED)
		{
			return false;
		}

		return _isBalance(root->_left, bCount, curCount) && isBalance(root->_right, bCount, curCount);
	}

	Node* leftMost()
	{
		Node* cur = _header->_parent;
		while (cur && cur->left)
		{
			cur = cur->_left;
		}
		return cur;
	}

	Node* rightMost()
	{
		Node* cur = _header->_parent;
		while (cur && cur->right)
		{
			cur = cur->_right;
		}
		return cur;
	}

	void RoteteR(Node* parent)
	{
		Node* subL = paren->left;
		Node* subLR = subL->_right;

		subL->_right = parent;
		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;
		if (_header->_parent == parent)
		{
			subL->_parent = _header;
			_header->_parent = subL;
		}
		else
		{
			Node* pparent = parent->_parent;
			if (pparent->_left == parent)
				pparent->_left = subL;
			else
				pparent->_right = subL;
			subL->_parent = pparent;
		}
		parent->_parent = subL;
	}

	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subLR = subR->_left;

		subL->left = prent;
		parent->_right = subLR;
		if (subLR)
			subLR->_parent = parent;
		if (parent == _header->_parent)
		{
			subR->parent = _header;
			_header->_parent = subR;
		}
		else
		{
			Node* pparent = parent->_parent;
			if (pparent->_left == parent)
				pparent->_left = subR;
			else
				pparent->_right = subR;
			subR->_parent = pparent;
		}
		parent->_parent = subR;
	}

private:
	//空树
	//header->parent = nullptr;
	//left:header;
	//right:header;
	Node* _header;
};