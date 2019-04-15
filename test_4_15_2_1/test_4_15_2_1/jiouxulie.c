#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
void rank(int* arr,int sz)
{
	int i = 0;
	int j = 0;
	int arr1[1024] = { 0 };
	int end = sz-1;
	for (i = 0; i < sz; i++)
	{
		
		if (arr[i] % 2 == 1)
		{
			arr1[j] = arr[i];
			j++;
		}
		else
		{
			arr1[end] = arr[i];
			end--;
		}

	}
	for (int k = 0; k < sz; k++)
	{
		printf("%d ", arr1[k]);
	}
	printf("\n");
}
int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	rank(arr,10);
	system("pause");
	return 0;
}