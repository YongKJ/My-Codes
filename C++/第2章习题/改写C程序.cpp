#include <iostream>
using namespace std;
int main()
{
  int a, b, d, min;
  cout << "Enter two numbers:";
  cin >> a >> b;
  min = a > b ? b:a;
  for (d=2;d<min;d++)
  if(0==a%d&&0==b%d)
    break;
  if (d == min) {
    cout << "No common denominators" << endl;
  }
  cout << "The lowest common denominators is "<< d << endl;
  return 0;
}