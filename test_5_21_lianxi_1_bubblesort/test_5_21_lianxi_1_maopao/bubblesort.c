#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
void my_swap(int* a, int* b)//交换的时候传地址（通过这两个地址去寻找对应变量）
{							//形参仅仅是实参的一份临时拷贝（如果不传地址的话就仅仅交换的是临时拷贝的形参的值，并不会影响实参）
	int tmp = 0;            //临时变量的类型是要交换的值得类型（对应）
	tmp = *a;				//交换的是地址解引用之后的值（要交换的值）
	*a = *b;
	*b = tmp;
}
void bubblesort(int* arr,int size)//传数组名及其大小
{
	for (int i = 0; i < size - 1; i++)//要冒泡的趟数（数组元素-1）
	{
		int flag = 0;//一个交换函数是否运行的标记，运行了变为1，否则为0
		for (int j = 0; j < size - 1 - i; j++)//遍历未排序的数组元素
		{
			if ((*(arr + j)) >(*(arr + j + 1)))
			{
				my_swap(&(*(arr + j)), &(*(arr + j + 1)));//交换元素直至最大数排在（此次遍历的）最后一位
				flag = 1;//若交换函数执行，则标记一下
			}
		}
		if (flag == 0)//若为 0，则说明上一次遍历时交换函数没有执行，即数组排序已（提前）完成
			return;
	}
}
int main()
{
	int a = 1;
	int b = 2;
	my_swap(&a, &b);
	printf("a == %d b == %d\n", a, b);
	int arr[10] = { 70, 55, 94, 65, 66, 28, 69, 44, 29, 35 };
	bubblesort(arr, 10);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", *(arr + i));
	}
	printf("\n");

	system("pause");
	return 0;
	
}