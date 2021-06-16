/*
#include<iostream>
using namespace std;
#include<string>
#include<vector>
*/

/*
int main()
{
    string str1;
    string str2;
    while(cin >> str1 >> str2)
    {
        vector<int> v1(26, 0);
        vector<int> v2(26, 0);
        //遍历str1
        for(int i = 0; i < str1.size(); i++)
        {
            v1[str1[i] - 'A']++;
        }

        for(int i = 0; i < str2.size(); i++)
        {
            v2[str2[i] - 'A']++;
        }

        //比较v1与v2中的元素
        int flag = 0;
        for(int i = 0, j = 0; i < v1.size() && j < v2.size(); i++, j++)
        {
            if(v2[j] > v1[i])
            {
                flag = 1;
                break;
            }
        }
        if(flag)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    return 0;
}*/

//循环层数太多
/*
#include<iostream>
using namespace std;
#include<vector>
#include<string>

void tra(vector<int>& vsr, string str)
{
    for(int i = 0; i < str.size(); i++)
    {
        vsr[str[i] - 'a']++;
    }
}

bool isEqual(const vector<int>& vsr,const vector<int>& vdes)
{
    for(int i = 0, j = 0; i < vsr.size() && j < vdes.size(); i++, j++)
    {
        if(vsr[i] != vdes[j])
            return false;
    }
    return true;
}

int main()
{
    int  n;
    while(cin >> n)
    {
        vector<string> vc(n);
        for(int i = 0; i < n; i++)
        {
            cin >> vc[i];
        }
        string des;
        cin >> des; //目标字符串
        int m;//找相邻序号的兄弟单词
        cin >> m;

        vector<int> vdes(26);
        tra(vdes, des);

        vector<int> vsr(26);
        int count = 0;
        for(int i = 0; i < vc.size(); i++)
        {
            vsr.clear();
            vsr.resize(26);
            if(vc[i] != des)
            {
                //遍历每一个vc[i]
                tra(vsr, vc[i]);
                //判断vsr是否与vdes相同
                if(isEqual(vsr, vdes))
                    count++;
            }
        }

        vdes.clear();
        vdes.resize(26);
        tra(vdes, vc[m-1]);

        int i = m;
        for(; i < vc.size(); i++)
        {
            vsr.clear();
            vsr.resize(26);
            if(vc[i] != vc[m-1])
            {
                tra(vsr, vc[i]);

                if(isEqual(vsr, vdes))
                    break;
            }
        }
        cout << count << " "  << vc[i];
    }
    return 0;
}*/


