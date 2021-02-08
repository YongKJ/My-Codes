#include<iostream>
using namespace std;
int main(){
	int N,M;
	cin>>N>>M;
	int dp[N+5][M+5];
	int a[N+5];
	int i,j;
	//初始化dp数组 
	for(i=0;i<=N;i++){
		for(j=0;j<=M;j++){
			dp[i][j]=0;
		}
	} 
	//输入每种菜的金额 
	for(i=1;i<=N;i++){
		cin>>a[i];
	} 
	//动态规划,用第一道菜遍历到最后一道菜 
	for(i=1;i<=N;i++){
		//从0块遍历到输入的M块(因为我只要知道M之前的就可以了，M之后的数据不需要，所以遍历到M就可以了) 
		for(j=0;j<=M;j++){
			if(i==1){
				dp[i][0]=1;
				dp[i][a[i]]=1;
				break;
				//初始化第一道菜 
			}
			//动态规划转移方程  
			if(j>=a[i]){
				dp[i][j]=dp[i-1][j]+dp[i-1][j-a[i]];
			} 
			else dp[i][j] = dp[i-1][j];
		}
	}
	for(i=1;i<=N;i++){
          for (j = 0; j <= M; j++) {
            cout << dp[i][j] << " ";
          }
          cout << endl;
        }
        cout << dp[N][M] << endl;
        return 0;
}