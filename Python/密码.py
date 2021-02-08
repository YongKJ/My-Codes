def judge(s):
	flag = False
	list = [False,False,False,False]
	for i in range(0,len(s)):
		if 'A'<=s[i] and s[i]<='Z':
			list[0]=True
		elif 'a'<=s[i] and s[i]<='z':
			list[1]=True
		elif '0'<=s[i] and s[i]<='9':
			list[2]=True
		elif s[i]=='~' or s[i]=='!' or s[i]=='@' or s[i]=='#' or s[i]=='$' or s[i]=='%' or s[i]=='^':
			list[3]=True
		sum=0
		for j in range(0,4):
			if list[j]:
				sum+=1
		if sum==3 and 8<=len(s) and len(s)<=16:
			flag = True
			break
	return flag

if __name__ == "__main__":
	n = int(input())
	while n>0:
		n-=1
		s = input()
		if judge(s):
			print("YES")
		else:
			print("NO")

"""
Problem Description

网上流传一句话:"常在网上飘啊，哪能不挨刀啊～"。其实要想能安安心心地上网其实也不难，学点安全知识就可以。

首先，我们就要设置一个安全的密码。那什么样的密码才叫安全的呢？一般来说一个比较安全的密码至少应该满足下面两个条件：

(1).密码长度大于等于8，且不要超过16。
(2).密码中的字符应该来自下面“字符类别”中四组中的至少三组。

这四个字符类别分别为：
1.大写字母：A,B,C...Z;
2.小写字母：a,b,c...z;
3.数字：0,1,2...9;
4.特殊符号：~,!,@,#,$,%,^;

给你一个密码，你的任务就是判断它是不是一个安全的密码。
 

Input
输入数据第一行包含一个数M，接下有M行，每行一个密码（长度最大可能为50），密码仅包括上面的四类字符。
 

Output
对于每个测试实例，判断这个密码是不是一个安全的密码，是的话输出YES，否则输出NO。
 

Sample Input
3
a1b2c3d4
Linle@ACM
^~^@^@!%
 

Sample Output
NO
YES
NO

"""