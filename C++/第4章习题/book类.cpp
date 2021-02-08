#include <iostream>
using namespace std;
class book {
public:
  book();
  book(float x, float y);
  void Set_book(float x);
  void Show();

private:
  float qu, price;
};
int main(){
  book d1[5];
  for (int i = 0, j = 1; i < 5; i++,j++) {
    d1[i].Set_book(j);
    d1[i].Show();
  }
  book d2[5] = {book(1, 10), book(2, 20), book(3, 30), book(4, 40),
                book(5, 50)};
  cout << endl << endl;
  for (int i = 0; i < 5;i++)
    d2[i].Show();
  return 0;
}
book::book() {}
book::book(float x, float y) {
  qu = x;
  price = y;
}
void book::Set_book(float x) {
  qu = x;
  price = 10 * x;
}
void book::Show() { cout << qu * price << endl; }