#include <stdio.h>
#define N 3
struct stu
{
char name[10];//姓名
int num;//学号
int age;//年龄
float score;//成绩
}boys[N], boy,*pboys;
int main()
{
FILE*fp;
int i;
pboys = boys;
if((fp=fopen("stu1.txt","wb+"))== NULL )
{
printf("Cannot open file, press any key to exit!\n");
//getch();
//exit(1);
}
printf("Input data:\n");
for (i = 0; i < N; i++, pboys++) 
{
  scanf("%s %d %d %f", pboys->name, &pboys->num, &pboys->age, &pboys->score);
}
fwrite(boys, sizeof(struct stu), N, fp); //写入三条学生信息
fseek(fp, sizeof(struct stu), SEEK_SET); //移动位置指针
fread(&boy, sizeof(struct stu), 1, fp);  //读取一条学生信息
printf("%s  %d  %d %f\n", boy.name, boy.num, boy.age, boy.score);
fclose(fp);
}