#define _CRT_SECURE_NO_WARNINGS 1
#include <malloc.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
//归并排序

//这一步的目的：将两个有序的子序列按顺序合并成一个有序的序列放入temp中（排序）
void mergeData(int* array, int left,int mid, int right, int *temp)
{
	int begin1 = left, end1 = mid;
	int begin2 = mid, end2 = right;
	int index = left;

	while (begin1 < end1 && begin2 < end2)//将有序序列的元素进行比较
	{
		if (array[begin1] < array[begin2])
			temp[index++] = array[begin1++];
		else
			temp[index++] = array[begin2++];
	}
	//能走下来说明左右子区间至少有一个遍历完了
	while (begin1 < end1)//能走下来说明左右子区间至少有一个遍历完了
		temp[index++] = array[begin1++];
	while (begin2 < end2)//若begin2 < end2说明右边还没有遍历完，继续将剩余的元素放入temp
		temp[index++] = array[begin2++];
}

//这一步是递归（循环）将array分为若干个子区间，并且结合第一步对子区间进行排序
void _mergeSort(int* array, int left, int right, int* temp)
{
	if (right - left > 1)//如果左右之间有元素，继续分割为更小的子区间
	{
		int mid = left + ((right - left) >> 1);//将原数组以中间元素为基准分割成两个子序列
		_mergeSort(array, left, mid, temp);//对左序列进行归并排序(左闭右开)
		_mergeSort(array, mid, right, temp);//对右序列进行归并排序(左闭右开)
		mergeData(array, left, mid, right, temp);//将排序后的左右子序列进行合并，合并后放入temp中
		memcpy(array + left, temp + left, sizeof(int)*(right - left));//将temp中的有序序列拷贝到array中
	}
}

void mergeSort(int* array, int size)//再封装一层，是函数参数个数减少
{
	int* temp = (int*)malloc(sizeof(int)*size);
	if (NULL == temp)
	{
		assert(0);
		return;
	}
	_mergeSort(array, 0, size, temp);
	free(temp);
}

//非递归
void MergeSortNor(int* array, int size)
{
	int* temp = (int*)malloc(sizeof(int)*size);
	if (NULL == temp)
	{
		assert(0);
		return;
	}
	int gap = 1;
	while (gap < size)
	{
		for (int i = 0; i < size; i += 2 * gap)
		{
			int left = i;
			int mid = left + gap;
			int right = mid + gap;
			if (mid >= size)
				mid = size;
			if (right >= size)
				right = size;
			mergeData(array, left, mid, right, temp);
		}
		memcpy(array, temp, sizeof(int)* size);
		gap *= 2;
	}
	free(temp);
}



int main()
{
	int arr[] = { 3, 4, 2, 9, 1, 7, 6, 0, 8, 5 };
	mergeSort(arr, sizeof(arr) / sizeof(arr[0]));

	//MergeSortNor(arr, sizeof(arr) / sizeof(arr[0]));
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
		printf("%d ", arr[i]);
	printf("\n");
	system("pause");
	return 0;
}