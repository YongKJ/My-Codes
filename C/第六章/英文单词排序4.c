#include <stdio.h>
void change(char *m,char *n)
{
  char t;
  int k;
  for (k = 0; k < 10; k++) 
  {	
    t = *m;	//数组换行
    *m = *n;
    *n = t;
    m++;
    n++;
  }
}
void f(char *s[],int n)
{
  int i,j=0;
  for (i = 0; i < n*(n+1)/2 ; i++)
  {
    if (*s[j] > *s[j + 1])		//单词按首字母顺序排序
      change(s[j], s[j + 1]);
    else if(*s[j]==*s[j+1])
    if (*(s[j] + 1) > *(s[j + 1] + 1))	//若首字母相同，则按第二个字母顺序排序
        change(s[j], s[j + 1]);
        j = (j + 1) % (n-1);
  }
}  	
int main() 
{
  int i, j, n=4;
  char *s[n], a[100][10] = {0};
  for (i = 0; i < n; i++)
    scanf("%s", a[i]);
  for (i = 0; i < n; i++)
      s[i] = a[i];      //指针指向每行第一个元素
  f(s, n);
  for (i = 0; i < n; i++) 
  {
    for (j = 0; j < 10; j++)
      if (a[i][j] != 0)
        printf("%c", a[i][j]);
      if(i!=n-1)
        printf("\n");	//最后一行取消换行
  }
}