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
  int x;
  while (scanf("%d%d%d", &a.year, &a.month, &a.day) != EOF) 
  {
    scanf("%d%d%d", &b.year, &b.month, &b.day);
    if(a.year==b.year)
      printf("0\n");
    else 
    {
      x = b.year - a.year;
      if (b.month < a.month || (b.month == a.month && b.day < a.day))
        x--;
    }
    printf("%d\n", x);
  }
}