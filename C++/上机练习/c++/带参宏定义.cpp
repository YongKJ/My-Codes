#include <iostream>
using namespace std;
#define doub(x) x*2
int main()
{
	for(int i=1;i<=3;i++)
	cout<<i<<" double is "<<doub(i)<<endl;
	cout<<"1+2 doubled is "<<doub(1+2)<<endl;
	return 0;
}