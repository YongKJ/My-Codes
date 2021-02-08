#include <stdio.h>
void swap( int *x, int *y )
{   
int  *p;        
p = x; 
x = y;
y = p;
printf("3）*x=%d，*y=%d\n", *x, *y);
}
int main()
{   
int  a=10, b=20;    
int *p1=&a, *p2=&b;
printf("1）a=%d，b=%d\n", a, b);
swap( p1, p2 );    
printf("2）a=%d，b=%d\n", a, b);    
printf("3）*p1=%d，*p2=%d\n", *p1, *p2);
}