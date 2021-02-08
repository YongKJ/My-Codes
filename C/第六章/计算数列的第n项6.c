#include<stdio.h>
int main()
{
    int a,b,n,i;
    while (scanf("%d%d%d",&a,&b,&n)!=EOF)
    {
        int x[210]={0};
        x[1]=x[2]=1;
        if (n>200)
        {
            for (i=3;i<=200;i++)
            x[i]=(a*x[i-1]+b*x[i-2])%7;
            for (i=1;i<50;i++)
                if (x[100]==x[100-i]&&x[99]==x[99-i])
                    break;
            n=n%i+3*i;
            printf("%d\n",x[n]);
        } else {
          for (i = 3; i <= n; i++)
            x[i] = (a * x[i - 1] + b * x[i - 2]) % 7;
          printf("%d\n", x[n]);
        }
    }
    return 0;
}