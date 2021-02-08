#include<iostream>
using namespace std;
#define m 3
#define n 3

int a[3][3]={{1,1,8},
			{3,1,7},
			{1,4,6}};
int i,j;
int temp1=0;
int temp2=0;
int row,col;
int k;
int flag;
void find(int a[m][n]){
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(a[i][0]<a[i][j]){//寻找行中的最大值
				temp1=a[i][j];//将两两比较中的最大值赋给中间变量temp
				row=i;//将最大值的行号和列号记录
				col=j;
			}
		}

		for(k=0;k<m;k++){
			if(a[k][col]<temp1){
				break;
			}
			else{
				if(k==m-1){//结束判断条件
					cout<<"当前鞍点是"<<row+1<<"行"<<col+1<<"列的"<<a[row][col]<<endl;
					flag++;
				}
			}
	}	
	
   }
	if(flag==0){
		cout<<"当前"<<i+1<<"行没有鞍点"<<endl;
	}
	else{
		cout<<"有"<<flag<<"个鞍点"<<endl;
	}
	
}
int main(){
	for(int i=0;i<m;i++){
          for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
          }
          cout << endl;
        }

        find(a);
}
/*
描述


若矩阵Am´n中的某一元素A[i][j]是第i行中的最小值，
同时又是第j列中的最大值，则称此元素为该矩阵的
一个鞍点。假设以二维数组存放矩阵，试编写一个
函数，确定鞍点在数组中的位置（若鞍点存在时），
并分析该函数的时间复杂度。该程序可以测试多个案例。

输入


第一行输入测试案例数T 
以后T块输入每个测试案例 
每个测试案例第一行输入m与n(m与n均小于100） 
然后是m行数据 每行共n个数据（这些数据全为整数）

输出


对每个案例输出所有的鞍点，鞍点的顺序从上到下，从左
到右,每个鞍点输出格式为："A[i][j]"其中i,j是实际鞍点对应
数字 每个鞍点之间空一个空格 
如果没有鞍点，则输出“NO.”(注意NO后面有一个点'.') 
2个案例之间空一个空行,最后一个案例后面无空行。

样例输入

2
2 2
2 3
1 1
2 3
4 5 1
7 6 -1

样例输出

A[1][1]

A[1][3]
*/