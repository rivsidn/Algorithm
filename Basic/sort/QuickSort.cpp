#include <iostream>
#include <algorithm>

#include "data.h"

/*
 * 快速排序.
 */

/*《算法训练营(入门篇)》P65 */
int Partition2(int r[], int low, int high) {
	int i=low,j=high,pivot=r[low];
	while(i<j){
		while(i<j&&r[j]>pivot)
			j--;
		while(i<j&&r[i]<=pivot)
			i++;
		if(i<j)
			std::swap(r[i++],r[j--]);
	}
	if(r[i]>pivot){
		std::swap(r[i-1],r[low]);
		return i-1;
	}
	std::swap(r[i],r[low]);
	return i;
}

/*《算法训练营(入门篇)》P60 */
int Partition(int r[],int low,int high){
	int i=low,j=high,pivot=r[low];
	while(i < j){
		while(i < j && pivot < r[j])
			j--;
		if(i<j) {
			std::swap(r[i],r[j]);
			i++;
		}

		while(i < j && r[i] <= pivot)
			i++;
		if(i<j) {
			std::swap(r[i],r[j]);
			j--;
		}
	}
	return i;
}

void QuickSort(int r[],int low,int high){
	if(low<high){
		int mid=Partition2(r,low,high);
#if 0
		/*
		 * ERROR1: 为什么这样会出问题？
		 *
		 * 快速排序时候，如果执行
		 * QuickSort() -> Partition() -> QuickSort()
		 *
		 * 前后如果不发生变化(也就是第二次调用QuickSort的mid 与
		 * 第一次的high 相同)，会出现无限递归的情况.
		 *
		 * 假设数组为[5 3 5]，low = 0; high = 2;
		 * 此时就会出现这种情况.
		 *
		 * 通过(mid-1) 可以避免这种情况发生.
		 */
		QuickSort(r,low,mid);
#else
		/* OK: 正常情况 */
		QuickSort(r,low,mid-1);
#endif
		QuickSort(r,mid+1,high);
	}
}

bool is_sorted(int A[], int array_size)
{
	for (int i = 0; i < array_size-1; i++) {
		if (A[i] > A[i+1])
			return false;
	}
	return true;
}

int main()
{
	QuickSort(array, 0, array_size-1);
#if 1
	/* 判断排序是否成功 */
	if (is_sorted(array, array_size)) {
		std::cout << "OK!" << std::endl;
	} else {
		std::cout << "ERROR!" << std::endl;
		for (int i = 0; i < array_size; i++) {
			std::cout << array[i] << std::endl;
		}
	}
#endif

	return 0;
}
