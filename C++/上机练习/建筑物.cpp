#include <iostream>
using namespace std;
class Building {
public:
  int floors, rooms;
  double areas;
  Building(int x, int y, double z);
  void show();
};
class Housing : public Building {
public:
  Housing(int x, int y, double z, int n, int m);
  void display();

private:
  int bedrooms, bathrooms;
};
class Office : public Building {
public:
  Office(int x, int y, double z, int n, int m);
  void display();

private:
  int fires, telephones;
};
int main() {
  int x, y, n, m,t;
  double z;
  cin >> t;
  while (t--) {
    cin >> x >> y >> z >> n >> m;
    Housing d1(x, y, z, n, m);
    d1.display();
    cin >> x >> y >> z >> n >> m;
    Office d2(x, y, z, n, m);
    d2.display();
  }
  return 0;
}
Building::Building(int x, int y, double z) {
  floors = x;
  rooms = y;
  areas = z;
}
void Building::show() {
  cout << "Floors:" << floors << endl;
  cout << "Rooms:" << rooms << endl;
  cout << "Total area:" << areas << endl;
}
Housing::Housing(int x, int y, double z, int n, int m) : Building(x, y, z) {
  bedrooms = n;
  bathrooms = m;
}
void Housing::display() {
  cout << "HOUSING:" << endl;
  Building::show();
  cout << "Bedrooms:" << bedrooms << endl;
  cout << "Bathrooms:" << bathrooms << endl;
}
Office::Office(int x, int y, double z, int n, int m) : Building(x, y, z) {
  fires = n;
  telephones = m;
}
void Office::display() {
  cout << "OFFICING:" << endl;
  Building::show();
  cout << "Extinguishers:" << fires << endl;
  cout << "Phones:" << telephones << endl;
}