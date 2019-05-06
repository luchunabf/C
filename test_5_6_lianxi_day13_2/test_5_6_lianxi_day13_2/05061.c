#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define ROW 3
#define COL 3
int findYs(int arr[ROW][COL], int num)
{
	int row = 0;
	int col = COL - 1;
	while (row < ROW && col >= 0)
	{
		if (num > arr[row][col])
			row++;
		else if (num < arr[row][col])
			col--;
		else if (num == arr[row][col])
			return 1;
	}
	return 0;
}
void test()
{
	int arr[ROW][COL] =
	{
		1, 2, 3,
		4, 5, 6,
		7, 8, 9
	};
	int ret = findYs(arr, 5);
	if (ret == 1)
		printf("找到了\n");
	else
		printf("没找到\n");
}
int main()
{
	test();
	system("pause");
	return 0;
}