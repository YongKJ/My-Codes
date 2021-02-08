#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int GetMinNum(int a, int b, int c)//获取三个数中最小数
{
    int min = a < b ? a : b;
    return min < c ? min : c;
}
void MinDistance(char *s1, int len1, char *s2, int len2)
{
    int i = 0;
    int j = 0;
    int **d = (int **)malloc(sizeof(int*)*len1);
    for (i = 0; i < len1; i++)
    {
        d[i] = (int*)malloc(sizeof(int)*len2);
    }
    for (i = 0; i <len1; i++)
    {
        d[i][0] = i;
    }
    for (j = 0; j < len2; j++)
    {
        d[0][j] = j;
    }
    for (i = 1; i < len1; i++)
    {
        for (j = 1; j <len2; j++)
        {
            int cost = (s1[i] == s2[j] ? 0 : 1);
            int del = d[i - 1][j] + 1;
            int insert = d[i][j - 1] + 1;
            int sub = d[i - 1][j - 1] + cost;
            d[i][j] = GetMinNum(del, insert, sub);
        }
    }
    printf("%s and %s min distance is: %d\n", s1, s2, d[len1 - 1][len2 - 1]);

}
int main() {
  char s1[] = "abcdefg";
  char s2[] = "aabcg";
  MinDistance(s1, strlen(s1), s2, strlen(s2));
  system("pause");
  return 0;
}
/*
描述

       设A 和B 是2 个字符串。要用最少的字符操作将字符串A 
       转换为字符串B。这里所说的字符操作包括 (1)删除一个字
       符； (2)插入一个字符； (3)将一个字符改为另一个字符。
       将字符串A变换为字符串B 所用的最少字符操作数称为字
       符串A到B 的编辑距离，记为 d(A,B)。试设计一个有效算法，
       对任给的2 个字符串A和B，计算出它们的编辑距离d(A,B)。

输入

    输入的第一行是字符串A，文件的第二行是字符串B。

输出

   程序运行结束时，将编辑距离d(A,B)输出。

样例输入

fxpimu
xwrs

样例输出

5
*/