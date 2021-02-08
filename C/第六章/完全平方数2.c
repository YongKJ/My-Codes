#include <stdio.h>
#include <math.h>
int main()
{
 int i,a,b,c,d;
 printf("形如aabb的四位完全平方数为:");
 for(i=1000;i<10000;i++){
  a=i/1000;
  b=i/100%10;
  c=i/10%10;
  d=i%10;
  if(a==b && c==d && sqrt(i)==(int)sqrt(i)){
   printf("%d ",i);
  }  
 }
 return 0;
} 