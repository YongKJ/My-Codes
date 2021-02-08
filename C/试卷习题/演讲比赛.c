#include <stdio.h>
struct data 
{
  int number;
  char name[20];
  int score[6];
  int score1;
};
int main()
{
  struct data a[50], t;
  int i, j,s;
  for (i = 0;i<50;i++)
  {
    scanf("%d%s", &a[i].number, a[i].name);
    s = 0;
    for (j = 0; j < 6; j++) 
    {
      scanf("%d", &a[i].score[j]);
      s += a[i].score[j];
    }
    a[i].score1 = s / 6;
  }
  for (i=0;i<50;i++)
    for (j=i+1;j<50;j++)
      if (a[i].score1 < a[j].score1) 
      {
        t = a[i];
        a[i] = a[j];
        a[j] = t;
      }
  printf("%d,%s,", a[0].number, a[0].name);
  for (i = 0; i < 6; i++)
    printf("%d ", a[0].score[i]);
  printf("%d\n", a[0].score1);
}