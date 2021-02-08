#include <iostream>
#include <algorithm>
using namespace std;
int a[10000001];
int main(){
  int n, d, max = 1;
  long long ans = 1;
  cin >> n >> d;
  for (int i=1;i<=n;i++)
    cin >> a[i];
  sort(a + 1, a + 1 + n);
  for (int i = 2; i <= n; i++) {
    while ((a[i] - d) > a[max] && max < i)
      max++;
    ans *= i - max + 1;
    ans %= 1000000009;
  }
  cout << ans << endl;
  return 0;
}
/*

int a[10000001]={0};//数组开大一点，以防访问无效内存。
int main()
{
    ios::sync_with_stdio(false);//关闭同步！否则最后一个点超时！
    int n,d,max=1;//max代表砖上能放的最大砖
    long long ans=1;
    cin>>n>>d;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);//使用STL排序
    for (int i=2;i<=n;i++)
    {
        while( (a[i]-d) > a[max] && max<i)//寻找能放在砖上的最大砖块
        {
               max++;
         }
        ans*=i-max+1;//乘法原理
        ans%=1000000009;//模运算，需要注意编写程序要尽量减少模运算，可以继续优化，请读者自行思考。
    }
    cout<<ans<<endl;//输出答案
}

题目描述
有N(2<=N<=600000)块砖，要搭一个N层的塔，
要求：如果砖A在砖B上面，那么A不能比B的长度+D要长。
问有几种方法,输出 答案 mod 1000000009的值.

输入输出格式
输入格式：
第一行： N，D 第二行： N个数，表示每块砖的长度。

输出格式：
方案数，输出要mod 1000000009

输入输出样例
输入样例#1： 
4 1
1 2 3 100
输出样例#1： 
4
*/