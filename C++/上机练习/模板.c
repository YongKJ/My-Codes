#include <stdio.h>
#include <string.h>
int main (void)

{

    char str1[5],str2[5][20];

    int p,i,j;

    for(i=0;i<4;i++)

gets(str2[i]);

    for(i=0;i<4;i++)

    {

        p=i;

        strcpy(str1,str2[i]);

        for(j=i+1;j<4;j++)
            if(strcmp(str2[j],str1)<0)
          {
                p = j;
                strcpy(str1, str2[j]);
              }

        if (p != i)

        {

          strcpy(str1, str2[i]);

          strcpy(str2[i], str2[p]);

          strcpy(str2[p], str1);
        }

        puts(str2[i]);

        printf("\n");
    }
    return 0;
}