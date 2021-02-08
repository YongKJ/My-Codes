#include <stdio.h>
#include <math.h>
int sushu(int n)
{
    int i;
    if(n==1) return 2;
    if(n==2) return 1;
    for(i=2;i<=sqrt(n);i++)
        if(n%i==0)
          return 0;
    return 1;
}
int jiecheng(int n)
{
    int i,s=1;
    for(i=1;i<=n;i++)
      s *= i;
    return s;
}
int main()
{
    int n,m,k=0,i;
    int j,j_t,s;
    int a,b;
    int yinzi[10000] = {0};
    scanf("%d",&s);
    for(a=1;a<=s;a++)
    {
            b=0;
        scanf("%d %d",&n,&m);
        for(j=1;j<=n;j++)
        {
            if(sushu(j)==2)
              k = 1, yinzi[0] = 1;
            else if(sushu(j)==1)         
              k = 2, yinzi[0] = 1, yinzi[1] = j;
            else if(sushu(j)==0)//n不是素数的情况下才可以分解
           {  
           k=0,i=2,j_t=j;
                while(j_t!=1)
                {
                    if(j_t%i==0)
                    {
                        yinzi[k]=i;
                        j_t=j_t/i;
                        k++;
                        i=2;
                        continue;
                    }
                    i++;
                }
            }
            for (i = 0; i < k; i++) 
              if (m == yinzi[i])
                b++;
        }
        printf("%d\n",b);
    }
    return 0;
}