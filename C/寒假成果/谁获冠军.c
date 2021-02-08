#include <stdio.h>
struct f {
  int x, y;
};
int main() {
  struct f b1[4][2] = {0}, b2[4] = {0};
  int i, j, a[4] = {0}, c[5] = {0},s=1;
  do {
    for (i = 0; i < 4; i++) 
    {
      scanf("%d", &a[i]);
      if (a[i] == 0)
        ;
      else if (a[i] == 1)
        s *= 2;
      else if (a[i] == 2)
        s *= 1;
    }
    for (i=0;i<4;i++)
      for (j=0;j<2;j++)
        scanf("%d%d", &b1[i][j].x, &b1[i][j].y);
     while(s--)
     {
     	
     
  } while ('<expression>')