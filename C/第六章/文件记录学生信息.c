#include <stdio.h>
#include <string.h>
int main()
{
  FILE *f;
  if((f=fopen("stu1.txt","r+"))==NULL)
    printf("Cannot open file, press any key to exit!\n");
  char a[5][100],b[100];
  int i,s=0,t;
  for (i = 0; i < 5; i++) 
  {
   fgets(a[i], 100, stdin);
    if(i<2)
    s += strlen(a[i]);
   fprintf(f, "%s", a[i]);
  }
  fseek(f, s, 0);
  fgets(b, 100, f);
  printf("%s\n",b);
  printf("%d\n", t);
  fseek(f, s, 0);
  fprintf(f, "%s",a[1]);
  fclose(f);
}