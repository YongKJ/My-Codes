#include <cstdio>
#include <iostream>
using namespace std;
long long a,b,c,x,y,z,t;
char m;
int main() {
  cin >> a >> m >> b >> m >> c >> x >> m >> y >> m >> z >> t;
  //读入
  cout << ((x - a) * 3600 + (y - b) * 60 + (z - c)) * t;
  //时分秒的转换兼输出
}