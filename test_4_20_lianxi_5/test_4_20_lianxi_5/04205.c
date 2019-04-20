#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
void swap1(int* p1, int* p2)
{
	int x = *p1;
	*p1 = *p2;
	*p2 = x;
}
void swap(int** pp1, int** pp2)
{
	int* x = *pp1;
	*pp1 = *pp2;
	*pp2 = x;
}
int main()
{
	int a1 = 0, a2 = 1;
	int* p1 = &a1;
	int* p2 = &a2;
	printf("a1=%d,a2=%d\n", a1, a2);
	swap1(&a1, &a2);
	printf("a1=%d,a2=%d\n", a1, a2);
	printf("\n");
	/*printf("%p\n", &a1);
	printf("%p\n", &a2);*/
	printf("%p\n", p1);
	printf("%p\n", p2);
	printf("\n");
	swap(&p1, &p2);
	printf("%p\n", p1);
	printf("%p\n", p2);


	system("pause");
	return 0;
}