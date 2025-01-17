#include <iostream>
#include <set>
#include <cmath>
using namespace std;
class number{
public:
    number(long y);
    int judge(long x);
    void show();
private:
    long n;
};
int main(){
    long n;
    while(cin>>n)
        number d1(n);
    return 0;
}
number::number(long y){
    n=y;
    show();
}
int number::judge(long x){
    int t=0,i;
    if(x==2)
        t=1;
    for(i=2;i<sqrt(x);i++)
        if(x%i==0)
            break;
    if(x%i!=0)
        t=1;
    return t;
}
void number::show(){
    set<long> x;
    set<long>::iterator p,q;
    long j=2;
    int s=0;
    do {
      if (judge(j))
        x.insert(j);
    } while (++j < n);
    for (p = x.begin(); p != x.end(); p++) {
      for (q =p; q != x.end(); q++)
        if ((*q) + (*p) == n)
          s++;
    }
    cout << s << endl;
}
/*
描述


      哥德巴赫（Goldbach ]C.，1690.3.18~1764.11.20）是德国数学家；出生于格奥尼格斯别尔格（现名加里宁城）；曾在英国牛津大学学习；原学法学，由于在欧洲各国访问期间结识了贝努利家族,所以对数学研究产生了兴趣；曾担任中学教师。1725年，到了俄国，同年被选为彼得堡科学院院士；1725年~1740年担任彼得堡科学院会议秘书；1742年，移居莫斯科，并在俄国外交部任职。
     1742年，哥德巴赫在教学中发现，每个不小于6的偶数都是两个素数（只能被1和它本身整除的数）之和。如6＝3＋3，14＝3＋11等等。公元1742年6月7日哥德巴赫写信给当时的大数学家欧拉，欧拉在6月30日给他的回信中说，他相信这个猜想是正确的，但他不能证明。叙述如此简单的问题，连欧拉这样首屈一指的数学家都不能证明，这个猜想便引起了许多数学家的注意。从哥德巴赫提出这个猜想至今，许多数学家都不断努力想攻克它，但都没有成功。
      我们不需要你去证明哥德巴赫猜想。
      如果哥德巴赫猜想是正确的，一个（不小于6的）偶数，都是两个素数之和。那么这个偶数能被至少一个素数对表示，如14，即可以表示为14＝3＋11，也可以表示为14=7+7。不同的偶数对应的素数对的数目是不一样的，如偶数6，就只能表示为6=3+3。对于每个给定的偶数，我们希望知道有多少素数对的和等于该偶数。

输入


有多组测试数据。每组测试数据占一行，包含唯一的一个正偶数n.(6 <= n <= 2^24,)。

输出


对于每个输入的偶数，输出一行包含唯一的一个整数：表示有多少个素数对的和是输入的偶数。
样例输入

6
14

样例输出

1
2
*/