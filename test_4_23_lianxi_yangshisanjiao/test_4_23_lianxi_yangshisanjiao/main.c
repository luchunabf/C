#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//#define N 10
int main()
{
	int N = 0;
	printf("«Î ‰»Î–– ˝N£∫");
	scanf("%d", &N);
	printf("\n");
	int arr[100][100] = { 0 };
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			arr[i][0] = arr[i][i] = 1;
			/*printf("%d ", arr[i][j]);*/
		}
		for (int j = 1; j <= i; j++)
		{
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
		for (int j = 0; j <= i; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");

	}
	system("pause");
	return 0;
}