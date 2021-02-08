package sanFaTi;

import java.util.Scanner;
import java.util.Stack;

public class Bitset {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()) {
			int n = sc.nextInt();
			Stack<Integer> s = new Stack<Integer>();
			do {
				s.push(n % 2);
				n /= 2;
			}while(n % 2 != 0 || n / 2 != 0);
			while(!s.empty()) {
				System.out.print(s.pop());
			}
			System.out.println();
			s.clear();
		}
		sc.close();
	}

}

/*
Problem Description
Give you a number on base ten,you should output it on base two.(0 < n < 1000)
 

Input
For each case there is a postive number n on base ten, end of file.
 

Output
For each case output a number on base two.
 

Sample Input
1
2
3
 

Sample Output
1
10
11

*/