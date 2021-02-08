#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct program{
      int start;
      int en;
}a[100];
int cmp(program a,program b)        //对节目结束的时间从小到大排序，若相同，则开始时间越迟，看的节目越多
{
    if(a.en==b.en)
    {
        return a.start>b.start;
    }
    else
        return a.en<b.en;
}
int main()
{
    int i,t,n,k;
    while(cin>>n)
    {
      for (i = 0; i < n; i++) 
        cin >> a[i].start >> a[i].en;
        sort(a,a+n,cmp);           //根据节目结束的时间进行升序排序
        if(n==0) break;
        for (int i=0;i<n;i++)
          cout << a[i].start << " " << a[i].en<<endl;
        k=1;
        t=a[0].en;                 //把第一个节目的结束时间赋值给t
        for(i=0;i<n;i++)
        {
          if (a[i].start >= t) {
            cout << a[i].start << " " << a[i].en << endl;
            t = a[i].en; //如果后面节目被选中，则将该节目结束的时间赋值给t
            k++;
          }
        }
        cout << k << endl;
    }
    return 0;
}
/*
12
1 3
3 4
0 7
3 8
15 19
15 20
10 15
8 18
6 12
5 10
4 14
2 9
0
*/