#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	enum day//枚举类型
	{ 
		mon,
		tues = 4,
		wed,
		thur,
		fri,
		sat,
		sun
	};
	//enum day a = tues;//枚举赋值只能赋枚举里面包含的：mon,tues,wed……
	//printf("%d\n", mon);//0
	//printf("%d\n", tues);//1
	//printf("%d\n", wed);//2
	//printf("%d\n", a);
	printf("%d\n", sizeof(enum day));
	system("pause");
	return 0;
}