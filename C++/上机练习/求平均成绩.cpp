#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
  int n, m, sum,t,i,j;
  double Students[100][100],Score1[100] = {0}, Score2[100] = {0};
    while (cin>>n>>m)
  {
    for(i=0;i<n;i++)
    for(j=0;j<m;j++)
    {
        cin>>Students[i][j];
        Score1[i]+=Students[i][j];
        Score2[j]+=Students[j][i];
    }
    for(i=0;i<n-1;i++)
    {
    Score1[i]/=m;
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<Score1[i]<<" ";
    }
    Score1[n-1]/=m;
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<Score1[n-1]<<endl;
    for(i=0;i<m-1;i++)
    {
    Score2[i]/=n;
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<Score2[i]<<" ";
    }
    Score2[m-1]/=n;
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<Score1[m-1]<<endl;
    sum=t=0;
    for (i = 0; i < n; i++) 
    {
      for (j = 0; j < m; j++) {
        if (Students[i][j] > Score2[j])
          sum++;
      }
      if (sum == m)
        t++;
    }
    cout << t << endl << endl;
  }
    return 0;
}