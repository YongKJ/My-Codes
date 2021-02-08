#include<iostream>
using namespace std;
int num[103][30];
int main()
{
	num[1][29]=1;//第一项 
	num[2][29]=1;//第二项
	for(int i=3;i<=100;i++)
	{
          for (int j = 29; j >= 0; j--) //循环，数组行是从1开始，列是从0开始
          {
            if ((num[i - 1][j] + num[i - 2][j]) >= 10) //进位，占多一个元素
              num[i][j - 1] += 1;
            num[i][j] = num[i][j] + (num[i - 1][j] + num[i - 2][j]) % 10;
          }
        }
        int j = 0;
        while (num[100][j] == 0)
          j++;
        for (int i = j; i < 30; i++)
          cout << num[100][i];
        return 0;
}