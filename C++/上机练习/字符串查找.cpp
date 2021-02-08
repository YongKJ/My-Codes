#include <iostream>
#include <string>
using namespace std;
int main(){
  string str1, str2;
  while(cin>>str1>>str2){
    int sum=0;
    for (int i = 0, j = 0; str1[i];j=0) {
      if (str1[i] != str2[j])i++;
      else
        while (str2[j] && str1[i] == str2[j])i++, j++;
      if (!str2[j])sum = i - str2.size();
    }
    cout << (sum ? sum : -1) << endl;
  }
  return 0;
}
/*
abcdabab
ab
abcd
ef
*/          
    
    
/*
描述


       给出两个字符串，要求出第二个字符串在第一个字符串中
       最后一次出现的位置。所有字符的位置下标都从0开始。 

      如字符串"ba"，在另一字符串"abababa"中出现的位置分
      别为1,3,5。那么答案就是5，如果子字符串没有在原字符
      串中出现过，则答案为-1。

输入


         输入有多组测试数据。

每组测试数据两行，第一行为原字符串，第二行为子字符串。

两行都不为空串，而且长度均不超过1000000。

输出


     对于每组测试数据，在一行上输出一个整数，表示子字符串
     最后一次在原字符串中出现的位置。

样例输入

abababa
ba

样例输出

5
*/