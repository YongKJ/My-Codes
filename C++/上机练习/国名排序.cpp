#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
  vector<string> p;
  int n;
  string m;
  cin >> n;
  while (n-- && cin >> m)
    p.push_back(m);
  sort(p.begin(), p.end());
  vector<string>::iterator q;
  for (q = p.begin(); q != p.end(); q++)
    cout << *q << endl;
  return 0;
}

/*
例输入

3
China
Canada
America

样例输出

America
Canada
China
*/