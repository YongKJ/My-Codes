#include <math.h>
#include <stdio.h>
int main(void) 
{
  double a, b, c, m, n, x1, x2,w, t;
  printf("一元二次方程实数根及顶点求解程序\n\n");
  printf("输入二次项前的系数a:");
  scanf("%lf", &a);
  printf("输入一次项前的系数b:");
  scanf("%lf", &b);
  printf("输入常数项系数c:");
  scanf("%lf", &c);
  w = b*b-4*a*c;
  t = sqrt(w);
   m = b / (-2 * a);
   n = (4*a*c-b*b)/4*a;
  if (a == 0)
 {
    printf("该方程不是一元二次方程！\n");
  }
  else if (w> 0) 
  {
    x1 = (-b- t) / 2 * a;
    x2 = (-b+ t) / 2 * a;
    printf("实数根x1=%5.2f,实数根x2=%5.2f\n", x1, x2);
    printf("顶点坐标(%5.2f,%5.2f)\n", m, n);
  }

  else if (w== 0) 
 {
    x1 = x2 = (-b+ t) / 2 * a;
    printf("实数根x1=%5.2f,实数根x2=%5.2f\n", x1, x2);
    printf("顶点坐标(%5.2f,%5.2f)\n", m, n);
  } 
    else
  {
    printf("该一元二次方程无实数根!\n");
    printf("顶点坐标(%5.2f,%5.2f)\n", m, n);
  }
  return 0;
}
    
  