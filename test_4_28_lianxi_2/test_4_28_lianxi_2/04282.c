#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	char* c[] = { "ENTER", "NEW", "POINT", "FIRST" };//һ���ַ�ָ�����飬���������Ԫ����E,N,P,F���׸��ַ����ĵ�ַ����ַָ��"ENTER", "NEW", "POINT", "FIRST"
	///////����ֱ�Ӵ��"ENTER", "NEW", "POINT", "FIRST"����������ǵĵ�ַ
	char** cp[] = { c + 3, c + 2, c + 1, c };//�����ַ�ָ�����飬����ͬ��
	char*** cpp = cp;//
	printf("%s\n", **++cpp);//point
	printf("%s\n", *--*++cpp + 3);
	printf("%s\n", *cpp[-2] + 3);
	printf("%s\n", cpp[-1][-1] + 1);
	system("pause");
	return 0;
}