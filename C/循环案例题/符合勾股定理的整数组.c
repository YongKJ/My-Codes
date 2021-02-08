#include <stdio.h>
#include <math.h>
int main() 
{
  int a,b,c,i=1;
  for (a = 1; a <= 100; a++)
  for (b = 1; b <= 100;b++)
 {
   c = sqrt(a * a + b * b);
   if(c<=100&&(int)c==c)         
   if(a+b>c&&a+c>b&&b+c>a)
   if(a*a+b*b==c*c||a*a+c*c==b*b||b*b+c*c==a*a)          
   if(c>b&&c>a&&b>a)
   printf("%3d  %3d  %3d        %3d\n", a, b, c, i++);
  }  
}