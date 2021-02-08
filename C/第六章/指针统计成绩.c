#include <stdio.h>
float f0(float x) 
{
  float a;
  int t;
  a = x * 10;
  a += 0.5;
  t = a;
  x = t / 10.0;
  return x;
}
void f1(long a[100][20],int n)
{
  double s[100] = {0};
  int i, j;
  for (i = 0; i < n; i++) 
  {
    for (j = 1; j < 6; j++)
      s[i] += a[i][j];
    s[i] /= 5.0;
  }
  for (i = 0; i < n; i++) 
  {
    for (j = 0; j < 6; j++)
    printf("%ld ", a[i][j]);
    printf("%.1lf\n",s[i]);
  }
}
void f2(long *s[],int n)
{
  float b[5] = {0};
  int i, j,t=1;
  for (i = 0; i < 5; i++) 
  {
    for (j = 0; j < n; j++)
    b[i] += *(s[j] + t);
    b[i] /= (n*1.0);
    t++;
  }
  for (i = 0; i < 5; i++)
  if(i==4)
    printf("%.1f", f0(b[i]));
  else
    printf("%.1f ", f0(b[i]));
  printf("\n");
}
int main() 
{
  long *s[100], a[100][20] = {0};
  int i, j, n;
  scanf("%d", &n);
  for (i = 0; i < n; i++)
    for (j = 0; j < 6; j++)
      scanf("%ld", &a[i][j]);
  for (i = 0; i < n; i++)
    s[i] = a[i];
  f1(a, n);
  f2(s, n);
}