#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int main(){
  int n;
  char str[10000];
  cin >> n;
  getchar();
  while (n--) {
    int sum = 0;
    cin.getline(str, 10000);
    for (int i = 0; str[i]!= '\0'; i++)
      if (str[i] < 0||str[i]>126)
        sum++,i++;
    cout << sum << endl;
  }
  return 0;
}
/*
Sample Input
2
WaHaHa! WaHaHa! 今年过节不说话要说只说普通话WaHaHa! WaHaHa!
马上就要期末考试了Are you ready?
 

Sample Output
14
9
*/
    