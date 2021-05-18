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

	//��ɫ
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
		//����������Ĭ���Ǻ�ɫ
		_header->left = _header->_right = _header;
	}

	bool insert(const pair<K, V>& kv)
	{
		//1.�������Ĳ���
		//������_header->parent = nullptr
		if (_header->_parent == nullptr)
		{
			Node* root = new Node(kv);
			_header->_parent = root;
			_header->_left = _header->_right = root;
			root->_parent = _header;

			//�޸���ɫ
			root->_color = BLACK;
			return true;
		}

		//�Ӹ��ڵ㿪ʼ����
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
		//2.�޸���ɫ���ߵ����ṹ
		//�ж��Ƿ���������ɫ���
		while (cur != _header->_parent && cur->_parent->_color == RED)
		{
			parent = cur->_parent;
			Node* gparent = parent->_parent;

			//��uncle���,�����Ǻ�ɫ
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
					//û��uncle������uncle���Ϊ��ɫ

					//1.�ж��Ƿ���˫������,��ߵ��ұ�Ϊ��ɫ
					if (parent->_right == cur)
					{
						//����
						RotateL(cur);
						swap(cur, parent);
					}
					//��ߵ����Ϊ��ɫ��uncleΪ��ɫ
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
					//�ж��Ƿ�˫��
					//�ұߵ������������ɫ
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
		_header->_left = 
		_header->_right = 
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
	//����
	//header->parent = nullptr;
	//left:header;
	//right:header;
	Node* _header;
};