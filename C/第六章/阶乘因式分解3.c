#include<stdio.h>
int main()
{
	int t;
	int m,n;
	scanf("%d",&t);
	while(t--)
	{
		int sum = 0;
		scanf("%d%d",&m,&n);
		while (m != 0)
		{
			m = m / n;
			sum += m;
		}
		printf("%d\n",sum);
	}
	return 0;
}      