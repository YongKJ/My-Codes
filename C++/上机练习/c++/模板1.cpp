#include<iostream>
using namespace std;
class Point
{ 

public:int x,y;
   Point(int a,int b)
   { 
      x=a;
      y=b;
    }
};
class Re:public Point
{ 
    int x1,y1;
public:
    Re(int c,int d,int e,int f):Point(c,d)
    {
      x1=e;
      y1=f;
      x=x+x1;
      y=y+y1;
    }
void disp()
  {
      cout<<x<<" "<<y<<endl;
  }
};
int main()
{ 
  int a,b,c,d;
  while(cin>>a>>b>>c>>d)
   {
      Re r(a,b,c,d);
      r.disp();
   }
  return 0;
  }