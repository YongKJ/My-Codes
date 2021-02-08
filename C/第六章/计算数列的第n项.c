#include<stdio.h>
int main()
{
long f[151],a,b,n,i;
while (scanf("%ld%ld%ld", &a, &b, &n) != EOF) {
  if (a == 0 && b == 0 && n == 0)
    break;
  // f[0]=0;
  f[1] = f[2] = 1;
  for (i = 3; i <= 150; i++)
    f[i] = (a * f[i - 1] + b * f[i - 2]) % 11;
  for (i = 1; i <= 150; i++) 
  {
    printf("%3ld ", f[i]);
    if (i % 10 == 0&&i != 0)
      printf("\n");
  }
}
return 0;
}