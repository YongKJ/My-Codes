#include <iostream>
#include <string>
using namespace std;
int sum, chess[4][5], x, y,s[8][2] = {-2, -1, -2, 1, -1, -2, -1, 2, 1, -2, 1, 2, 2, -1, 2, 1};
void show(int a,int b){
  int x1, y1;
  for (int i = 0; i < 8; i++) {
    x1 = a + s[i][0], y1 = b + s[i][1];
    if ((x1 >= 0 && x1 <= 3) && (y1 >= 0 && y1 <= 4) && chess[x1][y1] == 0)
      chess[x1][y1] = 1, show(x1, y1), chess[x1][y1] = 0;
    if (x1 + 1 == x && y1 + 1 == y)
     sum++;
  }
}
int main() {
  while (sum = 0, memset(chess, 0, sizeof(chess)), cin >> x >> y)
    chess[x - 1][y - 1] = 1, show(x - 1, y - 1), cout << sum << endl;
  return 0;
}
	
	
	
	
  	