#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>


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


//�����ṹ�����ͣ��������ṹ���ʱ��ʡ�Ե��˽ṹ���ǩ��tag��
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
 	ps = &stu1;//�Ƿ������������������������������ȫ��ͬ���������ͣ����ԷǷ�
 
 	return 0;
 }

//�ṹ��������ã�����ָ�룬��Ϊ��û�д����ýṹ�壬������ǰʹ��
struct Node
{
	int data;//4
	struct Node* next;//4    ���������ã���Ҫ�ýṹ��ָ�루��*��
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
 
#include <stddef.h>   //size_t offsetof (structName, memberName)��ͷ�ļ�
#include <stdio.h>
#include <stdlib.h>

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
 	struct S1 s1 = {0};
	 printf("%d\n", sizeof(struct S1));//12
	 printf("%d\n", sizeof(struct S2));//8
 	printf("%d\n", sizeof(struct S3));//16
 	printf("%d\n", sizeof(struct S4));//32  
 
 	struct S2 s2 = {0};
 	printf("%d\n", offsetof(struct S1, c1));//0 ��ʼλ�õ�ƫ����Ϊ0
 	printf("%d\n", offsetof(struct S1, i));//4
 	printf("%d\n", offsetof(struct S1, c2));//8
	�ṹ���С = ��ƫ���� + 1 ���� ��ȡ������������������

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

#pragma pack(2) //�޸�Ĭ�϶�����      Ĭ�϶�������VS--> 8   linux --> 4
struct S
{
	double d;//0-7��ƫ������   8 2 -->��������  2
	char c;//8��ƫ������ 1 2  -->��������1     1
};
#pragma pack()  //�ָ�Ĭ�϶����� ע�⣺�����޷ֺ�

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



// λ�Σ��������ͱ���ȫΪ ( unsigned )int ���� ȫΪ char ; ���Ҳ���ƽ̨
 struct A
 {
 	int _a:2;    //ð�ź��2 �ĵ�λ�� bit������λ
 	//����4���ֽ�-->32��bit 
 	int _b:5;  //���Է��£����迪���µ�
 	int _c:10; //���Է��£����迪���µ�
 	//32 - 17 = 15 ʣ��15��bit �Ѿ��Ų���30��bit�������µ�
 	//����4���ֽ�-->32��bit
 	int _d:30; //�ܹ���������int�Ŀռ��С���ʽṹ���СΪ8
 };
 
 int main()
 {
 	printf("%d\n", sizeof(struct A));// 8
	system("pause");
 	return 0;
 }

struct S
{
	char a:3;//����1���ֽ� --> 8��bit
	char b:4;//���Է��£����迪���µĿռ�
	char c:5;//�Ų��£��ٿ���1���ֽ� --> 8��bit
	char d:4;//ע�⣺5 ���ᰤ��֮ǰʣ���1��bitȥ��ţ����Ų��µ�ʱ�����¿��٣����ᰤ����
			 //����������Ҫ�ٿ���1���ֽ�
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


 //ö��:һһ�о�
  enum Day//����
  {
  	Mon=100,  //Ĭ����0     ������ֵΪ100�������һ�ε���1
  	Tues,	  //Ĭ����1
  	Wed,	  //Ĭ����2
  	Thur,	  //Ĭ����3
  	Fri,	  //Ĭ����4
  	Sat,	  //Ĭ����5
  	Sun		  //Ĭ����6     ���һ�������޶���
  };
 
 int main()
 {
 	enum Day day = Mon;
	day = Tues;
 	printf("%d\n", day);

	//int num  = Mon;
	//printf("%d\n", Mon);//100

	printf("%d\n", sizeof(day));//��Сһ��Ϊ4  ���ö������Ϊchar��Ϊ1
	system("pause");
 	return 0;
 }
 

 //���ϣ������壩��һϵ�г�Ա����һ��ռ�
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
 
 //������Ĵ�С������Ա�Ĵ�С��
 //��Ȼ�������Ա��С��������������������ʱ����Ҫ���뵽����������������
union Un1
{
	char c[5]; //������1         ����Ա�������1 * 5 = 5 ���ֽ�
	int i;    //������ 4         �������� 4��ȡ������λΪ --> 8
};
union Un2
{
	short c[7]; //������1        ����Ա������� 2 * 7 = 14 ���ֽ�  
	int i;		//������4		 �������� 4��ȡ������λΪ --> 16
};
int main()
{
	printf("%d\n", sizeof(union Un1));//8
	printf("%d\n", sizeof(union Un2));//16
	system("pause");
	return 0;
}
 //�жϵ��Դ�С��
 int check_sys()
 {
 	int a = 1;
 	//����1,С��
 	//����0,���
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
		printf("С��\n");
	else
		printf("���\n");
	return 0;
}


