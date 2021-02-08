#include <stdio.h>
void main() 
{
  char a;
  printf("从键盘输入一个字母:");
  scanf("%c", &a);
  if (a>= 'A' && a <= 'Z')
   {
    a= a+ 32;
    printf("%c", a);
   } 
   else
   {
    a = a - 32;
    printf("%c", a);
   }
}