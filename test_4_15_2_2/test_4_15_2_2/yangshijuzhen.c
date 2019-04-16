#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

#define ROW 3
#define COL 3

int FindYs(int arr[ROW][COL], int num)
{
	int row = 0;
	int col = COL - 1;
	while (row < ROW && col >= 0)
	{
		if (num > arr[row][col])//�������˵������û�У�����һ�в���
		{
			row++;
		}
		else if (num < arr[row][col])//���С��˵������û�У���ǰһ�в���
		{
			col--;
		}
		else if (num == arr[row][col])
		{
			return 1;//�ҵ�����1
		}
	}
	return 0;//ѭ������û���ҵ�������0
}
void test()
{
	int arr[ROW][COL] =
	{
		1, 2, 3,
		4, 5, 6,
		7, 8, 9,
	};
	int ret = FindYs(arr, 5);
	if (1 == ret)
	{
		printf("�ҵ���\n");
	}
	else
	{
		printf("û�ҵ�\n");
	}
}
int main()
{
	test();
	system("pause");
	return 0;
}



//�Լ�д��
//int FindYs(int arr[ROW][COL], int num)
//{
//	int row = 0;
//	int col = 0;
//	for (row = 0; row < ROW; row++)
//	{
//		for (col = 0; col < COL; col++)
//		{
//			if (num == arr[row][col])
//				return 1;
//		}
//	}
//	return 0;
//}
//void test()
//{
//	int arr[ROW][COL] =
//	{
//		1, 2, 3,
//		4, 5, 6,
//		7, 8, 9,
//	};
//	int ret = FindYs(arr, 5);
//	if (1 == ret)
//	{
//		printf("�ҵ���\n");
//	}
//	else
//	{
//		printf("û�ҵ�\n");
//	}
//}
//int main()
//{
//	test();
//	system("pause");
//	return 0;
//}