#include <stdio.h>
int main()
{
  FILE *f;
  float n;
  int a, b, c;
  a = b = c = 0;
  f = fopen("num.txt", "r");
  while(fscanf(f,"%f",&n)!=EOF)
    if ((int)n == n) 
    {
      if (n > 0)
        a++;
      else if (n < 0)
        c++;
      else
        b++;
    }
  printf("%d %d %d\n", a, b, c);
}