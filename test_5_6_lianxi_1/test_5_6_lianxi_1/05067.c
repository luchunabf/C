#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
size_t check_sys()
{
	size_t i = 1;
	return (*(char*)&i);
}
int main()
{
	size_t ret = check_sys();
	if (ret == 1)
		printf("Ð¡¶Ë\n");
	else
		printf("´ó¶Ë\n");
	system("pause");
	return 0;
}