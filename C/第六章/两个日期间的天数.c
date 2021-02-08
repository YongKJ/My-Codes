#include <stdio.h>
int x1[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int y1[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
struct date 
{
  int year;
  int month;
  int day;
};
struct date m, n;
int a, b, c;
int f0(int n) 
{
  if ((n % 4 == 0 && n % 100 != 0) || n % 100 == 0)
    return 1;
  else
    return 0;
}
int f1(int x, int y) 
{
  int i, s = 0;
  for (i = x+1 ; i < y; i++)
    if (f0(i))
      s += 366;
    else
      s += 365;
  return s;
}
int f2(int year1,int x,int year2,int y)
{
  int s = 0, i;
      if (f0(year1))
    for (i = x; i < 12; i++)
      s += y1[i];
    else
      for (i=x;i<12;i++)
      s += x1[i];
     if (f0(year2))
    for (i = 0; i <y-1; i++)
      s += y1[i];
    else
      for (i=0;i<y-1;i++)
      s += x1[i];
  return s;
}
int f3(int year1,int x,int x2)
{
  int i, s = 0;
  if (x == 2 ) 
  if (f0(year1))
  s += 29 - x2;
  s += x1[x - 1] - x2;
  return s;
}
int main()
{
  int i;
  while (scanf("%d%d%d", &n.year, &n.month, &n.day) != EOF) 
  {
    int s = 0;
    scanf("%d%d%d", &m.year, &m.month, &m.day);
    a = m.year - n.year;
    if (a != 0) 
    {
      s += f1(n.year, m.year);
      s += f2(n.year, n.month, m.year, m.month);
      s += f3(n.year, n.month, n.day);
      s += m.day;
    }
    if (a == 0) 
    {
      for (i = n.month; i < m.month-1; i++)
        if (f0(n.year))
          s += y1[i];
        else
          s += x1[i];
      s += f3(n.year, n.month, n.day);
      s += m.day;
    } 
    printf("%d/%d/%d-%d/%d/%d=%d\n",m.year,m.month,m.day,n.year,n.month,n.day, s);
  }
}