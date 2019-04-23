#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//逆转数组
//int main()
//{
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
//	int left = 0; 
//	int right = sizeof(arr) / sizeof(arr[0]) - 1;
//	while (left < right)
//	{
//		int tmp;
//		tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right--;
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	system("pause");
//	return 0;
//}


//逆转二进制位

//unsigned int reverse_bit1(unsigned int value)
//{
//	int i = 0;
//	unsigned int num = 0;
//	for (i = 0; i < 32; i++)
//		num += (((value >> i) & 1)* (pow(2,(31-i))));
//	return num;
//	
//}
unsigned int reverse_bit2(unsigned int value)
{
	unsigned int num = 0;
	for (int i = 0; i < 32; i++)
	{
		num <<= 1;//将一个左移1位使其最后的1位（二进制第一位）为0
		//0|x == x(对于第1位一直为0)
		num |= ((value >> i) & 1);//将value的二进制每一位赋给num二进制中最右边的位（第一位）
	}
	return num;
}
int main()
{
	int a = 0;
	scanf("%d", &a);
	/*int ret = reverse_bit1(a);*/
	int ret = reverse_bit2(a);
	printf("%u\n", ret);//输出的时候用%u
	system("pause");
	return 0;
}
