#include <stdio.h>
int gcd(int n,int m)  
{
    int r;
    if(n==m)
    return n;
    else
    while((r=n%m)!=0)
    {
      n=m;
      m=r;
    }
    return m;
}
int lcs (int n,int m)   
{
    if(n==m)
    return n;
    else
    return n/gcd(n,m)*m;  
}
int main()
{
    int m,n;
    while(scanf("%d%d",&m,&n)!=EOF)
            printf("zdgys=%d zxgbs=%d\n",gcd(n,m),lcs(n,m));
    return 0;
}
