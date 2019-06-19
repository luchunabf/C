#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char buf[] = "This is a test of the memset function";
	printf("before:%s\n", buf);

	memset(buf, '*', 4);
	printf("before:%s\n", buf);

	system("pause");
	return 0;
}