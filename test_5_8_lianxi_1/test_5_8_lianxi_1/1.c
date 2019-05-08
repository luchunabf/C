#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//strcpy
char* my_strcpy1(char* dst, const char* src)
{
	assert(src && dst);
	char* ret = dst;
	while (*dst++ = *src++);
	return ret;
}
char* my_strcpy2(char* dst, const char* src)
{
	assert(src && dst);
	char* ret = dst;
	while (*src != '\0')
	{
		*dst = *src;
		dst++;
		src++;
	}
	if (*src == '\0')
		*dst = *src;
	return ret;
}
int main()
{
	char str1[20] = { 0 };
	char* str2 = "I Love you";
	char* str3 = "forever";
	char* strstr = my_strcpy1(str1, str2);
	printf("%s ", strstr);
	printf("%s\n", my_strcpy2(str1, str3));
	system("pause");
	return 0;
}