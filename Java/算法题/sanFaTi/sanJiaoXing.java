package sanFaTi;

import java.util.Scanner;

public class sanJiaoXing {
	
	double a,b,c;
	
	public sanJiaoXing(double x, double y, double z) {
		a=x;
		b=y;
		c=z;
	}
	
	public Boolean trangleJudge() {
		Boolean flag = false;
		if(a + b > c && a + c > b && b + c > a)
			flag = true;
		return flag;
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		while(n-->0) {
			double a = sc.nextDouble();
			double b = sc.nextDouble();
			double c = sc.nextDouble();
			sanJiaoXing s = new sanJiaoXing(a, b, c);
			if(s.trangleJudge()) {
				System.out.println("YES");
			}else {
				System.out.println("NO");
			}
		}
		sc.close();
	}

}

/*
Problem Description
给定三条边，请你判断一下能不能组成一个三角形。
 

Input
输入数据第一行包含一个数M，接下有M行，每行一个实例，包含三个正数A,B,C。其中A,B,C <1000;
 

Output
对于每个测试实例，如果三条边长A,B,C能组成三角形的话，输出YES，否则NO。
 

Sample Input
2
1 2 3
2 2 2
 

Sample Output
NO
YES
*/