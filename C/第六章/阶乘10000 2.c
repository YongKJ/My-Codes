#include<stdio.h>
int a[50000]; //保存最终运算结果的数组
int main()
{
     int n; //需要求阶乘的数字
     int carry; //进位
     int digit = 1; //位数
     int temp, i, j; // temp为阶乘的任一元素与临时结果的某位的乘积结果
     scanf("%d", &n); //接收所求数字
     a[0] = 1;        //将结果先初始化为1
     for (i = 2; i <= n; ++i) //开始阶乘，阶乘元素从2开始依次登场
  {
//按乘法运算思想来考虑，将临时结果的每位与阶乘元素相乘
     for (j = 1, carry = 0; j <= digit; ++j) 
     {
     temp = a[j - 1] * i +carry; //相应阶乘中的一项与当前所得临时结果的某位相乘（加上进位）
     a[j - 1] = temp % 10; //更新临时结果的位上信息
     carry = temp / 10;    //看是否有进位
      }
      while (carry) //如果有进位
      {
      a[++digit - 1] = carry % 10; //新加一位，添加信息。位数增1
      carry /= 10;                 //看还能不能进位.     
      }
   }
      printf("结果是:\n"); //显示结果
      for (i = digit; i >= 1; --i)
      printf("%d", a[i - 1]);
}