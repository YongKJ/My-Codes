#include <stdio.h>
struct date 
{
  int year;
  int month;
  int day;
};
int f0(int n) 
{
  if ((n % 4 == 0 && n % 100 != 0) || n % 100 == 0)
    return 1;
  else
    return 0;
}
int main()
{
  struct date n, m;
  int i,a,b,c;
  int p[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int r[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  while(scanf("%d%d%d",&n.year,&n.month,&n.day)!=EOF)
  {
    int s = 0;
    scanf("%d%d%d", &m.year, &m.month, &m.day);
    a = m.year - n.year;
    if(a==0)
    {
      if (f0(n.year)) 
      {
        for (i = n.month + 1; i < m.month; i++)
          s += r[i];
        s += r[n.month] - n.day + m.day;
      }
      else 
      {
        for (i = n.month + 1; i < m.month; i++)
          s += p[i];
        s += p[n.month] - n.day + m.day;
      }
    } 
    else 
    {
      for (i = n.year + 1; i < m.year; i++)
        if (f0(i))
          s += 366;
        else
          s += 365;
      for (i = n.month + 1; i <= 12; i++)
        if (f0(n.year))
          s += r[i];
        else
          s += p[i];
      for (i = 1; i < m.month; i++)
        if (f0(m.year))
          s += r[i];
        else
          s += p[i];
      if (f0(n.year))
        s += r[n.month] - n.day + m.day;
      else
        s += p[n.month] - n.day + m.day;
    }
    printf("%d/%d/%d-%d/%d/%d=%d\n", m.year, m.month, m.day, n.year, n.month,
           n.day, s);
  }
}