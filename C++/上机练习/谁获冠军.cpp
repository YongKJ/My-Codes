#include <iostream>
#include <map>
using namespace std;
class champion {
public:
  champion(int t1, int t2, int t3, int t4);
  void Set();
  void count1();
  int is_it();
  void display();
  void show();

private:
  int s[4], i1[4], a, b, c, d,one,two;
  map<int, int> x[4], y;
  map<int, int>::iterator p[4], q;
};
int main(){
  int a, b, c, d;
  while (cin >> a >> b >> c >> d) {
    champion d1(a, b, c, d);
    d1.Set();
    d1.count1();
    void show();
  }
  return 0;
}
champion::champion(int t1, int t2, int t3, int t4) {
  s[0] = t1, s[1] = t2, s[2] = t3, s[3] = t4;
}
void champion::Set(){
  int a, b;
  for (int i = 0; i < 4; i++) {
    cin >> a >> b;
    x[i][a] = b;
    cin >> a >> b;
    x[i][a] = b;
  }
  for (int i = 1; i <= 5; i++)
    y[i] = 0;
}
void champion::count1(){
  one = two = 0;
  for (int i=0,j=0;i<4;i++){
    if (s[i] == 1) {
      one++;
      i1[j++] = i;
    } else if (s[i] == 2) {
      two += 2;
      for (p[i] = x[i].begin(); p[i] != x[i].end(); p[i]++)
        y[p[i]->first] = p[i]->second;
    }
  }
  a = b = c = d = 0;
  switch (one) {
  case 1:
    a = i1[0];
    break;
  case 2:
    a = i1[0], b = i1[1];
    break;
  case 3:
    a = i1[0], b = i1[1], c = i1[2];
    break;
  case 4:
    a = i1[0], b = i1[1], c = i1[2], d = i1[3];
    break;
  default:
    break;
  }
}
int champion::is_it() {
  int number = 0, t = 0;
  for (q = y.begin(); q != y.end(); q++)
    if (q->second != 0)
      number++;
  if (number == one + two)
    t = 1;
  return t;
}
void champion::display(){
  int s = 0;
	if(one+two==5){
          for (q = y.begin(); q != y.end(); q++) {
            if (q == --y.end())
              cout << q->second << endl;
            else
              cout << q->second << " ";
          }
        }
          else if(one+two==4){
            for (q=y.begin();q!=y.end();q++)
              s += q->second;
              for (q=y.begin();q!=y.end();q++)
                if (q->second == 0) {
                  q->second = 15 - s;
                  break;
                }
              for (q = y.begin(); q != y.end(); q++) {
                if (q == --y.end())
                  cout << q->second << endl;
                else
                  cout << q->second << " ";
              }
          }
        }
void champion::show(){
  int flag = 1;
  switch (one) {
  case 1:
    for (p[a]=x[a].begin();p[a]!=x[a].end();p[a]++){
      y[p[a]->first] = p[a]->second;
      if (is_it()) {
        flag = 0;
        display();
      }
      y[p[a]->first] = 0;
    }
    break;
  case 2:
  for (p[a]=x[a].begin();p[a]!=x[a].end();p[a]++)
    for (p[b]=x[b].begin();p[b]!=x[b].end();p[b]++){
      y[p[a]->first] = p[a]->second;
      y[p[b]->first] = p[b]->second;
      if (is_it()) {
        flag = 0;
        display();
      }
      y[p[a]->first] = 0;
      y[p[b]->first] = 0;
  }
    break;
  case 3:
  for (p[a]=x[a].begin();p[a]!=x[a].end();p[a]++)
    for (p[b]=x[b].begin();p[b]!=x[b].end();p[b]++)
      for (p[c]=x[c].begin();p[c]!=x[c].end();p[c]++){
        y[p[a]->first] = p[a]->second;
        y[p[b]->first] = p[b]->second;
        y[p[c]->first] = p[c]->second;
        if (is_it()) {
          flag = 0;
          display();
        }
        y[p[a]->first] = 0;
        y[p[b]->first] = 0;
        y[p[c]->first] = 0;
      }
    break;
  case 4:
  for (p[a]=x[a].begin();p[a]!=x[a].end();p[a]++)
    for (p[b]=x[b].begin();p[b]!=x[b].end();p[b]++)
      for (p[c]=x[c].begin();p[c]!=x[c].end();p[c]++)
        for (p[d]=x[d].begin();p[d]!=x[d].end();p[d]++){
          y[p[a]->first] = p[a]->second;
          y[p[b]->first] = p[b]->second;
          y[p[c]->first] = p[c]->second;
          y[p[d]->first] = p[d]->second;
          if (is_it()) {
            flag = 0;
            display();
          }
          y[p[a]->first] = 0;
          y[p[b]->first] = 0;
          y[p[c]->first] = 0;
          y[p[d]->first] = 0;
        }
    break;
  default:
    break;
  }
  if (flag)
    cout << "Sorry" << endl;
}
          
          
    
	

  
	
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