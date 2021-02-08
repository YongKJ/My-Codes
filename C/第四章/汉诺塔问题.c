#include <stdio.h>
void hanoi(int n, char a, char b, char c)
{
  int s = 1;
  if (n==1)
    printf("%c-->%c     此时的abc:%c,%c,%c\n", a, c,a,b,c);
    else
   {     
        hanoi(n - 1, a, c, b);
        printf("%c-->%c %d   此时的ABC:%c,%c,%c\n", a, c,s,a,b,c);
        hanoi(n - 1, b, a, c);      
    }
}
 int main() 
 {
   int n;
   printf("input number:\n");
   scanf("%d", &n);
   printf("the step to moving %2d diskes:\n", n);
   hanoi(n, 'A', 'B', 'C');
 }