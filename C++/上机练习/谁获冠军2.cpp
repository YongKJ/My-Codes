#include <iostream>
#include <map>
using namespace std;
class champion {
public:
  champion(int t1, int t2, int t3, int t4);
  void set_data(int x1,int x2,int x3,int x4,int x5);
  int research(int n,int m);
  int show();

private:
  int a, b, c, d,s;
  map<int, int> x[4], y;
};
int main(){
  int a, b, c, d,e,s;
  while (s=0,cin >> a >> b >> c >> d) {
    champion d1(a, b, c, d);
    for (a=1;a<=5;a++)
      for (b=1;b<=5;b++)
        for (c=1;c<=5;c++)
          for (d = 1; d <= 5; d++) {
            e = 15 - a - b - c - d;
            d1.set_data(a, b, c, d, e);
            s+=d1.show();
          }
    if (s == 0)
      cout << "Sorry" << endl;
  }
  return 0;
}
champion::champion(int t1, int t2, int t3, int t4){
  a = t1, b = t2, c = t3, d = t4;
  int n, m;
  for (int i = 0; i < 4; i++) {
    cin >> n >> m;
    x[i][n] = m;
    cin >> n >> m;
    x[i][n] = m;
  }
}
void champion::set_data(int x1, int x2, int x3, int x4, int x5) {
  for (int i = 1; i <= 5; i++)
    y[i] = 0;
  y[1] = x1, y[2] = x2, y[3] = x3, y[4] = x4, y[5] = x5;
  s = x1 * x2 * x3 * x4 * x5;
}
int champion::research(int n, int m) {
  int t = 0;
  map<int, int>::iterator p;
  p = y.find(n);
  if (p != y.end() && p->second == m)
    t = 1;
  return t;
}
int champion::show(){
  int k[4][2],j,t1,t2,t3,t4,flag=0;
  map<int, int>::iterator p;
  for (int i = 0; i < 4; i++) {
    j = 0;
    for (p = x[i].begin(); p != x[i].end(); p++)
      k[i][j++] = research(p->first, p->second);
  }
  t1 = k[0][0] + k[0][1];
  t2 = k[1][0] + k[1][1];
  t3 = k[2][0] + k[2][1];
  t4 = k[3][0] + k[3][1];
  if (t1 == a && t2 == b && t3 == c && t4 == d && s == 120){
    for (p = y.begin(); p != y.end(); p++) {
      flag = 1;
      if (p == --y.end())
        cout << p->second << endl;
      else
        cout << p->second << " ";
    }
  }
  return flag;
}
	
	
/*
@勇往直前k 针对这个问题，在网上找到了pascal语言算法，可以借鉴下
var a,b,c,d,e:byte;
begin
for a:=1 to 5 do
for b:=1 to 5 do
for c:=1 to 5 do
for d:=1 to 5 do begin
e:=15-a-b-c-d;
if (ord(b=5)+ord(d=3)=1) and
(ord(a=1)+ord(e=4)=1) and
(ord(c=4)+ord(d=2)=1) and
(ord(b=3)+ord(e=5)=1) and (a*b*c*d*e=120) then
writeln('a:',a,'b:',b,'c:',c,'d:',d,'e:',e);
end;
end
*/
/*
描述


ABCDE五个人在运动会上分获百米（1）、二百米（2）、跳高（3）、跳远（4）和铅球冠军（5）中的一项，有四个人猜测比赛结果：
甲说：B获铅球冠军，D获跳高冠军。 
乙说：A获百米冠军，E获跳远冠军。 
丙说：C获跳远冠军，D获二百米冠军。 
丁说：B获跳高冠军，E获铅球冠军。 
其中每个人说了2句，现知道每个人说对了几句。问5人各获得哪项冠军？

输入


多组测试数据，每组测试数据包含5行 
第1行4个数字，分别表示4个人说对的句数（0，1或2） 
然后4行分别是各人的2个猜测，每行4个数字，先是运动员 然后是项目，A为1，B为2，C为3，D为4，E为5 

输出


在一行分别输出5人拿冠军的项目，如果不能确定则输出"Sorry"

样例输入

1 1 1 1
2 5 4 3
1 1 5 4
3 4 4 2
2 3 5 5
1 0 1 2
2 5 4 3
1 1 5 4
3 4 4 2
2 3 5 5

样例输出

1 2 4 3 5
Sorry
*/