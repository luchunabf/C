#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//int main()
//{
//	int arr[5] = { 0 };
//	int* p;
//	printf("����������Ԫ�أ�\n");
//	p = arr;
//	for (int i = 0; i < 5; i++)
//	{
//		scanf("%d", &arr[i]);
//    }
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%d ", *p);
//		p++;
//	}
//	system("pause");
//	return 0;
//}
int main()
{
	int arr[5] = { 0 };
	int* p;
	printf("����������Ԫ�أ�\n");
	p = arr;
	for (int i = 0; i < 5; i++)
	{
		//scanf("%d", &arr[i]);
		scanf("%d", p++);//�����ʱ��Ĭ����Ԫ�ؼ��ǿո�
	}
	p = arr;
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", *p++);
		/*printf("%d ", *p);
		p++;*/
	}
	system("pause");
	return 0;
}