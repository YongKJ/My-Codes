if __name__ == "__main__":
	n = int(input())
	while n>0:
		n = n - 1
		m = int(input())
		sum = 1
		a = 1
		b = 1
		for i in range(2, m):
			sum = a + b
			a   = b
			b   = sum
		print(sum)

"""
Problem Description
有一楼梯共M级，刚开始时你在第一级，若每次只能跨上一级或二级，要走上第M级，共有多少种走法？
 

Input
输入数据首先包含一个整数N，表示测试实例的个数，然后是N行数据，每行包含一个整数M（1<=M<=40）,表示楼梯的级数。
 

Output
对于每个测试实例，请输出不同走法的数量
 

Sample Input
2
2
3
 

Sample Output
1
2


"""