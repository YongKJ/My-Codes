#include <iostream>
using namespace std;
int A[10];
int& array1(int i);
int main() {
  int i, number;
  A[0] = 0;
  A[1] = 1;
  cin >> number;
  for (i = 2; i < number; i++)
    array1(i) = array1(i - 2) + array1(i - 1);
  for (i = 0; i < number; i++)
    cout << " " << array1(i);
  cout << endl;
  return 0;
}
int& array1(int i) 
{ return A[i]; }
