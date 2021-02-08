#include <iostream>
using namespace std;
int sum=0;
void dfs(int s,int store,int flower,int p){
	if(!store&&!flower){
		if(!s&&!p)sum++;
		return;
	}
	if(store>0)dfs(s*2,store-1,flower,1);
	if(s>0&&flower>0)dfs(s-1,store,flower-1,0);
}
int main(){
	dfs(2,5,10,-1),cout<<sum<<endl;
} 
/*
话说大诗人李白，一生好饮。幸好他从不开车。
一天，他提着酒壶，从家里出来，酒壶中有酒2斗。他边走边唱：
    无事街上走，提壶去打酒。
    逢店加一倍，遇花喝一斗。
这一路上，他一共遇到店5次，遇到花10次，已知最后一次遇到的是花，他正好把酒喝光了。
请你计算李白遇到店和花的次序，可以把遇店记为a，遇花记为b。则：babaabbabbabbbb 就是合理的次序。
像这样的答案一共有多少呢？请你计算出所有可能方案的个数（包含题目给出的）。
 
 pre 为-1，表示是第一次；为0表示上一次是遇花，为1表示遇店
 
 没酒的时候 alco是0，遇到店，乘以2还是0.当结果符合要求时，按理说是合理的。就我的代码而言，是可以没酒遇到店的
 
 传递参数有：当前酒的斗数alco 遇店的次数store 遇花的次数flower 上一次是遇店还是遇花pre alco、store、flower
 都保证了大于等于0 pre 为-1，表示是第一次；为0表示上一次是遇花，为1表示遇店
 

*/
