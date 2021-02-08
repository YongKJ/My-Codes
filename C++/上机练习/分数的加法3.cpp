#include <iostream>
#include <cmath>
using namespace std;
class rationalNumber {
public:
  int gcd(int n, int m);
  rationalNumber(int x, int y);
  rationalNumber();
  rationalNumber operator +(rationalNumber &c);
  void show(rationalNumber &x, rationalNumber &y);

private:
  int a, b;
};
int main(){
  int x, y, a, b,t;
  cin >> t;
  while (t--) {
    cin >> x >> y>>a>>b;
    rationalNumber d1(x, y), d2(a, b), d3;
    if(y==0||b==0)
      continue;
    d3 = d1 + d2;
    d3.show(d1, d2);
  }
  return 0;
}
int rationalNumber::gcd(int n,int m){
    int r;
    if(n==m)
    return n;
    else
      while ((r = n % m) != 0) {
        n = m;
        m = r;
      }
    return m;
}
rationalNumber::rationalNumber(int x,int y){
  int r;
  if (y == 0) 
    cout << "denominator equal zero"<<endl;
  else 
  {
    if (y < 0)
      x *= -1, y *= -1;
    r = gcd(abs(x), abs(y));
    a = x/r;
    b = y/r;
  }
}
rationalNumber::rationalNumber() {}
rationalNumber rationalNumber::operator +(rationalNumber &c) {
  return rationalNumber(a * c.b + b * c.a, b * c.b);
}
/*void rationalNumber::show(rationalNumber &x, rationalNumber &y) {
  cout << x.a << "/" << x.b;
  if (y.a < 0)
    cout << y.a << "/" << y.b << "=";
  else
    cout << "+" << y.a << "/" << y.b << "=";
  if (a % b == 0)
    cout << a / b << endl;
  else if (a == 0)
    cout << a << endl;
  else
    cout << a << "/" << b << endl;
}*/
void rationalNumber::show(rationalNumber &x, rationalNumber &y) {
  cout << x.a << "/" << x.b;
  if (y.a >= 0)
    cout << "+";
    cout << y.a << "/" << y.b << "=";
  if (a % b == 0)
    cout << a / b;
  else if (a == 0)
    cout << a;
  else
    cout << a << "/" << b;
  cout << endl;
}