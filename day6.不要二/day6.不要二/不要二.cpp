#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
using namespace std;
#include<vector>

int main()
{
	int w, h, count = 0;//�У��У�������
	cin >> w >> h;
	vector<vector<int>> vv;//��ά����
	vv.resize(w);//resize��
	for (auto& e : vv)
	{
		e.resize(h, 1);//resize�У�ÿ��λ�ó�ʼ��Ϊ1
	}

	//������ά����
	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++)
		{
			//vv[i][j]���Էŵ��⣬vv[i+2][j]��vv[i][j+2]���ܷŵ���
			if (vv[i][j] == 1)
			{
				count++;//���Էŵ��������+1

				if (i + 2 < w)//�ж��Ƿ�Խ��
					vv[i + 2][j] = 0;//���Ϊ0

				if (j + 2 < h)
					vv[i][j + 2] = 0;
			}
		}
	}
	cout << count << endl;
	return 0;
}