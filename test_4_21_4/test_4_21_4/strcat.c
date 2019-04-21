#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* mystrcpy(char* str1, char* str2)
{
	char* str = str1;
	while (*str1 != '\0')
	{
		str1++;
	}
	while (*str2 != '\0')
	{
		*str1++ = *str2++;
	}
	str1 = '\0';
	return str;
}
int main()
{
	char a[1000] = "abcdef";
	char* p = "ghijkl";
	mystrcpy(a, p);
	printf("%s\n", a);
	system("pause");
	return 0;
}