#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
void my_swap(int* a, int* b)//������ʱ�򴫵�ַ��ͨ����������ַȥѰ�Ҷ�Ӧ������
{							//�βν�����ʵ�ε�һ����ʱ���������������ַ�Ļ��ͽ�������������ʱ�������βε�ֵ��������Ӱ��ʵ�Σ�
	int tmp = 0;            //��ʱ������������Ҫ������ֵ�����ͣ���Ӧ��
	tmp = *a;				//�������ǵ�ַ������֮���ֵ��Ҫ������ֵ��
	*a = *b;
	*b = tmp;
}
void bubblesort(int* arr,int size)//�������������С
{
	for (int i = 0; i < size - 1; i++)//Ҫð�ݵ�����������Ԫ��-1��
	{
		int flag = 0;//һ�����������Ƿ����еı�ǣ������˱�Ϊ1������Ϊ0
		for (int j = 0; j < size - 1 - i; j++)//����δ���������Ԫ��
		{
			if ((*(arr + j)) >(*(arr + j + 1)))
			{
				my_swap(&(*(arr + j)), &(*(arr + j + 1)));//����Ԫ��ֱ����������ڣ��˴α����ģ����һλ
				flag = 1;//����������ִ�У�����һ��
			}
		}
		if (flag == 0)//��Ϊ 0����˵����һ�α���ʱ��������û��ִ�У������������ѣ���ǰ�����
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