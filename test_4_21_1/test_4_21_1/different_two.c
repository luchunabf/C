#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 4, 3, 2, 1 };
	for (int i = 0; i < 10; i++)
	{
		int flag=0;
		for (int j = 0; j < 10; j++)
		{
			if ((arr[i] == arr[j]) && (i!=j))
				flag++;
			
		}
		if (flag==0)
		printf("%d\n", arr[i]);
	}
	system("pause");
	return 0;
}