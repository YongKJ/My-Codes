#include <stdio.h>
#include <string.h>
void count(char *p1[15], char *p3[17], int *q1[15], int m) 
{
  int i, j;
//  printf("3\n");
  for (i = 0; i < m; i++)
    for (j = 0; j < 15; j++)
      if (strcmp(p3[i],p1[j]) == 0) 
       *q1[j]+=1;
}
int rocket(int *q1[15]) 
{
  int a, b;
  a = *q1[13];
  b = *q1[14];
  //printf("%d %d\n", *q1[13],*q1[14]);
  if (a == 1 && b == 1)
    return 1;
  else
    return 0;
}
int bomb(int *q1[15]) {
  int i, a = 0;
  for (i = 0; i < 13; i++)
    if (*q1[i] == 4)
      a++;
  if (a == 1)
    return 1;
  else
    return 0;
}
int dui(int *q1[15]) 
{
  int i,a=0;
  for (i = 0; i < 13; i++)
    if (*q1[i] == 2)
      a++;
      if(a==1)
      return 1;
    else 
      return 0;  
}
int sang(int *q1[15]) {
  int i,a=0;
  for (i = 0; i < 13; i++)
    if (*q1[i] == 3)
      a++;
      if(a==1)
      return 1;
    else
      return 0;
}
int threeyi(int *q1[15]) {
  int i, a = 0, b = 0, c = 0;
  for (i = 0; i < 15; i++)
    if (*q1[i] == 3&&i<=13)
      a++;
    else if (*q1[i] == 1)
      b++;
    else if (*q1[i] == 2&&i<=13)
      c++;
  if ((a == 1 && b == 1) || (a == 1 && c == 1))
    return 1;
  else
    return 0;
}
int danshun(int *q1[15],int m) {
  int i, a = 0, b, c;
  for (i = 0; i < 12; i++) {
    if (*q1[i] == 1)
      a++;
    if (a == 1)
      b = i;
    if (a == m) 
    {
      c = i;
      break;
    }
  }
/*  for (i=0;i<12;i++)
    printf("%d\n", *q1[i]);
  printf("%d %d %d %d\n", b ,c,m,a);*/
  if (c - b == m - 1)
    return 1;
  else
    return 0;
}
int shuangshun(int *q1[15]) 
{
  int i, a = 0;
  for (i = 0; i < 12; i++)
    if (*q1[i] == 2)
      a++;
  if (a >= 3)
    return 1;
  else
    return 0;
}
int sanshun(int *q1[15]) {
  int i, a = 0;
  for (i = 0; i < 12; i++)
    if (*q1[i] == 3)
      a++;
  if (a >= 2)
    return 1;
  else
    return 0;
}
int feiji(int *q1[15]) {
  int i, a, b, c, f,t;
  a = b = c = f = 0;
  for (i = 0; i < 13; i++) {
    t = *q1[i];
    if (t == 3)
      a++;
    else if (t == 4)
      f++;
    else if (t == 1)
      b++;
    else if (t == 2)
      c++;
  }
  if ((a != 0 && (a == b || a == c)) || (f == 1 && (b==2 || c==2)))
    return 1;
  else
    return 0;
}
int main()
{
  char s1[15][10] = {"3", "4", "5", "6", "7", "8",  "9", "10",
                     "J", "Q", "K", "A", "2", "J1", "J2"},
       *p1[15],s3[17][10] = {"\0"}, *p3[17];
  int  c1[15], *q1[15],m, n, i, j;
  for (i = 0; i < 15; i++) {
    p1[i] = s1[i];
    q1[i] = &c1[i];
  }
  for (i=0;i<17;i++)
    p3[i] = s3[i];
  scanf("%d", &n);
  if(n>0&&n<=50)
  for (i=0;i<n;i++)
  {
    for (j=0;j<15;j++)
      c1[j] = 0;
    for (j=0;j<17;j++)
      memset(s3[i], 0, sizeof(s3[i]));
    scanf("%d", &m);
    for (j = 0; j < m; j++) 
      scanf("%s", s3[j]);
    //printf("1\n");
    count(p1, p3, q1, m);
    //printf("2\n");
    if (m == 1)
      printf("Case #%d: Yes\n", i + 1);
    else if (m == 2 && rocket(q1))
      printf("Case #%d: Yes\n", i + 1);
    else if (m == 2 && dui(q1))
      printf("Case #%d: Yes\n", i + 1);
    else if (m == 3 && sang(q1))
      printf("Case #%d: Yes\n", i + 1);
    else if (m == 4 && bomb(q1))
      printf("Case #%d: Yes\n", i + 1);
    else if ((m == 4 || m == 5) && threeyi(q1))
      printf("Case #%d: Yes\n", i + 1);
    else if (m >= 5 && danshun(q1, m))
      printf("Case #%d: Yes\n", i + 1);
    else if (m >= 6 && (shuangshun(q1)||sanshun(q1)))
      printf("Case #%d: Yes\n", i + 1);
    else if (m >= 6 && feiji(q1))
      printf("Case #%d: Yes\n", i + 1);
    else 
      printf("Case #%d: No\n", i + 1);
  }
}