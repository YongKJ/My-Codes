#include <iostream>
#include <iomanip>
using namespace std;
int Score(int x)
{
	if(90<=x)
	return 4;
	else if(80<=x)
	return 3;
	else if(70<=x)
	return 2;
	else if(60<=x)
	return 1;
	else
	return 0;
}
int main()
{
	int t;
	float s=0,k=0,x,y;
	cin>>t;
	while(t--)
	{
		cin>>x>>y;
		if(y!=-1)
		k+=x,s+=x*Score(y);
	}
		if(0==s)
		cout<<"-1"<<endl;
		else
		cout<<fixed<<setprecision(2)<<s/k<<endl;
		return 0;
}
		