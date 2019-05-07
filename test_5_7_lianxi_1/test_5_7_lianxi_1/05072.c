#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
//模拟实现strcpy
char* my_strcpy1(char* dst, const char* src)
{
	assert(dst && src);
	char* ret = dst;
	while (*dst++ = *src++);//当走到'\0'时先赋值，后判断
	return ret;
}
char* my_strcpy2(char* dst, const char* src)
{
	assert(src && dst);
	char* ret = dst;
	while (*src != '\0')//当走到'\0'时，先判断后赋值
	{
		*dst = *src;
		src++;
		dst++;
	}
	if (*src == '\0')
		*dst = *src;
	return ret;
}
int main()
{
	char str1[20] = { 0 };
	char *str2 = "hello world";
	printf("%s\n", my_strcpy1(str1, str2));
	printf("%s\n", my_strcpy2(str1, str2));
	system("pause");
	return 0;
}