#include <iostream>
#include <string>
using namespace std;
class Land{
	public:
          void Get_data();
          int Check(int n,int strNum[],string str[]);
          void Show(int x,int index);
	private:
          static int n, num, **strNum;
          static string str[];
          void Get_str();
          void Get_strNum();
};
int main() {
  Land d1;
  int n,y;
  cin >> n;
  for (int i = 0; i < n;i++)
    d1.Get_data();
  y = d1.Check();
  d1.Show(y, i);
  }
  return 0;
}
