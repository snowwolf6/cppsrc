#include<stdio.h>
#include<malloc.h>
#include<string.h>

char* convert(char* s,int numRows)
{//易错点：numRows等于1要特殊考虑，否则步长为负数，死循环
	if(!s||numRows<1)
		return NULL;
	int curPos,sSize=0,i,index=0,fwd=numRows+numRows-2;
	while(s[sSize]!='\0')
		sSize++;
	char *res=(char*)malloc(sizeof(char)*sSize);
	if(numRows==1)
	{
		strcpy(res,s);
		return res;
	}
	for(i=0;i<numRows;i++)
	{
		curPos=i;
		if(curPos<sSize)
			res[index++]=s[curPos];
		while(curPos<sSize)
		{
			if(fwd-i*2)
			{
				curPos+=(fwd-i*2);
				if(curPos<sSize)
					res[index++]=s[curPos];
			}
			if(i*2)
			{
				curPos+=i*2;
				if(curPos<sSize)
					res[index++]=s[curPos];
			}
		}
	}
	res[index]='\0';
	return res;
}

int main()
{
	char str[10000];
	int nums;
	while(gets(str))
	{
		scanf("%d",&nums);
		char *res=convert(str,nums);
		printf("%s\n",res);
		free(res);
	}
	return 0;
}
