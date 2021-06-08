#include <iostream>
using namespace std;

//二维数组中的查找
/*
bool find(int (*arr)[4], int rows, int columns, int number)//row行  columns列
{
    int row = 0;
    int column = columns - 1;

    if(arr != nullptr && rows > 0 && columns > 0)
    {
        while(row < rows && column >= 0)
        {
            int max = arr[row][column - 1];
            if(max ==  number)
            {
                return true;
            }
            else if(number < max)
            {
                column--;
            }
            else
            {
                row++;
            }
        }
    }
    return false;
}

void test()
{
    int arr[][4] = {{1, 2, 8, 9}, {2, 4, 9 ,12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    bool result = find(arr, 4, 4, 3);
    cout << result << endl;
    result = find(arr, 4, 4, 7);
    cout << result << endl;
    result = find(arr, 4, 4, 6);
    cout << result << endl;
    result = find(arr, 4, 4, 11);
    cout << result << endl;
    result = find(arr, 4, 4, 70);
    cout << result << endl;
}*/

int main() {
    test();
    return 0;
}
