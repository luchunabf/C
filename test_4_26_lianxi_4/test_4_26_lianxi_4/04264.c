#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i = 0;
	for (; i < 3; i++)//���������������ξ���û��ͬһˮƽ�ߡ�����ѭ�����������������׽����
	{
		for (int j = 0; j < 3; j++)//���������ξ���û��ͬһˮƽ��
		{
			for (int z = 0; z < 3; z++)//�����������ѭ����������ξ���Ȼ������ѭ��������ά��
			{
				for (int l = 0; l < 3; l++)//�����������ѭ����������ξ���Ȼ������ѭ��������ά��
				{
					printf("#");
					/*printf("\n");*/
				}
				printf("\n");
			}
			printf("\n");
		}
		printf("\n");

	}

	system("pause");
	return 0;
}