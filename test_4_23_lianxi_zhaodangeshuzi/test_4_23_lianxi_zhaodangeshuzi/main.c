#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define N 5
int main()
{
	int arr[N] = { 0 };
	printf("������������֣�ֻ��һ�����ֳ���һ�Σ��������־��������ε����飬�ûس�������\n");
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);//N�����ûس�������
	}
	//int arr[N] = { 1, 2, 3, 2, 1 };
	int ret = 0;
	for (int i = 0; i < N; i++)
	{
		ret ^= arr[i];
	}
	printf("���������ǣ�%d\n", ret);
	system("pause");
	return 0;
}