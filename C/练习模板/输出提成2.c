#include <stdio.h>
int main()
{
int c,a;
float  b,d1,d2,d3,d4,d5,d6;
scanf("%d", &a);
d1 = a*0.1;
d2 = 10000 + (a - 100000)*0.075;
d3 = 17500 + (a - 200000)*0.05;
d4 = 27500 + (a - 400000)*0.03;
d5 = 33500 + (a - 600000)*0.015;
d6 = 39500 + (a - 1000000)*0.01;
if (a > 1000000) c = 10;
else c = a / 100000;
switch (c)
{
 case 0:b = d1;break;
case 1:b = d2;break;
case 2:
case 3:b = d3;break;
case 4:
case 5:b = d4;break;
case 6:
case 7:
case 8:
case 9:b = d5;break;
case 10:b = d6;break;
}
printf("%.0f\n", b);
}