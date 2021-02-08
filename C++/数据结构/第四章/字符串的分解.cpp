#include <iostream>
using namespace std;
void format(char *s1, char *s2, char *s3, int n) {
  int x = 0;
  for (; s1[x]; x++)
    if (s1[x] != ' ')
      break;
  for (int i = 0; i < n - 1; i++)
    s2[i] = s1[x++];
  for (; s1[x]; x++)
    if (s1[x] != ' ')
      break;
  s2[n - 1] = s1[x++], s2[n] = '\0';
  for (int i = 0; s1[x]; i++)
    s3[i] = s1[x++], s3[i + 1] = '\0';
}
int main() {
  int n;
  char s1[20], s2[15], s3[15];
  while (cin.getline(s1,20),cin>>n)
   format(s1, s2, s3,n), cout << s2 <<endl << s3 << endl;
  return 0;
}
/*
输入:
  123     6789045  
5


输出:
123 6
789045  
*/