#include <stdio.h>
void hanoi(int n, int a, int b, int c)
{
  static int i = 1;
  if (n==1)
    printf("%d->%d %d\n", a, c,i++);
    else
   {     
        hanoi(n - 1, a, c, b);
        printf("%d->%d %d\n", a, c,i++);
        hanoi(n - 1, b, a, c);      
    }
}
int main() {
  int n;
  scanf("%d", &n);
  hanoi(n, 1, 2, 3);
}