#include<stdio.h>
int main()
{
	int a[10][6]={{0},{1},{0,2,4,8,6},{0,3,9,7,1},{0,4,6},{0,5},{0,6},
				  {0,7,9,3,1},{0,8,4,2,6},{0,9,1}};
	int n,bit,tem;
	int cnt;
	scanf("%d",&cnt);
	while(cnt>0)
	{
		--cnt;
		scanf("%d",&n);
		bit=n%10;
		if(bit==0||bit==1||bit==5||bit==6)
			printf("%d\n",bit);
		else if(bit==2||bit==3||bit==7||bit==8)
		{
			tem=n%4;
			if(tem==0) tem=4;
			printf("%d\n",a[bit][tem]);
		}
		else if(bit==4||bit==9)
		{
			tem=n%2;
			if(tem==0) tem=2;
			printf("%d\n",a[bit][tem]);
		}
	}
	return 0;
}
