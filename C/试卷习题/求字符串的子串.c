#include <stdio.h>
void f(char *s1,int start,int len,char *s2)
{
  char *k,*c;
  k = s1 + start - 1;
  c = s1 + start + len - 1;
  while (k <= c) 
  {
    *s2 = *k;
    s2++;
    k++;
  }
}

int main()
{
  char s1[100] = {0}, s2[100] = {0};
  int n, m,i;
  fgets(s1, 100, stdin);
  scanf("%d%d", &n, &m);
  f(&s1[0], n, m, &s2[0]);
    for (i = 0; i < m; i++)
      if (s2[i] != 0)
        printf("%c", s2[i]);
    printf("\n");
}