#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

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
//������ֱ���������
int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	for (int i = 9; i >= 0; i--)//ע��arr�Ǵ�arr[0]��arr[9]�ģ������ӡ����ֵ��ע��
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}