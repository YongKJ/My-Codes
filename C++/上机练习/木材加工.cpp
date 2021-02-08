#include <iostream>
#include <cstdio>
int d[100001],n,k;
using namespace std;
bool judge (int q){
	if (q==0) return 0;
	int sum=0;
	for (int i=1;i<=n;i++){
		sum=sum+(d[i]/q);
	}
	return (sum>=k);
}
int main(){
	int i,p=0;scanf("%d%d",&n,&k);
	int min=0;
	for (i=1;i<=n;i++) {
		scanf("%d",&d[i]);
		if (d[i]>min) min=d[i];
	}
        //cout << min << endl << endl;
	if (!judge(1)) cout<<'0'<<endl;
	else {
		for (i=min;i>0;i-=100) {
			if (judge(i)) break;
		}
		int u=i;
               // cout << u << endl << endl;
                for (; i <= u + 100; i++) {
                  if (judge(i))
                    p = i;
                }
                printf("%d\n", p);
        }
        return 0;
}
/*

         木材厂有一些原木，现在想把这些原木切
         割成一些长度相同的小段木头（并不是所
         有原木都一定要用完，可以有剩余），需
         要得到的小段的数目是给定的。当然，我
         们希望得到的小段越长越好，你的任务是
         计算能够得到的小段木头的最大长度。木
         头长度的单位是cm。原木的长度都是正整
         数，我们要求切割得到的小段木头的长度也
         是正整数。

输入

      第一行是两个正整数N和K
      (1 ≤ N ≤ 10000，1 ≤ K ≤ 10000)，
      N是原木的数目，K是需要得到的
      小段的数目。接下来的N行，每行
      有一个1到10000之间的正整数，
      表示一根原木的长度。

输出

    输出能够切割得到的小段的最大长度。
    如果连1cm长的小段都切不出来，输出”0”。

样例输入

3  5
20
22
24

样例输出

11

提示

二分搜索
*/