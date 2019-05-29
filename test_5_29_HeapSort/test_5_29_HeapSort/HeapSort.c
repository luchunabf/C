#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//建小堆降序
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
void Heapsort(int* arr,int size)//小堆
{
	int nleaf = (size - 2) >> 1;//找倒数第一个非叶节点
	for (int i = nleaf; i >= 0; --i)//建小堆
		adjustdown(arr, size, i);
	for (int j = size - 1; j >= 0; j--)
	{
		Swap(&arr[0], &arr[j]);//交换根节点和未排序部分数组最后一个的元素
		adjustdown(arr, j, 0);//将根节点出的心交换过来的节点重新调整到相应位置
	}
}
int main()
{
	int arr[] = { 5, 9, 3, 7, 6, 2, 4, 0, 1, 8 };
	Heapsort(arr, 10);
	for (int i = 0; i < 10; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}