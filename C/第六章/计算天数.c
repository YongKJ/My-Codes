#include <stdio.h>
int main()
{
  int n, m;
  while(scanf("%d%d",&n,&m)!=EOF)
  {
    switch (m) 
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      printf("31\n");
      break;
    case 4:
    case 6:
    case 9:
    case 11:
      printf("30\n");
      break;
    case 2:
      if ((n % 4 == 0 && n % 100 != 0) || n % 100 == 0) 
      {
        printf("29\n");
        break;
      }
       else 
       {
        printf("28\n");
        break;
      }
    }
  }
}