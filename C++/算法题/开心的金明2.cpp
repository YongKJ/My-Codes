#include<cstdio>
#include<iostream>
using namespace std;
int m,n,d[30001],w,v;
int main(){
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&v,&w);
        for (int j = m; j >= v; j--) {
          d[j] = max(d[j], d[j - v] + w * v); //就是这里
        }
    }
    printf("%d", d[m]);
    return 0;
}