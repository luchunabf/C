#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int my_strlen1(char* str)//���淨����ַ
{
	int count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}

int my_strlen2(char* str)//�ݹ鷨
{
	if (*str == '\0')
		return 0;
	else
		return 1 + my_strlen2(str + 1);
}

int my_strlen3(char* str)//��ַ-��ַ��
{
	char* p = str;//����Ԫ�صĵ�ַ����p
	while (*p != '\0')
	{
		p++;
	}
	return p - str;
}
int main()
{
	char arr[] = "abcdef";
	int ret1 = my_strlen1(arr);
	int ret2 = my_strlen2(arr);
	int ret3 = my_strlen3(arr);

	printf("%d\n", ret1);
	printf("%d\n", ret2);
	printf("%d\n", ret3);

	system("pause");
	return 0;
}