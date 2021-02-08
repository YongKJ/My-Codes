#include <stdio.h>
int main() 
{
  int a , b , c,s =1;
  for (a=1; a <=5; a++)
    for (b = 0; b <= 3; b++) 
    {
      c = 8 - a - b;
      if (c >= 0 && c <= 6)
        printf("方案%2d:%2d个红球，%2d个白球，%2d个黑球\n", s++, b, a, c);
    }
}