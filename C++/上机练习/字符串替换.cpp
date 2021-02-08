#include<stdio.h>
#include<string.h>
int main()
{
   char a[1010];
   int i;
   while(gets(a)){
 
    int len=strlen(a);
    int j=0,k=0;
    for(i=0;i<len;i++)
    {
        if(a[i]=='y'&&a[i+1]=='o'&&a[i+2]=='u')
       { 
                printf("we");
				i=i+2;
	   }
       else   printf("%c",a[i]);
          
    }    
       printf("\n");
 
  }
return 0;
}        

/*
描述


编写一个程序实现将字符串中的所有"you"替换成"we" 。

输入


输入包含多行数据。
每行数据是一个字符串，长度不超过1000。 
数据以EOF结束。

输出


对于输入的每一行，输出替换后的字符串。

样例输入

you are what you do
I love you
yours
kkkkkyo

样例输出

we are what we do
*/