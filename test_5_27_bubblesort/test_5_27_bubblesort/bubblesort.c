#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void bubblesort(int* arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int Flag = 0;
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(&arr[j], &arr[j + 1]);
				Flag = 1;
			}
		}
		if (Flag == 0)
			return;
	}
}
int main()
{
	int arr[6] = { 2, 6, 8, 9, 4, 0 };
	int size = sizeof(arr) / sizeof(arr[0]);
	bubblesort(arr, size);
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
	system("pause");
	return 0;
}