#include "stdio.h"
#include "string.h"
int main(int argc, char *argv[]) 
{
  char a[301] = "", b[301] = "", *pl, *ps;
  int t, ll, ls;
  printf("Please enter 2 super-long positive integer...\n");
  scanf("%300[0-9]%*[^0-9]%300[0-9]", a + 1, b + 1); //只接收数字且长度不超300
  a[0] = b[0] = '0'; //留出0号元素处理可能的最高进位
  pl = a, ps = b;
  if ((ll = strlen(a + 1)) < (ls = strlen(b + 1))) //总是让pl指向长一些的字符串
    pl = b, ps = a, t = ll, ll = ls, ls = t; //总是让ll较长
  for (t = ll; ls; pl[t--] += ps[ls--] - '0')
    ;        //把短字符串按字节加至长字符串上
  while (ll) //处理进位
    if (pl[ll--] > '9')
      pl[ll]++, pl[ll + 1] -= 10;
  while (pl[ll] == '0') //消除前导0
    ll++;
  printf("\nThe result is:\n%s\n", pl[ll] ? pl + ll : "0"); //输出结果
  return 0;
}