#include <iostream>
#include <stack>
using namespace std;
int main(){
  int t = 8;
  while(t--){
  long s;
  char a[26];
  stack<char> p;
  for (int i = 0; i < 26; i++) {
    if (i == 0)
      a[i] = 'Z';
    else
      a[i] = char('A' + i - 1);
  }
  cin >> s;
  while (s) {
    int n = s % 26;
    p.push(a[n]);
    s /= 26;
    if (n == 0)
      s--;
  }
  while (!p.empty())
    cout << p.top(), p.pop();
  cout << endl << endl;
  }
  return 0;
}
  	
    
/*
【问题描述】
Excel单元格的地址表示很有趣，
它使用字母来表示列号。
比如，
A表示第1列，
B表示第2列，
Z表示第26列，
AA表示第27列，
AB表示第28列，
BA表示第53列，
....
 
当然Excel的最大列号是有限度的，
所以转换起来不难。
如果我们想把这种表示法一般化，可
以把很大的数字转换为很长的字母序列呢？
 
本题目既是要求对输入的数字, 输出其对
应的Excel地址表示方式。
 
样例输入：
26
样例输出：
Z
 
样例输入：
2054
样例输出：
BZZ
 
我们约定，输入的整数范围
[1,2147483647]
*/