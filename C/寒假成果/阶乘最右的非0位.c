#include<stdio.h>
#include<string.h>
char str[10005];
int a[10005], Mp[20] = {1,1,2,6,4,2,2,4,2,8,4,4,8,4,6,8,8,6,8,2};  /*这个是F[5^(n/5)*G(n)]的前20(0-19)项,后面循环*/
int main(void)
{
	int T, len, ret, i, c;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%s", str);
		len = strlen(str);
		for(i=len-1;i>=0;i--)
			a[len-1-i] = str[i]-'0';     /*将n的每一位存入数组a[],其中a[0]是最低位,a[len-1]是最高位*/
		ret = 1;
		while(len!=0)  /*用循环代替递归*/
		{
			c = 0;
			ret = ret*Mp[a[1]%2*10+a[0]]%10;   /*"a[1]%2*10+a[0]"是计算n%20的值*/
                        for (i = len - 1; i >= 0; i--) 
                        {
                          c = c * 10 +
                              a[i]; /*计算n除以5之后的值,并将其存入(覆盖)a[]*/
                          a[i] = c / 5;
                          c %= 5;
                        }
                        if (a[len - 1] == 0) /*如果最高位是0,去掉最高位*/
                          len--;
                }
                if (strcmp(str, "1") == 0 || strcmp(str, "0") == 0)
                  printf("1\n");
                else
                  printf("%d\n", ret);
        }
        return 0;
}