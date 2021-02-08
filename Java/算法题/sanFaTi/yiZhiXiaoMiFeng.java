package shopping;

import java.util.Scanner;

public class yiZhiXiaoMiFeng {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n      = sc.nextInt();
		while(n-->0) {
			int x    = sc.nextInt();
			int y    = sc.nextInt();
			long a   = 1;
			long b 	 = 2;
			long sum = 0;
			for(int i = 2; i < y - x; i ++) {
				sum = b + a;
				a   = b;
				b   = sum;
			}
			if(y - x == 1) {
				System.out.println(a);
			}else if (y - x == 2) {
				System.out.println(b);
			}else {
				System.out.println(sum);
			}
		}
		sc.close();
	}

}

/*
Problem Description
有一只经过训练的蜜蜂只能爬向右侧相邻的蜂房，不能反向爬行。请编程计算蜜蜂从蜂房a爬到蜂房b的可能路线数。
其中，蜂房的结构如下所示。

 

Input
输入数据的第一行是一个整数N,表示测试实例的个数，然后是N 行数据，每行包含两个整数a和b(0<a<b<50)。
 

Output
对于每个测试实例，请输出蜜蜂从蜂房a爬到蜂房b的可能路线数，每个实例的输出占一行。
 

Sample Input
2
1 2
3 6
 

Sample Output
1
3

 */