#include <iostream>
using namespace std;
const int N = 5;
class Stock {
public:
  Stock();
  Stock(int a, float b, float x, float y, float z);
  void Set_Stock();
  void Set_Stock(int a, float b, float x, float y, float z);
  float Get_End();
  void Show_Stock();
  int Get_N_count();
  void Assign_Stock(Stock &p);
  friend int Get_Stock(Stock *p);

private:
  int Number;
  float Max, Min, Begin, End;
  static int N_count;
};
int main() {
  int i;
  Stock d1[100], *p,s1(4,7.88,7.48,7.56,7.68),s2;
  for (i = 0, p = d1; i < N; i++, p++) {
    p->Set_Stock();
    p->Show_Stock();
    if(i>=1)
      cout << (p->Get_End() - (p - 1)->Get_End()) / (p - 1)->Get_End() * 100
           << " %" << endl;
    cout << Get_Stock(p) << endl;
  }    
  cout << p->Get_N_count() << endl;
  s2.Assign_Stock(s1);
  s2.Show_Stock();    
  return 0;
}
Stock::Stock() {}
Stock::Stock(int a, float b, float x, float y, float z) {
  N_count++;
  Number = a;
  Max = b;
  Min = x;
  Begin = y;
  End = z;
}
void Stock::Set_Stock() {
  N_count++;
  cin >> Number >> Max >> Min >> Begin >> End;
}
void Stock::Set_Stock(int a, float b, float x, float y, float z) {
  N_count++;
  Number = a;
  Max = b;
  Min = x;
  Begin = y;
  End = z;
}
float Stock::Get_End() { return End; }
void Stock::Show_Stock() {
  cout << Number << "\t" << Max << "\t" << Min << "\t" << Begin << "\t" << End
       << endl;
}
int Stock::Get_N_count() { return N_count; }
void Stock::Assign_Stock(Stock &p){
  if (this != &p) {
    N_count++;
    Number = p.Number;
    Max = p.Max;
    Min = p.Min;
    Begin = p.Begin;
    End = p.End;
  }
}
int Get_Stock(Stock *p) {
  cout << p->Begin << "\t" << p->End << endl;
  if ((p->Begin) > (p->End))
    return 1;
  else
    return 0;
}