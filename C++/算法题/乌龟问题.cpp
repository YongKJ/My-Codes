﻿#include <iostream>
using namespace std;
int main(){
	int n;
	while(cin>>n){
		long long s[n+1];
		s[1]=1,s[2]=2;
		for(int i=3;i<=n;i++)
		s[i]=s[i-1]+s[i-2];
		cout<<s[n]<<endl;
	}
	return 0;
}
/*
有一天，一只小乌龟爬一个N个台阶的楼梯，它每次可以爬1步或2步。
请编写一个函数来计算，它有多少种不同的方法可以爬到最顶部。
输入
N
输出
多少种不同的方法走到楼梯上
样例输入
30
样例输出
1346269

思路：如果要爬到第i层台阶，因为每次只能爬1层台阶或者2层台阶，
所以说只能是从第i-1层台阶或者第i-2层台阶到达第i层，所以到达
第i层台阶的方法总数就是到达第i-1层的方法总数加上到达第i-2层
的方法总数。这就是为什么爬楼梯问题也是属于动态规划算法的原因，
爬第i层楼梯的方法数只计算一次，然后进行保存，以备直接利用进行计算。
*/
