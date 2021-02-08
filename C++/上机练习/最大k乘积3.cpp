#include<iostream>  
#include<cstring>  
  
using namespace std;  
  
int n,k;  
int a[44];  
int dp[44][10];//前i个数中间有j个乘号   
int m[44][44];  
string s;  
void init()  
{  
    for(int i=1;i<=n;i++)m[i][i]=a[i];  
    for(int i=1;i<=n;i++)  
    {  
        for(int j=i+1;j<=n;j++)  
        {  
            m[i][j]=m[i][j-1]*10+m[j][j];  
        }  
    }  
 }   
int main()  
{  
    cin>>n>>k;  
    for(int i=1;i<=n;i++)  
    {  
        char ch;cin>>ch;  
        a[i]=ch-'0';  
    }  
    init();  
      
    for(int i=1;i<=n;i++)//枚举前i个数字   
    {  
        for(int j=0;j<i;j++)//枚举乘号个数  
        {  
            if(j==0)  
            {  
                dp[i][j]=m[1][i];continue;    
            }  
            for(int k=1;k<i;k++)//枚举乘号位置   
            {  
                dp[i][j]=max(dp[i][j],dp[k][j-1]*m[k+1][i]);  
            }  
              
        }  
    }  
    cout<<dp[n][k-1]<<endl;  //前n个数字分成n段，相当于前面添加n-1个乘号
    return 0;  
}  