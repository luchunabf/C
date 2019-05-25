#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

void mySwap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void bubblesort(int* arr, int size)
{
	int Flag = 0;
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = 0; j < size - 1 - i; ++j)
		{
			if (arr[j] > arr[j + 1])
				mySwap(&arr[j], &arr[j + 1]);
			Flag = 1;
		}
		if (!Flag)
			return;
	}
}
void print(int* arr, int size)
{
	for (int i = 0; i < size; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}
int main()
{
	int arr[11] = { 45, 77, 86, 46, 66, 9, 87, 99, 0, 55, 43 };
	int size = sizeof(arr) / sizeof(arr[0]);
	print(arr, size);
	bubblesort(arr, size);
	print(arr, size);
	system("pause");
	return 0;
}
