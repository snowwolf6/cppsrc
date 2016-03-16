#include<stdio.h>
int main()
{
	int i,t,n;
	int sum,max,a;
	scanf("%d",&t);
	while(t>0)
	{
		--t;
		scanf("%d",&n);
		sum=0;max=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a);
			sum+=a;
			if(a>max)
				max=a;
		}
		if(sum-max+1>max)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
