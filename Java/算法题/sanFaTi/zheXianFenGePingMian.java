package sanFaTi;

import java.util.Scanner;

public class zheXianFenGePingMian {
	public static void main(String[] args) {
		long s[] = new long[10005];
		s[0] = 0;
		s[1] = 2;
		s[2] = 7;
		for(int i = 3; i < 10005; i++) {
			s[i] = s[i - 1] + 2 * 2 * (i - 1) + 1;
		}
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		while(n-- > 0) {
			int m = sc.nextInt();
			System.out.println(s[m]);
		}
		sc.close();
	}
}

/*
Problem Description
我们看到过很多直线分割平面的题目，今天的这个题目稍微有些变化，
我们要求的是n条折线分割平面的最大数目。比如，一条折线可以将平
面分成两部分，两条折线最多可以将平面分成7部分，具体如下所示。

 

Input
输入数据的第一行是一个整数C,表示测试实例的个数，然后是C 行数据，
每行包含一个整数n(0<n<=10000),表示折线的数量。

 

Output
对于每个测试实例，请输出平面的最大分割数，每个实例的输出占一行。

 

Sample Input
2
1
2
 

Sample Output
2
7

#include<stdio.h>
#include<math.h>
#define ll long long

int main()
{
    ll a[10005]={0,2,7};
    for(int i=3;i<10005;i++)
        a[i]=a[i-1]+2*2*(i-1)+1;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        printf("%lld\n",a[n]);
    }
    return 0;
}
*/