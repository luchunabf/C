#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//(1)希尔排序比插入排序多了一层gap由size / 3 + 1 ---> 1 的循环
//(2)将插入里面的移动1全部改为移动gap，只有i不需要移动gap（还是++i）
void Shellsort(int* arr, int size)
{
	int gap = size / 3 + 1;
	for (; gap >= 1; --gap)//或者while(gap > 0)
	{
		//for (int i = 1; i < size; ++i)//注意这里是i++，并不是i+gap，因为可以让多组同时去调整排序
		for (int i = gap; i < size; ++i)//////////////注意i是从gap开始的
		{								/////////////因为gap之前的元素属于分了gap组中每组的0号下标元素，而我们插入直接从1号元素开始，因为第一个元素只有一个元素必有序
			int key = arr[i];
			int end = i - gap;
			while (end >= 0 && key < arr[end])
			{
				arr[end + gap] = arr[end];
				end -= gap;
			}
			arr[end + gap] = key;
		}
		//上面while(gap > 0)的时候
		//这里需要多加 gap-=1；
	}
}
int main()
{
	int arr[6] = { 5, 2, 4, 6, 1, 3 };
	int size = sizeof(arr) / sizeof(arr[0]);
	Shellsort(arr, size);
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}