#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
void swap(int* p1, int* p2)
{
	int tmp = *p1;//*p1其实是a，类型int 故int tmp；
	*p1 = *p2;
	*p2 = tmp;
}                               //int* p1=&a
void swap1(int** pp1, int** pp2)//则p1=&a//*p1=a;
{                               //int** pp1=&p1;
	int* tmp;                   //则pp1=&p1//*pp1=p1//**pp1=*p1=a//
	tmp = *pp1;//临时变量的创建需跟给他赋值的值得类型一致。*pp1其实是p1 类型是int* ，故int* tmp；
	*pp1 = *pp2;
	*pp2 = tmp;
}
int main()
{
	int a = 20;
	int b = 10;
	swap(&a, &b);
	//printf("a=%d,b=%d\n", a, b);
	int *p1 = &a;
	int *p2 = &b;
	printf("p1=%p,p2=%p\n", p1, p2);
	swap1(&p1, &p2);
	printf("p1=%p,p2=%p\n", p1, p2);

	system("pause");
	return 0;
}