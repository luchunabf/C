#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>


//int
//float
//内置类型
//自定义类型:结构体,枚举,联合
//
//结构体的声明
//struct tag		//tag:结构体标签
//{					
//	member - list;  //结构体成员列表
//}variable-list;   //结构体变量列表


struct Student
{
	char name[20];
	short age;
	char sex[5];
}stu1, stu2, stu3;

int main()
{
	struct Student stu4;

	return 0;
}


//匿名结构体类型：在声明结构提的时候省略掉了结构体标签（tag）
 struct
 {
 	char name[20];
 	short age;
 	char sex[5];
 }stu1;
 
 struct
 {
 	char name[20];
 	short age;
 	char sex[5];
 }* ps;
 
 int main()
 {
 	ps = &stu1;//非法，编译器会把上面两个声明当成完全不同的两个类型，所以非法
 
 	return 0;
 }

//结构体的自引用：需用指针，因为还没有创建好结构体，不能提前使用
struct Node
{
	int data;//4
	struct Node* next;//4    这里自引用，需要用结构体指针（加*）
};

int main()
{
	struct Node n;//
	return 0;
}


 
 typedef struct Node
 {
 	int data;//4
 	struct Node* next;//4
 }Node;
 
 int main()
 {
 	struct Node n;//
 	return 0;
 }
 
#include <stddef.h>   //size_t offsetof (structName, memberName)的头文件
#include <stdio.h>
#include <stdlib.h>

//结构体内存对齐
 
struct S1
{
	char c1;//4
	int i;//4
	char c2;//4
};
//最大对齐数4
//放的是0-8 共9个偏移量 取4的整数倍12

  struct S2
  {
  	char c1;
  	char c2;
  	int i;
  };
  //最大对齐数4
  //放的是0-7 共8个偏移量，刚好是4的倍数
 
 

 struct S3
 {
 	double d;//0-7 8 8 8
 	char c;//8
 	int i;//12-15
 };
 //练习4-结构体嵌套问题
 struct S4
 {
 	char c1;//0
 	//1-7
 	struct S3 s3;//8-23
 	double d;//24-31
 };
 int main()
 {
 	struct S1 s1 = {0};
	 printf("%d\n", sizeof(struct S1));//12
	 printf("%d\n", sizeof(struct S2));//8
 	printf("%d\n", sizeof(struct S3));//16
 	printf("%d\n", sizeof(struct S4));//32  
 
 	struct S2 s2 = {0};
 	printf("%d\n", offsetof(struct S1, c1));//0 起始位置的偏移量为0
 	printf("%d\n", offsetof(struct S1, i));//4
 	printf("%d\n", offsetof(struct S1, c2));//8
	结构体大小 = （偏移量 + 1 ）个 （取整最大对齐数整数倍）

 	struct S1 s1 = {0};
 	printf("%d\n", sizeof(struct S2));//8
 	printf("%d\n", sizeof(s1));//12
 
	system("pause");
 	return 0;
 }



 struct S
 {
 	char c;
 	int i;
 };

#define offsetof(s,m)   (size_t)&( ((s *)0)->m  )

//(size_t) &(((struct S*)0)->c)
 
 int main()
 {
 	printf("%d\n", offsetof(struct S, c));//0
 	printf("%d\n", offsetof(struct S, i));//4
	
	system("pause");
 	return 0;
 }

#pragma pack(2) //修改默认对齐数      默认对齐数：VS--> 8   linux --> 4
struct S
{
	double d;//0-7（偏移量）   8 2 -->对齐数：  2
	char c;//8（偏移量） 1 2  -->对齐数：1     1
};
#pragma pack()  //恢复默认对齐数 注意：后面无分号

int main()
{
	printf("%d\n", sizeof(struct S));// 9
	system("pause");
	return 0;
}

 
 struct S
 {
 	int i;
 	char c;
 };
 
 int main()
 {
 	return 0;
 }



// 位段：数据类型必须全为 ( unsigned )int 或者 全为 char ; 而且不跨平台
 struct A
 {
 	int _a:2;    //冒号后的2 的单位是 bit：比特位
 	//开辟4个字节-->32个bit 
 	int _b:5;  //可以放下，无需开辟新的
 	int _c:10; //可以放下，无需开辟新的
 	//32 - 17 = 15 剩余15个bit 已经放不下30个bit，开辟新的
 	//开辟4个字节-->32个bit
 	int _d:30; //总共开辟两个int的空间大小，故结构体大小为8
 };
 
 int main()
 {
 	printf("%d\n", sizeof(struct A));// 8
	system("pause");
 	return 0;
 }

struct S
{
	char a:3;//开辟1个字节 --> 8个bit
	char b:4;//可以放下，无需开辟新的空间
	char c:5;//放不下，再开辟1个字节 --> 8个bit
	char d:4;//注意：5 不会挨着之前剩余的1个bit去存放，当放不下的时候，重新开辟，不会挨着排
			 //故在这里需要再开辟1个字节
};

int main()
{
	struct S s = {0};
	printf("%d\n", sizeof(struct S));//3 
	s.a = 10;
	s.b = 12;
	s.c = 3;
	s.d = 4;
	
	system("pause");
	return 0;
}


 //枚举:一一列举
  enum Day//星期
  {
  	Mon=100,  //默认是0     若赋初值为100，下面的一次递增1
  	Tues,	  //默认是1
  	Wed,	  //默认是2
  	Thur,	  //默认是3
  	Fri,	  //默认是4
  	Sat,	  //默认是5
  	Sun		  //默认是6     最后一个后面无逗号
  };
 
 int main()
 {
 	enum Day day = Mon;
	day = Tues;
 	printf("%d\n", day);

	//int num  = Mon;
	//printf("%d\n", Mon);//100

	printf("%d\n", sizeof(day));//大小一般为4  如果枚举内容为char则为1
	system("pause");
 	return 0;
 }
 

 //联合（共用体）：一系列成员共用一块空间
 union Un
 {
 	char i;//1
 	int c;//4
 };
 
 
 int main()
 {
 	union Un u = {0};
 	u.c = 0x12345678; // 78 56 34 12
 	u.i = 0x00;		  // 00 56 34 12
 	return 0;
 }
 
 //联合体的大小是最大成员的大小，
 //当然如果最大成员大小不是最大对齐数的整数倍时，需要对齐到最大对齐数的整数倍
union Un1
{
	char c[5]; //对齐数1         最大成员是这个：1 * 5 = 5 个字节
	int i;    //对齐数 4         最大对齐数 4，取其整数位为 --> 8
};
union Un2
{
	short c[7]; //对齐数1        最大成员是这个： 2 * 7 = 14 个字节  
	int i;		//对齐数4		 最大对齐数 4，取其整数位为 --> 16
};
int main()
{
	printf("%d\n", sizeof(union Un1));//8
	printf("%d\n", sizeof(union Un2));//16
	system("pause");
	return 0;
}
 //判断电脑大小端
 int check_sys()
 {
 	int a = 1;
 	//返回1,小端
 	//返回0,大端
 	return *(char*)&a;
 
 // 	if(1 == *(char*)&a)
 // 	{
 // 		return 1;
 // 	}
 // 	else
 // 	{
 // 		return 0;
 // 	}
 }
int main()
{
	int ret = check_sys();
	if(ret == 1)
		printf("小端\n");
	else
		printf("大端\n");
	return 0;
}


