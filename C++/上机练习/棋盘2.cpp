#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
//tr表示棋盘左上角行号
//tc表示棋盘左上角列号
//dr表示特殊棋盘的行号
//dc表示特殊棋盘的列号
//size = 2^k
//棋盘的规格为2^k * 2^k
const int SIZE = 4;
static int tt = 1;
static int board[SIZE][SIZE];
void ChessBoard(int tr,int tc,int dr,int dc,int size)
{
    if(size == 1)//棋盘只有一个方格且是特殊方格
        return ;
    int t = tt++; //L型骨牌号
    int s = size>>1;//分割棋盘
     //覆盖左上角子棋盘
    //cout << size << " " << s << endl;
    if(dr<tr+s&&dc<tc+s)
        ChessBoard(tr,tc,dr,dc,s); //特殊方格在此棋盘中
    else
    {
         //此棋盘无特殊方格
         //用t号L型骨牌覆盖右下角
        board[tr+s-1][tc+s-1] = t;
        //覆盖其余方格
        ChessBoard(tr,tc,tr+s-1,tc+s-1,s);
    }
    //覆盖右上角
    if(dr<tr+s&&dc>=tc+s) //特殊方格在此棋盘中
        ChessBoard(tr,tc+s,dr,dc,s);
    else
    {
         //此子棋盘中无特殊方格
         //用t号L型骨牌覆盖左下角
        board[tr+s-1][tc+s] = t;
         //覆盖其余方格
        ChessBoard(tr,tc+s,tr+s-1,tc+s,s);
    }
    //覆盖左下角子棋盘
     if(dr >= tr + s && dc < tc + s)
     {
         //特殊方格在此棋盘中
         ChessBoard(tr + s, tc, dr, dc, s);
     }
     else
     {
         //用t号L型骨牌覆盖右上角
         board[tr + s][tc + s -1] = t;
         //覆盖其余方格
         ChessBoard(tr + s, tc, tr + s, tc + s - 1, s);
     }

     //覆盖右下角子棋盘
     if(dr >= tr + s && dc >= tc + s)
     {
         //特殊方格在此棋盘中
         ChessBoard(tr + s, tc + s, dr, dc, s);
     }
     else
     {
         //用t号L型骨牌覆盖左上角
         board[tr + s][tc + s] = t;
         //覆盖其余方格
         ChessBoard(tr + s, tc + s, tr + s, tc + s, s);
     }
}
void ChessPrint()
{
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            cout.width(3);
            cout<<board[i][j]<<" ";
        }
       cout<<endl;
    }
}
int main() {
  int x, y;
  cin >> x >> y;
  ChessBoard(0, 0, x-1, y-1, SIZE);
  ChessPrint();
  return 0;
}
/*
样例输入

2
2 3

样例输出

2 2 3 3
2 1 0 3
4 1 1 5
4 4 5 5
*/