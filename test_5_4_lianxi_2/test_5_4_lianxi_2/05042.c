#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int check_sys()
{
	int i = 1;
	char* p = (char*)&i;
	return (*p);
}
int check_sys1()
{
	int i = 1;
	return (*(char*)&i);
}
int main()
{
	int ret = check_sys();
	if (ret == 1)
		printf("С��\n");
	else
		printf("���\n");
	int ret1 = check_sys1();
	if (ret1 == 1)
		printf("С��\n");
	else
		printf("���\n");
	system("pause");
	return 0;
}