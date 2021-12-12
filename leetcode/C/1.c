#include <stdio.h>

/* 整理几种排序算法 */
void merge_sort(int *arr, int len)
{
	int *a = arr;
	int *b = (int *) malloc(len * sizeof(int));
	int seg, start;
	for (seg = 1; seg < len; seg += seg) {
		for (start = 0; start < len; start += seg * 2) {
			int low = start, mid = min(start + seg, len), high = min(start + seg * 2, len);
			int k = low;
			int start1 = low, end1 = mid;
			int start2 = mid, end2 = high;
			while (start1 < end1 && start2 < end2)
				b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
			while (start1 < end1)
				b[k++] = a[start1++];
			while (start2 < end2)
				b[k++] = a[start2++];
		}
		int *temp = a;
		a = b;
		b = temp;
	}
	if (a != arr) {
		int i;
		for (i = 0; i < len; i++)
			b[i] = a[i];
		b = a;
	}
	free(b);
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	int i, j;
	int *ret = malloc(sizeof(int)*2);

	/* 排序 */
	merge_sort(nums, numsSize);

	/* 查找 */
	i = 0; j = numsSize-1;
	if (nums[i] + nums[j] != target) {
		if (nums[i] + nums[j] < target)
			i++;
		else
			j++;
	} else {
		ret[0] = i;
		ret[1] = j;
	}
	*returnSize = 2;
	return ret;
}

int main()
{
	int nums[] = {1, 2, 3, 6};
	int target = 5;
	int returnSize;

	(void)twoSum(nums, sizeof(nums), target, &returnSize);

	return 0;
}
