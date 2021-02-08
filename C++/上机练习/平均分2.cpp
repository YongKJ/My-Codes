#include <iostream>
#include<iomanip>
using namespace std;
class E
{
  static int c;
  static double s;
  char *n;
  double i;

public:
void in(char *a,double _i)
{
   n=a;
  i=_i;
  c++;
  s+=i;
}
static void av()
{
   double av=0;
   av=s/c;
   cout<<fixed<<setprecision(2)<<av<<endl;
}

}; 
  double E::s=0;int E::c=0;
int main()
{
   char c[20];double n;
   while (cin >> c >> n) {
     E a1;
     a1.in(c, n);
   }

   E::av();
   return 0;
}