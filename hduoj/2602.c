#include<stdio.h>
#include<memory.h>

int max(int a,int b)
{
	return a>b?a:b;
}

int main()
{
	int t,n,i,j,res,v;
	int w[1002],c[1002],dp[1002];

	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&v);
		for(i=1;i<=n;i++)
			scanf("%d",&w[i]);
		for(i=1;i<=n;i++)
			scanf("%d",&c[i]);
		memset(dp,0,sizeof(dp));

		for(i=1;i<=n;i++)
			for(j=v;j>=c[i];j--)
				dp[j]=max(dp[j],dp[j-c[i]]+w[i]);
		printf("%d\n",dp[v]);
	}

	return 0;
}
