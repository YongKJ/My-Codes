extern void sort(stu student[],int n)
{
  int i,j,k;
  stu temp;
  for(i=0 ;i<n-1;i++)
  {
    k=i;
    for(j=i+1;j<n;j++)
    if(student[k].score>student[j].score)
    k=j;
    if(k!=i)
    {
      temp=student[i];
      student[i]=student[k];
      student[k]=temp;
    }
  }
  printf("ʹ使用选择法升序排列的结果为:\n" );
}