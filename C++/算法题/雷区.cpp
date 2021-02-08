#include <iostream>
#include <string>
#include <set>
using namespace std;
int n,s[4][2]={-1,0,1,0,0,1,0,-1};
set<int> num;
string str[100],map1[100];
void dfs(int x,int y,int sum,char a){
	if(str[x][y]=='B'){
		num.insert(sum);
		return;
	}
	for(int i=0;i<4;i++){
		int x1=x+s[i][0],y1=y+s[i][1];
		if((0<=x1&&x1<n)&&(0<=y1&&y1<n)&&map1[x1][y1]=='0'&&a!=str[x1][y1]){
			map1[x1][y1]='1';
			dfs(x1,y1,sum+1,str[x1][y1]);
			map1[x1][y1]='0';
		}
		
	}
}
int main(){
	while(num.clear(),cin>>n){
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>str[i][j],map1[i][j]='0';
		dfs(0,0,0,'A'),cout<<*num.begin()<<endl;
	}
}
/*
X星的坦克战车很奇怪，它必须交替地穿越正能量辐射区和负能量辐射区才能保持正常运转，否则将报废。 
某坦克需要从A区到B区去（A，B区本身是安全区，没有正能量或负能量特征），怎样走才能路径最短？

已知的地图是一个方阵，上面用字母标出了A，B区，其它区都标了正号或负号分别表示正负能量辐射区。 
例如： 
A + - + - 
- + - - + 
- + + + - 
+ - + - + 
B + - + - 
坦克车只能水平或垂直方向上移动到相邻的区。

数据格式要求： 
输入第一行是一个整数n，表示方阵的大小， 4<=n<100 
接下来是n行，每行有n个数据，可能是A，B，+，-中的某一个，中间用空格分开。 
A，B都只出现一次。 
要求输出一个整数，表示坦克从A区到B区的最少移动步数。 
如果没有方案，则输出-1

例如： 
用户输入： 
5 
A + - + - 
- + - - + 
- + + + - 
+ - + - + 
B + - + - 
则程序应该输出： 
10

*/