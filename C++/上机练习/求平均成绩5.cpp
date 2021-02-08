//#include<iostream>
#include<stdio.h>
//#include<iomanip>
//using namespace std;
int main()
{
	double n,m;
	while(scanf("%lf%lf",&n,&m)!=EOF&&n<=50&&m<=5)//while(cin>>n>>m)
	{
		//if(m==0||n==0) break;
	double ave[6],mark[51][6],tot[6]={0},totst[51]={0};
	int i,j,cnt=0;
	for(i=0;i<n;i++)
	   for(j=0;j<m;j++)
	   {
	   	scanf("%lf",&mark[i][j]);//cin>>mark[i][j];
	   	totst[i]+=mark[i][j];
	   	tot[j]+=mark[i][j];
	   }
	for(j=0;j<m;j++) ave[j]=tot[j]/n;
	for(i=0;i<n;i++)
	{
		int flag=0;
		printf("%.2lf",totst[i]/m);//cout<<fixed<<setprecision(2)<<totst[i]/m;
		if(i<n-1) printf(" ");//cout<<" ";
		else printf("\n");//cout<<endl;
		for(j=0;j<m;j++)
		  if(mark[i][j]>=ave[j]) flag++;
		if(flag==m) cnt++;
	}
        for (j = 0; j < m; j++) {
          printf("%.2lf", ave[j]); // cout<<fixed<< setprecision(2) <<ave[j];
          if (j < m - 1)
            printf(" "); // cout<<" ";
          else
            printf("\n"); // cout<<endl;
        }
        printf("%d\n\n", cnt); // cout<<cnt<<endl;cout<<endl;
        }

        return 0;
}