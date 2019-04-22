#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int my_strlen1(char* str)//常规法：地址
{
	int count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}

int my_strlen2(char* str)//递归法
{
	if (*str == '\0')
		return 0;
	else
		return 1 + my_strlen2(str + 1);
}

int my_strlen3(char* str)//地址-地址法
{
	char* p = str;//将首元素的地址赋给p
	while (*p != '\0')
	{
		p++;
	}
	return p - str;
}
int main()
{
	char arr[] = "abcdef";
	int ret1 = my_strlen1(arr);
	int ret2 = my_strlen2(arr);
	int ret3 = my_strlen3(arr);

	printf("%d\n", ret1);
	printf("%d\n", ret2);
	printf("%d\n", ret3);

	system("pause");
	return 0;
}