#include <stdio.h>
#include<math.h>
int main()
{
int n,i,j;
double x,y;
y=0;
n=1;
scanf("%lf",&x);
while(n<=10){
i=1;
j=1;
while (i <= (2 * n - 1)) {
  j = j * i;
  i = i++;
}
y = y + (pow(-1, n - 1) * pow(x, 2 * n - 1) / j);
n = n++;
}
printf("sin(x)=%.2f\n", y);
return 0;
}