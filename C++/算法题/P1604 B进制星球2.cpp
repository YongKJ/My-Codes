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