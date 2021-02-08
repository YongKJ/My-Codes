#include<iostream>
#include<algorithm>
#include <vector>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
using namespace std;
void fun();
int main()
{
	fun();
	return 0;
}
void fun()
{
	char str0[100],str1[100],dest[100];
	gets(str0);
	gets(str1);
	if(!strcmp(str0,str1))
		puts(str1);
	else
	{
		memset(dest,'\0',sizeof(dest));
		int i,j,n,length=0,end=0,arr[100][100];
		for(i=0;str0[i];i++)
		{
			for(j=0;str1[j];j++)
			{
				n = (i - 1 >= 0 && j - 1 >= 0) ? arr[i - 1][ j - 1] : 0;
				arr[i][j] = str0[i] == str1[j] ? 1 + n : 0;
				if (arr[i][j] > length)
				{
					length = arr[i][j];
					end = i;
				}
			}
		}
		if(length==0)
			cout<<"false"<<endl;
                else {
                  strncpy(dest, &str0[end - length + 1], length);
                  cout << dest << endl;
                }
        }
}
/*
描述


采用顺序结构存储串，编写程序求两个字符串的
一个最长公共子串。

输入


输入有2行，每行为1个字符串。

输出


两个字符串的一个最长公共子串。

样例输入

123abcdabcdef
aabcdf

样例输出

abcd
*/