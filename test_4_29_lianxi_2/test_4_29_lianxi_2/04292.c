#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//1 计数器法 2 递归 3 指针-指针
size_t my_strlen1(const char* str)
{
	assert(str != NULL);
	size_t count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}
size_t my_strlen2(const char* str)
{
	assert(str);
	if (*str == '\0')
		return 0;
	/*else*/
	return 1 + my_strlen2(str + 1);
}
//size_t my_strlen3(const char* str)
//{
//	assert(str);
//	const char* p = str;
//	while (*p != '\0')
//	{
//		p++;
//	}
//	return p - str;
//}
size_t my_strlen3(const char* str)
{
	assert(str);
	const char* p = str;
	while (*str != '\0')
	{
		str++;
	}
	return str - p;
}

int main()
{
	char a[] = "abcdef";
	size_t ret1 = my_strlen1(a);
	size_t ret2 = my_strlen2(a);
	size_t ret3 = my_strlen3(a);
	printf("%d\n", ret1);
	printf("%d\n", ret2);
	printf("%d\n", ret3);
	system("pause");
	return 0;
}