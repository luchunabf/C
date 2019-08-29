#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//int main()
//{
//	int i = 0, j = 0;
//	printf("请输入n：\n");
//	int n = 0;
//	scanf("%d", &n);
//	printf("1 \n");
//	for (i = 1; i <= n; i++)
//	{
//		/*for (j = 1; j <= i + 1; j++)*/////////////在这里多循环了一次
//
//		
//		/*{
//			if (j == 1)*/
//				printf("1 ");
//			if (j>1&&j<=i)
//			{
//				for (int k = 1; k <= i-1; k++)
//					printf("%d ", i);
//			}
//			if (j==i+1)
//				printf("1");
//
//		/*}*/
//		printf("\n");
//	}
//
//
//	system("pause");
//	return 0;
//}

int main()
{
	int i = 0;
	printf("请输入n：\n");
	int n = 0;
	scanf("%d", &n);
	printf("1 \n");
	for (i = 1; i <= n; i++)
	{
		printf("1 ");
		for (int k = 1; k <= i - 1; k++)
				printf("%d ", i);
		printf("1");
		printf("\n");
	}
	system("pause");
	return 0;
}
