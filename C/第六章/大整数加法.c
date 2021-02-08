#include <stdio.h>
#include <string.h>
int main() 
{
  int i, l, s, t;
  char a[201]="", b[201]="",n[500]="" ,*p, *q;
  scanf("%s", a + 1);
  scanf("%s", b + 1);
  a[0] = b[0] =n[0]= '0';
  p = a;
  q = b;
  l = strlen(a + 1);
  s = strlen(b + 1);
    for (i = l; s; s--, i--)
      n[i] = a[i] + b[s]-'0';
  p = n;
  while (l)
    if (p[l--] > '9')
      p[l]++, p[l + 1] -= 10;
  while (p[l] == '0')
    l++;
  printf("%s\n",p[l]? p + l:"0");
}