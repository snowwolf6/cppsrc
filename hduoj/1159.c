#include<stdio.h>
#include<string.h>

int max(int a,int b)
{
	return a>b?a:b;
}

int main()
{
	int len1,len2,i,j,maxlen;
	int dp[1002][1002];
	char str1[1002],str2[1002];
	while(scanf("%s %s",str1,str2)!=EOF)
	{
		len1=strlen(str1);
		len2=strlen(str2);
		maxlen=max(len1,len2);
		for(i=0;i<maxlen;i++)
		{
			if(i<len1)
				dp[0][i]=0;
			if(i<len2)
				dp[i][0]=0;
		}
		for(i=1;i<=len1;i++)
		{
			for(j=1;j<=len2;j++)
			{
				if(str1[i-1]==str2[j-1])
					dp[i][j]=dp[i-1][j-1]+1;
				else
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
		printf("%d\n",dp[len1][len2]);
	}
	return 0;
}
