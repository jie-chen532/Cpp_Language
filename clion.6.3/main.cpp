#include <iostream>
using namespace  std;
#include<time.h>

template<class T>
struct  BTreeNode {
    BTreeNode<T>* _left;
    BTreeNode<T>* _right;
    T _val;

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
        return nullptr;
    }

    bool insert(const T& val)
    {
        //如果是根结点，则直接插入
        if(_root == nullptr)
        {
             _root = new Node(val);
            return true;
        }
        //先搜素是否有相同的
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
        //若没有相同的就插入，找叶子结点
        cur = new Node(val);
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
            cout << root->_val <<" ";
            _inorder(root->_right);
        }
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
    srand((unsigned int)time(NULL));
    for(int i = 0; i < 100; i++)
    {
        bt.insert(rand());
    }
    bt.inorder();
    BTree<int> bt1(bt);
    bt.inorder();
}

/*
void test()
{
    BTree<int> bt;
    bt.insert(10);
    bt.insert(1);
    bt.insert(2);
    bt.insert(15);
    bt.insert(17);
    bt.insert(26);
    bt.insert(13);

    BTree<int> bt1(bt);

    cout << "bt:";
    bt.inorder();
    cout << endl;
    cout << "bt1:";
    bt1.inorder();
    cout << endl;
}*/

int main()
{
    test();
    return 0;
}


/*
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

int main()
{
    int a;
    while(cin >> a)
    {
        int tmp = a;
        vector<int> vc;
        for(int i = 2; i <= sqrt(a); i++)
        {
            if(a % i == 0)
            {
                while(a % i == 0)
                {
                    a = a / i;
                    vc.push_back(i);
                }
            }
        }
        if(a != 1)
            vc.push_back(a);

        cout << tmp << " = ";
        for(int i = 0; i < vc.size(); i++)
        {
            if(i < vc.size() - 1)
                cout << vc[i] << " * ";
            else if(i == vc.size() - 1)
                cout << vc[i];
        }
        cout << endl;
    }
    return 0;
}
 */

/*
#include<iostream>
using namespace std;
#include<math.h>

static int ArrMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//平年28天

static int ArrMul[13] = {0, 2, 1, 1, 2, 1, 2, 1, 2, 2, 2 ,1, 2};

bool is_leap(int year)//闰年
{
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

int getDay(int year, int month)
{
    if(is_leap(year) && month ==2)
        return 29;
    return ArrMonth[month];
}

int getMonth(int year, int month)//每个月获得的钱
{
    if(is_leap(year) && month == 2)
    {
        return 29;
    }
    else
        return ArrMul[month] * ArrMonth[month];
}


int main()
{
    int year, year1;
    int month, month1;
    int day, day1;
    while(cin >> year >> month >> day >> year1 >> month1 >> day1)
    {
        int sum = 0;
        if(year == year1 && month == month1)
        {
            if(day == day1)
                sum += ArrMul[month] * (day1 - day + 1);
            else if(day == 1 && day1 == getDay(year, month))
                sum +=  getMonth(year, month);
            else
                sum += ArrMul[month] * (day1 - day + 1);
        }
        else
        {
            if(day == 1)
            {
                sum = ArrMul[month] * getDay(year,month);
            }
            else
                sum += ArrMul[month] * (getDay(year, month) - day + 1);
            month++;
            if(month > 12)
            {
                year += 1;
                month = 1;
            }
            while(year <= year1 && month <= 12)
            {
                if(year == year1 && month == month1)
                    break;
                sum += getMonth(year, month);
                month++;
                if(month > 12)
                {
                    year += 1;
                    month = 1;
                }
            }
            sum += ArrMul[month] * day1;
        }
        cout << sum << endl;
    }
    return 0;
}
 */


// write your code here cpp
/*
#include<iostream>
using namespace std;
#include<vector>

int main()
{
    int n;
    vector<int> fibo(100002);
    fibo[0] = 1;
    fibo[1] = 1;
    int i;
    for(i = 2; i <= 100001; i++)
    {
        fibo[i] = (fibo[i - 1] + fibo[i - 2]) % 1000000;
    }
    while(cin >> n)
    {
        if(n < 29)
            printf("%d", fibo[n]);
        else
            printf("%06d", fibo[n]);
    }
    return 0;
}
 */

/*
#include<iostream>
using namespace std;
#include<vector>

int main()
{
    int from, to;
    vector<long long> hum(81);
    hum[0] = 1;//第一天
    hum[1] = 1;//第二天
    for(int i = 2; i <= 80; i++)
    {
        hum[i] = hum[i-1] + hum[i-2];
    }
    while(cin >> from >> to)
    {
        long long sum = 0;
        for(int i = from; i <= to; i++)
        {
            sum += hum[i - 1];
        }
        cout << sum << endl;
    }
    return 0;
}
 */


/*
#include<iostream>
using namespace std;
#include<string>

int main()
{
    string f_str, s_str;
    while(cin >> f_str >> s_str)
    {
        int count = 0;
        int find_len = s_str.size();
        for(int i = 0; i < f_str.size() && (i + find_len <= f_str.size());)
        {
            string tmp = f_str.substr(i,find_len);
            if(tmp == s_str)
            {
                count++;
                i = i + find_len;
            }
            else
                i++;
        }
        cout << count << endl;
    }
    return 0;
}
 */