#include <iostream>
using namespace std;
inline int doub(int x);
int main()
{
	for(int i=1;i<=3;i++)
	cout<<i<<" doubled is "<<doub(i)<<endl;
	cout<<"1+2 doubled is "<<doub(1+2)<<endl;
	return 0;
}
inline int doub(int x)
{
	return x*2;
}