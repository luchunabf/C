#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//�������ǰk����С��ֵ
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void adjustdown(int* arr, int size, int parent)//�����
{
	int child = parent * 2 + 1;
	if (parent < size)
	{
		while (child < size)
		{
			if (child + 1 < size && arr[child] < arr[child + 1])//�����������ϴ��
				child += 1;
			if (arr[parent] < arr[child])//������ѣ��ϴ�ıȸ��ڵ��Ļ�������   ����С�ѣ���С�ıȸ��ڵ�С�Ļ�������
			{
				Swap(&arr[parent], &arr[child]);
				parent = child;
				child = parent * 2 + 1;
			}
			else
				return;
		}
	}
}

void topK(int* arr, int size, int k)
{
	//int N = sizeof(arr) / sizeof(arr[0]);
	//ȡ����ǰk��Ԫ�ؽ���
	int root = (k - 2) >> 1;//�ҵ���һ����Ҷ�ڵ�
	for (; root >= 0; --root)
		adjustdown(arr, k, root);
	
	//��ʣ��N-K��Ԫ��������Ѷ�Ԫ�ؽ��бȽϣ��ж��Ƿ���Ҫ����
	for (int i = k; i < size; ++i)
	{
		if (arr[i] < arr[0])//��һ��
		{
			Swap(&arr[i], &arr[0]);
			adjustdown(arr, k, 0);
		}
	}
}


int main()
{
	int arr[10] = { 55, 99, 33, 22, 44, 88, 77, 11, 66, 5 };
	topK(arr, 10, 4);
	for (int i = 0; i < 4; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}





