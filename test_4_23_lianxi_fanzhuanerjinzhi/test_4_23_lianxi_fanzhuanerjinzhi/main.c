#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//��ת����
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


//��ת������λ

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
		num <<= 1;//��һ������1λʹ������1λ�������Ƶ�һλ��Ϊ0
		//0|x == x(���ڵ�1λһֱΪ0)
		num |= ((value >> i) & 1);//��value�Ķ�����ÿһλ����num�����������ұߵ�λ����һλ��
	}
	return num;
}
int main()
{
	int a = 0;
	scanf("%d", &a);
	/*int ret = reverse_bit1(a);*/
	int ret = reverse_bit2(a);
	printf("%u\n", ret);//�����ʱ����%u
	system("pause");
	return 0;
}
