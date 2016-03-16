#include<stdio.h>

/**
  *Note: The returned array must be malloced, assume caller calls free().
  */
int* twoSum(int* nums, int numsSize, int target)
{

}

int main()
{
	int nums[100]={2,11,15,3,5,7};
	int* resArry=twoSum(nums,6,9);
	printf("%d %d\n",*resArry,*(++resArry));
	free(resArry);
	return 0;
}
