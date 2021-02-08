#include<cstdio>  
#include<cstring>  
#include<iostream>  
#include<math.h>  
#include<algorithm>  
  
using namespace std;  
  
int main()  
{  
    int n, ans;  
    int a[100];  
    memset(a,0,sizeof(a));  
    a[1]=1;  
    a[2]=3;  
    a[3]=5;  
    for(int i=4; i<=64; i++)  
       {  
           int min=1000000000;  
           for(int m=1;m<i;m++)  
           {  
               if(min > a[m]*2+pow(2,i-m)-1)  
                min=a[m]*2 + (int)pow(2,i-m) - 1;  
           }  
           a[i]=min;  
       }  
    while(~scanf("%d", &n))  
    {  
        printf("%d\n", a[n]);  
    }  
    return 0;  
}  