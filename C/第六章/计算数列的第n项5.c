#include <stdio.h>
int main()
{
	int a,b,n;
	int f[10001];
	f[1] = 1;
	f[2] = 1;
	int s;		//记录周期 
	while (~scanf ("%d %d %d",&a,&b,&n) && (a || b || n))
	{
		if (n == 1 || n == 2)
		{
			printf ("1\n");
			continue;
		}
		a %= 7;
		b %= 7;
		f[3] = (a * f[2] + b * f[1]) % 7;		//先求两项（为了避免后面都为0的情况） 
		f[4] = (a * f[3] + b * f[2]) % 7;
		for (int i = 5 ; ; i++)
		{
			f[i] = (a * f[i-1] + b * f[i-2]) % 7;
			if (f[i] == f[4] && f[i-1] == f[3]) 		//两项相等就开始循环
			{
				s = i - 4;
				break;
			}
		}
//		int pos = (n - 2) % s;
//		pos = pos == 0 ? s : pos;		//余数为0取最后一项
		int pos = (n - 3) % s + 1;		//这样的写法比上面的巧，小细节，学习一下 
		printf ("%d\n",f[2+pos]);
	}
	return 0;
}
