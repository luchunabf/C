#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//int main()
//{
//	int arr[5] = { 0 };
//	int* p;
//	printf("请输入数组元素：\n");
//	p = arr;
//	for (int i = 0; i < 5; i++)
//	{
//		scanf("%d", &arr[i]);
//    }
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%d ", *p);
//		p++;
//	}
//	system("pause");
//	return 0;
//}
int main()
{
	int arr[5] = { 0 };
	int* p;
	printf("请输入数组元素：\n");
	p = arr;
	for (int i = 0; i < 5; i++)
	{
		//scanf("%d", &arr[i]);
		scanf("%d", p++);//输入的时候默认是元素间是空格
	}
	p = arr;
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", *p++);
		/*printf("%d ", *p);
		p++;*/
	}
	system("pause");
	return 0;
}