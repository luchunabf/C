#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
struct Test
{
	int Num;
	char *pcName;
	short sDate;
	char cha[2];
	short sBa[4];
}*p;
//����p ��ֵΪ0x00000000.
int main()
{
	printf("%p\n", p + 0x1);//0x00000014      �ṹ��Ĵ�С��20���ֽ�
	printf("%p\n", (unsigned long)p + 0x1);//0x00000001     ��ָ��+1�����ù����ͣ���+1
	printf("%p\n", (unsigned int*)p + 0x1);//0x00000004     ָ��+1������Ϊ�޷������ͣ���+4
	system("pause");
	return 0;
}