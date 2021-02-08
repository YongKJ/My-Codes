#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAX 1100000
int main()
{
    int n,m,j,i,s,t,l;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        s=0;
        for(i=pow(2,n-1);i<pow(2,n);i++)
        {
            m=i;
            while (m) 
            {
              if (m % 2 == 1)
                s++;
              m /= 2;
            }
        }
        printf("%d\n", s);
    }
    return 0;
}