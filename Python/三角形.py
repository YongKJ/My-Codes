class sanJiaoXing(object):
	a = 0
	b = 0
	c = 0
	def __init__(self, x, y, z):
		a = x
		b = y
		c = z
	def trangle_judge(self):
		flag = False
		if a+b>c and a+c>b and b+c>a:
			flag = True
		return flag
if __name__ == "__main__":
	n = int(input())
	for i in range(0, n):
		a,b,c=map(float,input().split())
		s = sanJiaoXing(a, b, c)
		if s.trangle_judge():
			print("YES")
		else:
			print("NO")

"""
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

"""