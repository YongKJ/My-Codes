#include"stdio.h"
void main()
{
	int a[3][2],b[2][3],c[3][3];
	int i,j,k;
	for(i=0;i<3;i++)//输入
	{
		for(j=0;j<2;j++)
			scanf("%d",&a[i][j]);
	}
	for(i=0;i<2;i++)//输入
	{
		for(j=0;j<3;j++)
			scanf("%d",&b[i][j]);
	}
	for(i=0;i<3;i++)//计算
	{
		for(j=0;j<3;j++)
		{
			c[i][j]=0;//初始化c
			for(k=0;k<2;k++)
				c[i][j]+=a[i][k]*b[k][j];
		}
	}
        for (i = 0; i < 3; i++) //输出
        {
          for (j = 0; j < 3; j++)
            printf("%d ", c[i][j]);
          printf("\n");
        }
}