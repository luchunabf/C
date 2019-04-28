#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	char* c[] = { "ENTER", "NEW", "POINT", "FIRST" };//一级字符指针数组，数组里面的元素是E,N,P,F（首个字符）的地址，地址指向"ENTER", "NEW", "POINT", "FIRST"
	///////并非直接存放"ENTER", "NEW", "POINT", "FIRST"，存的是它们的地址
	char** cp[] = { c + 3, c + 2, c + 1, c };//二级字符指针数组，解释同上
	char*** cpp = cp;//
	printf("%s\n", **++cpp);//point
	printf("%s\n", *--*++cpp + 3);
	printf("%s\n", *cpp[-2] + 3);
	printf("%s\n", cpp[-1][-1] + 1);
	system("pause");
	return 0;
}