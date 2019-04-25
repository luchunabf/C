#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int arr[10] = { 1, 6, 3, 9, 5, 4, 7, 8, 2, 0 };
	int sz = sizeof(arr) / sizeof(int);
	int start = 0;
	int end = sz - 1;
	while (start < end)
	{
		while ((start < end) && (arr[start] % 2 != 0))
			start++;
		while ((start < end) && (arr[end] % 2 == 0))
			end--;
		if (start < end)
		{
		arr[start] = arr[start]^arr[end];
		arr[end] = arr[start] ^ arr[end];
		arr[start] = arr[start] ^ arr[end];
		}
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}