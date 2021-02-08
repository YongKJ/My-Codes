#include<stdio.h> 
int f[50010], sum;

int find(int x)
{
	if(f[x] != x)
		f[x] = find(f[x]);
	return f[x];
}

void make(int a, int b)
{
	int f1 = find(a);
	int f2 = find(b);
	if(f1 != f2)
	{
		f[f2] = f1;
		sum --;
	}
}

int main()
{
	int n, m ,p = 1, i;
	while(scanf("%d %d", &n, &m) != EOF)
	{
		if(n == 0 && m == 0)
			break;
		
		for(i = 1; i <= n; i ++)
			f[i] = i;
		
		sum = n;

                for (i = 1; i <= m; i++) {
                  int a, b;
                  scanf("%d %d", &a, &b);
                  make(a, b);
                }

                printf("Case %d: %d\n", p++, sum);
        }
        return 0;
}
/*
样例输入

10 9
1 2
1 3
1 4
1 5
1 6
1 7
1 8
1 9
1 10
10 4
2 3
4 5
4 8
5 8
0 0

样例输出

Case 1: 1
Case 2: 7
*/