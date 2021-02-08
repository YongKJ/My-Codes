#include <stdio.h>
int main() {
  int x,c;
  double y;
  while (scanf("%d", &x) != EOF) 
  {
    if (x > 1000000)
      c = 10;
    else
      c = x / 100000;
    switch (c) 
  {
    case 0:y = 0.1 * x;break;
    case 1:y = 10000 + 0.075 * (x - 100000);break;
    case 2:
    case 3:y =17500+ 0.05 * (x - 200000);break;
    case 4:
    case 5:y = 27500 + 0.03 * (x - 400000);break;
    case 6:
    case 7:
    case 8:
    case 9:y = 33500+0.015 * (x - 600000);break;
    case 10:y = 39500+ 0.01 * (x - 1000000);break;
    	}
    printf("%.0f\n", y);
  }
  return 0;
    
  }