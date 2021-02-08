#include <iostream>
using namespace std;
int n, sum;
void number(int x) {
  if (x / 2 == 0)
    return;
  for (int i = 1; i <= x / 2; i++)
    sum++, number(i);
}
int main() {
  while (sum = 1, cin >> n)
    number(n), cout << sum << endl;
  return 0;
}
	
/*
描述

要求找出具有下列性质数的个数（包括输入的自然数n): 
先输入一个自然数n( n <= 1000),然后对此自然数按照如
下方法进行处理： 
（1）不作任何处理 
（2）在它的左边加上一个自然数，但该数不能超过原数的一半 
（3）加上数后，继续按此处理，直到不能再加自然数为止

 

输入

多个测试案例，每个测试案例为一个自然数n。

输出

输出满足以上条件的所有数的个数

样例输入

6

样例输出

6

提示

对于6，满足条件的数有 
6 
16 
26 
126 
36 
136
*/