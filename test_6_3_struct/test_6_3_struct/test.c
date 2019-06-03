#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>

//
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


//struct Student
//{
//	char name[20];
//	short age;
//	char sex[5];
//}stu1, stu2, stu3;
//
//int main()
//{
//	struct Student stu4;
//
//	return 0;
//}


//匿名结构体类型：在声明结构提的时候省略掉了结构体标签（tag）
// struct
// {
// 	char name[20];
// 	short age;
// 	char sex[5];
// }stu1;
// 
// struct
// {
// 	char name[20];
// 	short age;
// 	char sex[5];
// }* ps;
// 
// int main()
// {
// 	ps = &stu1;//非法，编译器会把上面两个声明当成完全不同的两个类型，所以非法
// 
// 	return 0;
// }

//结构体的自引用：需用指针，因为还没有创建好结构体，不能提前使用
//struct Node
//{
//	int data;//4
//	struct Node* next;//4    这里自引用，需要用结构体指针（加*）
//};
//
//int main()
//{
//	struct Node n;//
//	return 0;
//}


// 
// typedef struct Node
// {
// 	int data;//4
// 	struct Node* next;//4
// }Node;
// 
// int main()
// {
// 	struct Node n;//
// 	return 0;
// }
// 
#include <stddef.h>   //size_t offsetof (structName, memberName)的头文件
#include <stdio.h>
#include<stdlib.h>

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
 	//struct S1 s1 = {0};
	 printf("%d\n", sizeof(struct S1));//12
	 printf("%d\n", sizeof(struct S2));//8
 	printf("%d\n", sizeof(struct S3));//16
 	printf("%d\n", sizeof(struct S4));//32  
 
 	//struct S2 s2 = {0};
 	//printf("%d\n", offsetof(struct S1, c1));
 	//printf("%d\n", offsetof(struct S1, i));
 	//printf("%d\n", offsetof(struct S1, c2));
 
 	//struct S1 s1 = {0};
 	//printf("%d\n", sizeof(struct S2));//
 	//printf("%d\n", sizeof(s1));
 
	system("pause");
 	return 0;
 }

// struct S
// {
// 	char c;
// 	int i;
// };

//#define offsetof(s,m)   (size_t)&( ((s *)0)->m  )

// (size_t) &(((struct S*)0)->c)
// 
// int main()
// {
// 	printf("%d\n", offsetof(struct S, c));
// 	printf("%d\n", offsetof(struct S, i));
// 
// 	return 0;
// }
//
//#pragma pack(1)
//struct S
//{
//	double d;//0-7 8 4 4
//	char c;//8 1
//};
//#pragma pack()
//
//int main()
//{
//	printf("%d\n", sizeof(struct S));
//	return 0;
//}
//
// 
// struct S
// {
// 	int i;
// 	char c;
// };
// 
// int main()
// {
// 	return 0;
// }
// 
// struct A
// {
// 	int _a:2;
// 	//4-32 
// 	int _b:5;
// 	int _c:10;
// 	//15
// 	//4-32
// 	//
// 	int _d:30;
// };
// 
// int main()
// {
// 	printf("%d\n", sizeof(struct A));//
// 	return 0;
// }
//
//struct S
//{
//	char a:3;
//	char b:4;
//	char c:5;
//	char d:4;
//};
//
//int main()
//{
//	struct S s = {0};
//	//printf("%d\n", sizeof(struct S));//3 
//	s.a = 10;
//	s.b = 12;
//	s.c = 3;
//	s.d = 4;
//
//	return 0;
//}


// 
//  enum Day//星期
//  {
//  	Mon=1,
//  	Tues,
//  	Wed,
//  	Thur,
//  	Fri,
//  	Sat,
//  	Sun
//  };
// 
// int main()
// {
// 	//enum Day day = Mon;
// 	//day = Tues;
// 	//printf("%d\n", day);
// 	int num  = Mon;
// 	return 0;
// }
// 

// 
// union Un
// {
// 	char i;//1
// 	int c;//4
// };
// 
// 
// int main()
// {
// 	union Un u = {0};
// 	u.c = 0x11223344;
// 	u.i = 0x55;
// 	return 0;
// }
// 
// 
// int check_sys()
// {
// 	int a = 1;
// 	//返回1,小端
// 	//返回0,大端
// 	return *(char*)&a;
// 
// // 	if(1 == *(char*)&a)
// // 	{
// // 		return 1;
// // 	}
// // 	else
// // 	{
// // 		return 0;
// // 	}
// }
//int check_sys()
//{
//	
//}
//
//int main()
//{
//	int ret = check_sys();
//	if(ret == 1)
//		printf("小端\n");
//	else
//		printf("大端\n");
//	return 0;
//}


