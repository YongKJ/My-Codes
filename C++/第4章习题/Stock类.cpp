#include <iostream>
using namespace std;
const int SIZE = 80;
class Stock {
public:
  Stock();
  Stock(char na[], int q = 1000, double p = 8.98);
  void print();

private:
  char stockcode[SIZE];
  int quantity;
  double price;
};
int main() {
  char p[] = "600001";
  Stock d1(p, 3000, 8.98);
  d1.print();
  Stock d2;
  char d3[] = "600002";
  d2 = d3;
  d2.print();
  return 0;
}
Stock::Stock() { strcpy(stockcode, "     "); }
Stock::Stock(char na[], int q, double p) {
  strcpy(stockcode, na);
  quantity = q;
  price = p;
}
void Stock::print() {
  cout << this->stockcode;
  cout << "    " << this->quantity << "    " << this->price << endl;
}
	