//1.写一个电阻误差函数
#include <iostream>
#include <sstream>
#include <string>
#include <ctype.h>
using std::cout;
using std::cin;
using std::string;
using std::endl;
std ::stringstream ss;//整数数组转换整数关键字
long long dz[4];
string dw1; //储存电阻阻值
//电阻类
class dianzu {
	private:
          string c1[4];
		 int i2[6];
        int g;
    int b2 = 0;
    string str2, str3[3] = {"四色环", "五色环", "六色环"}; //初始化str3数组
  public:
    char jiyi[6];
    string dwhs(long long l){
      long long num = l;
      string dw;//储存电阻单位
    	 int count = 0; //计数器
         while (num != 0) //当不是0就循环
         {
           count++;        //计数器加1
           num = num / 10; //去掉个位赋值给自己
         }
         if (count>= 3)
           dw = "千欧";
         if (num >= 7)
           dw = "兆欧";
         /*else
           dw = "欧";*/
         return dw;
    }
    long long bs(string s1/*int i*/) {
      long long temp;
      /*for (int i1 = 0; i1 < i; i1++) {
        temp = 1 * i;
      }*/
      if (s1 == "黑")
        temp = 1;
      if (s1 == "棕")
        temp = 10;
      if (s1 == "红")
        temp = 100;
      if (s1 == "橙")
        temp = 1000;
      if (s1 == "黄")
        temp = 10000;
      if (s1 == "绿")
        temp = 100000;
      if (s1 == "蓝")
        temp = 1000000;
      if (s1 == "紫")
        temp = 10000000;
      if (s1 == "灰")
        temp = 100000000;
      if (s1 == "白")
        temp = 1000000000;
      return temp;
    }
 //判断颜色并转换成对应的阻值函数
 int zh(string s) {
   int a = 0;
   long d = 0;
    while (a < 1) {
      if (s == "黑")
        jiyi[a] = '0';//把判断对应的数组赋值给字符数组
      if (s == "棕")
        jiyi[a] = '1';
      if (s == "红")
        jiyi[a] = '2';
      if (s == "橙")
        jiyi[a] = '3';
      if (s == "黄")
        jiyi[a] = '4';
      if (s == "绿")
        jiyi[a] = '5';
      if (s == "蓝")
        jiyi[a] = '6';
      if (s == "紫")
        jiyi[a] = '7';
      if (s == "灰")
        jiyi[a] = '8';
      if (s == "白")
        jiyi[a] = '9';
      a++;
    }
    d = atoi(jiyi);//把字符数组转换成整数类型然后赋值给d变量名
    //cout << d;
   /* for(unsigned i = 0;
    i < sizeof jiyi / sizeof jiyi[0];
    ++i) ss<<jiyi[i];

    int result;
    ss>>result;
    std ::cout << result; // 603215
    cout <<* jiyi << endl;*///失败
    return d;
  }
  int zz1() {
  	//int b = 1, result = 0;
        int js = 0;
    cout << "输入色环列如" << str3[0] << "," << str3[1] << "," << str3[2] << ":";
    cin >> str2;
    if (str2 == "四色环") {
      js = 2;
      for (int i = 0; i < 4; i++) {
        cout << "输入第" << i << "色环颜色:";
        cin >> c1[i];
      }
      int l = 0;
      for (int i = 0; i < 4; i++) {
        dz[i] = zz2(i);
        if (i == 2) {
          long long temp2;
          string tempstr;
          temp2 = bs(c1[2]);
          tempstr = dwhs(temp2);
          dw1 = tempstr;
        }
      }
      /*for (int i = 6; i >= 0; i--) {
        result += b * a[i];
        b *= 10;
      }*/
    } else {
      cout << "您的输入有误请重新输入" << endl;
    }
    return js;
  }
  int zz2(int i6 = 0) {
    int i7 = 0;
    i7= zh(c1[i6]);
    // cout <<* i2;
    return i7;
  }
};
//主页面类
class Brass:public dianzu {
private:
  int i = 0;
  string str;
public:
  void zym() //主菜单;
  {
  	while (1){
    cout << "1.看颜色计算电阻的阻值" << endl;
    cin >> str;
    if (str == "1") {
      dianzu D1;
      i = D1.zz1();
      for(int i2=0;i2<i;i2++)
        cout << dz[i2];
      cout << dw1;
      cout << endl;
    } else
      cout << "你输入的有误请重新输入" << endl;
        }
  }
};
int main() {
  {
    Brass B1;
    B1.zym();
  }
  return 0;
}