#include <iostream>
#include <string.h>
#include <cmath>
#include <stdio.h>
using namespace std;
int main()
{
  int n, m,i,j;
  int grade[55][6];
  double student[55];
  double course[6];
  while(cin>>n>>m)
  {
    memset(grade, 0, sizeof(grade));
    memset(student, 0, sizeof(student));
    memset(course, 0, sizeof(course));
    for (i=1;i<=n;i++)
      for (j=1;j<=m;j++)
        cin >> grade[i][j];
    for (i = 1; i <= m; i++) {
      double sum = 0;
      for (j = 1; j <= n; j++)
        sum += grade[j][i];
      course[i] = sum / n;
    }
    for (i = 1; i <= n; i++) {
      double sum = 0;
      for (j = 1; j <= m; j++)
        sum += grade[i][j];
      student[i] = sum / m;
    }
    int count = 0;
    for (i=1;i<=n;i++)
    {
      int mark = 1;
      for (j=1;j<=m;j++)
        if (grade[i][j] < course[j]) {
          mark = 0;
          break;
        }
      if (mark == 1)
        count++;
    }
    for (i = 1; i <= n; i++) {
      if (i == 1)
        printf("%.2lf", student[i]);
      else
        printf(" %.2lf", student[i]);
    }
    cout << endl;
    for (i = 1; i <= m; i++) {
      if (i == 1)
        printf("%.2lf", course[i]);
      else
        printf(" %.2lf", course[i]);
    }
    cout << endl;
    cout << count << endl << endl;
  }
  return 0;
}