#include <stdio.h>
int DiJiTian(int year, int month, int day);
int isRunNian(int year);
void swap(int *a, int *b);
struct date 
{
  int year1;
  int month1;
  int day1;
};
int main()
{
        struct date x, y;
        int i;
	while(scanf("%d %d %d", &x.year1, &x.month1, &x.day1)!=EOF)
	{
         int result = 0;
	scanf("%d %d %d", &y.year1, &y.month1, &y.day1);
        if(x.year1 == y.year1)
	 {
	  result = DiJiTian(x.year1,x. month1,x. day1) - DiJiTian(y.year1, y.month1, y.day1);
          if(result < 0)
	  result = 0 - result;	
	 }
	 else
	 {
           if (x.year1 > y.year1) 
           {
             swap(&x.year1, &y.year1);
             swap(&x.month1, &y.month1);
             swap(&x.day1, &y.day1);
           }
           int a, b, c;
           if (isRunNian(x.year1))
             a = 366 - DiJiTian(x.year1, x.month1, x.day1);
           else
             a = 365 - DiJiTian(x.year1, x.month1, x.day1);
           b = 0;
           for ( i = x.year1 + 1; i < y.year1; i++)
             if (isRunNian(i))
               b += 366;
             else
               b += 365;
           c = DiJiTian(y.year1, y.month1, y.day1);
           result = a + b + c;
         }
         printf("%d/%d/%d-%d/%d/%d=%d\n", y.year1, y.month1, y.day1, x.year1,
                x.month1, x.day1, result);
        }
}
int isRunNian(int year) {
  int result;
  if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
    result = 1;
  else
    result = 0;
  return result;
}
int DiJiTian(int year, int month, int day)
{
	int result = 0,i;
	for( i = 1; i < month; i++)
	{ 
	if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)
	result += 31;	
	else if (i == 4 || i ==6 || i == 9 || i==11)
	result += 30;
        else if (i == 2) 
          {
          if (isRunNian(year))
        result += 29;
          else
        result += 28;
                }
        }
        result += day;
        return result;
}
void swap(int *a, int *b) 
{
  int e;
  e = *a;
  *a = *b;
  *b = e;
}