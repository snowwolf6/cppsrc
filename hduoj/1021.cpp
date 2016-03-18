#include<stdio.h>
//a=a%m   (a+b)%m=(a%m+b%m)%m
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if((n-2)%4==0)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
