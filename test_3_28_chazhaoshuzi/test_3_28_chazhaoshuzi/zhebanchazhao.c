#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//输入一个数组，先冒泡排序，而后折半查找出对应下标









//int main()
//{
//	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
//	/*printf("请输入有序数组arr=:");
//	scanf("%d %d %d %d %d %d %d %d", &arr[]);*/
//	int k=0;
//	printf("请输入要查找的数：\n");
//	scanf("%d", &k);
//	int left = 0;
//	int right = sizeof arr/sizeof arr[0];
//	int mid = 0;
//	while (left <= right)
//	{
//		mid = left + (right - left) / 2;
//		if (arr[mid]<k)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid]>k)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			
//			break;
//		}
//	}
//
//	if (left <= right)
//	{
//		printf("找到了，下标是%d\n", mid);
//	}
//	else
//	{
//		printf("找不到\n-1/n");
//		/*return -1;*/
//	}
//		
//
//
//
//	system("pause");
//	return 0;
//}


//冒泡排序
void bub(int arr[],int sz)
{
	/*int arr[] = { 0 };*/
	printf("请输入有序数组arr=:");
	scanf("%d %d %d %d %d", &arr);//如何设置要输入数的个数
	sz = sizeof arr / sizeof arr[0];
	for (int i = 0; i < sz-1; i++)
	{
		int flag = 0;
		for (int j = 1; j <= sz-1-i; j++)
		{
			if (arr[j]>arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
}





int main()
{
	/*int arr[] = {  1, 2, 3, 4, 5, 6, 7, 8, 9,10 };*/
	int arr[] = { 0 };
	int k = 0;
	printf("请输入要查找的数：\n");
	scanf("%d", &k);
	printf("\n");
	bub(arr, 5);
	int left = 0;
	int right = sizeof arr / sizeof arr[0]-1;
	int mid = 0;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (arr[mid]<k)
		{
			left = mid + 1;
		}
		else if (arr[mid]>k)
		{
			right = mid - 1;
		}
		else
		{
            printf("找到了，下标是%d\n", mid);
			break;
		}
	}

	if (left > right)
	
		printf("找不到\n-1\n");
		/*return -1;*/
	




	system("pause");
	return 0;
}