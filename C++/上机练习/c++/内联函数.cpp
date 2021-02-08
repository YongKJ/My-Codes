#include <iostream>
#include <iomanip>
using namespace std;
inline double circle(double r)
{
	return 3.1416*r*r;
}
int main()
{
	for(int i=1;i<=3;i++)
	cout<<"r="<<i<<" area="<<setw(7)<<circle(i)<<endl;
	return 0;
}
	