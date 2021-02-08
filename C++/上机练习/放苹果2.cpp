#include<iostream>
using namespace std;
int count(int m,int n)
{
   if(n==1 || m==0)  return 1;
   if(m<n) return count(m,m);
   else return count(m,n-1)+count(m-n,n);
}
int main()
{
 int i;
 cin>>i;
 for (; i > 0; i--) {
   int a, b;
   cin >> a >> b;
   cout << count(a, b) << endl;
 }
 return 0;
}
