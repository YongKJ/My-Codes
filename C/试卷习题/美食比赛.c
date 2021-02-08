#include <stdio.h>
struct information 
{
  int number;
  char name[20];
  char study[20];
  int score[10];
  int score1;
};
int main()
{
  struct information a[100],t;
  int i, j,s;
  for (i=0;i<100;i++)
  {
    scanf("%d%s%s", &a[i].number, a[i].name, a[i].study);
    s = 0;
        for (j = 0; j < 10; j++) 
    {
      scanf("%d", &a[i].score[j]);
      s += a[i].score[j];
    }
    a[i].score1 = s/10;
  }
  for (i=0;i<100;i++)
    for (j=i+1;j<100;j++)
      if (a[i].score1 < a[i].score1) 
      {
        t = a[i];
        a[i] = a[j];
        a[j] = t;
      }
  for (i = 0; i < 10; i++) 
  {
    printf("%d %s %s ", a[i].number, a[i].name, a[i].study);
    for (j = 0; j < 10; j++)
      printf("%d ", a[i].score[j]);
    printf("%d\n", a[i].score1);
  }
}