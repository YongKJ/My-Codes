void print(stu student[],int n)
{
  int j;
  for (j=0;j<n;j++)
  printf("学生%s的总成绩为:%d\n",student[j].name,student[j].score );
}