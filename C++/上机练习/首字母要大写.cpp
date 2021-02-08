#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main(){
  char x[100],y;
  while(scanf("%s",x)!=EOF){
    for (int i=0;i<strlen(x);i++)
    if(i==0)
      printf("%c", x[i] - 32);
     else
       cout << x[i];
  if(getchar()=='\n')
  cout << endl;
  else
    cout << " ";
}
  return 0;
}
    
  
/*
Sample Input
i like acm
i want to get an accepted
 

Sample Output
I Like Acm
I Want To Get An Accepted
*/