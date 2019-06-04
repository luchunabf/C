#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//int check_sys()
//{
//	int a = 1;
//	//返回1， 小端
//	//返回0， 大端
//	return *(char*)&a;
//}


//int check_sys()
//{
//	union
//	{
//		char c;
//		int i;
//	}u;
//	u.i = 1;
//	//返回1， 小端
//	//返回0， 大端
//	return u.c;
//}
//
//
//int main()
//{
//	//[01 00 00 00]
//	//[00 00 00 01]
//	int ret = check_sys();
//	if(ret == 1)
//	{
//		printf("小端\n");
//	}
//	else
//	{
//		printf("大端\n");
//	}
//	return 0;
//}
// 
// union Un
// {
// 	char c[5];//5 1  联合中有数组的时候，最大成员计算的时候，如果有数组，计算的是整个数组成员的大小，再来和其他的成员进行比较
// 	int i; //4    4
// };
// 
// int main()
// {
// 	printf("%d\n", sizeof(union Un));
// 	return 0;
// }
//
//结构体，联合 --> 需要内存对齐


#include <stdlib.h>
#include <errno.h>
#include <string.h>
//
//int main()
//{
//	//int a;//4
//	//char arr[5];//5
//	//动态内存开辟
//	//int arr[10] = {0};//40字节
//	int* p = (int*)malloc(40);  //malloc申请开辟内存的单位是字节
//	int i = 0;
//	//assert(p != NULL);
//	if(p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	for(i=0; i<10; i++)
//	{
//		*(p+i) = i;
//	}
//	for(i=0; i<10; i++)
//	{
//		printf("%d ", *(p+i));
//	}
//	//
//	free(p);
//	p = NULL;
//// 	while(1)
//// 	{
//// 		malloc(1);
//// 	}
//	return 0;
//}

// int main()
// {
// 	int arr[10] = {0};
// 	int *p = arr;
// 
// 	free(p);//err
// 	p = NULL;
// 	return 0;
// }
//calloc(size_t num, size_t size):  开辟num个size字节长度的空间，并且初始化为0
//calloc 比 malloc 多了个将开辟的每个字节初始化为0，而且开辟空间个数给定（num）
//int main()
//{
//	int*p = (int*)calloc(10, sizeof(int));//注意calloc还需要给出10（size_t num）,即将10个int型初始化为0
//	int i = 0;
//	int *ptr = NULL;
//
//	if(p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	for(i=0; i<10; i++)
//	{
//		printf("%d ", p[i]);
//	}
//	ptr = realloc(p, 2000*sizeof(int));
//	if(ptr != NULL)
//		p = ptr;
//
//	free(p);
//	p = NULL;
//	return 0;
//}

//常见的动态内存错误：
//void test()
//{
//	int* p = (int*)malloc(10);
//	if(p == NULL)
//	{
//		return;
//	}
//
//	if(1)
//		return;//return 必须在free后面
//	//...
//	free(p);  //函数提前返回，free无效
//	p = NULL;
//}
//
//int main()
//{
//	test();
//	getchar();
//	return 0;
//}

//错误一：对NULL指针的解引用
//void test()
//{
//	int *p = (int *)malloc(INT_MAX/4);
//	//if(p == NULL) //这一步必须进行 空指针判断
//	//{
//	//	return;
//	//}
//	*p = 20;//如果p的值是NULL，就会有问题
//	free(p);
//}
//int main()
//{
//	return 0;
//}


//错误二：对非动态开辟的内存使用free释放
//void test()
//{
//	int a = 10;
//	int *p = &a;
//	free(p);//ok?  错误，因为前面没有动态开辟
//}
//int main()
//{
//	test();
//	return 0;
//}
//

//错误三：对同一块动态内存多次释放（free）
//int main()
//{
//	int *p = (int *)malloc(40);
//	int i = 0;
//	if(p == NULL)
//	{
//		return;
//	}
//	//
//	for(i=0; i<5;i++)
//	{
//		printf("%d ", *(p+i));
//	}
//
//	free(p);
//	free(p);//重复释放
//	p = NULL;
//	return 0;
//}
//错误四：对动态开辟的空间越界访问
//void test()
//{
//	int i = 0;
//	int* p = (int*)malloc(sizeof(int)* 10);
//	if (NULL == p)
//	{
//		exit(EXIT_FAILURE);
//	}
//	for (i = 0; i <= 10; i++)//开辟了10个，这里访问了11个，访问越界
//	{
//		*(p + i) = i;
//	}
//	free(p);
//}
//错误五：使用free释放一块动态内存的一部分（并不是完全释放）
//void test()
//{
//	int* p = (int*)malloc(100);
//	p++;    //p已经走了一步，再去free释放-->Error  p作为所动态内存的首地址不能改变
//	free(p);//p不再指向动态内存的起始位置
//}
//错误六：忘记释放
//void test()
//{
//	int* p = (int*)malloc(100);//只开辟，后面没有对应的free来释放
//	if (NULL == p)
//	{
//		*p = 20;
//	}
//}
//int main()
//{
//	test();
//	while (1);
//}



//题目一
//void GetMemory(char *p)
//{
//	p = (char *)malloc(100);
//}
//void Test(void)
//{
//	char *str = NULL;
//	GetMemory(str);
//	strcpy(str, "hello world");
//	printf(str);
//	free(str);//???  程序崩溃    会造成内存泄漏  形参p是str的一份临时拷贝 形参出函数就不存在了
//	str = NULL;
//}
//int main()
//{
//	Test();
//	return 0;
//}

//修改-->传二级指针
//void GetMemory(char **p)
//{
//	*p = (char *)malloc(100);
//}
//void Test(void)
//{
//	char *str = NULL;
//	GetMemory(&str);
//	strcpy(str, "hello world");
//	printf(str);
//	free(str);//这里就没有问题了（相对于上面）
//	str = NULL;
//}
//int main()
//{
//	Test();
//	system("pause");
//	return 0;
//}
