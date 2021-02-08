#include <stdio.h>
int main()
{
  int n, i, j, k;
  while(scanf("%d", &n)!=EOF)
{  int a[n];
  if(n>1&&n<30)
  {
    for (i = k = 0; i < n; i++)
 {
      scanf("%d", &a[k]);
      for (j = 0; j < k; j++)
        if (a[k] == a[j])   //重要:for循环是先计算表达式1，
        {                   //然后计算表达式2，满足条件后
        //  printf("%d ", k); //才执行循环体
          k--;
        }
      k++;
    //  printf("%d\n", k);
    }
  }
    for (i = 0; i < k; i++)
      printf("%d ", a[i]);
    printf("\n");
  }
  }
