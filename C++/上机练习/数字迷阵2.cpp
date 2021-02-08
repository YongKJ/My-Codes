#include <iostream>
#include <map>
using namespace std;
const int num = 10;
class number {
public:
  number(int x, int y, int z);
  void plus(int a[],int n);

private:
  map<int, int> p;
};
int main() {
  int x, y, z;
  while (cin >> x >> y >> z)
    number d1(x, y, z);
  return 0;
}
number::number(int x, int y, int z) {
  int s[10][10] = {0};
  for (int i = 4; i <= 31; i++)
    p[i] = 1;  
  for (int i = 0; i < num; i++)
    plus(s[i], i);
  cout << s[x - 1][y - 1] % z << endl;
}
void number::plus(int a[],int k){
  int s = 0;
  map<int, int>::iterator q;
  if (k == 0)
    a[0] = 1, a[1] = 2;
        else {
          for (q = p.begin(); q != p.end(); q++) {
            if(q->second)
              s++;
            if (s == 1&&q->second) 
              a[0] = q->first, q->second = 0;
            else if (s == 3 && q->second) {
              a[1] = q->first, q->second = 0;
              break;
            }
          }
        }
        for (int i = 2; i < num; i++) {
          a[i] = a[i - 1] + a[i - 2];
          if (p.find(a[i]) != p.end())
            p[a[i]]--;
        }
}
