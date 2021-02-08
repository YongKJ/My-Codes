#include <iostream>
using namespace std;
int &f(int &i) 
{
  i += 10;
  return i;
}
int main() 
{
  int k = 0;
  int &m = f(k);
  cout << k << endl;
  m = 20;
  k = 1100;
  f(k);
  cout << m << endl;
  return 0;
}
