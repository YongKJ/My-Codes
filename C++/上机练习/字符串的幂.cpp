/*
题意： 给出一个字符串s，求重复子串出现的最大次数
分析：kmp的next[]数组的应用
要求重复子串出现的最大次数，其实就是要求字符串的
最小循环节

这里我们假设这个字符串的长度是len，那么如果len可以
被len-next[len]整除的话，我们就可以说
len-next[len]就是那个最短子串的长度


为什么呢？ 假设我们有一个字符串 ababab 那么next[6]=4，
  由于next的性质，匹配失配后，下一个能继续进行匹配的位置，
也就是说，把字符串的前四个字母，abab，平移2个单位，
这个abab一定与原串的abab重合(否则就不满足失败函数的性质),
zhejiu shuomi
题目分析转载于：http://bbezxcy.iteye.com/blog/1377787
*/
#include<iostream>
#include<cstring>
#include<algorithm>
#include<stdio.h>
using namespace std;

const int maxn =1e6+10;
int Next[maxn];     /// 串的next数组 （看这个串的相似度）
char s1[maxn];

void kmp_pre(char x[],int m,int next[])
{
    int i,j;
    j=next[0]=-1;
    i=0;
    while(i<m){
        while(-1!=j&&x[i]!=x[j])j=next[j];
        next[++i]=++j;
    }
}

int main()
{
  while (scanf("%s", s1) != EOF) {
    memset(Next, 0, sizeof(Next));
    if (s1[0] == '.')
      break;
    int len = strlen(s1);
    kmp_pre(s1, len, Next);
    int temp = len - Next[len];
    if (len % temp == 0)
      printf("%d\n", len / temp);
    else
      printf("1\n");
  }
  return 0;
}
/*
描述


给出两个字符串a和b，定义a*b为两个字符串的连接，
如a="abc",b=“de”，则a*b=“abcde”。如果将连接看成
乘法，则a*a可以看成a的平方。

输入一个字符串s，输出最大的n满足s为a的n次方，a
为任意字符串。

输入


包括多组数据，每组一个字符串s。

输出


最大的n

样例输入

abcd
aaaa
ababab

样例输出

1
4
3
*/