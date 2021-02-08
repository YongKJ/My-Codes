import queue

if __name__ == '__main__':
	n = int(input())
	while 0 < n and n < 1000:
		s = queue.LifoQueue()
		while True:
			s.put(int(n % 2))
			n //= 2
			if int(n % 2) == 0 and n // 2 == 0:
				break
		while not s.empty():
			print(s.get(),end='')
		print()
		n = int(input())
"""
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

"""