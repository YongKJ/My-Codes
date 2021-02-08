#include<stdio.h>
#include<string.h>
#define LEN 100 //单词最大长度
#define NUM 4 //单词个数
int main()
{
char str[NUM][LEN];
int i = 0,j = 0;
for(i = 0;i < NUM;i++)
{
scanf("%s",str[i]); //输入单词
}
for(i = 1;i < NUM;i++)	//对字符串排序
{
if(strcmp(str[i],str[i-1]) < 0)
{
char temp[NUM];
strcpy(temp,str[i]);
strcpy(str[i],str[i-1]);
for(j = i-2;strcmp(str[j],temp) > 0 && j >= 0;--j)
{
strcpy(str[j+1],str[j]);
}
strcpy(str[j+1],temp);
}
}
for (i = 0; i < NUM; i++) 
{
  printf("%s", str[i]);
  printf("\n"); //输出单词
}
return 0;
}