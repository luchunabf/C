#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int bin_search(int arr[], int left, int right, int key)
{
	int mid = 0;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (arr[mid] < key)
			left = mid + 1;
		else if (arr[mid]>right)
			right = mid - 1;
		else
			return mid;
	}
	return -1;
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int key = 7;
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0])-1;
	int mid = 0;
	
	while (1)
	{
		int ret = bin_search(arr, left, right, key);
		if (ret == -1)
			printf("找不到");
		else
		{
			printf("找到了，下标是%d\n", mid);
			break;
		}

	}
	


	system("pause");
	return 0;
}