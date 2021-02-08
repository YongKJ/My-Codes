#include <iostream>
#include <map>
using namespace std;
const int num = 100;
int main() {
  int x, y, z;
  while (cin >> x >> y >> z){
    int s[num][num] = {0};
    map<int, int> p;
    map<int, int>::iterator q;
    for (int i=3;i<num;i++)
      p[i] = 1;
    for (int i=1;i<=x;i++){
        if(i==1)
          s[i][0] = 1, s[i][1] = 2;     
        else{
          for (q=p.begin();q!=p.end();q++)
            if (q->second) {
              s[i][0] = q->first, q->second = 0;
              break;
            }
          s[i][1] = s[i][0] * 2 - (i - 1), p[s[i][1]] = 0;
        }
        for (int j = 2;; j++) {
          s[i][j] = s[i][j - 1] + s[i][j - 2];
          if (s[i][j]>=num&&j >= y)
            break;
          if (s[i][j] < num)
            p[s[i][j]] = 0;
        }
    }
    cout <<s[x][y-1]<<" "<< s[x][y - 1] % z << endl;
  }
  return 0;
}