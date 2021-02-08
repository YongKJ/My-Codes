#include <cstdio>
using namespace std;
const int maxn = 1000;
int a[maxn][maxn];
int b[maxn][maxn];
int c[maxn][maxn];
typedef struct  node {
    int row, col, v;
} node;
struct T {
    node Node[maxn];
    int MAXrow, MAXcol, MAXsize;
} TA, TB, TC;
int an, am, bn, bm;
int main() {
    scanf("%d%d", &an, &am);//输入a矩阵
    TA.MAXrow = an;
    TA.MAXcol = am;
    for(int i = 1; i <= an; i++) {//下标从1开始
        for(int j = 1; j <= am; j++) {
            scanf("%d", &a[i][j]);
            if(a[i][j]) {

                TA.Node[TA.MAXsize].row = i;
                TA.Node[TA.MAXsize].col = j;
                TA.Node[TA.MAXsize].v = a[i][j];
                TA.MAXsize++;
            }
        }
    }
    scanf("%d%d", &bn, &bm);//输入b矩阵
    TB.MAXrow = bn;
    TB.MAXcol = bm;
    for(int i = 1; i <= bn; i++) {//下标从1开始
        for(int j = 1; j <= bm; j++) {
            scanf("%d", &b[i][j]);
            if(b[i][j]) {

                TB.Node[TB.MAXsize].row = i;
                TB.Node[TB.MAXsize].col = j;
                TB.Node[TB.MAXsize].v = b[i][j];
                TB.MAXsize++;
            }
        }
    }
    TC.MAXrow = an;
    TC.MAXrow = bm;
    for(int i = 1; i <= an; i++) {//计算c矩阵
        for(int j = 1; j <= bm; j++) {
            int sum = 0;
            for(int p = 0; p < TA.MAXsize ; p++) {
                if(TA.Node[p].row != i) continue;
                for(int q = 0; q < TB.MAXsize; q++) {
                    if(TB.Node[q].col != j) continue;
                    if(TA.Node[p].col == TB.Node[q].row) {
                        sum += TA.Node[p].v * TB.Node[q].v;
                    }
                }
            }
            if(sum != 0) {
               TC.Node[TC.MAXsize].row = i;
                TC.Node[TC.MAXsize].col = j;
                TC.Node[TC.MAXsize].v = sum;
                TC.MAXsize++;
            }
        }
    }
    printf("\n\n");
    int t = 0;
    for(int i = 1; i <= an; i++) {//输出c矩阵
        for(int j = 1; j <= bm; j++) {
          if (TC.Node[t].row == i && TC.Node[t].col == j) {
            printf("%d ", TC.Node[t].v);
            t++;
          } else
            printf("0 ");
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}