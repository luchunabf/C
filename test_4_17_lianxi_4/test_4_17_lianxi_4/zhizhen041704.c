#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char *p = "abcdef";
	printf("%d\n", sizeof(p));//6改4
	printf("%d\n", sizeof(p + 0));//1改4
	printf("%d\n", sizeof(*p));//1不确定1
	printf("%d\n", sizeof(p[1]));//1
	printf("%d\n", sizeof(&p));//4
	printf("%d\n", sizeof(&p + 1));//4
	printf("%d\n", sizeof(&p[0] + 1));//4
	printf("\n");
	//printf("%d\n", strlen(p));//
	//printf("%d\n", strlen(p + 0));//
	//printf("%d\n", strlen(*p));//
	//printf("%d\n", strlen(p[1]));//
	//printf("%d\n", strlen(&p));//
	//printf("%d\n", strlen(&p + 1));//
	//printf("%d\n", strlen(&p[0] + 1));//

	system("pause");
	return 0;
}