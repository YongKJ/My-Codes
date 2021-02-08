#include <iostream>
#include <iomanip>
using namespace std;
const double PI=3.1415927;
int main()
{
	double r,V;
	while(cin>>r)
	{
		V=4.0/3*PI*r*r*r;
		cout<<setiosflags(ios::fixed)<<setprecision(3)<<V<<endl;
	 }
	 return 0;
}