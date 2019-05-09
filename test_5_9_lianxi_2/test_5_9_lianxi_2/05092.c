#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
check_sys()
{
	int i = 1;
	int ret = *(char*)&i;
	if (ret == 1)
		return 1;
	else
		return 0;
}
int main()
{
	int ret = check_sys();
	if (ret == 1)
		printf("Ð¡¶Ë\n");
	else
		printf("´ó¶Ë\n");
	system("pause");
	return 0;
}
