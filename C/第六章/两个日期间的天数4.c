#include <stdio.h>
int DiJiTian(int year, int month, int day);
int isRunNian(int year);
void swap(int *a, int *b);
int main()
{
	int year1, month1, day1;
	int year2, month2, day2;
	int result = 0;
	scanf("%d %d %d", &year1, &month1, &day1);
	scanf("%d %d %d", &year2, &month2, &day2);
     if(year1 == year2)
	 {
	  result = DiJiTian(year1, month1, day1) - DiJiTian(year2, month2, day2);
          if(result < 0)
		  {
		    result = 0 - result;
          }	
	 }//情况1的代码
	 else
	 {
	 	if(year1 > year2)
	 	{
	     swap(&year1, &year2);
	     swap(&month1, &month2);
	     swap(&day1, &day2);
         }
         int a, b, c;
          if(isRunNian(year1))
          {
	      a = 366 - DiJiTian(year1, month1, day1);
          }
          else
          {
	      a = 365 - DiJiTian(year1, month1, day1);
          }//计算a的代码
          b = 0;
          for(int i = year1 + 1; i < year2; i++)
		  {
	        if(isRunNian(i))
	        {
		     b += 366;
	         }
	         else
	         {
	       	 b += 365;
	         }
          }  //计算b的代码
          c = DiJiTian(year2, month2, day2);
            //计算c的代码
          result = a + b + c;
          //情况2的代码	
     }
	printf("%d\n", result);
	return 0;
}
int isRunNian(int year)
{
	int result;
	if(year%400 == 0 ||(year%4==0 && year%100!=0))
	{
		result = 1;
	} 
	else
	{
		result = 0;
	}
      return result;	
}//判断闰年的函数
int DiJiTian(int year, int month, int day)
{
	int result = 0;
	for(int i = 1; i < month; i++)
	{ 	//step1
		if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)
		{
			result += 31;	
		} 
		else if (i == 4 || i ==6 || i == 9 || i==11)
		{
			result += 30;
		}
		 else if(i == 2 )
		 {
			if(isRunNian(year))
			{
				result += 29;
			} else {
				result += 28;
			}	
		}
	}
	result += day;	//step2
	return result;	
}//求解某一日期是当年的第几天的函数
	void swap(int *a, int *b)
	{
			int e;
			e = *a;
			*a = *b;
			*b = e; 
	}//交换两个变量的值的函数