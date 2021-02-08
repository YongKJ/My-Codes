#include <stdio.h>
struct date 
{
  int year;
  int month;
  int day;
};
struct information 
{
  long number;
  char name[10];
  char sex[10];
  char identity[100];
  int salary;
  char address[100];
  struct date s;
};
int main() 
{
  struct information a[6];
  int i,s=0,t=0;
  for (i = 0; i < 6; i++) 
  {
    scanf("%ld%s%s%s%d%s", &a[i].number, a[i].name, a[i].sex, a[i].identity,
          &a[i].salary, a[i].address);
          if(a[i].salary>t)
            t = a[i].salary;
          s += a[i].salary;    
  }
  printf("%d %d\n", t, s);
}