#include <iostream>
#include <cmath>
using namespace std;
int main(){
	int n;
	char str[10000][8];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>str[i];
	int s1[7],s2[10000];
	for(int i=0;i<n;i++){
		int k=0;
		s1[k]=1;
		char t=str[i][0];
	for(int j=1;j<7;j++){
	if(t==str[i][j])
		s1[k]++;
	else{
		t=str[i][j];
		s1[++k]=1;
	}
	}
	int sum=0,s;
	for(int l=0,x=k;l<=k;l++,x--){
		t=x,s=1;
		while(t--)
			s*=10;
		sum+=s*s1[l];
	}
	s2[i]=sum;
	}
	int sum=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++)
			if(s2[i]==s2[j])
				sum++;
		}
			cout<<sum<<endl;

	return 0;
}