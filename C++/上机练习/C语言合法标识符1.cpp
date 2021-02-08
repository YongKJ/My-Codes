#include<stdio.h>
#include<string.h>
#include<ctype.h>
void main()
{
     char array[50],c;
     int n,i,j=0,flag=0;
     scanf("%d%d",&n,&c);
     for(i=0;i<n;i++)
     {
     	flag=0;
         gets(array);//scanf把空格当做一种结束符号
         if(isalpha(array[0])||array[0]=='_')
         {
           flag=1;
           for(j=1;j<strlen(array)&&flag;j++)
           {
             if (!isalnum(array[j]) && array[j] != '_') {
               flag = 0;
               break;
             }
           }
         }
         if (flag)
           printf("yes\n");
         else
           printf("no\n");
     }
}