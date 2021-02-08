#include <iostream>
#include <map>
using namespace std;
class number {
public:
  number(int a, int b, int c);
  void show();

private:
  int n, m, d;
  map<int, int> x;
};
int main() {
  int a, b, c;
  while (cin >> a >> b >> c)
    number d1(a, b, c);
  return 0;
}
number::number(int a, int b, int c) {
  n = a, m = b, d = c;
  for (int i = 3; i < 100; i++)
    x[i] = 1;
  show();
}
void number::show(){
  int s[40][20] = {0};
  map<int, int>::iterator p;
  for (int i = 1; i <= n;i++){
      if(i==1)
          s[i][0] = 1, s[i][1] = 2;
          else{
              for (p=x.begin();p!=x.end();p++)
                  if (p->second) {
                    s[i][0] = p->first, p->second = 0;
                    break;
                  }
                s[i][1] = s[i][0] * 2 - (i - 1), x[s[i][1]] = 0;
          }
          for (int j = 2;; j++) {
            s[i][j] = s[i][j - 1] + s[i][j - 2];
            if (s[i][j] >= 100 && j >= m)
              break;
            if (s[i][j] < 100)
              x[s[i][j]] = 0;
          }
  }
  cout << s[n][m - 1] % d << endl;
}