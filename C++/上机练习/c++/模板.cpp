#include <iostream>
//#include <cstring>
#include <string.h>
#include <stdio.h>
using namespace std;
int strlen1(char *p){
	int sum=0,i=0;
	while(p[i]!='\0')
	sum++,i++;
	return sum;
}
	
int main()
{
	char str[50],a=' ',b='\0';
	int t;
	memset(str,0,sizeof(str));
	//cin>>str;
	cin>>t;
	while(t--){
	fgets(str,50,stdin);
	printf("%d\n",str[4]);
	cout<<strlen(str)<<endl;
	}
//	cout<<strlen1(str)<<endl;
	/*char a,b;
	scanf("%c",&a);
	cin>>b;
	printf("%d %d\n",a,b);*/
}