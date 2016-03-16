#include<stdio.h>

int power(int a,int b)
{//快速幂 
	int ans;
	if(b==0)
		return 1;
	ans=power(a*a,b/2);
	if(b%2!=0)
		ans*=a;
	return ans;
}

int modpower(int a,int b)
{//快速幂 
	int ans;
	if(b==0)
		return 1;
	ans=modpower((a%1000)*(a%1000),b/2);
	if(b%2!=0)
		ans*=(a%1000);
	return ans%1000;
}

int main()
{
	int a,b,res;
	while(scanf("%d %d",&a,&b)&&(a!=0&&b!=0))
	{
		res=modpower(a,b);
		printf("%d\n",res);
	}
	return 0;
}
