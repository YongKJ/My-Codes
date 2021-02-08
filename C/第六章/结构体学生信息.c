#include <stdio.h>
struct student 
{
  long number;
  char name[50];
  char sex[20];
  int Chinese;
  int math;
  int English;
};
int main() 
{
  struct student a[1000];
  int i, j;
  for(i=0;scanf("%ld",& a[i].number) !=EOF;i++)
    if(a[i].number ==0)
      break;
    else 
      scanf("%s%s%d%d%d", a[i].name, a[i].sex, &a[i].Chinese, &a[i].math,
            &a[i].English);
  for (j = 0; j < i; j++)
    printf("%ld\n%s\n%s\n%d  %d  %d\n", a[j].number, a[j].name, a[j].sex,
           a[j].Chinese, a[j].math, a[j].English);
}