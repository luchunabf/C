#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//插入排序
void InsertSort(int* array, int size)
{
	for (int i = 1; i < size; ++i)
	{
		// 待插入元素
		int key = array[i];

		// 找key的插入位置：与前面已经排序好的元素从后往前比较
		int end = i - 1;
		while (end >= 0 && key < array[end])
		{
			array[end + 1] = array[end];
			end -= 1;
		}

		// 插入元素
		array[end + 1] = key;
	}
}

//快速排序
// a  b  c


//三数取中法：寻找left mid right 的（数组）中间数
int GetMiddleIndex(int* array, int left, int right)
{
	int mid = left + ((right - left) >> 1);//left mid right 其中mid是left 和 right 的平均值
	if (array[left] < array[right - 1])//其实就是三个数之间比大小，return中间大小的那个数
	{
		if (array[mid] < array[left])//比左小，说明left是中间数
			return left;
		else if (array[mid] > array[right - 1])//比右大， 说明right - 1 是中间数 
			return right - 1;
		else
			return mid;
	}
	else
	{
		if (array[mid] > array[left])
			return left;
		else if (array[mid] < array[right - 1])
			return right - 1;
		else
			return mid;
	}
}

// [left, right)：数组大小是[0-(size-1)],到时候传的是left:0   right: size  故[left, right)表示的是数组区间 所以下面的 end = right - 1;
//数组只能取到 left 到 right - 1

//1.hoare法：以数组末端元素作为基准值key
int Partion1(int* array, int left, int right) //返回值是key的下标（begin和end 重合处）
{
	int begin = left;
	int end = right - 1;
	int mid = GetMiddleIndex(array, left, right);
	Swap(&array[mid], &array[right - 1]);//三数取中法优化后将中间数放于数组末尾right-1处

	int key = array[right - 1];

	while (begin < end)
	{
		// 从左往右找比基准值大的元素，找到之后停止
		while (begin < end && array[begin] <= key)
			begin++;

		// 从右往左找比基准值小的元素，找到之后停止
		while (begin < end && array[end] >= key)
			end--;

		if (begin != end)
			Swap(&array[begin], &array[end]);//这里交换的是begin和end下标对应的数组元素的交换，并不影响begin和end的位置
	}
	//走出循环以后begin和end必相等	重要：因为begin先走，而end后走,故当begin与end重合时，也就是出循环时，begin必定落在end上，
	//而此时end在比key大的区间的第一个元素处，然后就可以直接将重合的这个位置和key交换，就可以达到用基准值key将数组分为[左比其小][右比其大]的两个区间
	if (begin != right - 1)//将基准值放于begin和end的重合处
		Swap(&array[begin], &array[right - 1]);

	return begin;
}

//2.挖坑法：先用begin去找第一个比key大的元素
//	然后用该元素去覆盖key处（这里应该理解为：用key作为基准值将数组末尾处【三数取中法处理以后才是数组末尾，也可能不是】的值保存，也就相当于这里有一个可以填充（掩盖）的坑）
//  让begin从前往后走去寻找比key大的元素，然后填end处坑
//	让end从后往前走去寻找比key小的元素，然后填begin处坑
//  每填坑完一次坑以后让begin++或者end--移动一个去循环
//	最后出循环和hoare法一样：begin先走一步导致begin和end重合，而此时end处是坑（因为上一次end已经赋值给begin处填坑），用key来填该坑
int Partion2(int* array, int left, int right) //返回值是key的下标（begin和end 重合处）
{
	int begin = left;
	int end = right - 1;
	int mid = GetMiddleIndex(array, left, right);
	Swap(&array[mid], &array[right - 1]);

	int key = array[right - 1];//也是用数组末尾元素（三数取中法优化后将中间值放于数组末尾即可）作为基准值

	while (begin < end)
	{
		// 从前往后找比基准值大的元素，找到后填充end位置的坑
		while (begin < end && array[begin] <= key)
			begin++;

		// 填充end位置的坑：因为end位置处用key已经标记，所以覆盖其以后还可以用key找到它
		if (begin < end)
		{
			array[end] = array[begin];
			end--;
		}

		// 从后往前找比基准值小的元素，找到后填充begin位置的坑
		while (begin < end && array[end] >= key)
			end--;

		if (begin < end)
		{
			array[begin] = array[end];
			begin++;
		}
	}
	//出循环和hoare法一样：begin先走一步导致begin和end重合，而此时end处是坑（因为上一次end已经赋值给begin处填坑），可以直接用key来填即可
	array[begin] = key;
	return begin;
}

