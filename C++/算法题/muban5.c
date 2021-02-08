#include <stdio.h>
typedef struct{
	int no;
	char name[10];
	float score;
}Student;
int main()
{
	Student s[10];
	int i=0,n,j;
	FILE*fp;
	printf("请输入要删除第几个数:");
	scanf("%d",&n);
	if ((fp=fopen("student.txt","r+"))==NULL){

		printf("文件打开失败!");
		return 0;
	}
        for (i=0;!feof(fp);i++)
	fscanf(fp,"%d%s%f\n",&s[i].no,s[i].name,&s[i].score);
        printf("原文件内容是:\n");
        for (j=0;j<i;j++)
          printf("%d %s %f\n", s[j].no, s[j].name, s[j].score);
        if (n < 1 || n > j + 1) {
          printf("删除位置错误!");
          return 0;
        }
        for (j = n-1; j+1<i; j++) {
          s[j] = s[j+1];
        }
        rewind(fp);
        for (j = 0; j<i-1; j++) {
          fprintf(fp, "%d %s %f\n", s[i].no, s[i].name, s[i].score);
        }
        printf("修改后的文件内容是:\n");
        for (j=0;j<i-1;j++)
          printf("%d %s %f\n", s[j].no, s[j].name, s[j].score);
        fclose(fp);
        return 0;
}