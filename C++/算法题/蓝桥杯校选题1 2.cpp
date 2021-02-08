#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int main(){
  char a[101];
  int n,t=8;
  queue<char> s;
  while(t--){
  cin >> a >> n;
  for (int k = 0; k < strlen(a); k++)
    s.push(a[k]);
  for (int i=1;i<=n;i++){
  	int m = s.size(), sum;
      char c;
      for (int j=1;j<=m;j++){
        if (j == 1) {
          if (j == m) {
            s.push('1');
            s.push(s.front());
            s.pop();
          } else {
            sum = 1;
            c = s.front();
            s.pop();
          }
        }
        else if(j!=1&&j!=m){
          if (c == s.front()) {
            sum++;
            s.pop();
          } else {
            s.push(char(sum + '0'));
            s.push(c);
            sum = 1;
            c = s.front();
            s.pop();
          }
        }
        else{
          if (c == s.front()) {
            s.push(char(sum + 1 + '0'));
            s.push(c);
            s.pop();
          } else {
            s.push(char(sum + '0'));
            s.push(c);
            s.push('1');
            s.push(s.front());
            s.pop();
          }
        }
      }
  }
  while (s.size()) {
    cout << s.front();
    s.pop();
  }
  cout << endl << endl;
 }
  return 0;
}
/*
【问题描述】
从X星截获一份电码，是一些数字，
如下：
13
1113
3113
132113
1113122113
....
 
YY博士经彻夜研究，发现了规律：
第一行的数字随便是什么，以后每一行
都是对上一行“读出来”
比如第2行，是对第1行的描述，意思
是：1个1，1个3，所以是：1113
第3行，意思是：3个1,1个3，所以
是：3113
 
请你编写一个程序，可以从初始数字
开始，连续进行这样的变换。
 
数据格式：
 
第一行输入一个数字组成的串，不超
过100位
第二行，一个数字n，表示需要你连
续变换多少次，n不超过20
 
输出一个串，表示最后一次变换完的
结果。
 
样例输入：
5
7
 
样例输出：
13211321322115
*/
         