#include<iostream>
#include<stdio.h>
#include<memory.h>
using namespace std;

int main()
{
	int n,w[1002],dp[1002],i,j,max;
	while(scanf("%d",&n)&&n)
	{
		for(i=0;i<n;i++)
			scanf("%d",&w[i]);
		dp[0]=w[0];
		max=dp[0];
		for(i=1;i<n;i++)
		{
			dp[i]=w[i];
			for(j=0;j<i;j++)
			{
				if(w[i]>w[j]&&dp[j]+w[i]>dp[i])
				{
					dp[i]=dp[j]+w[i];
				}
			}
			if(dp[i]>max)
				max=dp[i];
		}
		printf("%d\n",max);
	}
	return 0;
}
