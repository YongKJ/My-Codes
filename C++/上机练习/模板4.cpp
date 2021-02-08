#include <iostream>
#include <map>
using namespace std;
int main(){
  int sum,x1,x2,x3,x4;
  while (sum=0,cin >> x1>>x2>>x3>>x4){
    int a, b, c, d, e;
    map<int, int> x[4];
    map<int, int>::iterator p, q;
    for (int i = 0; i < 4; i++) {
      cin >> a >> b >> c >> d;
      x[i][a] = b;
      x[i][c] = d;
    }
    for (a=1;a<=5;a++)
      for (b=1;b<=5;b++)
        for (c=1;c<=5;c++)
          for (d = 1; d <= 5; d++){
            int k[4] = {0}, s;
            map<int, int> y;
            e = 15 - a - b - c - d;
            s = a * b * c * d * e;
            y[1] = a, y[2] = b, y[3] = c, y[4] = d, y[5] = e;
            for (int i = 0; i < 4; i++)
              for (p = x[i].begin(); p != x[i].end(); p++) {
                q = y.find(p->first);
                if (q != y.end() && q->second == p->second)
                  k[i]++;
              }
       if (k[0]==x1&&k[1]==x2&&k[2]==x3&&k[3]==x4&&s==120)
         for (sum++, p = y.begin(); p != y.end(); p++) {
           if (p == --y.end())
             cout << p->second << endl;
           else
             cout << p->second << " ";
         }
          }
      if (sum == 0)
      cout << "Sorry" << endl;   
      }
      
  return 0;
}
/*
描述


ABCDE五个人在运动会上分获百米（1）、二百米（2）、跳高（3）、跳远（4）和铅球冠军（5）中的一项，有四个人猜测比赛结果：
甲说：B获铅球冠军，D获跳高冠军。 
乙说：A获百米冠军，E获跳远冠军。 
丙说：C获跳远冠军，D获二百米冠军。 
丁说：B获跳高冠军，E获铅球冠军。 
其中每个人说了2句，现知道每个人说对了几句。问5人各获得哪项冠军？

输入


多组测试数据，每组测试数据包含5行 
第1行4个数字，分别表示4个人说对的句数（0，1或2） 
然后4行分别是各人的2个猜测，每行4个数字，先是运动员 然后是项目，A为1，B为2，C为3，D为4，E为5 

输出


在一行分别输出5人拿冠军的项目，如果不能确定则输出"Sorry"

样例输入

1 1 1 1
2 5 4 3
1 1 5 4
3 4 4 2
2 3 5 5
1 0 1 2
2 5 4 3
1 1 5 4
3 4 4 2
2 3 5 5

样例输出

1 2 4 3 5
Sorry
*/