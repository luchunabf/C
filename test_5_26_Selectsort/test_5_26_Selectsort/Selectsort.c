#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//—°‘Ò≈≈–Ú
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void Selectsort(int* arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int maxpos = 0;
		//int maxpos = i;

		for (int j = 1; j < size - i; j++)
		//for(int j = i; j <= size - 1 - i; j++)
		{
			if (arr[maxpos] < arr[j])
				maxpos = j;
		}
		if (maxpos != size - 1 - i)
			Swap(&arr[maxpos], &arr[size - 1- i]);
	}
}
int main()
{
	int arr[6] = { 5, 2, 4, 6, 1, 3 };
	int size = sizeof(arr) / sizeof(arr[0]);
	Selectsort(arr, size);
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}