#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[3][2] = { (0, 1), (2, 3), (4, 5) };//���ű��ʽ�е�ֵ�����һ�����ź����ֵ����a[3][2]={1,3,5}
	int* p;
	p = a[0];//��ά����a[0]�������е�������
	printf("%d\n", p[0]);//p[0]��(*(p+0)) ��p������0�����ʹ�С(int*)
	printf("%d\n", p[1]);//p[1]��(*(p+1)) ��p������1�����ʹ�С(int*)
	printf("%d\n", p[2]);//p[2]��(*(p+2)) ��p������2�����ʹ�С(int*)
	system("pause");
	return 0;
}