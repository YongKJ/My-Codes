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
  struct information a;
    scanf("%ld%s%s%s%d%s%d%d%d", &a.number, a.name, a.sex, a.identity,
          &a.salary, a.address,&a.s.year,&a.s.month,&a.s.day);
    printf("%ld\n%s\n%s\n%s\n%d\n%s\n%d/%d/%d\n", a.number, a.name, a.sex, a.identity,
           a.salary, a.address, a.s.year, a.s.month, a.s.day);
}