#include <stdio.h>
struct date 
{
  int year;
  int month;
  int day;
};
int main()
{
  struct date a,b;
  int x, y, z;
  while (scanf("%d%d%d", &a.year, &a.month, &a.day) != EOF) 
  {
    scanf("%d%d%d", &b.year, &b.month, &b.day);
    x = b.year - a.year;
    y = b.month - a.month;
    z = b.day - a.day;
    if((y>0&&z<0)||(y==0&&z==0))
      printf("%d\n", x);
    else if (x == 0)
      printf("0\n");
    else
      printf("%d\n", --x);
  }
}