#include<stdio.h>
#include<stdlib.h>
int main()
{
char str1[50],str2[50];
int locat[50];
char *p,*q;
int i=0,len=0,lct=1,j;
printf("请输入字符串1\n");
gets(str1);
printf("请输入字符串2\n");
gets(str2);
q=str2;
for (; *q != '\0'; q++) {
  len = len + 1;
}
p=str1;
q=str2;
do
{
  if (*p != *q) {
    p++;
    lct++;
  }
else
{
  while ((*q != '\0') && (*q == *p)) {
    q++;
    p++;
    lct++;
  }
  if (*q == '\0') {
    locat[i] = lct - len;
    i++;
  }
  }
  q = str2;
}
while(*p!='\0');
if (i == 0) {
  printf("no");
} else {
  printf("字符串2在字符串1中出现%d次，起始位置分别是：", i);
  for (j = 0; j < i; j++)
    printf("%d\n", locat[j]);
}
system("pause");
return 0;
}