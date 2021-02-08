#include <iostream>
using namespace std;
void init(int x=5,int y=10);
int main()
{
	init(100,80);
	init(23);
	init();
	return 0;
}
void init(int x,int y)
{
	cout<<"x: "<<x<<"\ty: "<<y<<endl;
}