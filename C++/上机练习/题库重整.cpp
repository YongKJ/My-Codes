#include <iostream>
#include <map>
#include <string>
using namespace std;
int main(){
  map<string, int> x;
  map<int, string> y;
  map<string, int>::iterator p;
  map<int, string>::iterator q;
  int n,m,i;
  string str;
  cin >> n;
  while (n-- && cin >> m&&getchar()&&getline(cin,str)) {
    y.insert(make_pair(m, str));
    if (x.find(str) != x.end())
      x[str]++;
    else
      x[str] = 1;
  }
  for (p=x.begin();p!=x.end();p++)
  if(p->second>1){
    cout << p->first << " ";
    for (i=1,q=y.begin();q!=y.end();q++){
    if(p->first==q->second){
      cout << q->first;
    if (i == p->second) {
      cout << endl;
      break;
    } else {
      cout << " ";
      i++;
    }
   }
  }
 }
  return 0;
}
      
/*
描述


    OJ由于在早期没有题目搜索功能，导致系统内出现了很多重复的题目，为了检查题目重复情况，crq需要统计出系统内哪些题目是重复的，现在就把这个任务交给你了。

输入



     输入数据有多组组，每组数据的第1行是题库总量t，t<=10000。接下来有t行，每行有两个数据，分别为题号（题号从1001开始计直到最后一题，中间没有缺失）和标题（标题是一个字符串，可能包含空格）。

    为简化问题，假设标题长度不超过20个字符，行末没有空格。

    输入以EOF结束。

输出



    请根据标题的字典序输出所有有重复的题目信息，每个信息占一行。

    每行包括一个标题以及所有重复的题号，并按照题号的顺序从小到大排列。之间用空格分开。

样例输入

5
1001 a+b
1003 humble number
1002 humble number
1004 hello world
1005 a+b

样例输出

a+b 1001 1005
humble number 1002 1003
*/