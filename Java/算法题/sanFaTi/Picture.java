package sanFaTi;

import java.util.Scanner;

public class Picture {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()) {
			int n = sc.nextInt();
			int m = sc.nextInt();
			for(int i = 0; i< m + 2; i++) {
				if(i == 0 || i == m + 1) {
					System.out.print("+");
					for(int j = 0; j < n; j++) {
						System.out.print("-");
					}
					System.out.println("+");
				}else {
					System.out.print("|");
					for(int j = 0; j < n; j++) {
						System.out.print(" ");
					}
					System.out.println("|");
				}
			}
			System.out.println();
		}
		sc.close();
	}

}

/*
Problem Description
Give you the width and height of the rectangle,darw it.
 

Input
Input contains a number of test cases.For each case ,there are two numbers n and m (0 < n,m < 75)indicate the width and height of the rectangle.Iuput ends of EOF.
 

Output
For each case,you should draw a rectangle with the width and height giving in the input.
after each case, you should a blank line.
 

Sample Input
3 2
 

Sample Output
+---+
|   |
|   |
+---+

*/