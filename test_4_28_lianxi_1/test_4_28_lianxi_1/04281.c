#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//int main()
//{
//	char a[] = "work";
//	char *p = a;
//	p++;
//	printf("%c\n", *p);//////////char���� ������������'\0'
//	system("pause");
//	return 0;
//}
//int main()
{
	

	char *a[] = { "work","at","alibaba"};//char* a[]��һ��һ���ַ�ָ�����飬ÿ�������ŵ�ָ�룬ָ���������Ԫ�أ��׸��ַ����ĵ�ַ
	////��һ��������Ԫ�ص����飬����Ԫ���д�ŵ�������ָ�룬ÿ��ָ��ָ��������Ԫ�صĵ�ַ
	char **pa = a;//a����Ԫ�صĵ�ַ����Ԫ����ָ�룬��a��ָ��ĵ�ַ��������char**
	//char*** ppa = &pa;//pa�����ͻ���char** ,ֻ����a���������������⴦��a��������ĵ�ַ����˼
	pa++;
	printf("%s ", *a);//%s�������һ�����ʣ���'\0'����
	printf("%s ", *(a+1));
	printf("%s\n", *(a+2));

	printf("%s\n", *pa);///////////char*����(ָ��) ������������'\0'
	system("pause");
	return 0;
}