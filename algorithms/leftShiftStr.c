#include<stdio.h>
#include<string.h>

void reverse(char *str,const int head,const int tail)
{
	if(!str||head>=tail)
		return ;
	int tem,i,middle;
	middle=(head+tail)/2;
	for(i=head;i<=middle;i++)
	{
		tem=str[i];
		str[i]=str[tail-(i-head)];
		str[tail-(i-head)]=tem;
	}
}

int leftShiftStr(char *str, const int strLen, const int shiftNum)
{
	if(!str||strLen<=0)
		return -1;
	if(shiftNum>strLen||shiftNum<0)
		return -1;
	if(shiftNum==0||shiftNum==strLen)
		return 0;
	else
	{
		reverse(str,0,shiftNum-1);
		reverse(str,shiftNum,strLen-1);
		reverse(str,0,strLen-1);
	}
	return 0;
}


int main()
{
	char str[1000]={""};
	int n,i,len;
	printf("please input the string:\n");
	while(gets(str))
	{
		len=strlen(str);
		printf("please input the num:\n");
		scanf("%d",&n);
		printf("pre:%s %d\n",str,n);
		leftShiftStr(str,len,n);
		printf("after:%s %d\n\n",str,n);
		printf("please input the string:\n");
		getchar();
	}
	return 0;
}

