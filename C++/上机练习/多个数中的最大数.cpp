#include <iostream>
using namespace std;
template <class T> class Max{
public:
  T max(int n,T a[]);

private:
  T t;
};
int main(){
  int n, p1[20];
  double p2[20];
  cin >> n;
    for (int i; i < n; i++)
      cin >> p1[i];
    Max<int> d1;
    cout << d1.max(n,p1) << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> p2[i];
    Max<double>d2;
    cout<< d2.max(n,p2) << endl;
  return 0;
}
template <class T>
T Max<T>::max(int n,T a[]){
  t = a[0];
  for (int i = 0; i < n; i++) 
    if (a[i] > t)
      t = a[i];
  return t;
}