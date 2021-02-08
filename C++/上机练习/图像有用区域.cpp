//
//  main.cpp
//  NYOJ92
//
//  Created by jtusta on 2017/7/8.
//  Copyright © 2017年 jtahstu. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

struct point
{
    int x;
    int y;
};

int w, h;
int map[970][1450];
int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

void BFS(int a, int b)
{
    queue <point> q;
    point t1, t2;
    t1.x = a;
    t1.y = b;
    q.push(t1);
    while(!q.empty())
    {
        t1= q.front();
        q.pop();
        for(int i = 0; i < 4; ++i)
        {
            t2.x = t1.x + dir[i][0];
            t2.y = t1.y + dir[i][1];
            if(t2.x < 1 || t2.x > h || t2.y < 1 || t2.y > w || map[t2.x][t2.y] == 0)
                continue;
            map[t2.x][t2.y] = 0;
            q.push(t2);
        }
    }
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        cin >> w >> h;
       /* for(int i = 0; i <= h; ++i)
            map[i][0] = map[i][w + 1] = 1;
        for(int j = 0; j <= w; ++j)
            map[0][j] = map[h + 1][j] = 1;*/

        for(int i = 1; i <= h; ++i)
            for(int j = 1; j <= w; ++j)
                cin >> map[i][j];
        BFS(1, 1);
        for(int i = 1; i <= h; ++i)
          for (int j = 1; j <= w; ++j) {
            if (j == w)
              cout << map[i][j] << endl;
            else
              cout << map[i][j] << ' ';
          }
    }
    return 0;
}
/*
描述


      “ACKing”同学以前做一个图像处理的项目时，
      遇到了一个问题，他需要摘取出图片中某个
      黑色线?成的区域以内的图片，现在请你来
      帮助他完成第一步，把黑色线?外的区域全
      部变为黑色。

      

                图1                                                        图2 

     已知黑线各处不会出现交叉（如图2）
     ,并且，除了黑线上的点外，图像中没
     有纯黑色（即像素为0的点）。

输入

   第一行输入测试数据的组数N(0<N<=6)
   每组测试数据的第一行是两个个整数W,H
   分表表示图片的宽度和高度(3<=W<=1440,
   3<=H<=960)
   随后的H行，每行有W个正整数,表示该点
   的像素值。(像素值都在0到255之间，
   0表示黑色，255表示白色）

输出


以矩阵形式输出把黑色框之外的区域变黑之后
的图像中各点的像素值。

样例输入

1
5 5
100 253 214 146 120
123 0 0 0 0
54 0 33 47 0
255 0 0 78 0
14 11 0 0 0

样例输出

0 0 0 0 0
0 0 0 0 0
0 0 33 47 0
0 0 0 78 0
0 0 0 0 0
*/