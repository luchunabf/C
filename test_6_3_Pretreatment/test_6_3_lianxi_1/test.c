#define _CRT_SECURE_NO_WARNINGS 1
//#pragma warning(disable: 4996)//和上面的作用相同
#include <stdio.h>


int main()
{
	FILE* pf = fopen("log.txt", "w");
	int i = 0;
	if(pf  == NULL)
	{
		return 0;
	}
	for(i=0; i<10; i++)
	{
		fprintf(pf, "FILE:%s LINE:%d DATE:%s TIME:%s i = %d\n", __FILE__, __LINE__,__DATE__, __TIME__, i);
	}
	//printf("%d\n", __STDC__);//如果编译器遵循ANSI C，其值为1，否则未定义
	fclose(pf);
	pf = NULL;
	return 0;
}



//<鸟哥的linux私房菜>


//ls
//cd
//pwd
//mkdir
//rm 
//gcc
//vim




//预处理
//#define
//#include
//#pragma
//预处理指令


//#define reg register
//#define do_forever for(;;)
//
//for(;;)//死循环
int main()
{
	register int num = 0;
	reg int num2 = 0;
	do_forever;
	return 0;
}


#define CASE break;case

int main()
{
	int age = 0;
	switch(age)
	{
	case 1:
	CASE 2:
	CASE 3:
	CASE 4:
	}
	return 0;
}

#define MAX 1000;

int main()
{
	//int num = 1000;;
	//printf("%d\n", MAX);
	int num = 0;
	if(1)
		num = MAX;
	else
		num = -1;

	return 0;
}

#define SQUARE(num+3) ((x)*(x))
#define MAX 100

int main()
{
	int num = 10;
	printf("MAX=%d", 100);
	printf("%d\n", SQUARE(MAX+3));//43
	//printf("%d\n", num*num);
	return 0;
}


#define MAX(x,y) ((x)>(y)?(x):(y))
 
#define PRINT(x, format) printf("the value of "#x" is "format"\n", x)
 //#x:把一个宏参数变成对应的字符串  #x 在打印时就是"x"
 int main()
 {
 	int a = 10;
 	int b = 20;
	float f = 3.0;

 	//printf("the value of a is %d\n", a);
 	PRINT(a, "%d");//和上面的打印效果一致
	//printf("the value of ""a"" is %d\n", a);
 	PRINT(b, "%d");//和上面的打印效果一致
	//printf("the value of ""b"" is %d\n", b);
	PRINT(f, "%f");//和上面的打印效果一致
 	return 0;
 }
 


int main()
{
	printf("hello bit\n");
	printf("hello ""bit\n");//printf()中的参数可以使多个双引号，会直接打印在一行

	return 0;
}


#define CAT(X, Y) X##Y
//##：把位于它两边的符号合成一个符号，它允许宏定义从分离的文本片段创建标识符
int main()
{
	int num51 = 100;
	printf("%d\n", CAT(num, 51));//num ## 51 即把他们合成起来为 num51 （一个整体符号）
	return 0;
}


#define MAX(X, Y) ((X)>(Y)?(X):(Y))
//宏外面的整体也需要括号，不能丢，否则会导致操作符优先级问题

int Max(int x, int y)
{
	return x>y?x:y;
}

int main()
{
	int a = 10;
	int b = 20;
	int max1 = Max(a, b);
	int max2 = MAX(a, b);
	return 0;
}

#include <stdio.h>

#define MALLOC(num, type) (type*)malloc(num*sizeof(type))
#define SIZEOF(ARR) sizeof(ARR)/sizeof(ARR[0])

int main()
{
	int arr[10] = {0};
	int sz = SIZEOF(arr);
	printf("%d\n", sz);
	//int sz = sizeof(arr)/sizeof(arr[0]);

	//malloc(10*sizeof(int));
	//malloc(10, int);
	//int *p = MALLOC(10, int);

	//int *p = (int*)malloc(10*sizeof(int));

	return 0;
}

//带有副作用的宏参数
#define MAX(X, Y) ((X)>(Y)?(X):(Y))
int Max(int x, int y)
{
	return x>y?x:y;
}

int main()
{
	int a = 8;
	int b = 9;
	//int max = MAX(a++, b++);//尽量不要这样使用，会产生副作用，多加或者少加一次，达不到我们想要的效果
	//int max = ((a++)>(b++)?(a++):(b++));
	int max = Max(a++, b++);
	printf("%d\n", max);

	//int b = ++a;//带有副作用的
	return 0;
}
//小写的宏(宏一般都是全部大写)：
//offsetof：offsetof(type, member)用来求结构体type中的member成员在type中的偏移
//getchar：什么时候是宏，什么时候是函数 取决于编译器
 #define MAX 100
 
 int  main()
 {
 	printf("%d\n", MAX);
//#define MAX 100 //定义宏
 #undef MAX  //取消（移除）定义宏
 
 	printf("%d\n", MAX);
 
 	return 0;
 }
 
//条件编译：便于将一条语句（一组语句）编译或者放弃
			//调试性的代码，删除可惜，保留又碍事，所以可以选择性的编译
#define __DEBUG__

int main()
{	
	int a = 10;
	int arr[10] = {1,2,3,4,5};
	int i = 0;
#ifdef __DEBUG__ //如果编译条件为真，执行条件编译代码
	printf("a = %d\n", a);//条件编译代码
#endif //条件编译结束标志
	for(i=0; i<10; i++)
	{
#ifdef __DEBUG__ 
		printf("%d ", arr[i]);
#endif
	}

	return 0;
}

 //多分支的条件编译，哪一个条件成立，执行哪一个条件对应的编译代码
 int main()
 {
 #if 1==2
 	printf("hehe\n");
 #elif 2==3
 	printf("haha\n");
 #else
 	printf("heihei\n");
 #endif
 	return 0;
 }
 
#include <windows.h>

//fopen

int main()
{
	while(1)
	{
		Sleep(1000);//1000 单位：毫秒
		printf("hehe");
	}

	return 0;
}


#define M
//条件编译判断是否被定义，来决定是否执行代码
int main()
{
//#ifdef M //如果已经定义了宏 M
//#if defined(M) //另一种写法，和上面完全相同 注意括号将M括起来，并且无空格隔开

//#ifndef M //如果未定义宏 M
#if !defined(M)  //另一种写法，和上面完全相同
	printf("hehe\n");
#endif
	return 0;
}

/*#if
#ifdef
#ifndef
#endif
#if defined(x)*/
 #include <stdio.h>
 
 int main()
 {
 
 	return 0;
 }


int main()
{
#error 呵呵  //在这一句代码上提示一次编译错误

	return 0;
}


//CI- 持续集成




#include <stdio.h>


int main()
{
	char arr[10] = {0};
	scanf("%s",  arr);
	return 0;
}
