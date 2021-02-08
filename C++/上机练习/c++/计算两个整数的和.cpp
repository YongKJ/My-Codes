#include <iostream>
using namespace std;
int add(int a,int b);
int main()
{
	int x,y,sum;
	cout<<"Enter two numbers:"<<'\n';
	cin>>x>>y;
	sum=add(x,y);
	cout<<"The sum is:"<<sum<<'\n';
}
int add(int a,int b)
{
	int c;
	c=a+b;
	return c;
}