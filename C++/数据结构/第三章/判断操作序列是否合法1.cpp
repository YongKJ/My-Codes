#include <iostream>
using namespace std;
int judge(char a[]) {
  int j = 0, k = 0, t = 0;
  for (int i=0;a[i]!='\0';i++)
  switch(a[i]){
  case 'I':
    j++;
    break;
    case 'O':
      k++;
      if (j < k) {
        cout << "序列非法" << endl;
        return 0;
      }
    }
  if (j != k) 
    cout << "序列非法" << endl;
   else
     cout << "序列合法" << endl, t = 1;
   return t;
}
int main() {
  char a[10];
  while (cin >> a)
    judge(a);
  return 0;
}
/*
输入:
IOIIOIOO
IOOIOIIO
IIIOIOIO
IIIOOIOO

输出:
Yes
No
No
Yes
*/