#include <stdio.h>
void hanoi(int n, char a, char b, char c)
{
  static int i = 1;
  if (n==1)
    printf("%c->%c %d\n", a, c,i++);
    else
   {     
        hanoi(n - 1, a, c, b);
        printf("%c->%c %d\n", a, c,i++);
        hanoi(n - 1, b, a, c);      
    }
}
int main() 
{
  int n;
  scanf("%d", &n);
  hanoi(n, 'A', 'B', 'C');
}