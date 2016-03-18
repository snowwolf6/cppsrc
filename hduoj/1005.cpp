#include<stdio.h>

int fab(int a,int b,int n)
{
	if(n==1||n==2) return 1;
	return (a*fab(a,b,n-1)+b*fab(a,b,n-2))%7;
}
int main()
{
	int i,l[100]={0,1,1};
	for(i=3;i<17;i++)
		l[i]=(l[i-1]+l[i-2])%7;
	int a,b,n,res;
	while(scanf("%d %d %d",&a,&b,&n))
	{
		if(a==0&&b==0&&n==0) break;
		n=n%16;
		if(n==0) n=16;
		res=fab(a,b,n);
		printf("%d\n",res);
	}
	
	return 0;
}
