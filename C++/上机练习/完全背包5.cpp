#include<iostream>
#include<string>
using namespace std;
int main()
{
 int test,m,v,i,j;
 cin >> test;
 while (test--&&cin >> m >> v) {
   int c, w, f[v + 1];
   memset(f, -10, sizeof(f)), f[0] = 0;
   for (i = 0; i < m; i++) {
     cin >> c >> w;
     for (j = c; j <= v; j++)
       f[j] = max(f[j], f[j - c] + w);
   }
   if (f[v] < 0)
     cout << "NO" << endl;
   else
     cout << f[v] << endl;
 }
 return 0;
}