#include<stdio.h>
int compare(int number)
{
    int i,j,t;
    int one,two,three,four;
    int a[100];
    int smaller,bigger;
    int number_t;
    a[0]=one=number%10;
    a[1]=two=number/10%10;
    a[2]=three=number/10/10%10;
    a[3]=four=number/1000;
    for(i=0;i<=3;i++)
    {
        for(j=0;j<=3-i-1;j++)
        {
            if(a[j]>=a[j+1])
            {
                t=a[j+1];
                a[j+1]=a[j];
                a[j]=t;
            }
        }
    }
    smaller=a[0]*1000+a[1]*100+a[2]*10+a[3];
    bigger=a[3]*1000+a[2]*100+a[1]*10+a[0];
    //printf(%d,bigger=%d\n",smaller,bigger);
    number_t=bigger-smaller;
    return number_t;
    }
int main()
{
    int number,number_t;
    int n;
    int k;
    scanf("%d",&n);
    while(n!=0)
    {
        k=1;
        scanf("%d",&number);
        number_t=compare(number);
        while(1)
        {
      if (number_t != 6174) 
      {
        //     printf(%d\n",number_t);
        k++;
        number_t = compare(number_t);
      } 
      else
        break;
        }
        printf("%d\n",++k);
        n--;
        }
        return 0;
}