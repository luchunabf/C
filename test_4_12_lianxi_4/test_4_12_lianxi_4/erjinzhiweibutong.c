#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//��m��n������λ�в�ͬλ�ĸ���
int main()
{
	int m=0, n=0;
	printf("������m��n��ֵ��\n");
	scanf("%d %d", &m, &n);
	int a = m^n;
	int count = 0;
	for (int i = 0; i < 32; i++)
	{
		if (((a >> i) & 1) == 1)
			count++;
	}
	printf("%d\n", count);
	system("pause");
	return 0;
}