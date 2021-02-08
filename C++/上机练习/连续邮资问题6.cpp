#include<cstring>   
#include<cstdio>  
#include<cstdlib>  
#include<iostream>  
#define INF 2147483647  
#define MAXN 2000  
using namespace std;  
int h, k;  
int ans[MAXN], maxStampVal, stampVal[MAXN], maxVal[MAXN], y[MAXN];  
bool occur[MAXN];  
  
  
void search(int cur){  
    if(cur >= k){  
        if(maxVal[cur-1] > maxStampVal){  
            maxStampVal = maxVal[cur-1];  
            memcpy(ans, stampVal, sizeof(stampVal));  
        }  
        return ;  
    }  
    int tmp[MAXN];   
    memcpy(tmp, y, sizeof(y));  
    for(int i=stampVal[cur-1]+1; i<=maxVal[cur-1]+1; ++i){  
  
        stampVal[cur] = i;  
        // 关键步骤，利用了动态规划的思想  
        for(int j=0; j<stampVal[cur-1]*h; ++j)if(y[j]<h){  
            for(int num=1; num<=h-y[j]; ++num){  
                if(y[j]+num < y[j + i*num] && (j+i*num<MAXN))  
                    y[j+i*num] = y[j]+num;  
            }  
        }  
        int r = maxVal[cur-1];  
        while(y[r+1]<INF) r++;  
        maxVal[cur] = r;  
  
        search(cur+1);  
  
        memcpy(y, tmp, sizeof(tmp));  
    }  
}  
  
int main(){  
#ifdef LOCAL  
    freopen("input.txt", "r", stdin);  
#endif  
    // h数量， k面额数  
    while(scanf("%d %d", &h, &k), h+k){  
        stampVal[0] = 1;  
        maxVal[0] = h;  
        int i;  
        for(i=0; i<=h; ++i)  
            y[i] = i;  
        while(i<MAXN) y[i++] = INF;        
        maxStampVal = -2147483645;  
        search(1);  
  
        for(i=0; i<k; ++i)  
            printf("%3d", ans[i]);  
        printf(" ->%3d\n", maxStampVal);  
    }  
    return 0;  
}  
