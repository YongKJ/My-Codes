#include<stdio.h>
void func(int *s,int n)
{
	int i,j,t=0;
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
			if(*(s+i)<*(s+j))
			{
				t=*(s+i);
				*(s+i)=*(s+j);
				*(s+j)=t;
			}
}


void main()
{
	int i,n,a[100],*s=a,m;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	func(s,n);/*沔臬支峒*/
	scanf("%d",&m);
        int mid, high = n - 1, low = 0;
	while(low<=high)
	{
		mid=(high+low)/2;
		if(a[mid]==m)
		{
			printf("%d\n",mid+1);
			break;
		}
		if(a[mid]<m)
			high=mid-1;
		else
			low=mid+1;
		if(low>high)
			printf("wucishu!");
	}
}