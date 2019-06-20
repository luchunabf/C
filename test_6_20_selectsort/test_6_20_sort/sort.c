#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//选择排序
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

//我写的
//选择排序就是首先将数组的首元素（或最后一个元素）当成有序元素
//然后第一个（或者最后一个元素）先不管，去size - 1 - 1 个元素的数组里面寻找最小的（或者最大的）然后用minpos（或maxpos）标记
//整个循环有size - 2 次（其中size - 1 代表整个数组的大小，因为循环i是从0开始的）【也就是说 外层循环 i：0 - (size-2)】
//上面size-2 比整个数组范围[0 - (size - 1)]少一个：是因为，把size - 2 个元素排好了序以后，最后一个则必定在它应该在的位置
//找最大值时：寻找区间是[0, size - 1 - i]   maxpos 初始值是 0
//找最小值时：寻找区间是[i + 1, size - 1]	minpos 初始值是 i
//找最大值时：maxpos 应该放在 size - 1 - i 的位置，故里层循环结束后，判断maxpos是否在size - 1 - i处，若不在交换
//找最小值时：minpos 应该放在 i 的位置，故里层循环结束后，判断minpos是否在i处，若不在交换
//不用管ls写的

#if 0
void Selectsort1(int* arr, int size)//找最小值(i从前往后走)
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
//void Selectsort2(int* arr, int size)//找最大值(i从后往前走)
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
void Selectsort2(int* arr, int size)//找最大值(i从后往前走)
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


//选择排序：法二：同时找maxpos 和 minpos
void SelectSortOP(int* array, int size)
{
	// [有5个标记：begin end ：表示未排序的区间；maxpos minpos：标记begin到end区间内的最大值和最小值 index:从前往后遍历去寻找maxpos或minpos]
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

		if (maxPos != end)//若最大值不在末尾，将其置于末尾，不一定是数组末尾，而是begin-end区间的最后一个元素：end处
			Swap(&array[maxPos], &array[end]);

		// 注意：如果在放大元素之前，小元素刚好在end的位置
		//必须更新minPos的位置  因为小元素位置已经发生改变
		if (minPos == end)///重点理解[易忽略]////如果minpos刚好走到了end处，而此处因为前面将最大值arr[maxpos]与arr[end]已经交换,但是maxpos和end的位置没变，只是数值交换
			minPos = maxPos;/////////////////////上一步交换了以后会使原来在minpos处的最小值被交换到maxpos位置处，故需要让minpos指向maxpos处才是真正的最小值处

		if (minPos != begin)//若最小值不在起始，将其置于起始，不一定是数组起始，而是begin-end区间的第一个元素：begin处
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