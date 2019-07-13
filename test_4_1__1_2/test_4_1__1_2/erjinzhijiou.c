#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int arr[32];
	int m = 0, i = 0, count = 0;
	printf("请输入数：\n");
	scanf("%d", &m);
	for (i = 0; m != 0; i++)
	{
		arr[i] = m % 2;
		m = m / 2;
		count = i + 1;
	}
	for (; count < 32; count++)
	{
		arr[count] = 0;
	}
	printf("转换为二进制数后的奇数位为：\n");
	for (i = 30; i >= 0; i -= 2)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	printf("转换为二进制数后的偶数位为：\n");
	for (i = 31; i >= 0; i -= 2)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}
//int main()//输出一个数的二进制数
//{
//	int num = 0, i = 0, j = 0;
//	int arr[32] = { 0 };
//	printf("输入数\n");
//	scanf("%d", &num);
//	for (i = 0; num != 0; i++)
//	{
//		arr[i] = num % 2;
//		num = num / 2;
//		j = i + 1;//j是i循环完的数+1
//	}
//	for (; j < 32; j++)
//	{
//		arr[j] = 0;
//	}
//	printf("该数的二进制序列为：\n");
//	for (int k = 31; k >= 0; k--)// >不能少
//		printf("%d ", arr[k]);
//	printf("\n");
//
//	system("pause");
//	return 0;
//}