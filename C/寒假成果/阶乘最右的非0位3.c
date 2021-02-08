#include<stdio.h>
#include<string.h>
int mod[20]={1,1,2,6,4,2,2,4,2,8,4,4,8,4,6,8,8,6,8,2};
char n[1000];
int a[1000];
int main()
{
 int i,c,t,len;
 scanf("%s", n);
  t=1;
  len=strlen(n); 
  for(i=0;i<len;i++)
   a[i]=n[len-1-i]-'0';
  while (len) 
  {
    len -= !a[len - 1];
    t = t * mod[a[1] % (2 * 10) + a[0]] % 10;
    for (c = 0, i = len - 1; i >= 0; i--)
      c = c * 10 + a[i], a[i] = c / 5, c %= 5;
  }
  printf("%d\n", t);
}