//3.前后指针法：	cur：当前指针，无条件往后走，若cur处的值小于基准值key，那么让prev往后走一个；
//					prev:标记开始时cur的前一个位置处  （1）当cur处的值小于基准值key时，prev往后走一个	
//													  （2）当cur走完数组，循环结束后，prev再往后一个
//					当cur走完数组，循环结束后，prev再往后一个以后，交换prev和key出的值就OK了
int Partion3(int* array, int left, int right) //返回值是key的下标（begin和end 重合处）
{
	int cur = left;// cur标记当前指针的位置
	int prev = cur - 1;//prev标记开始时cur的前一个位置处
	int mid = GetMiddleIndex(array, left, right);
	Swap(&array[mid], &array[right - 1]);
	int key = array[right - 1];//也是用数组末尾元素（三数取中法优化后将中间值放于数组末尾即可）作为基准值


	while (cur < right)//cur这个标记从数组开始走到结尾，则循环结束（每次循环往后走一个）
	{
		if (array[cur] < key && ++prev != cur)//当arr[cur]的值小于key时，prev才往后走一个
											  //注意：当&&前面条件成立的话才会执行后面的++prev
			Swap(&array[cur], &array[prev]);//当prev+1不等于cur时，即pre和cur中间有[ >=key ]元素，并且prev当前一定指向的是[ >=key ]元素，然后交换cur处的元素和prev处的元素

		++cur; //每次循环pcur无条件往后走一个
	}
	///重点理解///if后面括号里的++prev会让prev往后走一个，与判断提交无关，若if (array[cur] < key && ++prev != cur)这种情况，前面的array[cur] < key条件成立了以后才会执行++prev
	if (++prev != right)//出循环后（cur走到数组末尾的下一个位置处）
						//如果prev没有走到倒数第一处[此时cur走到结尾后一处]，让prev再往后走一个（到比key大的区间的第一个元素处），将key值放入prev处
		Swap(&array[prev], &array[right - 1]);

	return prev;
}

void QuickSort(int* array, int left, int right)
{
	if (right - left < 16)//优化1：三数取中法 优化2：当递归到未排序的数组区间小于某个值（一般是16）时，采用插入排序
		InsertSort(array, right - left);
	else
	{
		// 按照基准值将区间分割成左右两部分
		// 左侧小于基准值 基准值 右侧大于基准值
		int div = Partion1(array, left, right);//Partion函数的区间都是左闭右开，[left, right)：数组大小是[0-(size-1)],传的是left:0   right: size  故[left, right)表示的是数组区间 因为函数体中的 end = right - 1;
		QuickSort(array, left, div);//同理如上，div取不到的
		QuickSort(array, div + 1, right);//同理如上，right取不到的
	}
}


#if 0
//非递归实现快排
#include "Stack.h"
void QuickSortNor(int* array, int size)
{
	int left = 0;
	int right = size;
	Stack s;
	StackInit(&s);
	StackPush(&s, right);
	StackPush(&s, left);

	while (!StackEmpty(&s))
	{
		left = StackTop(&s);
		StackPop(&s);
		right = StackTop(&s);
		StackPop(&s);

		if (right - left > 1)
		{
			int div = Partion3(array, left, right);

			// 保存右半部分区间
			StackPush(&s, right);
			StackPush(&s, div + 1);

			// 保存左半部分区间
			StackPush(&s, div);
			StackPush(&s, left);
		}
	}
}
#endif





int main()
{
	int arr[] = { 3, 4, 2, 9, 1, 7, 6, 0, 8, 5 };
	QuickSort(arr, 0, sizeof(arr) / sizeof(arr[0]));
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
		printf("%d ", arr[i]);
	printf("\n");
	system("pause");
	return 0;
}

