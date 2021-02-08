/* HELLO.C -- Hello, world */
#include "stdio.h"
#define n 5      //这是9*9方阵的，需要n*n方阵只需改这个n的值就行了
int  main()
{
    int square[n][n]={0};
    {
      int i=0,j=(n-1)/2,k,l,key;
     // for(i=0;i<n;i++)
      square[0][(n-1)/2]=1;
      
      for(key=2;key<=n*n;key++)
       {
        k=(i)? (i-1):(n-1);
        l=(j)? (j-1):(n-1);
        if(square[k][l])
         i=(i+1)%n;
        else
        {
         i=k;
         j=l;
        }
        square[i][j]=key;
       }
       
       for (i = 0; i < n; i++) 
       {
         for (j = 0; j < n; j++)
           printf("%4d", square[i][j]);
         printf("\n\n");
       }
    }
}