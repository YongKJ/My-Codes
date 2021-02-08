#include<iostream>
 #include<iomanip>
 using namespace std;
 class Yuan
 {
 private:
     double r;
 public:
     double mj(double x);
     double zc(double x);

 };
 double Yuan::zc(double x)
 {
     
     cout<<setiosflags(ios::fixed)<<setprecision(2)<<6.28*x<<" ";
     return 0;
 }
 double Yuan:: mj(double x)
 {
     
     cout<<setiosflags(ios::fixed)<<setprecision(2)<<3.14*x*x<<endl;
     return 0;
 }
 int main()
 {
     int i;
     double r,y;
     Yuan z;
     cin>>y;
     for (i = 0; i < y; i++) {
       cin >> r;
       z.zc(r);
       z.mj(r);
     }
 }