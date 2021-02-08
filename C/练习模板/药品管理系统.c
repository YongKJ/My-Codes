#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node {
  char *name;
  long number;
  float price, sales, sale_price;
  struct node *next;
} * link;
void menu();
void chose(int i);
void add();
void del();
void load();
void find();
void num_sort();
void price_sort();
void sales();
void sale_price_sort();
int main() {
  int i;
  menu();
  do {
    printf("\n\n\t请输入您要执行的操作:");
    scanf("%d", &i);
    chose(i);
  } while (i);
  return 0;
}
void menu() {
  int i;
  char *s[9];
  s[0] = "1.添加药品记录";
  s[1] = "2.删除药品记录";
  s[2] = "3.加载药品信息";
  s[3] = "4.查找药品记录";
  s[4] = "5.按编号排序  ";
  s[5] = "6.按单价排序  ";
  s[6] = "7.按销售量排序";
  s[7] = "8.按销售额排序";
  s[8] = "0.退出        ";
  printf("\n\t ");
  for (i = 0; i < 23; i++)
    printf("*");
  printf("欢迎使用药品管理系统");
  for (i = 0; i < 23; i++)
    printf("*");
  for (i = 0; i < 9; i++)
    printf("\n\t}%-22c%s%21c|", '*', s[i], '*');
  printf("\n\n\n\t ");
  for (i = 0; i < 66; i++)
    printf("*");
}
void chose(int i) {
  switch (i) {
  case 1:add();break;
  case 2:del();break;
  case 3:load();break;
  case 4:find();break;
  case 5:num_sort();break;
  case 6:price_sort();break;
  case 7:sales();break;
  case 8:sale_price_sort();break;
  case 0:printf("\n\t退出成功!"),exit(0);break;
  default:printf("\n\t输入错误!");
  }
}
