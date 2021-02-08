#include<stdio.h>
#include<math.h>
int a,b,c,d;
float f(float x)
{ float y;
y=((a*x+b)*x+c)*x+d;
return(y);
}
float f1(float x)
{ float y;
y=(3*a*x+2*b)*x+c;
return(y);
}
int main()
{ double x0,x1;
printf("请输入a,b,c,d的值:\n");
scanf("%d,%d,%d,%d",&a,&b,&c,&d);
x1=2.5;
do
{
x0=x1;
x1=x0-f(x0)/f1(x0);
} 
while (fabs(x1 - x0) >= 0.00001);
printf("%f",x1);
}
