#include<stdio.h>
void swap(int *x,int *y)
{
  int t;
  t = *x;
  *x = *y;
  *y = t;
}
int main()
{
  int m, n;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        swap(&n,&m);
        printf("%d %d\n",n,m);
    }
    return 0;
}

 