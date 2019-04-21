#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int a[3][4] = { 0 };
	printf("%d\n", sizeof(a)); // 48   a表示整个数组的大小
	printf("%d\n", sizeof(a[0][0])); // 4  第一个元素
	printf("%d\n", sizeof(a[0])); // 16  此时a[0]为变量名，特殊处理，求得的是第一行的数组大小
	printf("%d\n", sizeof(a[0] + 1)); // 4  这里a[0]没有特殊处理，非变量名，a[0]表示的是首行首元素的地址,a[0]+1则表示的是首行第二个元素的地址
	printf("%d\n", sizeof(*(a[0] + 1))); // 4   同上，对首行第二个元素解引用则为第二个元素
	printf("%d\n", sizeof(a + 1)); // 4   a是二维数组的变量名，表示首元素的地址，二维数组首元素是首行元素，故a表示的是首行元素的地址（数组指针），a+1 则表示首行元素加一行，即第二行元素的地址。
	printf("%d\n", sizeof(*(a + 1))); // 16  同上，（a+1）表示第二行元素的地址，解引用则为第二行元素（数组）。
	printf("%d\n", sizeof(&a[0] + 1)); // 4  此时a[0]是变量名，&a[0]表第一行元素的地址（数组指针），&a[0]与a（二维数组变量名）等价。&a[0]+1 则表示的是第二行的地址（a+1）。
	printf("%d\n", sizeof(*(&a[0] + 1))); // 16  同上，对第二行元素的地址解引用则为第二行元素。
	printf("%d\n", sizeof(*a)); // 16   a（二维数组变量名）表示的是首元素地址，二维，所以是首行元素的地址，解引用（*a）是首行元素。
	printf("%d\n", sizeof(a[3])); //16  //此时a[3]是变量名，表整行数组
	/*printf("%d %d %d %d\n", a[3][0], a[3][1], a[3][2], a[3][2]);*/

	/*printf("%p\n", a[0]);
	printf("%p\n", a[0] + 1);//+4
	int* p0 = a[0];*/

	//printf("%p\n", a);
	//printf("%p\n", a + 1);//+16
	//int(*p2)[4] = a;

	//&+数组名 时表示的是取整个数组的地址，数组名表示整个数组，而非表示取地址的地址
	// 二维数组中，a[i]就是第i行的数组名
	//printf("%p\n", a[0]); // a[0]是第一行首元素的地址
	//printf("%p\n", a[0] + 1);//+4
	//int* p0 = a[0];

	//printf("%p\n", &a[0]); // &a[0]是第一行地址 数组指针
	//printf("%p\n", &a[0] + 1);//+16
	//int(*p1)[4] = &a[0];
	//一维数组
	//int arr[4] = { 0 };
	//printf("%p\n", arr);
	//printf("%p\n", &arr);
	//printf("%p\n", arr+1);//+4 （+1个元素）
	//printf("%p\n", &arr+1);//+16 （+1个数组）
	system("pause");
	return 0;
}