#include <iostream>

using namespace std; 



int main()

{

int n;

cout << "please input num "<<endl;

cin >> n;

if(n<2&&n>9){

cout << "exit";

exit(0);

}
int * nums =new int[n];

for(int i = 1; i <= n; i++){

nums[i-1]=i;

}
for(int t = 0; t < n; t++){

for(int i = t; i < (n+t); i++){

  if (i >= n) {

    cout << nums[i % n] << " ";
  }

  else

    cout << nums[i] << " ";
}

cout << endl;
}

return 0;
}
/*
描述

      构造 N*N 阶的拉丁方阵(2<=N<=9)，使方阵中的每一行和
      每一列中数字1到N只出现一次。如N=3时： 1 2 3  2 3 1 3  1 2

输入

n。

输出

输出对应的拉丁矩阵，每两个数字之间间隔一个空格，每输出
n个数后换行。

样例输入

3

样例输出

1 2 3
2 3 1
3 1 2

提示

注意：每个数字后面有一个空格。
*/