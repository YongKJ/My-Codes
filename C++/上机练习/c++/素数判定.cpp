#include <iostream>
#include <cmath>
using namespace std;
int SuShu(int n)
{
	int i;
	if(n==2)
	return 1;
	else
	{	
	for( i=2;i<=sqrt(abs(n));i++)
	if(n%i==0)
	break;
	if(n%i!=0)
	return 1;
	else 
	return 0;
	}
}
int main()
{
	int x,y,a,k;
	while(cin>>x>>y&&(x||y))
	{
		k=0;
		for(int i=x;i<=y;i++)
		{
			a=i*i+i+41;
			if(SuShu(a))
			k++;
		}
		if(k==y-x+1)
		cout<<"OK"<<endl;
		else
		cout<<"Sorry"<<endl;
	}
		return 0;
}