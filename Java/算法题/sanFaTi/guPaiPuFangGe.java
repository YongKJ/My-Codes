package sanFaTi;

import java.util.Scanner;

public class guPaiPuFangGe {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long s[] = new long[51];
		s[1] = 1;
		s[2] = 2;
		for(int i = 3; i < 51; i++) {
			s[i] = s[i - 1] + s[i - 2];
		}
		while(sc.hasNext()) {
			int n = sc.nextInt();
			System.out.println(s[n]);
		}
		sc.close();
	}
	
}

/*
Problem Description
在2×n的一个长方形方格中,用一个1× 2的骨牌铺满方格,输入n ,输出铺放方案的总数.
例如n=3时,为2× 3方格，骨牌的铺放方案有三种,如下图：

 

Input
输入数据由多行组成，每行包含一个整数n,表示该测试实例的长方形方格的规格是2×n (0<n<=50)。
 

Output
对于每个测试实例，请输出铺放方案的总数，每个实例的输出占一行。
 

Sample Input
1
3
2
 

Sample Output
1
3
2

*/