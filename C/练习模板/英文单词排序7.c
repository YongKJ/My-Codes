#include<stdio.h>
#include<string.h>
#define N 5
void swap(char *p1,char *p2)
{
    char temp[100];
	strcpy(temp,p1);
	strcpy(p1,p2);
	strcpy(p2,temp);
}
int main()
{
    int i,j; 
	char str1[N][100],*str[N];
	for(i=0;i<N;i++){
	    scanf("%s",*(str1+i));
	}
	for(i=0;i<N;i++)
	{
	    str[i]=*(str1+i);
	}
    for(i=0;i<N;i++)
{
		for(j=i+1;j<N;j++)
		{
			if(strcmp(str[i],str[j])>0){swap(str[i],str[j]);}
		}
	}
        for (i = 0; i < N; i++) {
          printf("%s\n", str[i]);
        }
        //printf("\n");
        return 0;
}