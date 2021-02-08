#include <iostream>
using namespace std;
class Toy {
public:
  Toy();
  Toy(int x, int y);
  void Get_information(int x,int y);
  void Show();

private:
  int Price, Count;
  long Total;
};
int main() {
  Toy *op;
  op = new Toy[6];
  op[0].Get_information(25, 130);
  op[1].Get_information(30, 35);
  op[2].Get_information(15, 20);
  op[3].Get_information(25, 120);
  op[4].Get_information(45, 10);
  op[5].Get_information(85, 65);
  for (int i = 0; i < 6; i++)
    op[i].Show();
  return 0;
}
Toy::Toy() {}
Toy::Toy(int x, int y) {
  Price = x;
  Count = y;
}
void Toy::Get_information(int x, int y) {
  Price = x;
  Count = y;
}
void Toy::Show() {
  //Total = Price * Count;
  cout << "Price=" << Price << "\tCount=" << Count
       << "\tTotal=" << Price*Count << endl;
}