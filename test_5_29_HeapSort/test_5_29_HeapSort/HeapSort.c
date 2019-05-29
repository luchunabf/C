#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//��С�ѽ���
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//���µ�����
void adjustdown(int* arr, int size, int parent)
{
	int child = parent * 2 + 1;
	if (parent < size)
	{
		while (child < size)//�ߵ�child = size - 1 ��λ�ã���ĩ��
		{
			if (child + 1 < size && arr[child + 1] < arr[child])//��child�����������ӽڵ������С��
				child += 1;										//���򽨴���ҽϴ�ģ�����С���ҽ�С��
			if (arr[parent] > arr[child])//�������ˣ�Ҫ�����Ľڵ�Ƚ�С�Ĵ�Ļ�������   (�ҵĴ���֮��)
									//��֮������������ʱ��Ҫ�����Ľڵ�Ƚϴ��С�Ļ�������
			{
				Swap(&arr[child], &arr[parent]);
				parent = child;
				child = parent * 2 + 1;
			}
			else
				return;
			
		}
	}
}

//���ѣ����򽨴�ѣ�����С�ѣ���������в�Ӱ�죩
void Heapsort(int* arr,int size)//С��
{
	int nleaf = (size - 2) >> 1;//�ҵ�����һ����Ҷ�ڵ�
	for (int i = nleaf; i >= 0; --i)//��С��
		adjustdown(arr, size, i);
	for (int j = size - 1; j >= 0; j--)
	{
		Swap(&arr[0], &arr[j]);//�������ڵ��δ���򲿷��������һ����Ԫ��
		adjustdown(arr, j, 0);//�����ڵ�����Ľ��������Ľڵ����µ�������Ӧλ��
	}
}
int main()
{
	int arr[] = { 5, 9, 3, 7, 6, 2, 4, 0, 1, 8 };
	Heapsort(arr, 10);
	for (int i = 0; i < 10; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}