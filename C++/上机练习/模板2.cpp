#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct book {
  int x, y, z;
} d0;
bool cm(const book &n,const book &m){
	if(n.x<m.x)
          return 0;
        else if (n.x == m.x) 
        {
          if (n.y < m.y)
            return 0;
          else return 1;
        } 
        else return 1;
}
int main() {
  vector<book> p;
  book d1;
  int n, t;
  cin >> n;
  t = n;
  while (n-- && cin >> d1.x >> d1.y)
    p.push_back(d1);
  sort(p.begin(), p.end(), cm);
  for (int i = 0; i < t; i++)
    cout << p[i].x << " " << p[i].y << endl;
  return 0;
}
    
  