#include<stdio.h>
int main()
{
    int a , b , N , i , M;
    scanf( "%d" , &M );
    for( int j = 0; j < M; j++ )
    {
        scanf( "%d" , &N );
        int sum = 0;
        for (i = 0; i < N; i++) {
          scanf("%d", &a);
          sum += a;
        }
        printf("%d\n", sum);
        if (j < M - 1)
          printf("\n");
    }
    return 0;
}