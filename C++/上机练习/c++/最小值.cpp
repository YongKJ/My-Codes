#include <iostream>
using namespace std;
int main()
{
	int a,b,d,min;
	cout<<"Enter two numbers:";
	cin>>a;
	cin>>b;
	min=a>b?b:a;
	for(d=2;d<min;d++)
	if((0==a%d)&&(0==b%d))
	break;
	if(d==min)
	cout<<"No common denominators\n";
	cout<<"The lowest common denominator is"<<endl<<d;
}
