#include <iostream>
#include <cstdio>
using namespace std;
int leapyear(int year)
{
	if((year%4==0&&year%100!=0)||year%400==0)
	return 1;
	else return 0;
}
int monthdays(int year,int month)
{
	int i;
	switch(month)
	{
		case 1:i=31;break;
		case 2:i=leapyear(year)==1?29:28;break;
		case 3:i=31;break;
		case 4:i=30;break;
		case 5:i=31;break;
		case 6:i=30;break;
		case 7:i=31;break;
		case 8:i=31;break;
		case 9:i=30;break;
		case 10:i=31;break;
		case 11:i=30;break;
		case 12:i=31;break;
		default:i=0;break;
	}
		return i;
}
int main()
{
	int year,month,day,s;
	while(scanf("%d/%d/%d",&year,&month,&day)!=EOF)
	{
		s=0;
		for(int i=1;i<month;i++)
		s+=monthdays(year,i);
		s+=day;
		cout<<s<<endl;
	 }
	 return 0;
}