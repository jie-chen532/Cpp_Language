#include <iostream>
using namespace std;
#include<time.h>

template<class K, class V>
struct BTreeNode
{
    typedef BTreeNode<K, V> Node;

    Node* _left;//左子树
    Node* _right;//右子树
    K _key;
    V _value;

    BTreeNode(const K& key = K(), const V& val = V())
            :_left(nullptr)
            ,_right(nullptr)
            ,_key(key)
            ,_value(val)
    {}
};

template<class K, class V>
class BTree
{
public:
    typedef  BTreeNode<K, V> Node;

    BTree()
            :_root(nullptr)
    {}

    Node* find(const K& key)
    {
        Node* cur = _root;
        while(cur)
        {
            if(cur->_key == key)
                return cur;
            else if(cur->_key > key)
                cur = cur->_left;
            else
                cur = cur->_right;
        }
        return cur;
    }

    BTree(const BTree<K, V>& bt)
            :_root(copy(bt._root))
    {}

    Node* copy(Node* root)
    {
        if(root == nullptr)
            return nullptr;
        Node* newNode = new Node(root->_key, root->_value);
        newNode->_left = copy(root->_left);
        newNode->_right = copy(root->_right);

        return newNode;
    }

    bool insert(const K& key, const V& val)
    {
        //如果是空树，则直接插入结点，返回true
        if(_root == nullptr)
        {
            _root = new Node(key, val);
            return true;
        }

        Node* cur = _root;
        Node* parent = nullptr;//指向父结点的指针

        //若不是空树，需要遍历找到插入结点的位置
        while(cur)
        {
            parent = cur;
            //相同的结点，直接返回false，因为搜索树中不能出现相同的值
            if(cur->_key == key)
                return false;
                //比根节点小则继续查找左子树
            else if(cur->_key > key)
                cur = cur->_left;
                //比根节点大则继续查找右子树
            else
                cur = cur->_right;
        }

        //创建结点
        cur = new Node(key, val);

        //插入：判断插入到父结点的左边还是右边
        if(parent->_key > key)
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
            cout << root->_key<< "-->" << root->_value << " ";
            _inorder(root->_right);
        }
    }

    bool erase(const K& key)
    {
        //遍历搜索二叉树，找到要删除的结点
        Node* cur = _root;
        Node* parent = nullptr;

        while(cur)
        {
            if(cur->_key == key)//找到结点，结束循环
                break;
            parent = cur;
            if(cur->_key > key)
                cur = cur->_left;
            else
                cur = cur->_right;
        }

        //如果cur为空，说明没有找到要删除的结点，则直接返回false
        if(cur == nullptr)
            return false;

        //判断cur是否是叶子结点
        if(cur->_left == nullptr && cur->_right == nullptr)
        {
            //判断这个结点是否是根结点
            if(cur == _root)
            {
                //根结点置空
                _root = nullptr;
            }
            else
            {
                //判断要删除的结点是父亲结点的哪一边
                if(parent->_left == cur)
                    parent->_left = nullptr;
                else
                    parent->_right = nullptr;
            }
            //删除结点
            delete cur;
        }
        else if(cur->_right == nullptr)//需要删除的结点只有左孩子
        {
            //判断是否是根结点
            if(cur == _root)
            {
                _root = cur->_left;
            }
            else
            {
                //判断删除结点在父亲的哪一边
                if(parent->_left == cur)
                    parent->_left = cur->_left;
                else
                    parent->_right = cur->_left;
            }
            //删除cur
            delete cur;
        }
        else if(cur->_left == nullptr)//需要删除的结点只有右孩子
        {
            //判断是否是根节点
            if(cur == _root)
            {
                _root = cur->_right;
            }else
            {
                //判断删除结点在父结点的哪一边
                if(parent->_left == cur)
                    parent->_left = cur->_right;
                else
                    parent->_right = cur->_right;
            }
            delete cur;
        }
        else//需要删除的结点既有左孩子也有右孩子
        {
            Node* leftRightMost = cur->_left;
            parent = cur;

            //找到左子树的最有结点
            while(leftRightMost->_right)
            {
                parent = leftRightMost;
                leftRightMost = leftRightMost->_right;
            }

            //交换左子树的最右结点和需要删除的结点
            swap(cur->_key, leftRightMost->_key);
            swap(cur->_value,leftRightMost->_value);

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
    Node* _root;//根
};

void test() {
    BTree<int, int > bt;
    srand((unsigned int)time(NULL));

    for(int i = 0; i < 100; i++) {
        bt.insert(rand(), rand() % 10);
    }
    bt.inorder();
}

/*
void test()
{
    BTree<int, int > bt;
    bt.insert(10,10);
    bt.insert(2,3);
    bt.insert(4, 7);
    bt.insert(13,15);
    bt.insert(11,9);
    bt.insert(14,8);
    bt.insert(8,5);
    bt.insert(9,5);

    bt.inorder();

    BTree<int, int> bt1(bt);
    bt1.inorder();



    bt.erase(10);
    bt.inorder();
    bt.erase(2);
    bt.inorder();
    bt.erase(13);
    bt.inorder();


}*/

int main()
{
    test();
    return 0;
}