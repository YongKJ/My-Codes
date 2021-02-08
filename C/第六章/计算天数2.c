#include<stdio.h>
void main()
{
	struct day
	{
		int year;
		int month;
		int date;
	}d;//定义结构体变量d。
	scanf("%d%d%d",&d.year,&d.month,&d.date);
        //输入年、月、日。
	int m[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int i,days=0;
	if ((d.year%400==0)||((d.year%100!=0)&&(d.year%4==0))) 
	m[1]++;
	for(i=0;i<d.month-1;i++)
		days+=m[i];
	days+=d.date;
	printf("%d\n",days);//输入该日在本年中是第几天。
}