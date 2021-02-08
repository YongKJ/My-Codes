#include <iostream>  
#include <vector>  
using namespace std;  
  
const int N = 101;  
int a[N][N], p[N][N];  
  
int MaxRecSum(int n)  
{  
    for (int i = 0; i <= n; ++i)  
    {  
        p[i][0] = 0;  
        p[0][i] = 0;  
    }     
    for (int i = 1; i <= n; ++i)  
    {  
        for (int j = 1; j <= n; ++j)  
            p[i][j] = p[i-1][j] + p[i][j-1] - p[i-1][j-1] + a[i][j];  
    }  
  
    int max = INT_MIN;  
    for (int i = 1; i <= n; ++i)  
    {  
        for (int j = i; j <= n; ++j)  
        {  
            int sum = 0;  
            for (int k = 1; k <= n; ++k)  
            {  
                int temp = p[j][k] - p[j][k-1] - p[i-1][k] + p[i-1][k-1];  
                if (sum > 0)  
                    sum += temp;  
                else  
                    sum = temp;  
                if (sum > max)  
                    max = sum;  
            }  
        }  
    }  
    return max;  
}  
  
int main()  
{  
    int n = 4;  
    int num;  
    for (int i = 1; i <= n; ++i)  
    {  
        for (int j = 1; j <= n; ++j)  
        {  
            cin >> num;  
            a[i][j] = num;  
        }  
    }  
  
    cout << MaxRecSum(n) << endl;  
    return 0;  
}  
/*
给定一个N*N的矩阵，计算最大子矩阵和。

思路：

最大子段和问题可以用动态规划在O(n)内解决，
该题可以借助最大子段和的解法来做。我们考
虑第i行到第j行的子矩阵，可以将i ~ j行的矩阵
合并为一个一维数组，即把每列对应的数相加，
那么这个一维数组的最大子段和就是原子矩阵
的最大和。

我们用一个二维数组p来保存矩阵的部分和，
p[i][j]表示左上角是(1, 1)，(下标从1开始)， 右
下角是(i, j)的矩阵中元素的和。如果我们要求i~j
行、k~m列的矩阵中元素的和，我们可以通过以
下式子计算得出：

sum = p[j][m] - p[j][k-1] - p[i-1][m] + p[i-1][k-1]
只需要O(1)的时间。

部分和p[i][j]要怎么计算呢？我们可以通过更小的
部分和来计算得到它：

p[i][j] = p[i-1][j] + p[i][j-1] - p[i-1][j-1] + a[i][j]
其中a[i][j]是矩阵中的整数。我们只需要O(n2 ) 的
时间即可预处理得到所有的部分和。

所以总的时间为O(n3 )。
*/
/*
描述


给定一个由整数组成二维矩阵（r*c），现在需要
找出它的一个子矩阵，使得这个子矩阵内的所有
元素之和最大，并把这个子矩阵称为最大子矩阵。 
例子：
0 -2 -7 0 
9 2 -6 2 
-4 1 -4 1 
-1 8 0 -2 
其最大子矩阵为：

9 2 
-4 1 
-1 8 
其元素总和为15。

输入

第一行输入一个整数n（0<n<=100）,表示有n组测试数据；
每组测试数据：
第一行有两个的整数r，c（0<r,c<=100），r、c分别代表
矩阵的行和列；
随后有r行，每行有c个整数；

输出

输出矩阵的最大子矩阵的元素之和。

样例输入

1
4 4
0 -2 -7 0 
9 2 -6 2 
-4 1 -4 1 
-1 8 0 -2 

样例输出

15
*/