#include <iostream>
#include <stack>
#include<cstdio>
using namespace std;
 
int main()
{
    int n;
    int T;
    scanf("%d",&T);
    while(T--)
    {
    	scanf("%d",&n);
        stack<int> s;
        int* stack_in = new int[n];
        int* stack_out = new int[n];
        for(int i=1; i<=n; ++i)
            stack_in[i]=i;
        for(int i=1; i<=n; ++i)
            cin>>stack_out[i];
        int i = 1;
        bool isValid = false;//判断标志
        for(int j=1; j<=n; ++j)
        {
            //判断栈顶是否是该元素
            if(s.size() != 0 && s.top() == stack_out[j])
                s.pop();
            else
            {
                bool find = false;
                for(; i<=n;++i)
                {
                    s.push(stack_in[i]);
                    if(stack_in[i] == stack_out[j])
                    {
                        ++i;
                        find = true;
                        break;
                    }
                }
                if (!find) {
                  isValid = true;
                  break;
                } else
                  s.pop();
            }
        }
        if (isValid)
          cout << "NO" << endl;
        else
          cout << "YES" << endl;
        delete[] stack_in;
        delete[] stack_out;
    }
}
/*
描述


堆栈是一个很特殊的数据结构，他具有先进后出的特性，
在很多应用中都发挥了重要的作用。 对于一组数，怎样
判定是否可以由原始数据经过压栈和出栈得到？ 如此：
即对于一组数，从第一个数开始扫描，当扫描到a[i]时，
在a[i]后且比a[i]小的数必须以逆序出现，直到扫描到倒数
第二个数停止。 如： 2 4 1 3 5（原始数据1 2 3 4 5） ，
首先扫描2,比2小的数且在2之后的数只有1，按照逆序出现； 
继续扫描4，比4小且在4后面的数1，3不是按照逆序出现，
停止扫描，即不能通过堆栈得到。 1 2 3 4 5（原始数据1 2 3 4 5）
则按照上述规则判定成立，则可以通过堆栈得到。 
现在你的任务就是通过程序判定之。

输入


多组测试数据。第一行为测试数据的组数n，后面紧接着
有2n行。

后面的没两行为一组测试数据，第一行m表示原始序列的
个数（原始序列为1 ~ m），第二行则输入需要判断的序列

输出


输出n行，每行表示一组测试数据的结果。能够通过堆
栈得到输出“YES”，否则输出“NO”.

样例输入

2
3
3 1 2
3
1 2 3

样例输出

NO
YES
*/