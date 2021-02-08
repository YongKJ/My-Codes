#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct message {
  string str[4];
} d2;
bool cmp(const message &x, const message &y){
	if(x.str[2]<y.str[2])
          return 1;
          else if(x.str[2]==y.str[2]){
          	if(x.str[3]<y.str[3])
                  return 1;
                else if (x.str[3] == y.str[3]) {
                  if (x.str[0] < y.str[0])
                    return 1;
                  else
                    return 0;
                } else
                  return 0;
          } else
            return 0;
}
int main(){
  vector<message> x;
  vector<message>::iterator p;
  message d1;
  int n;
  cin >> n;
  while (n--) {
    cin >> d1.str[0] >> d1.str[1] >> d1.str[2] >> d1.str[3];
    x.push_back(d1);
  }
  sort(x.begin(), x.end(), cmp);
  for (p = x.begin(); p != x.end(); p++)
    cout << p->str[0] << " " << p->str[1] << " " << p->str[2] << " " << p->str[3]
         << endl;
  return 0;
}
  
	
/*
样例输入

5
crq 660000 huangyan 1979-1-1
carter 660000 huangyan 1979-1-1
tzc 668888 linhai 1990-1-11
wk 666666 ningbo 1986-10-1
metoo 665567 jiaojiang 1969-1-13

样例输出

carter 660000 huangyan 1979-1-1
crq 660000 huangyan 1979-1-1
metoo 665567 jiaojiang 1969-1-13
tzc 668888 linhai 1990-1-11
wk 666666 ningbo 1986-10-1
*/