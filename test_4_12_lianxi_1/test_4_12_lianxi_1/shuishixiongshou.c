#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int count_one_bits(unsigned int value)
{
	// ���� 1��λ�� 
	int count = 0;
	for (int i = 0; i < 32; i++)
	{
		if ((value >> i & 1) == 1)//ÿһλ�Ķ�����������λ�����ұߵ�һλȻ��&1�������1���λλ1������Ϊ0��
			count++;
	}
	return count;
}
int main()
{
	printf("������n��\n");
	int n = 0;
	scanf("%d", &n);
	int ret=count_one_bits(n);
	printf("%d\n", ret);
	system("pause");
	return 0;
}