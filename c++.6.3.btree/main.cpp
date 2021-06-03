
#include <iostream>
using namespace std;

template<class T>
struct BTreeNode
{
    typedef BTreeNode<T> Node;
    Node* _left;
    Node* _right;
    T _val;

    BTreeNode(const T& val = T())
           :_val(val)
           ,_left(nullptr)
           ,_right(nullptr)
    {}
};

template<class T>
class BTree
{
public:
   typedef BTreeNode<T> Node;

   BTree()
     :_root(nullptr)
   {}

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

   bool insert(const T& val)
   {
       //不能插入重复的数据

       //如果是根节点，则直接插入
       if(_root == nullptr)
       {
           _root = new Node(val);
           return true;
       }
       //不是根结点，需要找到合适插入的叶子结点
       Node* cur = _root;
       Node* parent = nullptr;
       while(cur)
       {
           parent = cur;
           if(cur->_val == val)
               return false;
           else if(cur->_val > val)
               cur = cur->_left;
           else
               cur = cur->_right;
       }
       //插入
       cur = new Node(val);
       if(parent->_val > val)
           parent->_left = cur;
       else
           parent->_right = cur;
       return true;
   }

   void inorder()
   {
       _inorder(_root);
       cout << endl;
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
        //先找到val
        Node* cur = _root;
        Node* parent = nullptr;
        while(cur)
        {
            if(cur->_val == val)
                break;
            parent = cur;
            if(cur->_val > val)
                cur = cur->_left;
            else
                cur = cur->_right;
        }
        //cur为空，说明没有找到val，返回false
        if(cur == nullptr)
            return false;

        if(cur->_left == nullptr && cur->_right == nullptr)//如果删除的是叶子结点
        {
            //如果是根结点
            if(cur == _root)
                _root = nullptr;
            else
            {
                if(parent->_right == cur)
                    parent->_right = nullptr;
                else
                    parent->_left = nullptr;
            }
            delete cur;
        }
        else if(cur->_right == nullptr)//有左子树，没有右子树
        {
            //如果是根节点
            if(cur == _root)
                _root = cur->_left;
            else
            {
                 if(parent->_left == cur)
                     parent->_left = cur->_left;
                 else
                     parent->_right = cur->_left;
            }
            delete cur;
        }
        else if(cur->_left == nullptr)//有右子树，没有左子树
        {
            if(cur == _root)
                _root = cur->_right;
            else
            {
                if(parent->_right == cur)
                    parent->_right = cur->_right;
                else
                    parent->_left = cur->_right;
            }
            delete cur;
        }
        else //既有左子树，又有右子树
        {
            Node* leftRightMost = cur->_left;
            parent = cur;

            //找到左子树的最右结点
            while(leftRightMost->_right)
            {
                parent = leftRightMost;
                leftRightMost = leftRightMost->_right;
            }

            //交换cur与leftRightMost,将cur交换到一个删除比较简单的位置
            swap(cur->_val, leftRightMost->_val);

            if(parent->_left == leftRightMost)
                parent->_left = leftRightMost->_left;
            else
                parent->_right = leftRightMost->_left;

            delete leftRightMost;
        }
   }

   void destory(Node* root)
   {
       if(root)
       {
           destory(root->_left);
           destory(root->_right);
           cout << "destory:" << root->_val << endl;
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
    Node* _root;
};

void test()
{
    BTree<int> bt;
    bt.insert(10);
    bt.inorder();
    bt.insert(20);
    bt.inorder();
    bt.insert(13);
    bt.inorder();
    bt.insert(11);
    bt.inorder();
    bt.insert(15);
    bt.inorder();
    bt.insert(16);
    bt.inorder();

    bt.erase(10);
    bt.inorder();
    bt.erase(15);
    bt.inorder();
    bt.erase(16);
    bt.inorder();
    bt.erase(11);
    bt.inorder();

}

int main() {
    test();
    return 0;
}

