#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
	char str[300],str1[100][200];
	
	int i,j,k=0,len,l,h;
	while((cin>>l)&&l)
	{
	 cin>>str;  
	 h=strlen(str)/l;
	 for(i=0;i<h;i++)
	 for(j=0;j<l;j++)
	 {
	 if(0==i%2)
	 str1[i][j]=str[k++];
	 else
	 str1[i][l-1-j]=str[k++];
	 }
	for(i=0;i<l;i++)
	 for(j=0;j<h;j++)
	 cout<<str1[j][i];
	 cout<<endl;
	 }
	 return 0;
}