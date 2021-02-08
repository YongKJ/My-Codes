#include <stdio.h>
int main()
{
  double n, m;
  while(scanf("%lf%lf",&n,&m)!=EOF&&n<50&&m<=5)
  {
    double ave[6], mark[51][6], tot[6] = {0}, totst[51] = {0};
    int i, j, cnt = 0;
    for (i=0;i<n;i++)
      for (j = 0; j < m; j++) {
        scanf("%lf", &mark[i][j]);
        totst[i] += mark[i][j];
        tot[j] += mark[i][j];
      }
    for (j=0;j<m;j++)
      ave[j] = tot[j] / n;
    for (i = 0; i < n; i++) {
      int flag = 0;
      printf("%.2lf", totst[i] / m);
      if (i < n - 1)
        printf(" ");
      else
        printf("\n");
      for (j = 0; j < m; j++)
        if (mark[i][j] >= ave[j])
          flag++;
      if (flag == m)
        cnt++;
    }
    for (j = 0; j < m; j++) {
      printf("%.2lf", ave[i]);
      if (j < m - 1)
        printf(" ");
      else
        printf("\n");
    }
    printf("%d\n\n", cnt);
  }
  return 0;
}