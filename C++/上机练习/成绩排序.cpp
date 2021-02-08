#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct Student {
  int Number, Chinese, Math, English,Total;
} d2;
bool compare(const Student &x, const Student &y) {
  if (x.Total < y.Total)
    return 1;
  else if (x.Total == y.Total)
   {
    if( x.Chinese < y.Chinese)
    return 1;
    else if (x.Chinese == y.Chinese)
    { 
    if(x.Math < y.Math)
    return 1;
    else if (x.Math == y.Math)
    {
      if (x.English < y.English)
        return 1;
      else return 0;
    } 
    else return 0;
    }
    else return 0;
  } 
  else return 0;
}
int main(){
  vector<Student> p;
  Student d1;
  int n,t;
  cin >> n;
  t = n;
  while (n-- &&cin >> d1.Number >> d1.Chinese >> d1.Math >> d1.English)
    d1.Total = d1.Chinese + d1.Math + d1.English, p.push_back(d1);
  sort(p.begin(), p.end(), compare);
  for (int i = 0; i < t; i++)
    cout << p[i].Number <<" "<<p[i].Total<< " " << p[i].Chinese << " " << p[i].Math << " "
         << p[i].English << endl;
  return 0;
}
  	