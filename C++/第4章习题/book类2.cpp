#include <iostream>
using namespace std;
class book {
public:
  book(float x, float y);
  void Show_book();

private:
  float qu, price;
};
int main(){
  book *p,
      d1[5] = {book(1, 10), book(2, 20), book(3, 30), book(4, 40), book(5, 50)};
  p = &d1[4];
  for (int i = 0; i < 5; i++, p--)
    p->Show_book();
  return 0;
}
book::book(float x, float y) {
  qu = x;
  price = y;
}
void book::Show_book() { cout << qu * price << endl; }

  