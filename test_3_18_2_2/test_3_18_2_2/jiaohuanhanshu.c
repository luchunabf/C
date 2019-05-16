#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//void swap(int *px, int *py)
//{
//	int tmp = 0;
//	tmp = *px;
//	*px = *py;
//	*py = tmp;
//}
//
//int main()
//{
//	int num1;
//	int num2;
//	printf("请输入两个数：");
//	scanf("%d %d", &num1, &num2);
//	swap(&num1, &num2);
//	printf("num1=%d num2=%d\n", num1, num2);
//	system("pause");
//	return 0;
//}



void swap(int *px, int *py)
{
	int tmp = 0;
	tmp = *px;
	*px = *py;
	*py = tmp;
}

int main()
{
	int a, b;
	printf("请输入两个数：\n");
	scanf("%d %d", &a, &b);
	swap(&a, &b);
	printf("交换后的数是\n");
	printf("%d %d\n", a, b);
	system("pause");
	return 0;
}