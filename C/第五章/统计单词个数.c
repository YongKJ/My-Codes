#include <stdio.h>
#include <string.h>

#define SIZE 20

int main()
{
	char str[SIZE]={'\0'};
	int count=0;
	printf("please input the string\n");
	gets(str);
	puts(str);
	int length = strlen(str);
	for (int i=0;i<length;i++)
	{
		//判断是不是空格不是的话在while里面i++执行判断到下一个空格的出现或是结束
		if(str[i]!=' ')
		{
			count++;
                        while (str[i] != ' ' && str[i] != '\0') {
                          i++;
                        }
                }
        }
        printf("%d\n", count);
        return 0;
}