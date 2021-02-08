#include<iostream>
#include<ctype.h>
#include<string>
using namespace std;
int main()
{
    int n; 
    scanf("%d", &n);
    getchar(); //函数后面通常用一个getchar()来接收回车符号
    for (int i = 0; i < n; i++){
        string str; 
        char yo = 0;
        getline(cin, str);
        if (isalpha(str[0]) || str[0] == '_')//判断字符ch是否为英文字母
        {
            yo = 1;
            for (int i = 1; str[i] != 0; i++)
            {
              if (!isalnum(str[i]) && str[i] != '_') //判断字符变量c是否为字母或数字，若是则返回非零，否则返回零。
              {
                yo = 0;
                break;
              }
            }
        }
        if (yo)
          printf("yes\n");
        else
          printf("no\n");
    }
    return 0;
}