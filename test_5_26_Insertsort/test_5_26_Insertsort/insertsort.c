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
		int key = arr[i];//key 只是个标记，保存下标i的数组元素值（key用来和arr[end]作比较，最后插入到相应的位置）
		int end = i - 1;//key标记的数组元素的前一个元素作为end的初始值，然后比较，让end往前走
		while (end >= 0 && arr[end] > key)
		{
			arr[end + 1] = arr[end];//比key小的话让end上的元素往后移动一个
			end--;//end往前走继续进行比较
		}
		//出循环的话key已经找到要插入的位置end+1
		arr[end + 1] = key;//将key插入到应该排序的位置
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