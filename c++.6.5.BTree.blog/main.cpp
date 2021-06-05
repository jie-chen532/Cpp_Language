/*
#include <iostream>
using namespace std;
#include<time.h>

template<class T>
struct BTreeNode
{
    typedef BTreeNode<T> Node;

    //��������ֵ
    Node* _left;//������
    Node* _right;//������
    T _val;//����

    BTreeNode(const T& val = T())
       :_left(nullptr)
       ,_right(nullptr)
       ,_val(val)
    {}
};

template<class T>
class BTree
{
public:
    typedef  BTreeNode<T> Node;

    BTree()
       :_root(nullptr)
    {}

    Node* find(const T& val)
    {
        Node* cur = _root;
        while(cur)
        {
            if(cur->_val == val)
                return cur;
            else if(cur->_val > val)
                cur = cur->_left;
            else
                cur = cur->_right;
        }
        return cur;
    }

    BTree(const BTree<T>& bt)
        :_root(copy(bt._root))
    {}

    Node* copy(Node* root)
    {
        if(root == nullptr)
            return nullptr;
        Node* newNode = new Node(root->_val);
        newNode->_left = copy(root->_left);
        newNode->_right = copy(root->_right);

        return newNode;
    }

    bool insert(const T& val)
    {
        //����ǿ�������ֱ�Ӳ����㣬����true
        if(_root == nullptr)
        {
            _root = new Node(val);
            return true;
        }

        Node* cur = _root;
        Node* parent = nullptr;//ָ�򸸽���ָ��

        //�����ǿ�������Ҫ�����ҵ��������λ��
        while(cur)
        {
            parent = cur;
            //��ͬ�Ľ�㣬ֱ�ӷ���false����Ϊ�������в��ܳ�����ͬ��ֵ
            if(cur->_val == val)
                return false;
            //�ȸ��ڵ�С���������������
            else if(cur->_val > val)
                cur = cur->_left;
            //�ȸ��ڵ�����������������
            else
                cur = cur->_right;
        }

        //�������
        cur = new Node(val);

        //���룺�жϲ��뵽��������߻����ұ�
        if(parent->_val > val)
            parent->_left = cur;
        else
            parent->_right = cur;

        return true;
    }

    void _inorder(Node* root)
    {
        if(root)
        {
            _inorder(root->_left);
            cout << root->_val << " ";
            _inorder(root->_right);
        }
    }

    bool erase(const T& val)
    {
        //�����������������ҵ�Ҫɾ���Ľ��
        Node* cur = _root;
        Node* parent = nullptr;

        while(cur)
        {
            if(cur->_val == val)//�ҵ���㣬����ѭ��
                break;
            parent = cur;
            if(cur->_val > val)
                cur = cur->_left;
            else
                cur = cur->_right;
        }

        //���curΪ�գ�˵��û���ҵ�Ҫɾ���Ľ�㣬��ֱ�ӷ���false
        if(cur == nullptr)
            return false;

        //�ж�cur�Ƿ���Ҷ�ӽ��
        if(cur->_left == nullptr && cur->_right == nullptr)
        {
            //�ж��������Ƿ��Ǹ����
            if(cur == _root)
            {
                //������ÿ�
                _root = nullptr;
            }
            else
            {
                //�ж�Ҫɾ���Ľ���Ǹ��׽�����һ��
                if(parent->_left == cur)
                    parent->_left = nullptr;
                else
                    parent->_right = nullptr;
            }
            //ɾ�����
            delete cur;
        }
        else if(cur->_right == nullptr)//��Ҫɾ���Ľ��ֻ������
        {
            //�ж��Ƿ��Ǹ����
            if(cur == _root)
            {
                _root = cur->_left;
            }
            else
            {
                //�ж�ɾ������ڸ��׵���һ��
                if(parent->_left == cur)
                    parent->_left = cur->_left;
                else
                    parent->_right = cur->_left;
            }
            //ɾ��cur
            delete cur;
        }
        else if(cur->_left == nullptr)//��Ҫɾ���Ľ��ֻ���Һ���
        {
            //�ж��Ƿ��Ǹ��ڵ�
            if(cur == _root)
            {
                _root = cur->_right;
            }else
            {
                //�ж�ɾ������ڸ�������һ��
                if(parent->_left == cur)
                    parent->_left = cur->_right;
                else
                    parent->_right = cur->_right;
            }
            delete cur;
        }
        else//��Ҫɾ���Ľ���������Ҳ���Һ���
        {
            Node* leftRightMost = cur->_left;
            parent = cur;

            //�ҵ������������н��
            while(leftRightMost->_right)
            {
                parent = leftRightMost;
                leftRightMost = leftRightMost->_right;
            }

            //���������������ҽ�����Ҫɾ���Ľ��
            swap(cur->_val, leftRightMost->_val);

            if(parent->_left == leftRightMost)
                parent->_left = leftRightMost->_left;
            else
                parent->_right = leftRightMost->_left;

            delete leftRightMost;
        }
        return true;
    }

    void inorder()
    {
        _inorder(_root);
        cout << endl;
    }

    void destory(Node* root)
    {
        if(root)
        {
            destory(root->_left);
            destory(root->_right);
            delete root;
        }
    }

    ~BTree()
    {
        if(_root)
        {
            destory(_root);
            _root = nullptr;
        }
    }

private:
    Node* _root;//��
};*/

/*
void test()
{
    BTree<int> bt;
    srand((unsigned int)time(NULL));

    //�������500������
    for(int i = 0; i < 500; i++)
    {
        bt.insert(rand());
    }

    //�������
    bt.inorder();
}*/

/*
void test()
{
    BTree<int> bt;
    bt.insert(5);
    bt.insert(3);
    bt.insert(7);
    bt.insert(1);
    bt.insert(4);
    bt.insert(6);
    bt.insert(8);
    bt.insert(0);
    bt.insert(2);
    bt.insert(9);
    bt.insert(10);

    bt.inorder();

    bt.erase(10);//ɾ��Ҷ�ӽ��
    bt.inorder();
    bt.erase(2);//ɾ��Ҷ�ӽ��
    bt.inorder();

    bt.erase(8);//ֻ���������Ľ��
    bt.inorder();

    bt.erase(1);//ֻ���������Ľ��
    bt.inorder();

    bt.erase(5);//�����������еĽ��
    bt.inorder();

}

int main() {
    test();
}*/
