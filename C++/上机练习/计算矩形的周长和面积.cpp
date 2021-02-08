#include <iostream>
using namespace std;
class rectangle
{
    public:
      rectangle(int x, int y);
      rectangle(const rectangle &N);
      void area();
      void cir();
  
    private:
        int a,b;
};
int main(){
    
    int t,x,y;
    cin>>t;
    while(t--){
        cin>>x>>y;
        rectangle d1(x, y);
        d1.area();
        rectangle d2 = d1;
        d2.cir();
    }
    return 0;
}
rectangle::rectangle(int x, int y) {
  a = x;
  b = y;
}
rectangle::rectangle(const rectangle &N) {
  a = N.a;
  b = N.b;
}
void rectangle::area(){
  cout << a * b << " ";
}
void rectangle::cir() {
  cout << 2*(a+b)<< endl;
}