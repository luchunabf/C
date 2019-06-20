#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>


//πÈ≤¢≈≈–Ú
#include <malloc.h>
#include <assert.h>
#include <string.h>

void MergeData(int* array, int left, int mid, int right, int* temp)
{
	int begin1 = left, end1 = mid;
	int begin2 = mid, end2 = right;
	int index = left;

	while (begin1 < end1 && begin2 < end2)
	{
		if (array[begin1] < array[begin2])
			temp[index++] = array[begin1++];
		else
			temp[index++] = array[begin2++];
	}

	while (begin1 < end1)
		temp[index++] = array[begin1++];

	while (begin2 < end2)
		temp[index++] = array[begin2++];
}

void _MergeSort(int* array, int left, int right, int* temp)
{
	if (right - left > 1)
	{
		int mid = left + ((right - left) >> 1);
		// [left, mid)
		// [mid, right)
		_MergeSort(array, left, mid, temp);
		_MergeSort(array, mid, right, temp);
		MergeData(array, left, mid, right, temp);
		memcpy(array + left, temp + left, sizeof(int)*(right - left));
	}
}

void MergeSort(int* array, int size)
{
	int* temp = (int*)malloc(sizeof(int)*size);
	if (NULL == temp)
	{
		assert(0);
		return;
	}

	_MergeSort(array, 0, size, temp);

	free(temp);
}

//∑«µ›πÈ
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
			MergeData(array, left, mid, right, temp);
		}

		memcpy(array, temp, sizeof(int)*size);
		gap *= 2;
	}

	free(temp);
}

int main()
{
	int arr[] = { 3, 4, 2, 9, 1, 7, 6, 0, 8, 5 };
	MergeSort(arr, sizeof(arr) / sizeof(arr[0]));

	//MergeSortNor(arr, sizeof(arr) / sizeof(arr[0]));
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
		printf("%d ", arr[i]);
	printf("\n");
	system("pause");
	return 0;
}