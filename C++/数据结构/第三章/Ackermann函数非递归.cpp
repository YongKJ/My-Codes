#include <iostream>
#include <stack>
using namespace std;
int main(){
	int m,n;
	stack<int> mystack;
	cout<<"请输入两个数（ctrl+z结束）："<<endl;
	cout<<"警告：不能太大否则系统崩溃！^_^"<<endl;
	while(cin>>m>>n){
		if(m==0){
			cout<<"运算结果如下："<<endl;
			cout<<n+1<<endl;
			cout<<"请输入两个整数（ctrl+z结束）："<<endl;
			cout<<"警告：不能 太大否则系统崩溃！^_^"<<endl;
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
		cout<<"运算结果如下："<<endl;
		cout<<n+1<<endl;
		cout<<"请输入两个整数（ctrl+z结束）："<<endl;
		cout<<"警告：不能太大否则系统崩溃！^_^"<<endl;
	}
	return 0;
}