#include <iostream>
using namespace std;
int n, k;
void search(int s[], int x, int y) {
   if(x>=y)
     return;
   cout << x + 1 << " " << y + 1 << endl;
  int low, high, temp, t;
  low = x, high = y, temp = s[low];
  cout << temp << endl;
  while (low < high) {
    while (low < high && temp <= s[high])
      high--;
    s[low] = s[high];
    while (low < high && s[low] <= temp)
      low++;
    s[high] = s[low];
  }
  s[low] = temp;
  for (int i = 0; i < n; i++)
      cout << s[i] << " ";
  cout << endl << low + 1 << " " << high + 1 << endl;
  cout << endl;
  search(s, x, low-1), search(s, low + 1, y);
}
int main(){
  while (cin >> n) {
    int s[n];
    for (int i = 0; i < n; i++)
      cin >> s[i];
    cin >> k, search(s, 0, n - 1);
    cout << s[k - 1] << endl;
  }
  return 0;
}

/*
10
9 8 7 6 1 2 3 4 5 10
3
*/
  	