#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//ѡ������
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//void Selectsort(int* arr, int size)
//{
//	for (int i = 0; i < size - 1; i++)
//	{
//		int maxpos = 0;
//		//int maxpos = i;
//
//		for (int j = 1; j < size - i; j++)
//			//for(int j = i; j <= size - 1 - i; j++)
//		{
//			if (arr[maxpos] < arr[j])
//				maxpos = j;
//		}
//		if (maxpos != size - 1 - i)
//			Swap(&arr[maxpos], &arr[size - 1 - i]);
//	}
//}

//��д��
//ѡ������������Ƚ��������Ԫ�أ������һ��Ԫ�أ���������Ԫ��
//Ȼ���һ�����������һ��Ԫ�أ��Ȳ��ܣ�ȥsize - 1 - 1 ��Ԫ�ص���������Ѱ����С�ģ��������ģ�Ȼ����minpos����maxpos�����
//����ѭ����size - 2 �Σ�����size - 1 ������������Ĵ�С����Ϊѭ��i�Ǵ�0��ʼ�ģ���Ҳ����˵ ���ѭ�� i��0 - (size-2)��
//����size-2 ���������鷶Χ[0 - (size - 1)]��һ��������Ϊ����size - 2 ��Ԫ���ź������Ժ����һ����ض�����Ӧ���ڵ�λ��
//�����ֵʱ��Ѱ��������[0, size - 1 - i]   maxpos ��ʼֵ�� 0
//����Сֵʱ��Ѱ��������[i + 1, size - 1]	minpos ��ʼֵ�� i
//�����ֵʱ��maxpos Ӧ�÷��� size - 1 - i ��λ�ã������ѭ���������ж�maxpos�Ƿ���size - 1 - i���������ڽ���
//����Сֵʱ��minpos Ӧ�÷��� i ��λ�ã������ѭ���������ж�minpos�Ƿ���i���������ڽ���
//���ù�lsд��

#if 0
void Selectsort1(int* arr, int size)//����Сֵ(i��ǰ������)
{
	for (int i = 0; i <= size - 2; ++i)
	{
		int minpos = i;
		for (int j = i + 1; j <= size - 1; ++j)
		{
			if (arr[j] < arr[minpos])
				minpos = j;
		}
		if (minpos !=  i)
			Swap(&arr[minpos], &arr[i]);
	}

}
#endif

#if 0
//void Selectsort2(int* arr, int size)//�����ֵ(i�Ӻ���ǰ��)
//{
//	for (int i = 0; i <= size - 2; ++i)
//	{
//		int maxpos = 0;
//		for (int j = 0; j <= size - 1 - i; ++j)
//		{
//			if (arr[j] > arr[maxpos])
//				maxpos = j;
//		}
//		if (maxpos != size - 1 - i)
//			Swap(&arr[maxpos], &arr[size - 1 - i]);
//	}
//}
void Selectsort2(int* arr, int size)//�����ֵ(i�Ӻ���ǰ��)
{
	for (int i = size - 2; i >= 0 ; --i)
	{
		int maxpos = 0;
		for (int j = 0; j <= size - 1 - i; ++j)
		{
			if (arr[j] > arr[maxpos])
				maxpos = j;
		}
		if (maxpos != size - 1 - i)
			Swap(&arr[maxpos], &arr[size - 1 - i]);
	}
}

int main()
{
	int arr[6] = { 5, 2, 4, 6, 1, 3 };
	int size = sizeof(arr) / sizeof(arr[0]);

	Selectsort1(arr, size);
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	Selectsort2(arr, size);
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}
#endif


//ѡ�����򣺷�����ͬʱ��maxpos �� minpos
void SelectSortOP(int* array, int size)
{
	// [��5����ǣ�begin end ����ʾδ��������䣻maxpos minpos�����begin��end�����ڵ����ֵ����Сֵ index:��ǰ�������ȥѰ��maxpos��minpos]
	int begin = 0;
	int end = size - 1;

	while (begin < end)
	{
		int maxPos = begin;
		int minPos = begin;

		int index = begin + 1;
		while (index <= end)
		{
			if (array[index] > array[maxPos])
				maxPos = index;

			if (array[index] < array[minPos])
				minPos = index;

			++index;
		}

		if (maxPos != end)//�����ֵ����ĩβ����������ĩβ����һ��������ĩβ������begin-end��������һ��Ԫ�أ�end��
			Swap(&array[maxPos], &array[end]);

		// ע�⣺����ڷŴ�Ԫ��֮ǰ��СԪ�ظպ���end��λ��
		//�������minPos��λ��  ��ΪСԪ��λ���Ѿ������ı�
		if (minPos == end)///�ص����[�׺���]////���minpos�պ��ߵ���end�������˴���Ϊǰ�潫���ֵarr[maxpos]��arr[end]�Ѿ�����,����maxpos��end��λ��û�䣬ֻ����ֵ����
			minPos = maxPos;/////////////////////��һ���������Ժ��ʹԭ����minpos������Сֵ��������maxposλ�ô�������Ҫ��minposָ��maxpos��������������Сֵ��

		if (minPos != begin)//����Сֵ������ʼ������������ʼ����һ����������ʼ������begin-end����ĵ�һ��Ԫ�أ�begin��
			Swap(&array[minPos], &array[begin]);

		begin++;
		end--;
	}
}
int main()
{
	int arr[6] = { 5, 2, 4, 6, 1, 3 };
	int size = sizeof(arr) / sizeof(arr[0]);

	SelectSortOP(arr, size);
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}