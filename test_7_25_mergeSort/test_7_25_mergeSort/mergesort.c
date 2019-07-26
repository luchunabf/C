#define _CRT_SECURE_NO_WARNINGS 1
#include <malloc.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
//�鲢����

//��һ����Ŀ�ģ�����������������а�˳��ϲ���һ����������з���temp�У�����
void mergeData(int* array, int left,int mid, int right, int *temp)
{
	int begin1 = left, end1 = mid;
	int begin2 = mid, end2 = right;
	int index = left;

	while (begin1 < end1 && begin2 < end2)//���������е�Ԫ�ؽ��бȽ�
	{
		if (array[begin1] < array[begin2])
			temp[index++] = array[begin1++];
		else
			temp[index++] = array[begin2++];
	}
	//��������˵������������������һ����������
	while (begin1 < end1)//��������˵������������������һ����������
		temp[index++] = array[begin1++];
	while (begin2 < end2)//��begin2 < end2˵���ұ߻�û�б����꣬������ʣ���Ԫ�ط���temp
		temp[index++] = array[begin2++];
}

//��һ���ǵݹ飨ѭ������array��Ϊ���ɸ������䣬���ҽ�ϵ�һ�����������������
void _mergeSort(int* array, int left, int right, int* temp)
{
	if (right - left > 1)//�������֮����Ԫ�أ������ָ�Ϊ��С��������
	{
		int mid = left + ((right - left) >> 1);//��ԭ�������м�Ԫ��Ϊ��׼�ָ������������
		_mergeSort(array, left, mid, temp);//�������н��й鲢����(����ҿ�)
		_mergeSort(array, mid, right, temp);//�������н��й鲢����(����ҿ�)
		mergeData(array, left, mid, right, temp);//�����������������н��кϲ����ϲ������temp��
		memcpy(array + left, temp + left, sizeof(int)*(right - left));//��temp�е��������п�����array��
	}
}

void mergeSort(int* array, int size)//�ٷ�װһ�㣬�Ǻ���������������
{
	int* temp = (int*)malloc(sizeof(int)*size);
	if (NULL == temp)
	{
		assert(0);
		return;
	}
	_mergeSort(array, 0, size, temp);
	free(temp);
}

//�ǵݹ�
void MergeSortNor(int* array, int size)
{
	int* temp = (int*)malloc(sizeof(int)*size);
	if (NULL == temp)
	{
		assert(0);
		return;
	}
	int gap = 1;
	while (gap < size)
	{
		for (int i = 0; i < size; i += 2 * gap)
		{
			int left = i;
			int mid = left + gap;
			int right = mid + gap;
			if (mid >= size)
				mid = size;
			if (right >= size)
				right = size;
			mergeData(array, left, mid, right, temp);
		}
		memcpy(array, temp, sizeof(int)* size);
		gap *= 2;
	}
	free(temp);
}



int main()
{
	int arr[] = { 3, 4, 2, 9, 1, 7, 6, 0, 8, 5 };
	mergeSort(arr, sizeof(arr) / sizeof(arr[0]));

	//MergeSortNor(arr, sizeof(arr) / sizeof(arr[0]));
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
		printf("%d ", arr[i]);
	printf("\n");
	system("pause");
	return 0;
}