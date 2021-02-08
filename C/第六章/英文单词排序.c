#include <stdio.h>
void f(char *s[], int n)
{
  int  j, k,t,b;
  char *a,*c,*p;
  p = s;
  c = p;
  a = c + 10;
  b = (n - 1) * 10;
   for (j=0;j<=(n-1)*n/2;j++)
      {   
         	
    	if(*p>*a)
          for (k = 0; k < 10; k++) 
          {
            t = *p;
            *p = *a;
            *a = t;
            p++;
            a++;
          }
          
        else 
        {
          p += 10;
          a += 10;
        }  
            
        if (a >= (c + n * 10)) 
        {
          p = c;
          a = c + 10;
        }      
         
    }
  }
        
    	
int main()
{
  int n=4, i, j;
  char a[100][10] = {0};
  for (i=0;i<n;i++)
    scanf("%s", a[i]);
  f(&a, n);
  for (i = 0; i < n; i++) 
  {
    for (j = 0; j < 10; j++)
      if (a[i][j] != 0)
        printf("%c", a[i][j]);
    printf("\n");
  }
}