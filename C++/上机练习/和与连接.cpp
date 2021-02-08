#include<iostream>
#include <cstring>
using namespace std;
int add(int a, int b) { return a + b; }
double add(double a, double b) { return a + b; }
char *add(char *a, char *b) {
  static char x[201];
  int i, j;
  for (i = 0; i < strlen(a); i++)
    x[i] = a[i];
  for (j = 0; j < strlen(b); j++)
    x[i + j] = b[j];
  x[i + j] = '\0';
  return x;
}
int main() {
  int a, b;
  double c, d;
  char e[100], f[100];
  cin >> a >> b >> c >> d >> e >> f;
  cout << add(a, b) << endl;
  cout << add(c, d) << endl;
  //cin >> e >> f;
  cout << add(e, f) << endl;
  return 0;
}