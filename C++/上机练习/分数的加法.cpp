#include <iostream>
#include <iomanip>
using namespace std;
class rationalNumber {
public:
  rationalNumber(int x, int y);  
  rationalNumber operator+(const rationalNumber &c);
  friend void print(rationalNumber x, rationalNumber y, rationalNumber z);

private:
  int a, b, t;
  int gcd(int n, int m);
  int lcs(int n, int m);
};
int main(){
  int x, y, t;
  cin >> t;
  while (t--) {
    cin >> x >> y;
    rationalNumber d1(x, y);
    cin >> x >> y;
    rationalNumber d2(x, y);
    rationalNumber d3 = d1 + d2;
    print(d1, d2, d3);
  }
  return 0;
}
rationalNumber::rationalNumber(int x,int y){
  int r;
  r = gcd(abs(x),abs(y));
  if (y == 0) 
  {
    cout << "denominator equal zero";
    t = 0;
  } 
  else if (y < 0) {
    a = -x / r;
    b = abs(y / r);
    t = 1;
  }
   else
  {
    a = x / r;
    b = y / r;
    t = 1;
   }
}
rationalNumber rationalNumber::operator+(const rationalNumber &c) {
  int r, s;
  r = lcs(b, c.b);
  s = a * r / b + c.a * r / c.b;
  //cout << s << " " << r << endl;
  return rationalNumber(s, r);
}
void print(rationalNumber x,rationalNumber y,rationalNumber z){
	if(x.t&&y.t&&z.t){
		
		
	  if(y.a>0){
             if (z.a % z.b == 0) 
             {
          	cout << x.a << "/" << x.b << "+" << y.a << "/" << y.b << "=";
                cout << z.a / z.b << endl;
              }
              else if (z.a== 0) 
              {
          	cout << x.a << "/" << x.b << "+" << y.a << "/" << y.b << "=";
                cout << z.a / z.b << endl;
              } 
              else 
              {
                cout << x.a << "/" << x.b << "+" << y.a << "/" << y.b << "=";
                cout << z.a << "/" << z.b << endl;
               }
          }
          else {
             if (z.a % z.b == 0) 
             {
                cout << x.a << "/" << x.b << y.a << "/" << y.b << "=";
                cout << z.a / z.b << endl;
              }
              else if (z.a== 0) 
              {
                cout << x.a << "/" << x.b << y.a << "/" << y.b << "=";
                cout << z.a<< endl;
              } 
              else 
              {
                cout << x.a << "/" << x.b << y.a << "/" << y.b << "=";
                cout << z.a << "/" << z.b << endl;
              }
           }
        }        
}
int rationalNumber::gcd(int n,int m){
          int r;
        	if(n==m)
                  return n;
                  else{
                    while ((r = n % m) != 0) {
                      n = m;
                      m = r;
                    }
                    return m;
                  }
}
int rationalNumber::lcs(int n, int m) {
          if (n == m)
            return n;
          else
            return n*m / gcd(n, m);
        }
    