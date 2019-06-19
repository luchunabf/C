#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include<stdlib.h>
#include<assert.h>
//#include <string.h>


char* my_strcpy(char* dest, const char* src)
{
	assert(dest && src);
	char* ret = dest;
	
	while (*dest++ = *src++);
	return ret;
}

char* my_strcat(char* dest, const char* src)
{
	assert(dest && src);
	char* ret = dest;
	while (*dest)
	{
		*dest++;
	}
	while (*dest++ = *src++);

	return ret;
}

char* my_strchr(const str, int c)
{
	assert(str);
	char* ret = (char*)str;
	while (*ret)
	{
		if (*ret == c)
			return ret;
		ret++;
	}
	return NULL;
}

int main()
{
	char *str1 = "hello";
	char str2[10] = {0};
	my_strcpy(str2, str1);
	printf("%s\n", str2);

	my_strcat(str2, " world");
	printf("%s\n", str2);

	char* ret = my_strchr(str2, 'l');
	//printf("%c\n", ret);
	printf("%s\n", ret);

	system("pause");
	return 0;
}