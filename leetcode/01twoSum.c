#include<stdio.h>
#include<malloc.h>

/**
  *Note: The returned array must be malloced, assume caller calls free().
  */
int cmp(const void *a,const void *b)
{
	return *(int*)a-*(int*)b;
}

int indexs[100000]={0};

int* twoSum(int* nums, int numsSize, int target)
{
	/**
	  *应考虑到原数组未排序，可能存在重复值，输出原始数组的索引
	  *易错点：用指针访问数组时，不要直接把数组名指针++
	  *否则再次使用那个指针访问时易造成越界未定义错误
	  */
	int i;
	for(i=0;i<numsSize;i++)
	{
		indexs[i]=*(nums+i);
	}
	qsort(nums,numsSize,sizeof(int),cmp);
	int startPos=0,endPos=numsSize-1;
	while(startPos<endPos)
	{
		if(*(nums+startPos)+*(nums+endPos)==target)
			break;	
		if(*(nums+startPos)+*(nums+endPos)<target)
			startPos++;
		else
			endPos--;
	}
	if(startPos<endPos)
	{
		int *res=(int *)malloc(2*sizeof(int));
		if(res)
		{
			int s,t,e;
			int startFlag=-1,endFlag=-1;
			int data1=*(nums+startPos);
			int data2=*(nums+endPos);
			for(i=0;i<numsSize&&(startFlag==-1||endFlag==-1);i++)
			{
				if(indexs[i]==data1&&startFlag==-1)
				{
					s=i;
					startFlag=1;
				}
				else if(indexs[i]==data2&&endFlag==-1)
				{
					e=i;
					endFlag=1;
				}
			}
			if(s>e)
			{
				t=s;
				s=e;
				e=t;
			}
			*res=s;
			*(res+1)=e;
		}
		else
			printf("malloc error\n");
		return res;
	}
	else
		return NULL;
}

int main()
{
	int nums[]={33,1,4,14,15,13};
	int* resArry=twoSum(nums,sizeof(nums)/sizeof(int),28);
	if(resArry)
	{
		printf("%d %d\n",*resArry,*(resArry+1));
		free(resArry);
	}
	return 0;
}
