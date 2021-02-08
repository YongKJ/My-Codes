#include <iostream>
using namespace std;
int main()
{
	
	int array[100],n;
	array[0]=array[1]=array[2]=1;
	for(int i=3;i<55;i++)
	array[i]=array[i-1]+array[i-3];
	while(cin>>n,n)
	{
		cout<<array[n+1]<<endl;
	}
		return 0;
}
		