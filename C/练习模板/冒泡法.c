#include "stdio.h"

void main()
{ 
      int a[10]; 
      int i, j, temp; 

      // 输入10个整型数据 
      printf("Please input ten numbers: \n"); 
      for (i = 0; i < 10; i++) 
            scanf("%d", &a[i]); 

      // 排序 
      for (i = 0; i < 9; i++) // 10个数，10 - 1轮冒泡，每一轮都将当前最大的数推到最后 
      { 
            for (j = 0; j < 9 - i; j++) // 9 - i，意思是每当经过一轮冒泡后，就减少一次比较
              if (a[j] > a[j + 1]) 
              {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
              }
      }

      // 打印排序结果
      for (i = 0; i < 10; i++)
        printf("%d\n", a[i]);

      return 0;
}