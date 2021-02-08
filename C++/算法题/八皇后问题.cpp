#include <iostream>
#include <cmath>
using namespace std;
int sum=0,s[9],flag;
void queue(int x){
	if(x>8){
		sum++;
		for(int i=1;i<=8;i++)
		cout<<s[i]<<(i!=8?" ":"\n");
		return;
	}
	for(int i=1;i<=8;i++){
		s[x]=i,flag=1;
		for(int j=1;j<x;j++)
		if(abs(j-x)==abs(s[j]-s[x])||s[j]==s[x]){
			flag=0;
			break;
		}
		if(flag)queue(x+1);
	}
}
int main(){
	queue(1),cout<<sum<<endl;
}
/*
在8*8的国际象棋棋盘上，要求在每一行(或者每一列)放置一个皇后，
且能做到在水平方向、竖直方向和斜方向都没有冲突(皇后)。请列出所有解法。
*/
