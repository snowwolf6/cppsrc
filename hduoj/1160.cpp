#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<memory.h>
using namespace std;

struct mouse
{
	int weight;
	int speed;
	int index;
}m[1005];
int res[1002];

bool cmp(struct mouse a,struct mouse b)
{
	if(a.weight!=b.weight)
		return a.weight<b.weight;
	else
		return a.speed>b.speed;
}

void printM(struct mouse *m,int cnt)
{
	int i;
	for(i=0;i<cnt;i++)
		printf("%d--%d--%d--%d  ",m[i].weight,m[i].speed,m[i].index,res[i]);
	printf("\n");
}

int main()
{
	int w,s,cnt=0,i,n;

	while(scanf("%d %d",&m[cnt].weight,&m[cnt].speed)!=EOF)
	{
		m[cnt].index=cnt+1;
		++cnt;
	}
	sort(m,m+cnt,cmp);
//	printM(m,cnt);
	n=1;
	int cmax,max,j,maxPos;
	res[0]=1;
	int pre[1002],pos;
	max=1;maxPos=1;
	for(i=1;i<cnt;i++)
	{
		pos=-1;
		cmax=1;
		for(j=i-1;j>=0;j--)
		{
			if(m[i].weight>m[j].weight&&m[i].speed<m[j].speed)
			{
				if(cmax<res[j]+1)
				{
					cmax=res[j]+1;
					pos=j;
				}
			}
		}
		res[i]=cmax;
		pre[i]=pos;
		if(cmax>max)
		{
			max=cmax;
			maxPos=i;
		}
	}
	int resList[1002];
	n=0;
	for(i=maxPos;pre[i]!=-1;i=pre[i])
	{
		resList[n++]=m[i].index;
	}
	resList[n]=m[i].index;
	printf("%d\n",n+1);
	for(i=n;i>=0;i--)
		printf("%d\n",resList[i]);
	return 0;
}
