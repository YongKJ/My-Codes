
if __name__ == "__main__":
	while True:
		n, m = map(int, input().split())
		if not (0 < n and n < 75 and 0 < m and m < 75):
			break
		for i in range(0, m + 2):
			if i == 0  or i == m + 1:
				s = "+"
				for j in range(0, n):
					s += "-"
				s += "+"
				print(s)
			else:
				s = "|"
				for i in range(0, n):
					s += " "
				s += "|"
				print(s)
		print()


"""
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

"""