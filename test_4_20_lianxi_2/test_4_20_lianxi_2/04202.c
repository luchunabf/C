#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	/*char pstr[] = "hello bit.";
	char*p = pstr;
	printf("%s\n", pstr);
	printf("%c\n", *p);*/


	char str1[] = "hello bit.";//1��2 ����� ��Ϊ��ջ��������������ͬ�Ĳ���
	char str2[] = "hello bit.";

	char* str3 = "hello bit.";//3��4 ���  ����Ϊָ��ָ���ڳ��������ٵ�ͬһ��ַ
	char* str4 = "hello bit.";

	if (str1 == str2)
		printf("str1 and str2 are same\n");
	else
		printf("str1 and str2 are not same\n");
	if (str3==str4)
		printf("str3 and str4 are same\n");
	else
		printf("str3 and str4 are not same\n");





	system("pause");
	return 0;
}
