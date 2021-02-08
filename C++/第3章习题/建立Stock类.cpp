#include <iostream>
#include <string>
using namespace std;
class Stock {
public:
  Stock();
  Stock(string x, int y = 1000, double z = 8.98);
  void print();

private:
  string stockcode;
  int quantity;
  double price;
};
int main() {
  Stock d1("600001", 3000, 5.67);
  d1.print();
  Stock d2("600002");
  d2.print();
  return 0;
}
Stock::Stock() { stockcode = "  "; }
Stock::Stock(string x, int y, double z) {
  stockcode = x;
  quantity = y;
  price = z;
}
void Stock::print() {
  cout << this->stockcode << " ";
  cout << this->quantity << " " << this->price << endl;
}