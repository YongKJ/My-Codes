#include <stdio.h>
int main() 
{
  int a, b, c,s=1;
  printf("用一元人民币换成一分、两分、五分。\n\n");
  printf("兑换方案:\n");
  for (a = 0; a <= 20; a++)
    for (b = 0; b <= 50; b++) {
      c = 100 - 5 * a - 2 * b;
      if (c >= 0 && c <= 100)
        printf("方案%3d:%3d张一分,%3d张二分,%3d张五分\n", s++, c, b, a);
    }

    
}
  
    
  