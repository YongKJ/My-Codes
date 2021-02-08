#include<stdio.h>
#include<math.h>
#include<malloc.h>
#include <iostream>
using namespace std;
#define true 1
#define false 0
void Trial(int i, int n, int *X);
int place(int s, int *X);
int place(int s, int *X) {
    int i = 1;
    for(; i < s; i++) {
        if(abs(i-s) == abs(X[i]-X[s]) || X[i] == X[s]) {
            return false;
        }
    }
    return true;
} 
void Trial(int i, int n, int *X) {
    int j, k;
    if(i > n) {   //输出 
        for(k = 1; k <= n; k++) {
            printf("%d ", X[k]);
        }
        printf(" \n");
    } else {
        for(j = 1; j <= n; j++) {
            X[i] = j;
            if(place(i, X)) {
                Trial(i+1, n, X);
            }
        }
    } 
}
int main(void) {
    int n;
    int *Queen = NULL;
    printf("请输入皇后的个数.\n");
    scanf("%d", &n);
    Queen = (int *)malloc(sizeof(int) * (n+1));
    Trial(1, n, Queen); 
} 
/*
描述


         检查一个如下的6 x 6的跳棋棋盘，有六个棋子被放置在棋盘上，
         使得每行，每列，每条对角线(包括两条主对角线的所有对角线)
         上都至多有一个棋子。

         例如，可以用序列2 4 6 1 3 5来描述一个布局，第i个数字表示
         在第i行的相应位置有一个棋子。

         请遍一个程序找出所有跳棋放置的解。并把它们以上面的
         序列方法输出。解按字典顺序排列。请输出前3个解。
         最后一行是解的总个数。 

 

输入

使一个数字N (6 <= N <= 13) 表示棋盘是N x N大小的。

输出

前三行为前三个解，每个解的两个数字之间用一个空格隔开。
第四行只有一个数字，表示解的总数。

样例输入

6

样例输出

2 4 6 1 3 5 
3 6 2 5 1 4 
4 1 5 2 6 3 
4

提示


回溯
*/