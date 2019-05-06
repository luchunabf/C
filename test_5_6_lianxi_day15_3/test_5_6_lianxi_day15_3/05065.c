#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
char* my_strcpy(char* dst,const char* src)
{
	assert(dst && src);
	char* ret = dst;
	while (*dst++ = *src++);
	return ret;

}
int main()
{
	char str1[20] = "hello";
	char* str2 = "world";
	printf("%s\n", my_strcpy(str1, str2));
	system("pause");
	return 0;

}