#include <iostream>
#include <map>
using namespace std;
class champion {
public:
  champion(int t1, int t2, int t3, int t4);
  void count1();
  int is_it();
  void display();
  void set_two();
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
    d1.count1();
    d1.show();
  }
  return 0;
}
champion::champion(int t1, int t2, int t3, int t4) {
  s[0] = t1, s[1] = t2, s[2] = t3, s[3] = t4;
  int a, b;
  for (int i = 0; i < 4; i++) {
    cin >> a >> b;
    x[i][a] = b;
    cin >> a >> b;
    x[i][a] = b;
  }
}
void champion::count1(){
  one = two = 0;
  for (int i=0,j=0;i<4;i++)
    if (s[i] == 1){
      one++;
      i1[j++] = i;
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
int champion::is_it(){
  int t = 0,s=0,sum=1;
  for(q=y.begin();q!=y.end();q++){
    s+= q->second;
    }
  for(q=y.begin();q!=y.end();q++){
    if (q->second == 0&&15-s>0)
       q->second = 15 - s;
     sum*=q->second; 
  }
  if (sum==120)
    t = 1;
  return t;
}
void champion::display(){
          for (q = y.begin(); q != y.end(); q++){
            if (q == --y.end())
              cout << q->second << endl;
            else
              cout << q->second << " ";
    }
}
void champion::set_two(){
  for (int i = 1; i <= 5; i++)
    y[i] = 0;
  for (int i=0;i<4;i++){
    if (s[i] == 2)
      for (p[i] = x[i].begin(); p[i] != x[i].end(); p[i]++)
        y[p[i]->first] = p[i]->second;
  }
}
void champion::show(){
  int flag = 1;
  set_two();
  switch(one){
  case 1:
    for (p[a]=x[a].begin();p[a]!=x[a].end();p[a]++){
      set_two();
      y[p[a]->first] = p[a]->second;
      if (is_it()){
        flag = 0;
        display();
      }
    }
  break;
  case 2:
    for (p[a]=x[a].begin();p[a]!=x[a].end();p[a]++){
     for (p[b]=x[b].begin();p[b]!=x[b].end();p[b]++){
      set_two();
      y[p[a]->first] = p[a]->second;
      y[p[b]->first] = p[b]->second;
      if (is_it()) {
        flag = 0;
        display();
      }
    }
 }
  break;
  case 3:
  for (p[a]=x[a].begin();p[a]!=x[a].end();p[a]++){
    for (p[b]=x[b].begin();p[b]!=x[b].end();p[b]++){
      for (p[c]=x[c].begin();p[c]!=x[c].end();p[c]++){
        set_two();
        y[p[a]->first] = p[a]->second;
        y[p[b]->first] = p[b]->second;
        y[p[c]->first] = p[c]->second;
        if (is_it()) {
          flag = 0;
          display();
        }
      }
    }
  }
  break;
  case 4:
  for (p[a]=x[a].begin();p[a]!=x[a].end();p[a]++){
    for (p[b]=x[b].begin();p[b]!=x[b].end();p[b]++){
      for (p[c]=x[c].begin();p[c]!=x[c].end();p[c]++){
        for (p[d]=x[d].begin();p[d]!=x[d].end();p[d]++){
          set_two();
          y[p[a]->first] = p[a]->second;
          y[p[b]->first] = p[b]->second;
          y[p[c]->first] = p[c]->second;
          y[p[d]->first] = p[d]->second;
          if (is_it()) {
            flag = 0;
            display();
          }
        }
      }
    }
  }
    break;
  default:
  if (is_it()) {
      flag = 0;
      display();
    }
    break;
  }
  if (flag)
    cout << "Sorry" << endl;
}