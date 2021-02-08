#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
int MAX = 0, a = 0, b = 0;
map<int, int> arr;
void solution();
int prove();
int main(){
  do {
    cin >> arr[MAX++];
  } while (getchar() == ' ');
  solution(), cout << a << endl << b << endl;
  return 0;
}
void solution(){
  do{
    int min = 0;
    for (int i=0;i<MAX;i++)
      if (arr[i]) {
        min = arr[i], arr[i] = 0;
        break;
      }
    for (int i = 0; i < MAX; i++)
      if (arr[i] < min && arr[i] != 0)
        min = arr[i], arr[i] = 0, a++;
    b++;
  } while (prove());
}
int prove() {
  for (int i = 0; i < MAX; i++)
    if (arr[i])
      return 1;
  return 0;
}