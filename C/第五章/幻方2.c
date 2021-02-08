#include<stdio.h>
#define N 15
int main()
{
int i,j,rowclrscr(),size,count,row,cloum,square[N][N];
printf("please enter the square size(odd && <=15):\n");
scanf("%d",&size);
while(size%2==0||size>15||size<3)
{
printf("error due to the wrng input!please input it again!\n");
scanf("%d",&size);
}
for(i=0;i<size;i++)
for(j=0;j<size;j++)
square[i][j]=0;
i=0;j=(size-1)/2;
square[i][j] = 1;
for(count=2;count<=size*size;count++)
{
row=i-1<0?(size-1):(i-1);
cloum=j-1<0?(size-1):(j-1);
if(square[row][cloum])
i=(i+1)%size;
else
{i=row;
j=j-1<0?(size-1):(j-1);
}
square[i][j] = count;
}
printf("the %d square is:\n",size);
for (i = 0; i < size; i++) {
  for (j = 0; j < size; j++)
    printf("%2d  ", square[i][j]);
  printf("\n");
}
}