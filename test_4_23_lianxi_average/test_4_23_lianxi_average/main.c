#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//int main()
//{
//	int a = 10;
//	int b = 30;
//	int m = a&b;//a��b����������ͬ��λ��
//	int n = a^b;//a��b�������в�ͬ��λ��
//	int average = m + n/2;
//	printf("%d\n", average);
//	system("pause");
//	return 0;
//}

int main()
{
	int a = 10;
	int b = 30;
	
	int average = a+((b-a)>>1);//��������λ������һλ�൱�ڳ���2
	printf("%d\n", average);
	system("pause");
	return 0;
}
