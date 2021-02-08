#include <stdio.h>
void main() {
  int y, m;
  printf("请输入年份和月份:");
  scanf("%d%d", &y, &m);
  switch (m) 
  {
  	
  case 1:
  case 3:
  case 5:
  case 7:
  case 8:
  case 10:
  case 12:
    printf("%d月的天数:31", m);
    break;
  case 4:
  case 6:
  case 9:
  case 11:
    printf("%d月的天数:30", m);
    break;
  case 2:
    if ((y % 4 == 0 && y % 100 != 0) || y % 100 == 0)
      printf("%d月的天数:29", m);
    else
      printf("%d月的天数:28", m);
  }
}