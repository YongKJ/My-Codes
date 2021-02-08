#include<stdio.h>
#include<algorithm>
using namespace std;
int main() {
	int n, m, a[100], b[100],i,j;
	while (~scanf("%d%d", &n, &m)&&(n||m)) {
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		for (i = 0; i < m; i++)
			scanf("%d", &b[i]);
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				if (a[i] == b[j]) {
					a[i] = 0; break;
				}
		int flag = 1;
		sort(a, a + n);
		for (i = 0; i < n; i++)
                  if (a[i]) {
                    printf("%d ", a[i]);
                    flag = 0;
                  }
                if (flag)
                  printf("NULL");
                printf("\n");
        }
        return 0;
}