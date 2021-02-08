#include<iostream>
#include<stack>
using namespace std;
int main()
{
 int m,n;
 stack<int>mystack;
 cout<<"请输入两个整数（ctrl+z结束）："<<endl;
 cout<<"警告：不能太大否则系统崩溃！^_^"<<endl;
 while(cin>>m>>n)
 {
  if(m==0)
  {
   cout<<"运算结果如下："<<endl;
   cout<<n+1<<endl;
   cout<<"请输入两个整数（ctrl+z结束）："<<endl;
   cout<<"警告：不能太大否则系统崩溃！^_^"<<endl;
  }
  else
  while(true)
  {
   if(m!=0&&n!=0)
     {
   mystack.push(m-1);
   n--;
     }
  else if(m==0)
   {
    m=mystack.top();
    n++;
    mystack.pop();
   }
   else if(n==0)
    {
     m=m-1;
     n=1;
    }
    if (mystack.empty() && m == 0) {
      n++;
      break;
    }
  }
  cout << "运算结果如下：" << endl;
  cout << n << endl;
  cout << "请输入两个整数（ctrl+z结束）：" << endl;
  cout << "警告：不能太大否则系统崩溃！^_^" << endl;
 }
 return 0;
}

/*
//Ackerman函数
int Ackerman(int m, int n)
{
    if (0 == m)
        return n + 1;//若m=0，则返回n+1的值
    else
    {
        if (m > 0 && 0 == n)
            return Ackerman(m - 1, 1);//若m>0且n=0，则返回Ackerman（m-1，1）的值
        else
            if (m > 0 && n > 0)
                return Ackerman(m - 1,Ackerman(m, n - 1));//若m>0且n>0，则返回Ackerman(m - 1,Ackerman(m, n - 1))的值
    }
}
*/