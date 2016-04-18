#include<stdio.h>
#include<memory.h>

int max(int a,int b)
{
	return a>b?a:b;
}

int num[100003][12];

int main()
{
	int n,x,t,i,j,maxTime;
	while(scanf("%d",&n)&&n)
	{
		maxTime=0;
		memset(num,0,100003*12);
		for(i=0;i<n;i++)
		{
			scanf("%d %d",&x,&t);
			num[t][x]++;
			maxTime=max(maxTime,t);
		}
		for(i=maxTime-1;i>=0;i--)
			for(j=0;j<11;j++)
			{
				if(j==0)
					num[i][j]+=max(num[i+1][j],num[i+1][j+1]);
				else if(j==10)
					num[i][j]+=max(num[i+1][j],num[i+1][j-1]);
				else
					num[i][j]+=max(max(num[i+1][j],num[i+1][j-1]),num[i+1][j+1]);
			}
		printf("%d\n",num[0][5]);
	}
	return 0;
}
