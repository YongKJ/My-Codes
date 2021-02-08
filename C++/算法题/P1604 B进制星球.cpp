#include <iostream>
#include <cstring>
using namespace std;
int x, y, z, l1, l2;
int a[2010], b[2010], c[2010];
char n[2001], m[2001];
int main(){ 
  cin >> z >> n >> m;
  l1 = strlen(n), l2 = strlen(m);
  for (int i = 0; i < l1; i++) {
    if (z > 10 && n[i] >= 'A')
      a[l1 - i] = n[i] - 'A' + 10;
    else
      a[l1 - i] = n[i] - '0';
  }
  for (int i = 0; i < l2; i++) {
    if (z > 10 && m[i] >= 'A')
      b[l2 - i] = m[i] - 'A' + 10;
    else
      b[l2 - i] = m[i] - '0';
  }
  while (x <= l1 || x <= l2) {
    x++;
    c[x] = a[x] + b[x] + y;
    y = c[x] / z;
    c[x] %= z;
  }
  while (c[x] == 0 && x > 1)
    x--;
  for (int i = x; i >= 1; i--) {
    if (c[i] < 10)
      cout << c[i];
    else
      cout << char(c[i] + 'A' - 10);
  }
  cout << endl;
  return 0;
}
  
/*
#include<iostream>
#include<cstring>
using namespace std;
int a[2010],b[2010],c[2018],i,y,x,l1,l2,z;
char n[2001],m[2001];
int main(){
    cin>>z;
    cin>>n; cin>>m;
    l1=strlen(n); l2=strlen(m);
    for (i=0; i<l1; i++)
      if (z>10&&n[i]>='A') a[l1-i]=n[i]-'A'+10;//字符串逆序存储
      else a[l1-i]=n[i]-'0';//遇到字母转换成数字
    for (i=0; i<l2; i++)
      if (z>10&&m[i]>='A') b[l2-i]=m[i]-'A'+10;//同上
      else b[l2-i]=m[i]-'0';
    while (x<=l1||x<=l2){//高精加
        x++;//x是位数指针
        c[x]=y+a[x]+b[x]; //y是进位
        y=c[x]/z; c[x]%=z;//在z禁止下逢z进1
    }
    while (c[x]==0&&x>1) x--; //去除前导零
    for (i=x; i>=1; i--){
        if (c[i]<10) cout<<c[i];
        else cout<<(char)(c[i]+'A'-10);//z>10是要输出大写字母，类型要转换成char,否则会输出ASCII码
    }
    return 0;
}```


题目背景
进制题目，而且还是个计算器~~

题目描述
话说有一天，小Z乘坐宇宙飞船，飞到一个美丽的星球。
因为历史的原因，科技在这个美丽的星球上并不很发达，
星球上人们普遍采用B（2<=B<=36）进制计数。星球上的
人们用美味的食物招待了小Z，作为回报，小Z希望送一个
能够完成B进制加法的计算器给他们。 现在小Z希望你可以
帮助他，编写实现B进制加法的程序。

输入输出格式
输入格式：
共3行第1行：一个十进制的整数,表示进制B。第2-3行：
每行一个B进制数正整数。数字的每一位属于{0，1，2，3，
4，5，6，7，8，9，A，B……}，每个数字长度<=2000位。

输出格式：
一个B进制数，表示输入的两个数的和。

输入输出样例
输入样例#1： 
4
123
321
输出样例#1： 
1110
说明
进制计算器
*/