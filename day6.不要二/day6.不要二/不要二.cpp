#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
using namespace std;
#include<vector>

int main()
{
	int w, h, count = 0;//行，列，计数器
	cin >> w >> h;
	vector<vector<int>> vv;//二维数组
	vv.resize(w);//resize行
	for (auto& e : vv)
	{
		e.resize(h, 1);//resize列，每个位置初始化为1
	}

	//遍历二维数组
	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++)
		{
			//vv[i][j]可以放蛋糕，vv[i+2][j]和vv[i][j+2]不能放蛋糕
			if (vv[i][j] == 1)
			{
				count++;//可以放蛋糕计数器+1

				if (i + 2 < w)//判断是否越界
					vv[i + 2][j] = 0;//标记为0

				if (j + 2 < h)
					vv[i][j + 2] = 0;
			}
		}
	}
	cout << count << endl;
	return 0;
}