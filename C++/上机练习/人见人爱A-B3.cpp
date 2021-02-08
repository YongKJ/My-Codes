#include <iostream>
#include <map>
using namespace std;
int main(){
	int n,m;
	while(cin>>n>>m,n||m){
		int x,y,s=0;
		map<int,int> a;
		map<int,int>::iterator p;
		for(int i=0;i<n;i++){
			cin>>x;
			a[x]=0;
		}
		for(int i=0;i<m;i++){
			cin>>y;
			if(a.find(y)!=a.end())
				a[y]++;
		}
		for(p=a.begin();p!=a.end();p++){
			if(p->second==0)
			cout<<p->first<<" ";
			s+=p->second;
		}
		if(s==n)
			cout<<"NULL";
			cout<<endl;
	}
	return 0;
}