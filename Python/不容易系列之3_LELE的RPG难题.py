global number
number = [0] * 51
def begin():
	global number
	for i in range(0, 51):
		number[i] = 0
	number[1] = 3
	number[2] = 6
	number[3] = 6

def getNum(i):
	global number
	if(number[i] != 0):
		return number[i]
	else:
		number[i] = getNum(i - 1) + getNum(i - 2) * 2
		return number[i]

if __name__ == "__main__":
	n = int(input())
	while 0 < n and n <= 50:
		begin()
		print(getNum(n)) 
		n = int(input())

"""
Problem Description
人称“AC女之杀手”的超级偶像LELE最近忽然玩起了深沉，这可急坏了众多“Cole”（LELE的粉丝,即"可乐"）,经过多方打探，某资深Cole终于知道了原因，原来，LELE最近研究起了著名的RPG难题:

有排成一行的ｎ个方格，用红(Red)、粉(Pink)、绿(Green)三色涂每个格子，每格涂一色，要求任何相邻的方格不能同色，且首尾两格也不同色．求全部的满足要求的涂法.

以上就是著名的RPG难题.

如果你是Cole,我想你一定会想尽办法帮助LELE解决这个问题的;如果不是,看在众多漂亮的痛不欲生的Cole女的面子上,你也不会袖手旁观吧?

 

Input
输入数据包含多个测试实例,每个测试实例占一行,由一个整数N组成，(0<n<=50)。
 

Output
对于每个测试实例，请输出全部的满足要求的涂法，每个实例的输出占一行。
 

Sample Input
1
2
 

Sample Output
3
6

"""