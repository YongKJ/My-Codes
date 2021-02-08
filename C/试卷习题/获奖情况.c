#include <stdio.h>
struct information 
{
  int number;
  char name1[20];
  char name2[20];
  int score[20];
  int score1;
};
int main()
{
  struct information a[100],t;
  int i, j,s;
  for (i = 0; i < 100; i++) 
  {
    scanf("%d%s%s", &a[i].number, a[i].name1, a[i].name2);
    s = 0;
    for (j = 0; j < 20; j++) 
    {
      scanf("%d", &a[i].score[j]);
      s += a[i].score[j];
    }
    a[i].score1=s;
  }
  for (i = 0; i < 100;i++)
    for (j=i+1;j<100;j++)
      if (a[i].score1 < a[j].score1) 
      {
        t = a[i];
        a[i] = a[j];
        a[j] = t;
      }
  printf("一等奖:\n");
  for (i = 0; i < 2; i++)
    printf("%s %s %d\n", a[i].name1, a[i].name2, a[i].score1);
  printf("二等奖:\n");
  for (i = 2; i < 5; i++)
    printf("%s %s %d\n", a[i].name1, a[i].name2, a[i].score1);
  printf("三等奖:\n");
  for (i = 5; i < 10; i++)
    printf("%s %s %d\n", a[i].name1, a[i].name2, a[i].score1);
}
  