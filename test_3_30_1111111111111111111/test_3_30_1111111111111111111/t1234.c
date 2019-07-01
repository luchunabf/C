#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//int main()
//{
//	int a = -10;
//	int *p = NULL;
//	printf("%d\n", !2);//0
//	printf("%d\n", !0);//1
//	a = -a;
//	p = &a;
//	
//	printf("%d\n", sizeof a);//4
//	printf("%d\n", sizeof (int));//4
//	printf("%d\n", a);//10
//	printf("%d\n", &a);//
//
//	printf("%d\n", p);//随机地址
//	printf("%d\n", *p);//10
//
//	printf("%p\n", p);//随机地址
//	printf("%p\n", *p);//固定地址
//
//	system("pause");
//	return 0;
//}


//void tet1(int arr[])
//{
//	printf("%d\n", sizeof(arr));
//}
//void tet2(char ch[])
//{
//	printf("%d\n", sizeof(ch));
//}
//int main()
//{
//	int arr[10] = { 0 };
//	char ch[10] = { 0 };
//	printf("%d\n", sizeof(arr));
//	printf("%d\n", sizeof(ch));
//	tet1(arr);
//	tet2(ch);
//
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int i = 0, a = 0, b = 2, c = 3, d = 4;
//	//i = a++ || ++b || d++;
//	i = a++ && ++b && d++;
//	printf("a=%d,b=%d,c=%d,d=%d", a, b, c, d);
//
//	system("pause");
//	return 0;
//}

//int main()
//{
	/*int n = 10;
	char *pc = (char*)&n;
	int *pi = &n;

	printf("%p\n", &n);
	printf("%p\n", pc);
	printf("%p\n", pc + 1);
	printf("%p\n", pi);
	printf("%p\n", pi + 1);
	system("pause");
	return 0;*/

	
//}

int main()
{
	int n = 0x11223344;
	char *pc = (char *)&n;
	char *pi = &n;
	*pc = 0x55;//重点在调试的过程中观察内存的变化。
	*pi = 0;//重点在调试的过程中观察内存的变化。
	return 0;
}