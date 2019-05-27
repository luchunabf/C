#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int partion(int* array, int left, int right)
{
	int begin = left;
	int end = right - 1;
	int key = array[right - 1];
	while (begin < end)
	{
		while (begin < end && array[begin] <= key)
			begin++;
		while (begin < end && array[end] >= key)
			end--;
		if (begin != end)
			Swap(&array[begin], &array[end]);
	}
	if (begin != right - 1)
		Swap(&array[begin], &array[right - 1]);
	return begin;
}
void Quicksort(int* array, int left, int right)
{
	if (right - left > 1)
	{
		int div = partion(array, left, right);
		Quicksort(array, left, div);
		Quicksort(array, div + 1, right);
	}
	
}

void TestQuick()
{
	//TestHeap1();
	//TestHeap2();
	int array[] = { 2, 3, 8, 0, 9, 1, 7, 4, 6, 5 };
	TestQuick(array, sizeof(array) / sizeof(array[0]));
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
		printf("%d ", array[i]);
}
int main()
{
	/*int arr[6] = { 2, 6, 8, 9, 4, 0 };
	int size = sizeof(arr) / sizeof(arr[0]);
	bubblesort(arr, size);*/
	TestQuick();
	printf("\n");
	system("pause");
	return 0;
}