#include<stdio.h>
int main()
{
	int n,cur,i,res,pre;
	while(scanf("%d",&n)&&n!=0)
	{
		pre=0;res=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&cur);
			if(cur>=pre)
				res+=((cur-pre)*6+5);
			else
				res+=((pre-cur)*4+5);
			pre=cur;
		}
		printf("%d\n",res);
	}
	return 0;
}
