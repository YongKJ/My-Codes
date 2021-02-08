#include <iostream>
using namespace std;
class Fibo {
public:
  void calculate_data();
  void show_result();

private:
  int *p = new int[20];
};
int main() {
  Fibo d1;
  d1.calculate_data();
  d1.show_result();
  return 0;
}
void Fibo::calculate_data() {
  *p = 1;
  *(p+1) = 1;
  for (int i = 2; i < 20; i++)
    p[i] = p[i - 1] + p[i - 2];
}
void Fibo::show_result(){
  for (int i = 0; i < 20; i++) {
    cout << p[i] << "\t";
    if ((i+1) % 5 == 0)
      cout << endl;
  }
  delete[] p;
}
          