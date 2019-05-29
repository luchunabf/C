#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//建小堆找前k个最大的值
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//向下调整法
void adjustdown(int* arr, int size, int parent)
{
	int child = parent * 2 + 1;
	if (parent < size)
	{
		while (child < size)//走到child = size - 1 的位置（堆末）
		{
			if (child + 1 < size && arr[child + 1] < arr[child])//用child保存两个孩子节点里面较小的
				child += 1;										//升序建大堆找较大的；降序建小堆找较小的
			if (arr[parent] > arr[child])//别再忘了，要调整的节点比较小的大的话，交换   (我的错误之处)
				//反之，建大堆升序的时候，要调整的节点比较大的小的话，交换
			{
				Swap(&arr[child], &arr[parent]);
				parent = child;
				child = parent * 2 + 1;
			}
			else
				return;

		}
	}
}

//建堆：升序建大堆，降序建小堆（这个函数中不影响）
void Heapsort(int* arr, int size, int k)//小堆
{
	int nleaf = (size - 2) >> 1;//找倒数第一个非叶节点
	for (int i = nleaf; i >= 0; --i)//建小堆
		adjustdown(arr, k, i);
	//用剩余N-K个元素依次与堆顶元素进行比较，判断是否需要交换
	for (int j = k; j < size; ++j)
	{
		if (arr[j] > arr[0])//滤一下
		{
			Swap(&arr[j], &arr[0]);
			adjustdown(arr, k, 0);
		}
	}
}
int main()
{
	int arr[] = { 55, 99, 33, 22, 44, 88, 77, 11, 66, 5 };
	//int arr[] = { 5, 9, 3, 7, 6, 2, 4, 0, 1, 8 };
	Heapsort(arr, 10, 4);
	for (int i = 0; i < 4; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}