#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	
	char arr[1024];
	printf("�������ַ�����");
	gets(arr);
	char* p = arr;
	int count = 0;
	while (*p != '\0')
	{
		p++;
		count++;
	}
	printf("%d\n", count);
	printf("%d\n", strlen(arr));

	system("pause");
	return 0;
}