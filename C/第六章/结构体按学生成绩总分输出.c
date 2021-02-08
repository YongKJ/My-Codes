#include <stdio.h>
struct student 
{
  int information;
  int Chinese;
  int math;
  int English;
};
struct add 
{
  int information;
  int sum;
};
int main()
{
  struct student a[20];
  struct add b[20];
  int n,i,j,t;
  while(scanf("%d",&n)!=EOF)
  {
    for (i = 0; i < n; i++) 
    {
      scanf("%d%d%d%d", &a[i].information, &a[i].Chinese, &a[i].math,
            &a[i].English);
      b[i].information = a[i].information;
      b[i].sum = a[i].Chinese + a[i].math + a[i].English;
    }
    for  (i=0;i<n;i++)
      for (j=i+1;j<n;j++)
        if (b[i].sum > b[j].sum) 
        {
          t = b[i].information, b[i].information = b[j].information,
          b[j].information = t;
          t = b[i].sum, b[i].sum = b[j].sum, b[j].sum = t;
        }
    for (i = 0; i < n; i++)
      printf("%d %d\n", b[i].information, b[i].sum);
  }
}