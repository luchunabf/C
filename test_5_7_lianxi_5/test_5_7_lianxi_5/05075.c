#define _CRT_SECURE_NO_WARNINGS 1
//strcat
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
char* my_strcat1(char* dst, const char* src)
{
	char* ret = dst;
	while (*dst++);//如果不在括号内++，则不需要--
	dst--;
	while (*dst++ = *src++);
	return ret;
}
char* my_strcat2(char* dst, const char* src)
{
	assert(dst && src);
	char* ret = dst;
	int count = 0;
	while (dst[count])
	{
		count++;
	}
	dst += count;
	while (*dst++ = *src++);
	return ret;
}
int main()
{
	char str1[20] = "hello";
	char str2[20] = "hello";
	char* str3 = " world";
	char* str4 = " world";
	printf("%s\n", my_strcat1(str1, str3));
	printf("%s\n", my_strcat1(str2, str4));
	system("pause");
	return 0;
}