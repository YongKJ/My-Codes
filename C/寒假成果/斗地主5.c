#include <stdio.h>
#include <string.h>
int continuum(int num,int total,int buffer[15])
{
  int i,count=0;
  int flag=0;
  int sig=0;
  for(i=0;i<15;i++)
  {
    if(buffer[i]==num)
    {
      if(sig)
        return 0;
      count++;
      if(count==total)
        return 1;
      flag=1;
    } 
    else 
    {
      if (flag)
        sig = 1;
    }
  }
}
static int type_buffer(int buffer[15])
{
  int i, one=0,pair=0,triple=0,quattuor=0,sum=0;
  for(i=0;i<15;i++){
    if(buffer[i] == 1)
      one++, sum++;
    else if(buffer[i] == 2)
      pair++, sum++;
    else if(buffer[i] == 3)
      triple++, sum++;
    else if(buffer[i] == 4)
      quattuor++, sum++;
  }
  if(!(sum))
  {
    return -1;
  }
  else if(sum<=5)
  {
    if(one == 1 && !pair && !triple && !quattuor)
      return 1;
    else if(pair == 1 && !one && !triple && !quattuor)
      return 2;
    else if(one == 2 &&buffer[13]&&buffer[14])
      return 3;
    else if(triple == 1 && !one && !pair && !quattuor) 
      return 4;
    else if(one ==1 && !pair && triple == 1 && !quattuor )
      return 5;
    else if(!one && !pair && !triple && quattuor == 1)
      return 6;
    else if(!one && pair == 1 && triple == 1 && !quattuor)
      return 7;
    else if(one == 1 && !pair && !triple && quattuor==1){
      return 8;
    }
    else if(!pair && !triple && !quattuor && (!buffer[13] && !buffer[14])&& sum == 5)
    {
      if( continuum(1,one,buffer))
        return 9;
      else 
        return -1;
    }
    else return -1; 
  }
  else if(sum>=6){
    if((!one) && (pair == 1) && (!triple) && (quattuor == 1) )
      return 10; 
    else if(!one && !pair && !quattuor){
      if(continuum(3,triple,buffer))
        return 11;
      else return -1;
    }
    else if(!one && !triple && !quattuor){
      if(continuum(2,pair,buffer))
        return 12;
      else return -1;
    }
    else if(sum == 4*triple&&triple==one){
      if(continuum(3,triple,buffer))
        return 13;
      else return -1; 
    }
    else if((sum == 5*triple) && (triple == pair)){
      if(continuum(3,triple,buffer))
        return 14;
      else return -1;
    } else if (!pair && !triple && !quattuor &&
               (!buffer[13] && !buffer[14])) {
      if (continuum(1, one,buffer))
        return 9;
      else
        return -1;
    } else
      return -1;
  }
}
int main()
{
  char point1[][10] = {"3", "4", "5", "6", "7", "8",  "9", "10",
                       "J", "Q", "K", "A", "2", "J1", "J2"};
  int i, j, m, n,s,t=1;
  scanf("%d", &m);
  while(m--)
  {
    char point2[15][10] = {'\0'};
    int buffer[15] = {0};
    scanf("%d", &n);
    for (i = 0; i < n; i++)
      scanf("%s", point2[i]);
    for (i = 0; i < n; i++)
      for (j = 0; j < 15; j++)
        if (strcmp(point2[i], point1[j]) == 0)
          buffer[j]++;
    s = type_buffer(buffer);
    if (s == -1||n>17)
      printf("Case #%d: No\n", t++);
    else
      printf("Case #%d: Yes\n", t++);
  }
}