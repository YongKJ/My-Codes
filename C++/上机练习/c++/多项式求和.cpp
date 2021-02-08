#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k=1;
		double sum=0,j=1.0;
		cin>>n;
		for(int i=1;i<=n;i++,j++,k=-k)
		sum+=k/j;
		cout<<setiosflags(ios::fixed)<<setprecision(2)<<sum<<endl;
	}
	return 0;
}
		