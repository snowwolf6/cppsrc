#include<stdio.h>
int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	int num[100][100],t,n,i,j;
	scanf("%d",&t);
	while(t)
	{
		t--;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			for(j=0;j<=i;j++)
				scanf("%d",&num[i][j]);
		for(i=n-2;i>=0;i--)
			for(j=0;j<=i;j++)
				num[i][j]+=max(num[i+1][j],num[i+1][j+1]);
		printf("%d\n",num[0][0]);
	}
	return 0;
}
