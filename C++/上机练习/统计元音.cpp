#include <iostream>
#include <map>
#include <cstring>
using namespace std;
int main(){
  int n;
  char a[110],m;
  map<char, int> x;
  map<char, int>::iterator p;
  cin >> n;
  while(n--){
    m = 'a', x[m] = 0, m = 'e', x[m] = 0, m = 'i', x[m] = 0, m = 'o', x[m] = 0,
    m = 'u', x[m] = 0;
    while (cin >> a){
      for (int i = 0; i < strlen(a); i++)
        if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' ||
            a[i] == 'u')
            x[a[i]]++;
       if(getchar()=='\n')
         break;
    }
    for (p = x.begin(); p !=x.end(); p++)
      cout << p->first << ":" << p->second << endl;
     if(n)
       cout << endl;
    x.clear();
  }
  return 0;
}
    	
/*
Sample Input
2
aeiou
my name is ignatius
 

Sample Output
a:1
e:1
i:1
o:1
u:1

a:2
e:1
i:3
o:0
u:1
*/