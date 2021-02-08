#include<stdio.h>
void main()
{char  cnum;
 int x,y;
 printf("-------menu------\n");
 printf("1.add(+)\n");
 printf("2.sub(-)\n");
 printf("3.mul(*)\n");
 printf("4.div(/)\n");
 printf("-----------\n");
 printf("please select:");
 scanf("%c",&cnum);
 printf("please input two number:");
 scanf("%d,%d",&x,&y);
 switch (cnum) {
 case '1':
   printf("%d+%d=%d\n", x, y, x + y);
   break;
 case '2':
   printf("%d-%d=%d\n", x, y, x - y);
   break;
 case '3':
   printf("%d*%d=%d\n", x, y, x * y);
   break;
 case '4':
   printf("%d/%d=%d\n", x, y, x / y);
   break;
 default:
   printf("error\n");
 }
}