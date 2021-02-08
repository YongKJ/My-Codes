#include <iostream>
using namespace std;
int main(){
  int n,s;
  while(s=0,cin>>n){
  	if(n<4)
          cout << n<<endl;
        else {
          for (int i = 0; i <= n / 3; i++)
            for (int j = 0; j <= n / 2; j++)
              if (n - i * 3 - j * 2 >= 0)
                s++;
          cout << s << endl;
        }
  }
  return 0;
}
           
              
/*
样例输入

1
2
3
6
10

样例输出

1
2
3
7
14
*/