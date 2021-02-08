#include <stdio.h>
void min(int *p) 
{
  int i, j, t;
  for (i = 0; i < 4; i++)
    for (j = i + 1; j < 4; j++)
      if (*(p + i) > *(p + j))
        t = *(p + i), *(p + i) = *(p + j), *(p + j) = t;
}
void max(int *p) 
{
  int i, j, t;
  for (i = 0; i < 4; i++)
    for (j = i + 1; j < 4; j++)
      if (*(p + i) < *(p + j))
        t = *(p + i), *(p + i) = *(p + j), *(p + j) = t;
}
int compare(int *p, int *q) 
{
  int i, t = 0;
  for (i = 0; i < 4; i++)
    if (*(p + i) == *(q + i))
      t++;
  if (t == 4)
    return 1;
  else
    return 0;
}
int main()
{
  int n, i, j, a1[100][4] = {0}, a2[100][4] = {0}, a3[100][4] = {0},
               c[4] = {6, 1, 7, 4}, *q,k;
  q = c;
  while(scanf("%d",&n)!=EOF)
  {
    int *b1[n],*b2[n],*b3[n];
    for (i = 0; i < n; i++) 
    {
      for (j = 3; j >= 0; j--)
        scanf("%d", &a1[i][j]), a2[i][j] = a1[i][j];
      b1[i] = a1[i], b2[i] = a2[i], b3[i] = a3[i];
    }
    for (i=0;i<n;i++)
      max(b1[i]), min(b2[i]);
    for (i = 0; i < n;i++)
    {
      k = 0;
      while (compare(b3[i], q) != 1) 
      {
        for (j = 0; j < 4; j++)
          *(b3[i] + j) = *(b1[i] + j) - *(b2[i] + j);
        for (j = 0; j + 1 < 4; j++)
          if (*(b3[i] + j) < 0)
            *(b3[i] + j) += 10, *(b3[i] + j + 1) -= 1;
        if (compare(b3[i], q) != 1)
          k++;
        else
          printf("%d\n", k);
      }
    }
  }
}
      
    
      
    