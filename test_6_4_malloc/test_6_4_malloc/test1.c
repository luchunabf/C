#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>

//题目二：
//char *GetMemory(void)
//{
//	char p[] = "hello world";//局部变量的开辟是在栈上（出函数则自动销毁）
//	return p;				 //返回栈空间上的地址，属于访问非法地址 +static （静态区）就OK
//}
//void Test(void)
//{
//	char *str = NULL;
//	str = GetMemory();
//	printf(str);
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

//
//int* Test()
//{
//	int a = 10;
//	return &a;//返回的是形参的地址，形参出函数即销毁，无意义
//}
//int main()
//{
//	int *p = Test();
//	printf("hehe\n");
//	printf("%d\n", *p);
//	return 0;
//}
//
//int Test()
//{
//	int a = 10;
//	return a;
//}
//
//int main()
//{
//	int b = Test();
//	return 0;
//}
//题目三：
//void GetMemory2(char **p, int num)
//{
//	*p = (char *)malloc(num);
//}
//void Test(void)
//{
//	char *str = NULL;
//	GetMemory2(&str, 100);
//	strcpy(str, "hello");
//	printf(str);
//	//free(str);//不能忘记释放 而且这里都是传址操作，传值的话并不能将str赋为空
//	//str = NULL;
//}
//int main()
//{
//	Test();
//	return 0;
//}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//题目四：
//void Test(void)
//{
//	char *str = (char *) malloc(100);
//	strcpy(str, "hello");
//	free(str);//这里已经释放了
//	//str = NULL;
//	if(str != NULL)//再去访问 就属于非法访问了   free后面加上str = NULL;就不算非法访问，但是已经为空了，没有意义
//	{
//		strcpy(str, "world");
//		printf(str);
//	}
//}
//
//int main()
//{
//	Test();
//	return 0;
//}
//
//int main()
//{
//	char *p = "abcdef";
//	*p = 'w';
//	return 0;
//}


//柔性数组：结构中的最后一个元素允许是位置大小的数组--即柔性数组
//struct S
//{
//	int a;
//	char arr[0];//柔性数组:0可写可不写，表示大小未知
//};
//
//struct B
//{
//	int a;//4
//	char* arr;//4  指针形式给出的话大小就是4，所以必须是数组形式 char arr[]形式
//};
//
//void test2()
//{
//	char *ptr = NULL;
//	struct B* ps = (struct B*)malloc(sizeof(struct B));
//	ps->arr = (char *)malloc(100*sizeof(char));
//
//	ps->a = 20;
//	strcpy(ps->arr, "abcdef");
//	printf("%s\n", ps->arr);
//	printf("%d\n", ps->a);
//	ptr = realloc(ps->arr, 200s*sizeof(char));
//	if(ptr != NULL)
//		ps->arr = ptr;
//	//...
//	free(ps->arr);
//	ps->arr = NULL;
//	free(ps);
//	ps = NULL;
//}
//
//void test1()
//{
//	struct S* ps = (struct S*)malloc(sizeof(struct S)+100*sizeof(char));
//	struct S* ptr = NULL;
//	ps->a = 20;
//	strcpy(ps->arr, "abcdef");
//	printf("%s\n", ps->arr);
//	printf("%d\n", ps->a);
//
//	ptr = realloc(ps, sizeof(struct S)+200*sizeof(char));
//	if(ptr  != NULL)
//		ps = ptr;
//	//....
//	free(ps);
//	ps = NULL;
//}
//
//int main()
//{
//	test2();
//	return 0;
//}
//