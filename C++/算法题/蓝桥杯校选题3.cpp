#include <iostream>
#include <cstring>
#include <set>
using namespace std;
int main(){
  long long number;
  while(cin >> number,number!=-1){
    long long sum,flag=1;
    set<long long> s;
    do{
      sum = 0;
    while (number) {
      int k = number % 10;
      sum += k * k;
      number /= 10;
    }
    if (s.find(sum) == s.end()) {
      s.insert(sum);
      number = sum;
    } else {
      flag = 0;
      break;
    }
    } while (sum != 1);
  cout << (flag ? "true" : "false") << endl;
  }
  return 0;
}
     
  	
/*

这道题初步思路是将每一次的sum结果，
即每一次计算出的平方和保存在数组a中，
一旦某一次的结果和a中的数据有重复， 
便可判断为“非快乐数”。

【问题描述】
判断一个正整数是否是快乐数字？

如果一个数字能够通过有限次快乐变换成为1，
则是快乐数字。

快乐变换是对一个数字的每一位的平方数求和。

例如：

对于68

68 => 62+82= 100

100 => 12 + 02 + 02 = 1

因此68是快乐数字

输入
每一行输入一个整数，代表n；如果n为-1，
表示输入结束。（n <= 100000000)

输出
针对每组数据，输出是否是快乐数字 
true/false

 
样例输入
68
-1
样例输出
true
 
*/