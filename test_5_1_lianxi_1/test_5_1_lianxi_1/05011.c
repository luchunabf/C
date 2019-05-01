#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
char* my_strcpy1(char* dst, const char* src)
{
	assert(dst && src);
	char* ret = dst;
	while (*dst++ = *src++);
	return ret;
}
char* my_strcpy2(char* dst, const char* src)
{
	assert(dst && src);
	char* ret = dst;
	//char* ret;  
	//ret=dst;
	while (*src != '\0')
	{
		*dst = *src;
		*dst++;
		*src++;
	}
	if (*src == '\0')
		*dst = *src;
	return ret;
}
int main()
{
	char a[10];
	char* b = "hello";
	printf("%s\n", my_strcpy1(a, b));
	printf("%s\n", my_strcpy2(a, b));
	system("pause");
	return 0;
}