#include<iostream>

#include<cstdio>

#include<cstring>

using namespace std;

char a[1000];

char b[1000];

int next[1000];

void get_next()

{

    next[0] = -1;

    int j = -1;

    int i = 0;

    int str = strlen(b);

    while(i < str - 1)

    {

        if(j == -1 || b[i] == b[j])

        {

            next[++i] = ++j;

        }

        else

        {

            j = next[j];

        }

    }

}

int index_KMP()

{

    int stra = strlen(a);

    int strb = strlen(b);

    int i = -1,j = -1;

    while(i < stra && j < strb)

    {

        if(j == -1 || a[i] == b[j])

        {

            i++;j++;

        }

        else

        {

            j = next[j];

        }

    }

    if (j >= strb)

    { //在a中找到了b字符串

      return 1;
    }

    return 0;
}
int main()

{

    while(scanf("%s%s",a,b)!=EOF)

    {

        get_next();

        if(index_KMP())

        {

            printf("YES\n");

        }

        else

        {

          printf("NO\n");
        }
    }

    return 0;
}