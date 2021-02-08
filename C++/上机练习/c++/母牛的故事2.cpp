#include<stdio.h>
long cow(int n);
int main()
{
    int n;
    while(scanf("%d",&n)&&n!=0)
    {
        printf("%ld\n",cow(n));    
    }
    
}
long cow(int n)
{
    int i;
    int array[100];
    array[0]=array[1]=array[2]=1;
    for(i=3;i<=55;i++)
    {
        array[i]=array[i-1]+array[i-3];
     } 
    return array[n+1];
    
}