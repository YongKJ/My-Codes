#include <stdio.h>
#include <string.h>
static int x;
void paixu(char *p[15],char *q1[12],char *q2[12],int m)
{
  int i, j, t;
  for (i = 0, t = 0; i < 15; i++) 
  {
    for (j = 0; j < m; j++)
      if (strcmp((p[i]), (q1[j])) == 0) 
      {
     //   printf("%s ", p[i]);
        strcpy(q2[t++], p[i]);
      //  printf("%s\n", q2[t-1]);
      }
    if (t == m)
      break;
  }
}
int rocket(char *p[15], char *q2[12]) 
{
  int m, n;
  m = strcmp(p[13] , q2[0]);
  n = strcmp((p[14]), q2[1]);
  if (m == 0 && n == 0)
    return 1;
  else
    return 0;
}
int threezhang(char *p[15],char *q2[12],int m)
{
  int i, j, t, a, b, c, d, f;
  if (m == 3) 
  {
    for (i = 0; i < 15; i++)
      if (strcmp(p[i], q2[0]) == 0)
        break;
    b = strcmp(p[i], q2[1]);
    c = strcmp(p[i], q2[2]);
    if (b==0&&b == c)
      return 1;
  }
 else if (m == 4) 
  {
    for (i = 0; i < 15; i++)
      if (strcmp(p[i], q2[0])==0)
        break;
    b = strcmp(p[i], q2[1]);
    c = strcmp(p[i], q2[2]);
    for (j=0;j<15;j++)
      if (strcmp(p[j], q2[3])==0)
        break;
    d = strcmp(p[i], p[j]);
    if (b==0&&b == c&&d!=0)
      return 1;
    for (i = 0; i < 15; i++)
      if (strcmp(p[i], q2[1])==0)
        break;
    b = strcmp(p[i], q2[2]);
    c = strcmp(p[i], q2[3]);
 for (j=0;j<15;j++)
      if (strcmp(p[j], q2[0])==0)
        break;
    d = strcmp(p[i], p[j]);
    if (b==0&&b == c&&d!=0)
      return 1;
  }
  else if (m == 5) 
  {
    for (i = 0; i < 15; i++)
      if (strcmp(p[i], q2[0])==0)
        break;
    b = strcmp(p[i], q2[1]);
    c = strcmp(p[i], q2[2]);
    for (j = 0; j < 15; j++)
      if (strcmp(p[j], q2[3])==0)
        break;
    d = strcmp(p[j], q2[4]);
    f = strcmp(p[i], p[j]);
    if (f!=0 && b == 0 && b == c && d == 0)
      return 1;
    for (i = 0; i < 15; i++)
      if (strcmp(p[i], q2[2])==0)
        break;
    b = strcmp(p[i], q2[3]);
    c = strcmp(p[i], q2[4]);
    for (j = 0; j < 15; j++)
      if (strcmp(p[j], q2[0])==0)
        break;
    d = strcmp(p[j], q2[1]);
    f = strcmp(p[i], p[j]);
    if (f!=0 && b == 0 && b == c && d == 0)
      return 1;
   else
     return 0;
  }
}
int bomb(char *p[15], char *q2[12], int m) 
{
  int i, j, t, a, b, c;
  for (i = 0; i < 15; i++)
    if (strcmp(p[i], q2[0])==0)
      break;
  a = strcmp(p[i], q2[1]);
  b = strcmp(p[i], q2[2]);
  c = strcmp(p[i], q2[3]);
  if (a == 0 && a == b && a == c && b == c)
    return 1;
  else
    return 0;
}
int wulian(char *p1[12],char *q2[12],int m)
{
  int i, j, t;
  for (i = 0; i < 12; i++)
    if (strcmp(p1[i], q2[0]) == 0) 
      break;
  for (j = 0; j < m; j++)
    if (strcmp(p1[i+ j], q2[j]) != 0)
      break;
  if (j == m)
    return 1;
  else
    return 0;
}
int shuangshun(char *p1[12],char *q2[12],int m)
{
  int i, j,l,k=0,t1=0;
  char *t[12];
  for (i = 0; i < m; i += 2) 
  {
    for (j = 0; j < 12; j++)
      if (strcmp(q2[i], p1[j]) == 0)
        t[k++] = p1[j];
  }
  /*  for (i=0;i<6;i++)
      printf("%s\n", t[i]);*/
  for (i = 0, j = 1; j < m; i++, j += 2)
    if (strcmp(t[i], q2[j]) != 0)
      break;
  for (i=0;i<k;i++)
    for (l=i+1;l<k;l++)
      if (strcmp(t[i], t[l]) == 0)
        t1++;
  if (j == m + 1&&t1==0)
    return 1;
  else
    return 0;
}
int threeshun(char *p1[12], char *q2[12], int m)
{
  int i, j, k=0,l,t1=0;
  char *t[12];
  for (i = 0; i < m; i += 3) 
  {
    for (j = 0; j < 12; j++)
      if (strcmp(q2[i], p1[j]) == 0) 
      {
        t[k++] = p1[j];
        break;
      }
  }
  for (i = 0, j = 1, l = 2; i < k; i++, j += 3, l += 3) 
  {
    if (strcmp(t[i], q2[j]) != 0)
      break;
    if (strcmp(t[i], q2[l]) != 0)
      break;
  }
  for (j=0;j<k;j++)
    for (l = j + 1; l < k;l++)
      if (strcmp(t[j], t[l]) == 0)
        t1++;
  //printf("%d\n", i);
  if (i==k&&t1==0)
    return 1;
  else
    return 0;
}
int main()
{
  char s[15][10] = {  "3", "4", "5", "6",  "7", "8",
                    "9", "10", "J", "Q", "K", "A","2","J1", "J2"},*p[15];
  char s1[12][10] = {"3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K","A"},
       *p1[12];
  int i, j, t, m, n;
  for (i=0;i<15;i++)
    p[i] = s[i];
  for (i=0;i<12;i++)
    p1[i] = s1[i];
  scanf("%d",&n);
    for (i = 0,x=1; i < n; i++,x++) 
    {
      char s1[12][10] = {"\0"}, s2[12][10] = {"\0"}, *q1[12], *q2[12];
      scanf("%d", &m);
      for (j = 0; j < m; j++) 
      {
        scanf("%s", s1[j]);
        q1[j] = s1[j];
        q2[j] = s2[j];
      }
      paixu(p, q1, q2, m);
 /*  for (j=0;j<m;j++)
        printf("%s\n", s2[j]);*/
      if (m == 1)
        printf("Case #%d: Yes\n",x);
    //  printf("Case #%d: No\n", x);
        else if(m==2&&rocket(p, q2))
          printf("Case #%d: Yes\n", x);
        else if ((m == 4 && bomb(p, q2, m)))
          printf("Case #%d: Yes\n", x);
        else if((m==3||m==4||m==5)&&threezhang(p,q2,m))
            printf("Case #%d: Yes\n", x);
        else if (m >=5&&wulian(p1, q2, m))
          printf("Case #%d: Yes\n", x);
        else if (m >= 6 && (shuangshun(p1, q2, m)||threeshun(p1,q2,m)))
          printf("Case #%d: Yes\n", x);
        else
          printf("Case #%d: No\n", x);
    }
}