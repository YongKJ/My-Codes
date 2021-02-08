#include <stdio.h>
#include <string.h>
#define n 201
int main()
{
  char sa[n], sb[n];
  int i, j, la, lb, lsum;
  int a[n] = {0}, b[n] = {0}, sum[n * 2] = {0};
  scanf("%s%s", sa, sb);
  la = strlen(sa);
  lb = strlen(sb);
  for (i = 1, j = la - 1; i <= la; i++, j--)
    a[i] = sa[j] - '0';
  for (i = 1, j = lb - 1; i <= lb; i++, j--)
    b[i] = sb[j] - '0';
  for (i = 1; i <= la; i++)
    for (j=1,lsum=i-1;j<=lb;j++)
      sum[++lsum] += a[i] * b[j];
  for (i = 1; i <= lsum; i++)
    if (sum[i] >= 10) 
    {
      if (sum[lsum] >= 10)
        lsum++;
      sum[i + 1] += sum[i] / 10;
      sum[i] %= 10;
    }
  for (i = lsum; i > 0; i--)
    printf("%d", sum[i]);
  printf("\n");
}