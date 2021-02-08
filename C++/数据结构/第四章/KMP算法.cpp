#include <iostream>
#include <string>
using namespace std;
string s,t;
int next1[20],nextval[20];
void Next(){
	next1[1]=0;
	for(int i=1,j=0;i< s.size();)
		if(j==0||s[i]==s[j])
			i++,j++,next1[i]=j;
		else
			j=next1[j];
}
void Nextval(){
	nextval[1]=0;
	for(int i=1,j=0;i< s.size();)
		if(j==0||s[i]==s[j])
			i++,j++,nextval[i]=(s[i]==s[j]?nextval[j]:j);
		else
			j=nextval[j];
}
int KMP(){
	Next();
	int flag=0,j=1 ;
	for(int i=1;i<=t.size()&&j<=s.size();)
		if(j==0||s[j]==t[i])
			i++,j++;
		else
			j=next1[j];
	if(j>s.size())
		flag=1;
	return flag;
}
int KMP1(){
	Nextval();
	int flag=0,j=1;
	for(int i=1;i<=t.size()&&j<=s.size();)
		if(j==0||s[j]==t[i])
			i++,j++;
		else
			j=nextval[j];
	if(j>s.size())
		flag=1;
	return flag;
}
int main(){
	while(cin>>s){
	for(int i=s.size();i>0;i--)
		s[i]=s[i-1];
        cin >> t;
	for(int i=t.size();i>0;i--)
		t[i]=t[i-1];
	cout<<(KMP()?"Yes":"No")<<endl<<endl;
	cout<<(KMP1()?"Yes":"No")<<endl;
	}
	return 0;
}
/*
abcac
ababcabcacbab

Yes

Yes
*/