#include <cstdio>//简洁的头文件
using namespace std;
bool p[15];//桶，标记是否出现
bool f(int n)//养成写子程序的好习惯，代码就不会很长
{
    while(n)
    {
        if(p[n%10]==0)
            return 0;//不包含--直接跳出
        n/=10;
    }
    return 1;
}
bool check(int x,int y)
{
    int a=x*(y%10),b=x*(y/10),test=x*y;//所谓的“部分乘积”
    if(a>999 || b>999 || test>9999)//节约时间，跳过连位数都不符合的
        return 0;
    if(f(x)==1 && f(y)==1 && f(a)==1 && f(b)==1 && f(test)==1)//根据“开关特性”，只要有一为假就结束判断，因此并不耗时
        return 1;
    else
        return 0;
}
int main()
{
    int n,key,ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&key);
        p[key]=true;//桶的精华，标记一下
    }
    for(int i=100;i<1000;i++)
    {
      for (int j = 10; j < 100; j++) //真正的暴力在这儿！
      {
        if (check(i, j) == 1)
          ans++; //方案数++；
      }
    }
    printf("%d\n", ans); //输出
    return 0;
}
/*
其实这题就是暴力枚举

小学就学的三位数乘两位数，要求“部分乘积”为三位，结果四位

别想复杂了，没有坑！！！
*/