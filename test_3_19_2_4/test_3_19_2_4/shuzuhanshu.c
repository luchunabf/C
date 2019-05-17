#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

void print(int arr[])
{
	int i = 0;
	for (i = 0; i < 7; i++)
		printf("%d ", arr[i]);
}

void init(int *arr, int n)//为什么*arr
{
	for (int i = 0; i < 7; i++)
	arr[i] = n;
	print(arr);//前面定义的函数后面就可以用
}

void empty(int *arr)
{
	
	for (int i = 0; i < 7; i++)
	arr[i] = 0;
	print(arr);
}

void reverse(int *arr)
{
	int left = 0; int right = 6;//逆置的写法
	int tmp;
	while (left <= right)
	{
		tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}
	print(arr);
}

int main()
{
	int arr[7] = {0};
	for (int i = 0; i < 7; i++)
	{
		scanf("%d", &arr[i]);//输入多个数的时候的写法
	}
	printf("\n逆置：\n");
	reverse(arr);
	printf("\n初始化：\n");
	init(arr, 8);
	printf("\n清空：\n");
	empty(arr);
	printf("\n");
	system("pause");
	return 0;
}