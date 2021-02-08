#include<stdio.h>
#include<string.h>
#include<stack>
#include<queue>
using namespace std;
char str[1200];
int fun(char ch){ //对优先级进行预定义 
	switch(ch){
		case '+': ;
		case '-': return 1; break;
		case '*': ;
		case '/': return 2; break;
		case'(':  return 0;
		default: return -1;
	}
}
int main(){
	int T,i,j,k,t;
	stack<char>q;//定义栈 
	queue<char>p;//定义队列 
	scanf("%d",&T);
	while(T--){
		while(!q.empty())//对栈初始化 
		   q.pop();
		while(!p.empty())//对队列初始化 
		   p.pop();
		q.push('#');//对栈底做标记 
		scanf("%s",str);
		    k=strlen(str);
		for(i=0;i<k;i++){
			if(str[i]>='0' && str[i]<='9')
			   p.push(str[i]);
			else if(str[i]=='(')
			   q.push(str[i]);
			else if(str[i]==')') //遇到后括号后将括号之前的运算符存入队列 
			   {
			   	while(q.top()!='('){
			   		p.push(q.top());
			   		q.pop();
			   	}
			   	q.pop();
			   }
			else if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/'){
				char zifu=q.top();
				while(fun(str[i])<=fun(zifu)){//判断运算符优先级 
					p.push(zifu);
					q.pop();
					zifu=q.top();
				}
				q.push(str[i]);//不要忘了将运算符存到栈中 
			}
			
		}
		while(!q.empty()){//对栈内剩余运算符存入到队列中 
			p.push(q.top());
			q.pop();
		}
                while (p.front() != '#') { //输出队列
                  printf("%c", p.front());
                  p.pop();
                }
                printf("\n");
        }
        return 0;
}
/*
描述


    我们熟悉的表达式如a+b、a+b*(c+d)等都属于中缀表达式。
    中缀表达式就是（对于双目运算符来说）操作符在两个操作
    数中间：num1 operand num2。同理，后缀表达式就是操
    作符在两个操作数之后：num1 num2 operand。ACM队的
    “C小加”正在郁闷怎样把一个中缀表达式转换为后缀表达式，
    现在请你设计一个程序，帮助C小加把中缀表达式转换成后
    缀表达式。为简化问题，操作数均为个位数，操作符只有+-*
     / 和小括号。

输入


第一行输入T，表示有T组测试数据（T<10）。
每组测试数据只有一行，是一个长度不超过1000的字符串，
表示这个表达式。这个表达式里只包含+-* /与小括号这几种
符号。其中小括号可以嵌套使用。数据保证输入的操作数中
不会出现负数。并且输入数据不会出现不匹配现象。

输出


每组输出都单独成行，输出转换的后缀表达式。

样例输入

2
1+2
(1+2)*3+4*5

样例输出

12+
12+3*45*+
*/