#include <iostream>
#include <stack>
using namespace std;
int main(){
	int m,n;
	stack<int> mystack;
	cout<<"��������������ctrl+z��������"<<endl;
	cout<<"���棺����̫�����ϵͳ������^_^"<<endl;
	while(cin>>m>>n){
		if(m==0){
			cout<<"���������£�"<<endl;
			cout<<n+1<<endl;
			cout<<"����������������ctrl+z��������"<<endl;
			cout<<"���棺���� ̫�����ϵͳ������^_^"<<endl;
		}
		else
		while(1){
			if(m!=0&&n!=0)
				mystack.push(m-1),n--;
			else  if(m==0)
				m=mystack.top(),n++,mystack.pop();
			else if(n==0)
				m--,n=1;
			if(mystack.empty()&&m==0)
				break;
		}
		cout<<"���������£�"<<endl;
		cout<<n+1<<endl;
		cout<<"����������������ctrl+z��������"<<endl;
		cout<<"���棺����̫�����ϵͳ������^_^"<<endl;
	}
	return 0;
}