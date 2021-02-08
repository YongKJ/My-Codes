#include <stdio.h>
#include <string.h>
#define N 100
void AddStudent();    /*添加学生成绩*/
void DelStudent();    /*删除学生成绩*/
void UpdateStudent();   /*修改学生成绩*/
void SearchStudent();   /*查询学生成绩*/
void Avearage();    /*统计并输出每门功课的平均成绩*/
void DispStudent();   /*输出学生成绩*/
void SortStudent1();    /*按总分降序*/
void SortStudent2();    /*按姓名升序*/
void SaveFile();    /*学生成绩写入文件Student.txt中*/
void ReadFile();    /*从文件Student.txt中读入学生成绩*/
struct Student
{
  char name[20];
  int math,chinese,english,total;
} ;
struct Student st[N];
int length;
int main()
{
  int select;
  ReadFile();
  printf("\n\t\t已从文件student.txt读入%d个学生的数据\n",length );
  while(1)
  {
    printf("\n\n= = = = = = 欢迎使用学生成绩管理系统 = = = = = =\n" );
    printf("\n" );
    printf("\t\t\t1.添加学生成绩\n" );
    printf("\t\t\t2.删除学生成绩\n" );
    printf("\t\t\t3.修改学生成绩\n" );
    printf("\t\t\t4.查询学生成绩\n" );
    printf("\t\t\t5.统计学生成绩\n" );
    printf("\t\t\t6.输出学生成绩\n" );
    printf("\t\t\t7.按照总分降序\n" );
    printf("\t\t\t8.按照姓名升序\n" );
    printf("\t\t\t0.保存数据、退出系统\n" );
    printf("\n" );
    printf("\t\t请输入你的选择:\n" );
    scanf("%d",&select );
    switch (select)
    {
      case 1:AddStudent();    break;
      case 2:DelStudent();    break;
      case 3:UpdateStudent(); break;
      case 4:SearchStudent(); break;
      case 5:Avearage();      break;
      case 6:DispStudent();   break;
      case 7:SortStudent1();  break;
      case 8:SortStudent2();  break;
      case 0:SaveFile();      return 0;
    }
  }
}
/****添加学生成绩****/
void AddStudent()
{
  struct Student t;
  printf("\n请输入学生姓名：\n" );
  scanf("%s",t.name );
  printf("\n请输入学生三门功课的成绩：\n" );
  scanf("%d%d%d",&t.math,&t.english,&t.chinese );
  t.total=t.math+t.english+t.chinese;
  st[length++]=t;
  SaveFile();
  printf("\n删除成功！目前共%d条数据\n\n",length );
}
/****删除学生成绩****/
void DelStudent()
{
  char name[20];
  int i;
  printf("请输入要删除学生的姓名：\n" );
  scanf("%s",name );
  for(i=0;i<length;i++)
  if(strcmp(st[i].name,name)==0)
  for(;i+1<length;i++)
  st[i]=st[i+1];
  length--;
  SaveFile();
  printf("\n删除成功！目前共%d条数据\n\n",length );
}
/****修改学生成绩****/
void UpdateStudent()
{
  struct Student t;
  int i;
  printf("请输入学生姓名：\n" );
  scanf("%s",t.name );
  printf("请输入学生三门功课的成绩：\n" );
  scanf("%d%d%d",&t.math,&t.english,&t.chinese );
  t.total=t.math+t.english+t.chinese;
  for(i=0;i<length;i++)
  if(strcmp(st[i].name,t.name)==0)break;
  st[i]=t;
  SaveFile();
  printf("\n修改成功！目前共%d条数据\n\n",length );
}
/****根据学生姓名进行查询****/
void SearchStudent()
{
  char name[20];
  int i;
  printf("\n请输入要查找学生的姓名：\n" );
  scanf("%s",name );
  for(i=0;i<length;i++)
  if(strcmp(st[i].name,name)==0)
  {
    printf("\n学生姓名：%s\n",st[i].name );
    printf("三门功课成绩\n" );
    printf("数学:%d\n",st[i].math );
    printf("语文:%d\n",st[i].chinese );
    printf("英语:%d\n",st[i].english );
    printf("总分:%d\n",st[i].total );
    break;
  }
}
/****分别统计并输出每门功课的平均成绩****/
void Avearage()
{
  double mathSum,englishSum,chineseSum;
  int i;
  mathSum=englishSum=chineseSum=0;
  for(i=0;i<length;i++)
  {
    mathSum+=st[i].math;
    chineseSum+=st[i].chinese;
    englishSum+=st[i].english;
  }
  printf("\n\t\t  三门功课的平均成绩:\n" );
  printf("\t\t语文平均分:%5.2f\n",chineseSum/length );
  printf("\t\t数学平均分:%5.2f\n",mathSum/length );
  printf("\t\t英语平均分:%5.2f\n",englishSum/length );
}
/*****输出学生成绩****/
void DispStudent()
{
  int i;
  printf("\n" );
  printf("\t\t|学生姓名|数学|语文|英语|总分|\n" );
  for(i=0;i<length;i++)
  printf("\t\t|%-8s|%4d|%4d|%4d|%4d|\n",st[i].name,st[i].math,st[i].chinese,st[i].english,st[i].total );
}
/****按照总分降序****/
void SortStudent1()
{
  int i,j;
  struct Student t;
  for(i=0;i<length;i++)
  for(j=i+1;j<length;j++)
  if(st[i].total<st[j].total)
  t=st[i],st[i]=st[j],st[j]=t;
  printf("\t\t********按总分从大到小排序********\n" );
  DispStudent();
  SaveFile();
}
/****按照姓名升序****/
void SortStudent2()
{
  int i,j;
  struct Student t;
  for(i=0;i<length;i++)
  for(j=i+1;j<length;j++)
  if(strcmp(st[i].name,st[j].name)>0)
  t=st[i],st[i]=st[j],st[j]=t;
  printf("\t\t********按姓名字母升序********\n" );
  DispStudent();
  SaveFile();
}
/****将学生成绩写入文件student.txt中****/
void SaveFile()
{
  FILE *fp;
  int i;
  fp=fopen("student.txt","w");
  for(i=0;i<length;i++)
  {
    fprintf(fp, "%s ",st[i].name );
    fprintf(fp, "%d ",st[i].math );
    fprintf(fp, "%d ",st[i].chinese );
    fprintf(fp, "%d ",st[i].english );
    fprintf(fp, "%d\n",st[i].total );
  }
  printf("%d\n", length);
  fclose(fp);
}
/****从文件student.txt中读入学生成绩****/
void ReadFile()
{
  FILE *fp;
  struct Student t;
  fp=fopen("student.txt","r");
  length=0;
  while (!feof(fp))
  {
    fscanf(fp,"%s",st[length].name);
    fscanf(fp,"%d",&st[length].math);
    fscanf(fp,"%d",&st[length].chinese);
    fscanf(fp,"%d",&st[length].english);
    fscanf(fp,"%d",&st[length].total);
    length++;
  }
  fclose(fp);
}