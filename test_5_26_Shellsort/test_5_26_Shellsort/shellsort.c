#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//(1)ϣ������Ȳ����������һ��gap��size / 3 + 1 ---> 1 ��ѭ��
//(2)������������ƶ�1ȫ����Ϊ�ƶ�gap��ֻ��i����Ҫ�ƶ�gap������++i��
void Shellsort(int* arr, int size)
{
	int gap = size / 3 + 1;
	for (; gap >= 1; --gap)//����while(gap > 0)
	{
		//for (int i = 1; i < size; ++i)//ע��������i++��������i+gap����Ϊ�����ö���ͬʱȥ��������
		for (int i = gap; i < size; ++i)//////////////ע��i�Ǵ�gap��ʼ��
		{								/////////////��Ϊgap֮ǰ��Ԫ�����ڷ���gap����ÿ���0���±�Ԫ�أ������ǲ���ֱ�Ӵ�1��Ԫ�ؿ�ʼ����Ϊ��һ��Ԫ��ֻ��һ��Ԫ�ر�����
			int key = arr[i];
			int end = i - gap;
			while (end >= 0 && key < arr[end])
			{
				arr[end + gap] = arr[end];
				end -= gap;
			}
			arr[end + gap] = key;
		}
		//����while(gap > 0)��ʱ��
		//������Ҫ��� gap-=1��
	}
}
int main()
{
	int arr[6] = { 5, 2, 4, 6, 1, 3 };
	int size = sizeof(arr) / sizeof(arr[0]);
	Shellsort(arr, size);
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}