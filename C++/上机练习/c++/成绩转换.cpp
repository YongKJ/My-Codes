#include <iostream>
using namespace std;
int main()
{
	double score;	 
	while(cin>>score)
	{       
		if(score>100||score<0)
		cout<<"Score is error!"<<endl;
		else
		{
		if(score>=90&&score<=100)
		cout<<"A"<<endl;
		else if(score>=80)
		cout<<"B"<<endl;
		else if(score>=70)
		cout<<"C"<<endl;
		else if(score>=60)
		cout<<"D"<<endl;
		else 
		cout<<"E"<<endl;
		}
	}
		return 0;
}
		