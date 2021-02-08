#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	double n;
	while(cin>>n)
	{
		n=n<0?-n:n;
		cout<<setiosflags(ios::fixed)<<setprecision(2)<<n<<endl;
	}
	return 0;
}