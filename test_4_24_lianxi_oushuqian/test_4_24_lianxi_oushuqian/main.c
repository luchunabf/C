#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int arr[10] = { 1, 8, 4, 3, 5, 2, 6, 7, 0, 9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int start = 0;
	int end = sz - 1;
	while (start < end)
	{
		while ((start < end)&&(arr[start] % 2 != 0))
		{
			start++;
		}
		while ((start < end)&&(arr[end] % 2 == 0))
		{
			end--;
		}
		int tmp = arr[start];
		arr[start] = arr[end];
		arr[end] = tmp;

	}
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}