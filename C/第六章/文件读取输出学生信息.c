#include <stdio.h>
struct student 
{
  long num;
  char name[10];
  int age;
  char sex;
  char speciality;
  char addr[40];
};
int main() 
{
  FILE *f;
  struct student s[2000];
  int i;
  if ((f = fopen("stu2.dat", "r")) == NULL)
    printf("Cannot open file!\n");
  fread(s, sizeof(struct student), 2000, f);
  for (i = 0; i < 2000; i++)
    if (s[i].age == 18 || s[i].age == 19)
      printf("%ld %s %d %c\n", s[i].num, s[i].name, s[i].age, s[i].sex);
  fclose(f);
}