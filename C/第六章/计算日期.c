#include <stdio.h>
void f(int z,int x,int y)
{
  int i, t=0,s[12];
  for (i = 0; i < 12; i++) 
  {
    if (i == 0 || i == 2 || i == 4 || i == 6 || i == 7 || i == 9 || i == 11)
      s[i] = 31;
    if (i == 3 || i == 5 || i == 8 || i == 10)
      s[i] = 30;
    if (i == 1)
      s[i] = 28;
  }
  if((z%4==0&&z%100!=0)||z%100==0)
    s[1]++;
  for (i = 0; i < x-1; i++)
    t += s[i];
  t += y;
  printf("%d\n", t);
}
struct date 
{
  int year;
  int month;
  int day;
};
int main()
{
  struct date s;
  while (scanf("%d%d%d", &s.year, &s.month, &s.day) != EOF) 
  {
    f(s.year, s.month, s.day);
  }
}