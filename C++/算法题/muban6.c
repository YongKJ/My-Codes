#include<stdio.h>
struct student {
  char num[6];
  char name[8];
  float score[3];
  float avr;
} stu[5];
int main()
{
	int i,j;
        float sum;
        FILE *fp;
       for(i=0;i<5;i++){
	//printf("\n please input No.%d score:\n",i+1);
        //printf("stuNo:");
        scanf("%s", stu[i].num);
        //printf("name:");
        scanf("%s", stu[i].name);
        sum = 0;
        for (j = 0; j < 3; j++) {
          // printf("score %d:", j + 1);
          scanf("%f", &stu[i].score[j]);
          sum += stu[i].score[j];
        }
        stu[i].avr = sum / 3;
       }
       printf("\n要写入文件的内容:\n");
       for ( i=0;i<5;i++)
         printf("%s %s %.1f %.1f %.1f %.1f\n", stu[i].num, stu[i].name, stu[i].score[0],
                stu[i].score[1], stu[i].score[2], stu[i].avr);
       fp = fopen("stud.txt", "w");
       for (i = 0; i < 5; i++) {
         //if (fwrite(&stu[i], sizeof(struct student), 1, fp) != 1)
      //     printf("file write error\n");
         fprintf(fp,"%s %s %.1f %.1f %.1f %.1f\n", stu[i].num, stu[i].name,
                stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].avr);
       }
       fclose(fp);
       return 0;
}
/*
1001 张三 66.1 77.5 88.1
1002 李四 66.2 77.6 88.2
1003 王五 66.3 77.7 88.3
1004 赵六 66.4 77.8 88.4
1005 陈七 66.5 77.9 88.5
*/



