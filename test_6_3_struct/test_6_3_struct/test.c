#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>

//
//int
//float
//��������
//�Զ�������:�ṹ��,ö��,����
//
//�ṹ�������
//struct tag		//tag:�ṹ���ǩ
//{					
//	member - list;  //�ṹ���Ա�б�
//}variable-list;   //�ṹ������б�


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


//�����ṹ�����ͣ��������ṹ���ʱ��ʡ�Ե��˽ṹ���ǩ��tag��
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
// 	ps = &stu1;//�Ƿ������������������������������ȫ��ͬ���������ͣ����ԷǷ�
// 
// 	return 0;
// }

//�ṹ��������ã�����ָ�룬��Ϊ��û�д����ýṹ�壬������ǰʹ��
//struct Node
//{
//	int data;//4
//	struct Node* next;//4    ���������ã���Ҫ�ýṹ��ָ�루��*��
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
#include <stddef.h>   //size_t offsetof (structName, memberName)��ͷ�ļ�
#include <stdio.h>
#include<stdlib.h>

//�ṹ���ڴ����
 
struct S1
{
	char c1;//4
	int i;//4
	char c2;//4
};
//��������4
//�ŵ���0-8 ��9��ƫ���� ȡ4��������12

  struct S2
  {
  	char c1;
  	char c2;
  	int i;
  };
  //��������4
  //�ŵ���0-7 ��8��ƫ�������պ���4�ı���
 
 

 struct S3
 {
 	double d;//0-7 8 8 8
 	char c;//8
 	int i;//12-15
 };
 //��ϰ4-�ṹ��Ƕ������
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
//  enum Day//����
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
// 	//����1,С��
// 	//����0,���
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
//		printf("С��\n");
//	else
//		printf("���\n");
//	return 0;
//}


