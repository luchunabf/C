#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[5][5];
	int(*p)[4];//����ָ�룬������Ϊ4�������������
	p = a;//a������ָ�룬����int(*p)[5];ǿת��p=(int(*)[4])a
	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);//18-22=-4   (-4)�ĵ�ַ��FF FF FF FC   (-1)�ĵ�ַʮ������ȫΪF��FF FF FF FF
	system("pause");//p��a��4�����󣬼�16���ֽ�
	return 0;
}