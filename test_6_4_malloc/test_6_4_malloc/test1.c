#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>

//��Ŀ����
//char *GetMemory(void)
//{
//	char p[] = "hello world";//�ֲ������Ŀ�������ջ�ϣ����������Զ����٣�
//	return p;				 //����ջ�ռ��ϵĵ�ַ�����ڷ��ʷǷ���ַ +static ����̬������OK
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
//	return &a;//���ص����βεĵ�ַ���βγ����������٣�������
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
//��Ŀ����
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
//	//free(str);//���������ͷ� �������ﶼ�Ǵ�ַ��������ֵ�Ļ������ܽ�str��Ϊ��
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
//��Ŀ�ģ�
//void Test(void)
//{
//	char *str = (char *) malloc(100);
//	strcpy(str, "hello");
//	free(str);//�����Ѿ��ͷ���
//	//str = NULL;
//	if(str != NULL)//��ȥ���� �����ڷǷ�������   free�������str = NULL;�Ͳ���Ƿ����ʣ������Ѿ�Ϊ���ˣ�û������
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


//�������飺�ṹ�е����һ��Ԫ��������λ�ô�С������--����������
//struct S
//{
//	int a;
//	char arr[0];//��������:0��д�ɲ�д����ʾ��Сδ֪
//};
//
//struct B
//{
//	int a;//4
//	char* arr;//4  ָ����ʽ�����Ļ���С����4�����Ա�����������ʽ char arr[]��ʽ
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