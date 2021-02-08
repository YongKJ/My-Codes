#include <iostream>
using namespace std;
int n, k;
void search(int s[], int x, int y) {
   if(x>=y)
     return;
   int low = x, high = y, temp = s[x], t;
   while (low < high) {
     while (low < high && temp <= s[high])
       high--;
     s[low] = s[high];
     while (low < high && s[low] <= temp)
       low++;
     s[high] = s[low];
   }
  s[low] = temp, search(s, x, low - 1), search(s, low + 1, y);
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