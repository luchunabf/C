#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>


void Countsort(int* arr, int size)
{
	//找数据范围
	int maxValue = arr[0];
	int minValue = arr[0];
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] > maxValue)
			maxValue = arr[i];
		if (arr[i] < minValue)
			minValue = arr[i];
	}

	int range = maxValue - minValue + 1;
	//int* pCount = calloc(range, sizeof(int));
	int* pCount = (int*)malloc(sizeof(int)*range);
	memset(pCount, 0, sizeof(int)*range);
	if (NULL == pCount)
	{
		assert(0);
		return;
	}
	//统计每个元素出现的次数
	for (int i = 0; i < size; ++i)
	{
		pCount[arr[i] - minValue]++;
	}
	//排序（对pCount中的元素进行回收）
	int index = 0;
	for (int i = 0; i < range; ++i)
	{
		while (pCount[i])
		{
			arr[index++] = i + minValue;
			pCount[i]--;
		}
	}
	free(pCount);
}

int main()
{
	int arr[10] = { 1, 0, 3, 2, 0, 1, 3, 2, 1, 2 };
	int size = sizeof(arr) / sizeof(arr[0]);
	Countsort(arr, size);
	for (int i = 0; i < size; ++i)
		printf("%d ", arr[i]);
	printf("\n");
	system("pause");
	return 0;
}