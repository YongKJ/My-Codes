#include <stdio.h>
main()
{  int year,year1,month,month1,day,day1,age;
printf("请输入您的生日:");
scanf("%d  %d  %d",&year,&month,&day);
printf("请输入当前日期:");
scanf("%d  %d  %d",&year1,&month1,&day1);
if(year1==year)
   age=0;
else {
  age = year1 - year;
  if (month1 < month || (month1 == month && day1 < day))
    age = age - 1;
}
printf("您的年龄是:%d", age);
}