#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//int main()
//{
//	char a[] = "work";
//	char *p = a;
//	p++;
//	printf("%c\n", *p);//////////char类型 不能往后走找'\0'
//	system("pause");
//	return 0;
//}
//int main()
{
	

	char *a[] = { "work","at","alibaba"};//char* a[]是一个一级字符指针数组，每个数组存放的指针，指针则代表首元素（首个字符）的地址
	////是一个有三个元素的数组，数组元素中存放的是三个指针，每个指针指向数组首元素的地址
	char **pa = a;//a是首元素的地址，首元素是指针，故a是指针的地址，类型是char**
	//char*** ppa = &pa;//pa的类型还是char** ,只不过a是数组名，故特殊处理，a代表数组的地址的意思
	pa++;
	printf("%s ", *a);//%s输出的是一个单词，遇'\0'结束
	printf("%s ", *(a+1));
	printf("%s\n", *(a+2));

	printf("%s\n", *pa);///////////char*类型(指针) 可以往后走找'\0'
	system("pause");
	return 0;
}