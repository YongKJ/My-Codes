#include <iostream>
using namespace std;
int cube(int i)
{
	return i*i*i;
}
long cube(long l)
{
	return l*l*l;
}
double cube(double d)
{
	return d*d*d;
}
int main()
{
	int i=5;
	long l=123;
	double d=5.67;
	cout<<i<<"*"<<i<<"*"<<i<<"= "<<cube(i)<<endl;
	cout<<l<<"*"<<l<<"*"<<l<<"= "<<cube(l)<<endl;
	cout<<d<<"*"<<d<<"*"<<d<<"= "<<cube(d)<<endl;
	return 0;
}