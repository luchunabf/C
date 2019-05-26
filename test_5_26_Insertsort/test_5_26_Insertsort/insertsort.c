#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//void Insertsort(int* array, int size)
//{
//	
//	for(int i = 1; i < size; ++i)
//	{
//		int key = array[i];
//		int end = i - 1;
//		while (end >= 0 && key < array[end])
//		{
//			array[end + 1] = array[end];
//			end--;
//		}
//		array[end + 1] = key;
//	}
//}
//
//int main()
//{
//	int arr[6] = { 5, 2, 4, 6, 1, 3 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//	Insertsort(arr, size);
//	for (int i = 0; i < size; ++i)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}
void Insertsort(int* arr, int size)
{
	for (int i = 1; i < size; ++i)
	{
		int key = arr[i];//key ֻ�Ǹ���ǣ������±�i������Ԫ��ֵ��key������arr[end]���Ƚϣ������뵽��Ӧ��λ�ã�
		int end = i - 1;//key��ǵ�����Ԫ�ص�ǰһ��Ԫ����Ϊend�ĳ�ʼֵ��Ȼ��Ƚϣ���end��ǰ��
		while (end >= 0 && arr[end] > key)
		{
			arr[end + 1] = arr[end];//��keyС�Ļ���end�ϵ�Ԫ�������ƶ�һ��
			end--;//end��ǰ�߼������бȽ�
		}
		//��ѭ���Ļ�key�Ѿ��ҵ�Ҫ�����λ��end+1
		arr[end + 1] = key;//��key���뵽Ӧ�������λ��
	}
}
int main()
{
	int arr[6] = { 5, 2, 4, 6, 1, 3 };
	int size = sizeof(arr) / sizeof(arr[0]);
	Insertsort(arr, size);
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}