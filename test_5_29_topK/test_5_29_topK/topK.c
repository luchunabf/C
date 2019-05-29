#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//建大堆找前k个最小的值
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void adjustdown(int* arr, int size, int parent)//建大堆
{
	int child = parent * 2 + 1;
	if (parent < size)
	{
		while (child < size)
		{
			if (child + 1 < size && arr[child] < arr[child + 1])//建大堆找里面较大的
				child += 1;
			if (arr[parent] < arr[child])//（建大堆）较大的比根节点大的话，交换   （建小堆）较小的比根节点小的话，交换
			{
				Swap(&arr[parent], &arr[child]);
				parent = child;
				child = parent * 2 + 1;
			}
			else
				return;
		}
	}
}

void topK(int* arr, int size, int k)
{
	//int N = sizeof(arr) / sizeof(arr[0]);
	//取数组前k个元素建堆
	int root = (k - 2) >> 1;//找倒数一个非叶节点
	for (; root >= 0; --root)
		adjustdown(arr, k, root);
	
	//用剩余N-K个元素依次与堆顶元素进行比较，判断是否需要交换
	for (int i = k; i < size; ++i)
	{
		if (arr[i] < arr[0])//滤一下
		{
			Swap(&arr[i], &arr[0]);
			adjustdown(arr, k, 0);
		}
	}
}


int main()
{
	int arr[10] = { 55, 99, 33, 22, 44, 88, 77, 11, 66, 5 };
	topK(arr, 10, 4);
	for (int i = 0; i < 4; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}





