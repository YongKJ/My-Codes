#include <stdio.h>
#include <string.h>
int main()
{
  char str[10005];
  int a[10005],Mp[20] = {1, 1, 2, 6, 4, 2, 2, 4, 2, 8, 4, 4, 8, 4, 6, 8, 8, 6, 8, 2};
  int  len, ret, i, c;
  scanf("%s", str);
  len = strlen(str);
  for (i=len-1;i>=0;i--)
    a[len - 1 - i] = str[i] - '0';
  ret = 1;
  while(len--)
  {
    c = 0;
    ret = ret * Mp[a[1] % 2 * 10 + a[0]] % 10;
    for (i = len - 1; i >= 0; i--) 
    {
      c = c * 10 + a[i];
      a[i] = c / 5;
      c %= 5;
    }
    if (a[len - 1] == 0)
      len--;
  }
  if (strcmp(str, "1")==0 || strcmp(str, "0")==0)
    printf("1\n");
  else
    printf("%d\n", ret);
}