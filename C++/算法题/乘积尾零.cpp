#include <iostream>
#include <cstdio>
using namespace std;
int main(){
  int num1=0, num2=0, n,sum=0;
  do{
    cin >> n;
    sum++;
    while (n % 2==0 || n % 5==0) {
      if (n % 2==0)
        num1++, n /= 2;
      else
        num2++, n /= 5;
    }
    //cout << num1 << " " << num2 << endl;
  } while (sum!=100);
  cout << (num1 > num2 ? num2 : num1) << endl;
  return 0;
}
/*
如下的10行数据，每行有10个整数，请你求出它们的乘积的
末尾有多少个零？

5650 4542 3554 473 946 4114 3871 9073 90 4329
2758 7949 6113 5659 5245 7432 3051 4434 6704 3594
9937 1173 6866 3397 4759 7557 3070 2287 1453 9899
1486 5722 3135 1170 4014 5510 5120 729 2880 9019
2049 698 4582 4346 4427 646 9742 7340 1230 7683
5693 7015 6887 7381 4172 4341 2909 2027 7355 5649
6701 6645 1671 5978 2704 9926 295 3125 3878 6785
2066 4247 4800 1578 6652 4616 1113 6205 3264 2915
3966 5291 2904 1285 2193 1428 2265 8730 9436 7074
689 5510 8243 6114 337 4096 8199 7313 3685 211

注意：需要提交的是一个整数，表示末尾零的个数。不要填写任何多
余内容。
*/