#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//int check_sys()
//{
//	int a = 1;
//	//����1�� С��
//	//����0�� ���
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
//	//����1�� С��
//	//����0�� ���
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
//		printf("С��\n");
//	}
//	else
//	{
//		printf("���\n");
//	}
//	return 0;
//}
// 
// union Un
// {
// 	char c[5];//5 1  �������������ʱ������Ա�����ʱ����������飬����������������Ա�Ĵ�С�������������ĳ�Ա���бȽ�
// 	int i; //4    4
// };
// 
// int main()
// {
// 	printf("%d\n", sizeof(union Un));
// 	return 0;
// }
//
//�ṹ�壬���� --> ��Ҫ�ڴ����


#include <stdlib.h>
#include <errno.h>
#include <string.h>
//
//int main()
//{
//	//int a;//4
//	//char arr[5];//5
//	//��̬�ڴ濪��
//	//int arr[10] = {0};//40�ֽ�
//	int* p = (int*)malloc(40);  //malloc���뿪���ڴ�ĵ�λ���ֽ�
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
//calloc(size_t num, size_t size):  ����num��size�ֽڳ��ȵĿռ䣬���ҳ�ʼ��Ϊ0
//calloc �� malloc ���˸������ٵ�ÿ���ֽڳ�ʼ��Ϊ0�����ҿ��ٿռ����������num��
//int main()
//{
//	int*p = (int*)calloc(10, sizeof(int));//ע��calloc����Ҫ����10��size_t num��,����10��int�ͳ�ʼ��Ϊ0
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

//�����Ķ�̬�ڴ����
//void test()
//{
//	int* p = (int*)malloc(10);
//	if(p == NULL)
//	{
//		return;
//	}
//
//	if(1)
//		return;//return ������free����
//	//...
//	free(p);  //������ǰ���أ�free��Ч
//	p = NULL;
//}
//
//int main()
//{
//	test();
//	getchar();
//	return 0;
//}

//����һ����NULLָ��Ľ�����
//void test()
//{
//	int *p = (int *)malloc(INT_MAX/4);
//	//if(p == NULL) //��һ��������� ��ָ���ж�
//	//{
//	//	return;
//	//}
//	*p = 20;//���p��ֵ��NULL���ͻ�������
//	free(p);
//}
//int main()
//{
//	return 0;
//}


//��������ԷǶ�̬���ٵ��ڴ�ʹ��free�ͷ�
//void test()
//{
//	int a = 10;
//	int *p = &a;
//	free(p);//ok?  ������Ϊǰ��û�ж�̬����
//}
//int main()
//{
//	test();
//	return 0;
//}
//

//����������ͬһ�鶯̬�ڴ����ͷţ�free��
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
//	free(p);//�ظ��ͷ�
//	p = NULL;
//	return 0;
//}
//�����ģ��Զ�̬���ٵĿռ�Խ�����
//void test()
//{
//	int i = 0;
//	int* p = (int*)malloc(sizeof(int)* 10);
//	if (NULL == p)
//	{
//		exit(EXIT_FAILURE);
//	}
//	for (i = 0; i <= 10; i++)//������10�������������11��������Խ��
//	{
//		*(p + i) = i;
//	}
//	free(p);
//}
//�����壺ʹ��free�ͷ�һ�鶯̬�ڴ��һ���֣���������ȫ�ͷţ�
//void test()
//{
//	int* p = (int*)malloc(100);
//	p++;    //p�Ѿ�����һ������ȥfree�ͷ�-->Error  p��Ϊ����̬�ڴ���׵�ַ���ܸı�
//	free(p);//p����ָ��̬�ڴ����ʼλ��
//}
//�������������ͷ�
//void test()
//{
//	int* p = (int*)malloc(100);//ֻ���٣�����û�ж�Ӧ��free���ͷ�
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



//��Ŀһ
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
//	free(str);//???  �������    ������ڴ�й©  �β�p��str��һ����ʱ���� �βγ������Ͳ�������
//	str = NULL;
//}
//int main()
//{
//	Test();
//	return 0;
//}

//�޸�-->������ָ��
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
//	free(str);//�����û�������ˣ���������棩
//	str = NULL;
//}
//int main()
//{
//	Test();
//	system("pause");
//	return 0;
//}
