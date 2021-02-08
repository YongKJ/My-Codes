#include <stdio.h>
int main() 
{
  int a , b , c,s =1;
  printf("从三个红球、五个白球、六个黑球中任意取出八个球，且其中必须有白球。\n\n");
  printf("取球方案:\n");
  for (a=1; a <=5; a++)
    for (b = 0; b <= 3; b++) {
      c = 8 - a - b;
      if (c >= 0 && c <= 6)
        printf("方案%2d:%2d个红球，%2d个白球，%2d个黑球\n", s++, b, a, c);
    }
}