#include <iostream>
using namespace std;
template <class T >
 T max(T a[],int n )
{ 
  int i;
  T max=a[0],t=0; 
      for(i=0;i<n;i++)
    {

        if(a[i]>max)
      {
       t=a[i];
       a[i]=max;
       max=t;
      }
    }
  return max;
}

 int main()
 {
  int i,k,m,a[20];
   double b[20];
  cin>>k;
  for(i=0;i<k;i++)
      cin>>a[i];

  cout<<max<int >(a,k)<<endl;

  cin>>m;
  for(i=0;i<m;i++)
      cin>>b[i];

  cout<<max<double >(b,m)<<endl;

 return 0;

 }
