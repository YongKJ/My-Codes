#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int n=1;
char a[3000];
double work()
{
  scanf("%s", a), printf("1\n");
	int len=strlen(a);
	if(len==1&&!(a[0]>='0'&&a[0]<='9'))
		switch(a[0])
		{
			case '+':return work() + work();
			case '-':return work() - work();
			case '*':return work() * work();
			case '/':return work() / work();
		}
	else
	{
		return atof(a);
	}
}

int main() { printf("%f", work()); }
/*
描述

逆波兰表达式是一种把运算符前置的算术
表达式，例如普通的表达式2 + 3的逆波兰
表示法为+ 2 3。逆波兰表达式的优点是运
算符之间不必有优先级关系，也不必用括
号改变运算次序，例如(2 + 3) * 4的逆波兰
表示法为* + 2 3 4。本题求解逆波兰表达式
的值，其中运算符包括+ - * /四个。

输入

输入为一行，其中运算符和运算数之间都用
&空格分隔，运算数是浮点数。

输出

输出为一行，表达式的值。
可直接用printf("%f\n", v)输出表达式的值v。

样例输入

* + 5.0 4.0 - 4.0 2.0

样例输出

18.000000
*/