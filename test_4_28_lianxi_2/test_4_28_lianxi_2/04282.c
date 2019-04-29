#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	char* c[] = { "ENTER", "NEW", "POINT", "FIRST" };//一级字符指针数组，数组里面的元素是E,N,P,F（首个字符）的地址，地址指向"ENTER", "NEW", "POINT", "FIRST"
	///////并非直接存放"ENTER", "NEW", "POINT", "FIRST"，存的是它们的地址
	char** cp[] = { c + 3, c + 2, c + 1, c };//二级字符指针数组，解释同上
	char*** cpp = cp;//三级指针，指针的地址的地址
	printf("%s\n", **++cpp);//POINT   对指针解引用(*)的时候直接就指向所指向的元素
	printf("%s\n", *--*++cpp + 3);//ER  ++cpp的时候即cpp（三级指针：指针的指针的指针）已经改变，要特别注意，并且注意优先级，*的优先级高于+（加）
	printf("%s\n", *cpp[-2] + 3);//ST  cpp[-2]即(*(cpp-2)),但是这里cpp指向没有变 
	printf("%s\n", cpp[-1][-1] + 1);//EW 这道题主要是把图画清楚，就没有问题
	system("pause");
	return 0;
}