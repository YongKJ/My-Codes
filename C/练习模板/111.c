#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
  char score;
  char name[10];
  char num[15];
  char email[20];
  char qq[20];
  char wechat[20];
  char adds[20];
}person;
person pe[80];
int menu_select()
{
  char c;
  do{
    system("cls");
    printf("\t\t****ͨѶ¼****\n");
    printf("\t\t|---------|\n");
    printf("\t\t|1.��Ӽ�¼|\n");
    printf("\t\t|2.��ʾ��¼|\n");
    printf("\t\t|3.ɾ����¼|\n");
    printf("\t\t|4.��ѯ��¼|\n");
    printf("\t\t|5.�޸ļ�¼|\n");
    printf("\t\t|6.�����¼|\n");
    printf("\t\t|0.�˳�����|\n");
    printf("\t\t|---------|\n");
    printf("\t\t����ѡ��0-6����");
    c=getchar();
  }while(c<'0'||c>'6');
    return(c-'0');
}
int input(person per[],int n)
{
  int i=0;
  char sign,x[10];
  while(sign!='n'&&sign!='N')
  {
    printf("\tѧ�ţ�");
    scanf("\t%d",&per[n+i].score);
    printf("\t������");
    scanf("\t%s",per[n+i].name);
    printf("\t���䣺");
    scanf("\t%s",per[n+i].email);
    printf("\t�绰���룺");
    scanf("\t%s",per[n+i].num);
    printf("\t����סַ��");
    scanf("\t%s",per[n+i].adds);
    printf("\tqq��");
    scanf("\t%s",per[n+i].qq);
    printf("\t΢�ţ�");
    scanf("\t%s",per[n+i].wechat);
    gets(x);
    printf("\n\t�Ƿ������ӣ���Y/N��");
    scanf("\t%c",&sign);
    i++;
  }
  return(n+i);
}
int Display(person per[],int n)
{
  int i;
  printf("------------------------\n");
  printf("ѧ��   ����  ����   �绰����     ����סַ    qq      ΢��\n ");
  printf("------------------------\n");
  for(i=1;i<n+1;i++)
  {
    printf("%-5d%-8s%-6s%-13s%-15s%-15s%-15s\n",per[i-1].score,per[i-1].name,per[i-1].email,per[i-1].num,per[i-1].adds,per[i-1].qq,per[i-1].wechat);
    if(i>1&&i%10==0)
    {
      printf("\t------------------\n");
      printf("\t");
      system("pause");
      printf("\t-----------------\n");
    }
  }
  printf("------------------\n");
  system("pause");
}
int Delete_a_record(person per[],int n)
{
  char s[20];
  int i=0,j;
  printf("\t��������ɾ����¼�е����֣�");
  scanf("%s",s);
  while(strcmp(per[i].name,s)!=0&&i<n)i++;
  if(i==n)
  {
    printf("\tͨѶ¼��û�д��ˣ�\n");
    return(n);
  }
  for(j=i;j<n-1;j++)
  {
    strcpy(per[j].num,per[j+1].num);
    strcpy(per[j].name,per[j+1].name);
    strcpy(per[j].email,per[j+1].email);
    strcpy(per[j].adds,per[j+1].adds);
    strcpy(per[j].qq,per[j+1].qq);
    strcpy(per[j].wechat,per[j+1].wechat);
    per[j].score=per[j+1].score;
  }
  printf("\t\t\t�Ѿ��ɹ�ɾ����\n");
  return(n-1);
}
void Query_a_record(person per[],int n)
{
  int m;
  printf("\t\n ��ѡ���ѯ��ʽ��\n");
  printf("\t|1-----����|\n");
  printf("\t|2-----�绰|\n");
  printf("\t|3-----��ַ|\n");
  printf("\t|4-----����|\n");
  printf("��ѡ��");
  scanf("%d",&m);
  while(m!=1&&m!=2&&m!=3&&m!=4)
  {
    printf("�������������ѡ��");
    scanf("%d",&m);
  }
  if(m==1)
  {
    char s[20];
    int i=0;
    printf("\t���������ѯ��������");
    scanf("\t%s",s);
    while(strcmp(per[i].name,s)!=0&&i<n)i++;
    if(i==n)
    {
      printf("\tͨѶ¼��û�д���!\n");
      return;
    }
    printf("\t ����ѧ�ţ�%d\n",per[i].score);
    printf("\t �������䣺%s\n",per[i].email);
    printf("\t ���˵绰���룺%s\n",per[i].num);
    printf("\t ���������ַ��%s\n",per[i].adds);
    printf("\t ����qq��%s\n",per[i].qq);
    printf("\t ����΢�ţ�%s\n",per[i].wechat);
  };
  if(m==2)
  {
    char s[20];
    int i=0;
    printf("\t���������ѯ�ĵ绰��");
    scanf("\t%s",s);
    while(strcmp(per[i].num,s)!=0&&i<n)i++;
    if(i==n)
    {
      printf("\tͨѶ¼��û�д���!\n");
      return;
    }
    printf("\t ����ѧ�ţ�%d\n",per[i].score);
    printf("\t ����������%s\n",per[i].name);
      printf("\t �������䣺%s\n",per[i].email);
    printf("\t ���������ַ��%s\n",per[i].adds);
    printf("\t ����qq��%s\n",per[i].qq);
    printf("\t ����΢�ţ�%s\n",per[i].wechat);
  };
  if(m==3)
  {
    char s[20];
    int i=0;
    printf("\t���������ѯ�ĵ�ַ��");
    scanf("\t%s",s);
    while(strcmp(per[i].adds,s)!=0&&i<n)i++;
    if(i==n)
    {
      printf("\tͨѶ¼��û�д���!\n");
      return;
    }
    printf("\t ����ѧ�ţ�%d\n",per[i].score);
    printf("\t ����������%s\n",per[i].name);
      printf("\t �������䣺%s\n",per[i].email);
    printf("\t ���˵绰���룺%s\n",per[i].num);
    printf("\t ����qq��%s\n",per[i].qq);
    printf("\t ����΢�ţ�%s\n",per[i].wechat);
  };
}
void Change(person per[],int n)
{
  char s[20];
  int i=0;
  printf("\t ���������޸ĵļ�¼�е����֣�");
  scanf("%s",s);
  while(strcmp(per[i].name,s)!=0&&i<n)i++;
  if(i==n)
  {
    printf("\tͨѶ¼��û�д���!\n");
    return;
  }
  printf("\tѧ�ţ�");
  scanf("\t%d",&per[i].score);
  printf("\t ������");
  scanf("\t%s",per[i].name);
  printf("\t ���䣺");
  scanf("\t%s",per[i].email);
  printf("\t �绰���룺");
  scanf("\t%s",per[i].num);
  printf("\t ��ַ��");
  scanf("\t%s",per[i].adds);
  printf("\t qq��");
  scanf("\t%s",per[i].qq);
  printf("\t ΢�ţ�");
  scanf("\t%s",per[i].wechat);
  printf("\t �޸ĳɹ�!");
}
void WritetoText(person per[],int n)
{
  int i=0;
  FILE *fp;
  char filename[20];
  printf("\t ���浽�ļ�\n");
  printf("\t ��������������ļ�����");
  scanf("%s",filename);
  if(fp=fopen(filename,"w+")==NULL)
  {
    printf("\t�޷����ļ�\n");
    system("pause");
    return;
  }
  printf("%s\n",filename);
  printf("-1\n");
    fprintf(fp,"*************************ͨѶ¼***********************\n");
    fprintf(fp, "ѧ��   ����  ����    �绰����    �����ַ    qq    ΢��\n");
    fprintf(fp,"------------------------------------------------------\n");
    while(i<n)
    {
      fprintf(fp,"%-5d%-8s%-6s%-13s%-15s%-15s%-15s\n",per[i].score,per[i].name,per[i].email,per[i].num,per[i].adds,per[i].qq,per[i].wechat);
    i++;
    }

fprintf(fp,"------------------------------------------------------\n");
fprintf(fp,"------------------����%d ����¼----------------------\n");
  printf("-2\n");
fclose(fp);
printf("����ɹ���\n");
}
int main()
{
  int n=0;
  for(;;)
  {
    switch(menu_select())
    {
      case 1:
      printf("\n\t ��Ӽ�¼��ͨѶ¼\n");
      n=input(pe,n);
      break;
      case 2:
      printf("\n\t\t  ͨѶ¼��¼��\n");
      Display(pe,n);
      break;
      case 3:
      printf("\n\t ��ͨѶ¼��ɾ����¼\n");
      n=Delete_a_record(pe,n);
      printf("\t");
      system("pause");
      break;
      case 4:
      printf("\n\t ��ͨѶ¼�в��Ҽ�¼\n");
      Query_a_record(pe,n);
      printf("\t");
      system("pause");
      break;
      case 5:
      printf("\n\t �޸�ͨѶ¼�еļ�¼\n");
      Change(pe,n);
      printf("\t");
      system("pause");
      break;
      case 6:
      printf("\n\t���湦��\n");
      WritetoText(pe,n);
      printf("\t");
      system("pause");
      break;
      case 0:
      printf("\n\t\t ллʹ�ã��ټ���\n");
      printf("\n\t\t");
      system("pause");
      exit(0);



    }
  }
}
