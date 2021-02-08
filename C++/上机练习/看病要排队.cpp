#include <iostream>
#include <queue>
#include <string>
using namespace std;
typedef struct treat {
  int priority;
  int sequence;
  friend bool operator < (const treat &x, const treat &y){
	if(x.priority!=y.priority)
          return x.priority < y.priority;
        else
          return x.sequence > y.sequence;
}
} d2;
int main(){
  int n, x, y, z;
  string str;
  priority_queue<treat> doctor[3];
  treat d1;
  while(cin >> n){
  for (int i = 1; n-- && cin >> str;){
    if (str == "IN") {
      cin >> x >> y;
      d1.priority = y;
      d1.sequence = i;
      doctor[x - 1].push(d1);
      i++;
    }
    else
    {
      cin >> z;
        if (doctor[z-1].empty()) 
            cout << "EMPTY" << endl;
        else {
          cout << doctor[z - 1].top().sequence << endl;
          doctor[z - 1].pop();
        }
    }
  }
  }
  return 0;
}
      
	
/*
样例输入

7
IN 1 1
IN 1 2
OUT 1
OUT 2
IN 2 1
OUT 2
OUT 1
2
IN 1 1
OUT 1

样例输出

2
EMPTY
3
1
1
*/