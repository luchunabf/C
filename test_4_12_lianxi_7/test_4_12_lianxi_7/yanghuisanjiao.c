#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//�������
#define N 20//��û�зֺţ�û��
int main()
{
	int arr[N][N] = { 0 };
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			arr[i][0] = arr[i][i] = 1;
			/*printf("%d", arr[i][0]);*///////�Լ��Ĵ���
		}
		/*printf("\n");*/
	}
	for (int i = 2; i < N; i++)
	{
		for (int j = 1; j < i; j++)
		{
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
			
		}
		/*printf("\n");*/
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("%-5d ", arr[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
	
}