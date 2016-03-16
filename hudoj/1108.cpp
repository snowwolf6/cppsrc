#include<stdio.h>

int getgcd(int a,int b)
{
	if(b==0)
		return a;
	return getgcd(b,a%b);
}

int main()
{
	int a,b,gcd;
	while(scanf("%d %d",&a,&b)!=EOF)
	{
		gcd=getgcd(a,b);
		printf("%d\n",a*b/gcd);
	}
	return 0;
}
