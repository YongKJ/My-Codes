#include <stdio.h>
#include <stdlib.h>

int main()
{
    int s = 1;
    int h;                    // 数值和高度
    int i;
    int j;                        // 循环计数

    scanf("%d", &h);                 // 输入层数
    printf("1\n");                   // 输出第一个 1
    for (i = 2; i <= h; s = 1, i++)         // 行数 i 从 2 到层高
    {
printf("1 ");                // 第一个 1
for (j = 1; j <= i - 2; j++) // 列位置 j 绕过第一个直接开始循环
{
  // printf("%d ", (s = (i - j) / j * s));
  printf("%d ", (s = (i - j) * s / j));
}
printf("1\n"); // 最后一个 1，换行
    }
    getchar(); // 暂停等待

    return 0;
}