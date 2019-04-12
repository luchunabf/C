#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//int main()//输出一个数的二进制位
//{
//	int unsigned n = 0;
//	printf("请输入n：\n");
//	scanf("%d", &n);
//	int a[32] = { 0 };
//	int b[16] = { 0 };
//	for (int i = 0; i < 32; i++)
//	{
//		if (((n >> i) & 1) == 1)
//			a[i] = 1;
//		else
//			a[i] = 0;
//	}
//	for (int i = 31; i >= 0; i--)
//	{
//		printf("%d ", a[i]);
//	}
//	/*printf("%d", a[32]);*/
//	system("pause");
//	return 0;
//}

int main()
{
	int n = 0;
	printf("请输入n：\n");
	scanf("%d", &n);
	int a[16] = { 0 };
	int b[16] = { 0 };
	for (int i = 0; i < 16; i++)//重点理解
	{
		if ((n & 1) == 1)
			a[i] = 1;
		(n >>= 1);
		if ((n & 1) == 1)
			b[i] = 1;
		(n >>= 1);
	}
	for (int i = 15; i >= 0; i--)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	for (int i = 15; i >= 0; i--)
	{
		printf("%d ", b[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}