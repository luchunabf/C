#define _CRT_SECURE_NO_WARNINGS 1
//理解 
//一级指针
//二级指针
//指针和数组
//指针数组
#include<stdio.h>
#include<stdlib.h>
//一级指针
//指针是编程语言中的一个对象，它的值直接指向存在电脑存储器另一个地方的值，
//由于通过地址能找到所需的变量单元，可以说，地址指向该变量单元。
//因此，将地址形象化的称为“指针”，意思是通过它能找到以它为地址的的内存单元
//指针是变量，用来存放地址的变量
//int main()
//{
//	int a = 10;
//	int* p = &a;
//	printf("&a ==> %p\n", p);
//	system("pause");
//	return 0;
//}
//二级指针
//指针变量也是变量，是变量就有地址，而指针变量的地址就是二级指针
int main()
{
	int a = 10;
	int* p = &a;
	int** pp = &p;
	printf("&a ==> %p\n", p);
	printf("&p ==> %p\n", pp);
	system("pause");
	return 0;
}
//指针和数组
//数组名代表的是数组首元素的地址，使用指针来访问数组某元素
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
//	int *p = arr;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("&arr[%d]=%p <===> p+%d=%p\n", i, &arr[i], i, (p + i));
//	}
//	system("pause");
//	return 0;
//}
//p+i其实计算的是数组arr下标为i的地址
//可以直接访问
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int* p = arr;
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	system("pause");
//	return 0;
//}
//指针数组
//指针数组是数组，用来存放指针的数组。
//例如 int* arr[5];表示的是arr数组，这个数组有5个int* (指针)元素
//数组指针
//数组指针是指针，指向数组的指针。
//例如 int(*p)[10]=&arr(&+数组名：“整个数组的地址”);表示的是数组指针，指向拥有10个元素的整型数组的指针
//int main()
//{
//	int arr[5] = { 1, 2, 3, 4, 5 };
//	int(*p1)[5] = &arr;//(整形)数组指针
//	//int* p2 = &arr;  类型不同，前面是整形指针(int*),后面是数组指针(int(*)[5])
//	int* arr1[5] = { &arr[0], &arr[1], &arr[2], &arr[3], &arr[4] };//指针数组
//	int*(*p2)[5] = &arr1;//(指针)数组指针
//
//	//int (*p1)[5] = &arr;//(整形)数组指针
//	//int*(*p2)[5] = &arr1;//(整形指针)数组指针
//	return 0;
//}

