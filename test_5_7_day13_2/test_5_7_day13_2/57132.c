#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define ROW 3
#define COL 3
//���������е����鴫ֵ   
//һά���鴫��ʱ�򣺴���Ԫ�ص�ַ
//					void test(int* arr){}����void test(int* arr[20]){}������[20]���п��ޣ�������˻�Ϊָ�롣
//                  ����ָ�봫��ʱ���*����,void test(int** arr){}
//��ά���鴫��ʱ�򣺴����е�ַ
//					void test(int arr[3][5]){} ���� void test(int arr[][5]){}����������ʡ�ԣ����� void test(int (*arr)[5]){}����ʱ5��ʾ�У�
int find_num(int arr[ROW][COL], int num)//Ҫ��Ҫ*??  �����ԣ��в�ͬ����ʽ�ı��ʽ�����Ǵ��Ķ������е�ַ
{
	int row = 0;
	int col = COL - 1;
	while (row < ROW && col > 0)
	{
		if (num > arr[row][col])
			row++;
		else if (num < arr[row][col])
			col--;
		else if (num == arr[row][col])
			return 1;
	}
	return  0;
}
int main()
{
	int arr[ROW][COL] =
	{
		1, 2, 3,
		2, 3, 4,
		3, 4, 5
	};
	int ret = find_num(arr, 5);
	if (ret == 1)
		printf("�ҵ���\n");
	else
		printf("�Ҳ���\n");
	system("pause");
	return 0;
}