#include <iostream>
#include <vector>

#include "data.h"

/*
 * 归并排序.
 */
void Merge(int A[],int low,int mid,int high)
{
	int *B=new int[high-low+1];
	int i=low,j=mid+1,k=0;
	while(i<=mid && j<=high){
		if(A[i]<=A[j])
			B[k++]=A[i++];
		else
			B[k++]=A[j++];
	}

	while(i<=mid)
		B[k++]=A[i++];
	while(j<=high)
		B[k++]=A[j++];
	for(i=low,k=0;i<=high;i++)
		A[i]=B[k++];
	delete[] B;
}

void MergeSort(int A[],int low,int high)
{
	if (low < high) {
		int mid =(low+high)/2;
		MergeSort(A,low,mid);
		MergeSort(A,mid+1,high);
		Merge(A,low,mid,high);
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
	MergeSort(array, 0, array_size-1);
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
