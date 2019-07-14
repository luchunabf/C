#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//int main()//逆序输出整数的每一位
//{
//	printf("请输入数：\n");
//	int num = 0;
//	scanf("%d", &num);
//	//////////////////////for (; num >= 0; (num/10))//死循环
//	//////////////////////{
//	//////////////////////	int a= num % 10;
//	//////////////////////	printf("%d ", a);
//	//////////////////////	
//	//////////////////////	/*num = num / 10;*/
//	//////////////////////}
//	while (num>=10)
//	{
//		int a = 0;
//		a = num % 10;
//		printf("%d ", a);
//		num = num / 10;
//	}
//	if (num >= 0 && num < 10)
//	{
//		printf("%d\n", num);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}

int main()//顺序输出整数的每一位
{
	printf("请输入数：\n");
	int num = 0;
	scanf("%d", &num);
	while (1)
	{
		int a = num;
		int count = 0;
		while (a >= 10)
		{
			a = a / 10;
			count++;
		}
		if (a >= 0 && a < 10)
		{
			printf("%d ", a);
		}
		num = num % (int)pow(10, count);
		if (num >= 0 && num < 10)
		{
			printf("%d", num);
			break;
		}
	}
	printf("\n");
	system("pause");
	return 0;
}
