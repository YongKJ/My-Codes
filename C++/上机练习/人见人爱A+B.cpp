#include <iostream>
using namespace std;
int main(){
  int x0, y0, z0, x1, y1, z1,a,b,c,n;
  cin >> n;
  while (n--) {
    a = b = c = 0;
    cin >> x0 >> y0 >> z0;
    cin >> x1 >> y1 >> z1;
    a = x0 + x1;
    b = y0 + y1;
    c = z0 + z1;
    if (c >= 60)
      c -= 60, b++;
    if (b >= 60)
      b -= 60, a++;
    cout << a << " " << b << " " << c << endl;
  }
  return 0;
}
        
/*
Sample Input
2
1 2 3 4 5 6
34 45 56 12 23 34
 

Sample Output
5 7 9
47 9 30
*/