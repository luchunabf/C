#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int arr[9] = { 1, 2, 3, 4, 1, 2, 3, 4, 5 };
	int i = 0;
	int count = arr[0];
	for (i = 1; i < 9; i++)
	{
		count = count^arr[i];
	}
	printf("���������ǣ�");
	printf("%d\n", count);
	system("pause");
	return 0;
}