#include<stdio.h>
int main()
{
	int a[100];
	int i,n,t;
	int min;
        while (scanf("%d", &n), n != 0) {
          min = 0;
          for (i = 0; i < n; i++)
            scanf("%d", &a[i]);
          for (i = 0; i < n; i++)
            if (a[i] < a[min])
              min = i;
          t = a[0];
          a[0] = a[min];
          a[min] = t;
          for (i = 0; i < n - 1; i++)
            printf("%d ", a[i]);
          printf("%d", a[n - 1]);
          printf("\n");
        }
        return 0;
}