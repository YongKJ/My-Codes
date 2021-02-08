#include<iostream>
#include<string>
#include<stack>
#include<queue>

using namespace std;

int main()
{
    string a;
    int i=0;
    stack<char> s;
    queue<char> q;
    getline(cin,a);
/////////////////////////
    s.push(a[1]);
    q.push(a[0]);
    for(i=2;i<a.size();i++)
    {
        if((a[i]<='9')&&(a[i]>='0'))
            q.push(a[i]);
        else if((a[i]=='+')||(a[i]=='-'))
        {
            if((s.top()=='*')||(s.top()=='/'))
            {
                q.push(s.top());
                s.pop();
            }
            s.push(a[i]);
        }
        else if((a[i]=='*')||(a[i]=='/'))
            s.push(a[i]);
        else if(a[i]=='(')
            s.push(a[i]);
        else if(a[i]==')')
        {
            while(s.top()!='(')
            {
                q.push(s.top());
                s.pop();
            }
            s.pop();
        }
    }
    /////全部出栈////////////////
    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    //开始计算后缀表达式
    //需要用一个栈
    stack<int> ans;
    int x1,x2;
    while(!q.empty())
    {
        if((q.front()<='9')&&(q.front()>='0'))
        {
            ans.push(q.front()-'0');
            q.pop();
        }
        else if(q.front()=='+')
        {
            x2=ans.top();
            ans.pop();
            x1=ans.top();
            ans.pop();
            ans.push(x1+x2);
            q.pop();
        }
        else if(q.front()=='-')
        {
            x2=ans.top();
            ans.pop();
            x1=ans.top();
            ans.pop();
            ans.push(x1-x2);
            q.pop();
        }
        else if(q.front()=='*')
        {
            x2=ans.top();
            ans.pop();
            x1=ans.top();
            ans.pop();
            ans.push(x1*x2);
            q.pop();
        } else if (q.front() == '/') {
          x2 = ans.top();
          ans.pop();
          x1 = ans.top();
          ans.pop();
          ans.push(x1 / x2);
          q.pop();
        }
    }
    cout << ans.top();
}
/*
描述


      给定任意一个四则运算表达式，计算它的值。
      四则运算只包括加减乘除与左右括号。你可以
      假定运算数及其运算结果均是非负整数，且均
      不超过32位二进制整数。

输入


    每一行一个表达式（不超过80个字符，注意单独
    的一个数也是一个表达式），直到一个单独的0结束。

输出


    每一行一个整数，是对应输入的表达式的值。

样例输入

3+2+1
3-2-1
1+2*3
0


样例输出

6
0
7
*/