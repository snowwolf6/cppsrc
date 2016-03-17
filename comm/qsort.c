#include<stdio.h>
//qsort  is in stdlib.h
// sort char arry, is same to the int arry
int charcmp(const void *a,const void *b)
{
	return *(char*)a-*(char*)b;
}

//sort double arry
int doublecmp(const void *a,const void *b)
{
	return *(double*)a>*(double*)b?1:-1;//asc
	//return *(double*)a<*(double*)b;
}

//sort struct
struct in
{
	int x; int y;
};
int structcmp(const void *a,const void *b)
{//按照x从小到大排序，当x相等时按照y从小到大排序
	struct in *c=(struct in*)a;
	struct in *d=(struct in*)b;
	if(c->x!=d->x)
		return c->x - d->x;
	else
		return d->y - c->y;
}


int main()
{
	/**
	  *用法：void qsort(void *base,int nelem,int width,
	  *     int (*fcmp)(const void *,const void *))
	  *各参数：1.待排序数组首地址，2.数组中待排序元素数量，
	  *3.各元素的占用空间大小，4.指向函数的指针
	  *比较函数返回一个int值，如果返回值大于0,则表示a>b;
	  *返回值为0表示a=b,小于0表示a<b(一般返回-1)
	  *此处默认采用从小到大排序（即返回a-b的值）
	  */
	int i;
	char word[4]={'q','e','t','e'};

	qsort(word,4,sizeof(word[0]),charcmp);
	for(i=0;i<4;i++)
	{
		printf("%c ",word[i]);
	}
	printf("\n");

	double nums[5]={3.3,3,2,5,6};
	
	qsort(nums,5,sizeof(nums[0]),doublecmp);
	for(i=0;i<5;i++)
	{
		printf("%f ",nums[i]);
	}
	printf("\n");

	return ;
}
