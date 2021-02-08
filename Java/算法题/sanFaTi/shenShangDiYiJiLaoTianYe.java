package sanFaTi;

import java.util.Scanner;

public class shenShangDiYiJiLaoTianYe {
	
	long s[][] = new long[21][2];
	
	public shenShangDiYiJiLaoTianYe() {
		s[1][0] = 1;
		s[2][0] = 2;
		s[1][1] = 0;
		s[2][1] = 1;
		for(int i = 3; i < 21; i++) {
			s[i][0] = s[i - 1][0] * i;
			s[i][1] = (i - 1) * (s[i - 1][1] + s[i - 2][1]);
		}
	}
	
	public double getPercent(int m) {
		return 100.0 * s[m][1] / s[m][0];
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n 	   = sc.nextInt();
		while(n-- > 0) {
			int x = sc.nextInt();
			shenShangDiYiJiLaoTianYe s = new shenShangDiYiJiLaoTianYe();
			System.out.printf("%.2f",s.getPercent(x));
			System.out.println("%");
			
		}
		sc.close();
	}
}

/*
Problem Description
HDU 2006'10 ACM contest的颁奖晚会隆重开始了！
为了活跃气氛，组织者举行了一个别开生面、奖品丰厚的抽奖活动，这个活动的具体要求是这样的：

首先，所有参加晚会的人员都将一张写有自己名字的字条放入抽奖箱中；
然后，待所有字条加入完毕，每人从箱中取一个字条；
最后，如果取得的字条上写的就是自己的名字，那么“恭喜你，中奖了！”

大家可以想象一下当时的气氛之热烈，毕竟中奖者的奖品是大家梦寐以求的Twins签名照呀！不过，正如所有试图设计的喜剧往往以悲剧结尾，这次抽奖活动最后竟然没有一个人中奖！

我的神、上帝以及老天爷呀，怎么会这样呢？

不过，先不要激动，现在问题来了，你能计算一下发生这种情况的概率吗？

不会算？难道你也想以悲剧结尾？！
 

Input
输入数据的第一行是一个整数C,表示测试实例的个数，然后是C 行数据，每行包含一个整数n(1<n<=20),表示参加抽奖的人数。

 

Output
对于每个测试实例，请输出发生这种情况的百分比，每个实例的输出占一行, 结果保留两位小数(四舍五入)，具体格式请参照sample output。

 

Sample Input
1
2
 

Sample Output
50.00%

分析：这是一道递推题
1、n 个人 n 张票，就有 n! 种排列情况。我们需要做的就是从这 n! 种情况中，找出 n 个人所有的错排情况。

2、假设有 n 个人，错排情况数是 f ( n ) ，把他们分成 1 个人和 n - 1 个人两部分。有如下 3、4 两种情况：

3、假设 1 个人拿的是自己的票， n - 1 拿的都不是自己的票，那么这 1 个人只需要和这 n - 1 个人中任何一个人交换一下票，就可满足 n 个人错排。所以有 ( n - 1 ) * f ( n - 1 ) 。

4、假设 n - 1 个人其中有一个人拿的是自己的票，1 个人拿的不管是不是自己的票，只要和 n - 1 个人当中那个拿自己票的人交换一下，就可满足 n 个人错排。而且，n - 1 个人当中除掉拿自己票的人，n - 2 个人肯定满足错排。所以又有 ( n - 1 ) * f ( n - 2 ) 。

综上所述：f ( n ) = ( n - 1) * [ f ( n - 1 ) + f ( n - 2 ) ]

写程序时，可以利用一个二维数组cases [ 21 ] [ 2 ] ，数组第 0 列存储 n 个人的所有排列情况 n! ，数组第 1 列存储 n 个人的错排情况 f ( n ) = ( n - 1) * [ f ( n - 1 ) + f ( n - 2 ) ]
--------------------- 
作者：Litmmp 
来源：CSDN 
原文：https://blog.csdn.net/u011506951/article/details/25157161 
版权声明：本文为博主原创文章，转载请附上博文链接！
*/