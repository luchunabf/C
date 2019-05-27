#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void HeapAdjust(int* array, int size, int parent)
{
	int child = parent * 2 + 1;

	while (child < size)
	{
		// �����Һ����нϴ�ĺ���
		if (child + 1 < size && array[child + 1] > array[child])
			child += 1;

		if (array[child] > array[parent])
		{
			Swap(&array[child], &array[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			return;
		}
	}
}

void HeapSort(int* array, int size)
{
	// 1. ����---��ѣ�С�ѣ�  
	// �ҵ�����һ����Ҷ�ӽڵ�
	int root = ((size - 2) >> 1);
	for (; root >= 0; --root)
		HeapAdjust(array, size, root);

	// 2. ����: ɾ����ʽ
	int end = size - 1;
	while (end)
	{
		Swap(&array[0], &array[end]);
		HeapAdjust(array, end, 0);
		end--;
	}
}

void TestHeap()
{
	//TestHeap1();
	//TestHeap2();
	int array[] = { 2, 3, 8, 0, 9, 1, 7, 4, 6, 5 };
	HeapSort(array, sizeof(array) / sizeof(array[0]));
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
		printf("%d ", array[i]);
}
int main()
{
	/*int arr[6] = { 2, 6, 8, 9, 4, 0 };
	int size = sizeof(arr) / sizeof(arr[0]);
	bubblesort(arr, size);*/
	TestHeap();
	printf("\n");
	system("pause");
	return 0;
}