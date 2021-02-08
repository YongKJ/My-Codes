#include <iostream>
using namespace std;
class A {
public:
  A(int a);
  ~A();
 virtual void display();
    int x;
};
class B:virtual public A {
public:
  B(int a,int b);
  ~B();
  void display();
    int y;
};
class C:virtual public A {
public:
  C(int a, int c);
  ~C();
  void display();
    int z;
};
class D : public B, public C {
public:
  D(int a, int b, int c, int d);
  ~D();
  void display();
    int j;
};
int main() {
  A d1(1), *p;
  cout << endl;
  B d2(2, 3);
  cout << endl;
  C d3(4, 5);
  cout << endl;
  D d4(6,7,8,9);
  cout << endl;
  p = &d1;
  p->display();
  cout << endl;
  p = &d2;
  p->display();
  cout << endl;
  p = &d3;
  p->display();
  cout << endl;
  p = &d4;
  p->display();
  cout << endl;
  return 0;
}
A::A(int a) {
  x = a;
  cout << "构造函数初始化A" << endl;
}
A::~A() { cout << "析构函数释放A" << endl<<endl; }
void A::display() { cout << "a=" << x << endl; }
B::B(int a, int b) : A(a) {
  y = b;
  cout << "构造函数初始化B" << endl;
}
B::~B() { cout << "析构函数释放B" << endl; }
void B::display() {
  cout << "a=" << x << " "
       << "b=" << y << endl;
}
C::C(int a, int c) : A(a) {
  z = c;
  cout << "构造函数初始化C" << endl;
}
C::~C() { cout << "析构函数释放C" << endl; }
void C::display() {
  cout << "a=" << x << " "
       << "c=" << z << endl;
}
D::D(int a, int b, int c, int d) : A(a), C(a, c), B(a, b) {
  j = d;
  cout << "构造函数初始化D" << endl;
}
D::~D() { cout << "析构函数释放D" << endl; }
void D::display() {
  cout << "a=" << x << " "
       << "b=" << y << " "
       << "c=" << z << " "
       << "d=" << j << endl;
}