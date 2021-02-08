#include <stdio.h>
struct  worker
{ long num;
 char name[20];
 char sex;
 char Idnumber[12];
 float wages;
 char add[50];
}employee;
int main()
 {
  struct worker employee[6];
  int i, m;
  float max, ave = 0;
  printf("输入6个员工信息:职工号、姓名、性别、身份证号、工资、地址\n");
  for (i = 0; i < 6; i++) {
    scanf("%ld%s", &employee[i].num, employee[i].name);
    scanf(" %*c%c%s", &employee[i].sex, employee[i].Idnumber);
    scanf("%f%s", &employee[i].wages, employee[i].add);
    ave = ave + employee[i].wages;
  }
  ave = ave / 6;
  m = 0;
  for (i = 1; i < 6; i++)
    if (employee[i].wages > employee[m].wages)
      m = i;
  printf(" %.2f \n", ave);
  printf("工资最高的员工信息:职工号、姓名、性别、身份证号、工资、地址\n");
  printf("%ld、%s、", employee[m].num, employee[m].name);
  printf("%c、%s、", employee[m].sex, employee[m].Idnumber);
  printf("%f、%s\n", employee[m].wages, employee[m].add);
}