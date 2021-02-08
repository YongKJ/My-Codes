#include <stdio.h>
#include <math.h>
int main() 
{
  int a, n;
  long s;
  printf("S=a+aa+aaa+…+aa…aaa(有n个a)之值求解程序\n");
  printf("请输入一个数字和个数:");
  scanf("%d%d", &a, &n);
  s =((pow(10,n+1)-1)/9-1-n)*a/9;//((10(n+1)-1)/9-n-1)*a/9是运行不出结果的!
  printf("s=%ld", s);
}
  