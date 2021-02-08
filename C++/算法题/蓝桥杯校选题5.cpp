#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;
long long Seconds(string s);
struct times {
  long long x;
  long long seconds;
  bool operator<(times const a) const {
    if (x != a.x)
      return x < a.x;
    else
      return seconds <= a.seconds;
  }
};
int main(){
  int n,m;
  string s;
  times t;
  set<times> p1;
  set<times>::iterator q1;
  map<long long, int> p2;
  map<long long, int>::iterator q2;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t.x >> s;
    t.seconds = Seconds(s);
    p1.insert(t);
  }
  for (q1 = p1.begin(); q1 != p1.end(); q1++) {
    //cout << q1->x << " " << q1->seconds << endl;
    if (p2.find(q1->x) == p2.end()) {
      p2[q1->x] = 1;
      t = *q1;
    } else {
      if (q1->seconds - t.seconds <= 60 * 60)
        p2[q1->x]++;
    }
  }
  for (q2 = p2.begin(); q2 != p2.end(); q2++)
    if (q2->second >= 5)
      cout << q2->first << endl;
  // cout << q2->first << " "<<q2->second<<endl;
  return 0;
}
long long Seconds(string s) {
  long long t_hour, t_min, t_second;
  t_hour = (s[0] - '0') * 10 + (s[1] - '0');
  t_min = (s[3] - '0') * 10 + (s[4] - '0');
  t_second = (s[6] - '0') * 10 + (s[7] - '0');
  return t_hour * 60 * 60 + t_min * 60 + t_second;
}
/*
描述
为了提升用户帐号的安全性，H站决定实施一项措施：
对在1小时内(注：00:00:00与01:00:00仍视为在
1小时内)出现5次或5次以上密码错误的账户，暂时
禁止该帐号被登录。  
现在小Hi拿到了某日全部密码错误的日志，他想知道
有哪些帐号被暂时禁止登录。
输入
第一行包含一个整数N，代表记录的行数。  
以下N行每行包含一个整数A和一个时间T。其中是A代
表密码错误的账号ID；T代表发生时间，
格式是"hh:mm:ss"。  
1 ≤ N ≤ 10000  1 ≤ A ≤ 100000  
00:00:00 ≤ T ≤ 23:59:59
输出
从小到大输出所有被禁止登录的帐号ID，每个一行。
样例输入
10
1000 00:00:00
1001 00:59:00
1001 00:58:00
1001 01:00:00
1000 01:00:00
1000 02:00:00
1000 03:00:00
1001 01:00:01
1000 04:00:00
1001 01:23:14
样例输出
1001
*/