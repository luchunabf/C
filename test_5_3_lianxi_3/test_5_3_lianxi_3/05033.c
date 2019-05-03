#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//模仿qsort的功能实现一个通用的冒泡排序
int cmp1(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}
int cmp2(const void* a, const void* b)
{
	return (*(char*)a - *(char*)b);
}
int cmp3(const void* a, const void* b)
{
	return strcmp((char*)*(int*)a, (char*)*(int*)b);////////?
}
int cmp4(const void* a, const void* b)
{
	return (*(double*)a - *(double*)b) > 0 ? 1 : -1;///////?
}
void myswap( void* p1, void* p2, int size)
{
	for (int i = 0; i < size; i++)
	{
		char tmp = *((char*)p1 + i);
		*((char*)p1 + i) = *((char*)p2 + i);
		*((char*)p2 + i) = tmp;
	}
}
void my_bubble(void* str, int count, int size, int(*cmp)(void* , void* ))////////?????
{
	for (int i = 0; i < count - 1; i++)//////count - 1: 例如10个数字比较9次就够了
	{
		for (int j = 0; j < count - 1; j++)
		{
			if (cmp((char*)str + j * size, (char*)str + (j + 1)*size) > 0)
				myswap((char*)str + j * size, (char*)str + (j + 1)*size, size);
		}
	}
}
int main()
{
	int a1[] = { 5, 7, 9, 6, 3, 8, 4, 2 };
	char a2[] = "ghdfdv";
	char* a3[] = { "bgtf", "gtftf", "dhfrf", "uhgygtf" };
	double a4[] = { 2.0, 6.5, 8.8, 4.2, 9.9 };
	my_bubble(a1, 8, sizeof(int), cmp1);
	my_bubble(a2, 6, sizeof(char), cmp2);
	my_bubble(a3, 4, sizeof(char*), cmp3);
	my_bubble(a4, 5, sizeof(double), cmp4);
	/*my_bubble(a1, 8, 4, cmp1);
	my_bubble(a2, 6, 1, cmp2);
	my_bubble(a3, 4, 4, cmp3);
	my_bubble(a4, 5, 8, cmp4);*/
	for (int i = 0; i < 8; i++)
	{
		printf("%d ", a1[i]);
	}
	printf("\n");
	for (int i = 0; i < 6; i++)
	{
		printf("%c ", a2[i]);
	}
	printf("\n");
	for (int i = 0; i < 4; i++)
	{
		printf("%s ", a3[i]);
	}
	printf("\n");
	for (int i = 0; i < 5; i++)
	{
		printf("%f ", a4[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}