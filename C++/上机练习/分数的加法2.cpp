#include <iostream>  
 #include <cmath>  
 using namespace std;  
  
 class rationalNumber  
 {  
 public:  
     rationalNumber(int m,int n)  
     {  
         if(n==0)  
         {  
             cout<<"denominator equal zero"<<endl;  
         }  
         else  
         {  
             int count=0;//  
             if(n<0)  
                 m=-m,n=-n;  
             a=m,b=n;  
             m=abs(m),n=abs(n);  
             while(n!=0)//求最小公约数m  
             {  
                 int c=m%n;  
                 m=n;  
                 n=c;  
             }  
             a=a/m,b=b/m;//约分，分数化为最简  
         }  
     }  
     rationalNumber()  
     {  
     }  
     rationalNumber operator +(rationalNumber &r)  
     {  
         return rationalNumber(a*r.b+b*r.a,b*r.b);//调用构造函数，再约分，分数化为最简  
  
     }  
     void show(rationalNumber &r1,rationalNumber &r2)  
     {  
         cout<<r1.a<<"/"<<r1.b;  
         if(r2.a<0)  
             cout<<r2.a<<"/"<<r2.b<<"=";  
         else  
             cout<<"+"<<r2.a<<"/"<<r2.b<<"=";  
         if((a==b  ||  a==-b  )&&  a!=0)  
         {  
             if(a==b)  
                 cout<<"1"<<endl;  
             else  
                 cout<<"-1"<<endl;  
         }  
         else  
         {  
             if(a==0)  
                 cout<<"0"<<endl;  
             else  
                 cout<<a<<"/"<<b<<endl;  
         }  
     }  
 private:  
     int a,b;  
 };  
  
 int main()  
 {  
     int T,m,n,k,l;  
     cin>>T;  
     while(T--)  
     {  
         cin>>m>>n>>k>>l;  
         rationalNumber r1(m,n),r2(k,l),r3;  
           if(n==0  ||  l==0)//如果分母n，l为零，跳过下面句子，继续循环  
             continue;//  
  
         r3=r1+r2;  
         r3.show(r1,r2);  
     }  
     return 0;  
 }   