#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
unsigned int reverse_bit(unsigned int value)
{
	int i = 0;
	unsigned int num = 0;
	for (i = 0; i < 32; i++)
	{
		num += (((value >> i) & 1)*pow(2, (31 - i)));
	}
	return num;
}
int main()
{
	unsigned int a = 0;
	printf("ÇëÊäÈëaµÄÖµ£º\n");
	scanf("%d", &a);
	unsigned int ret = reverse_bit(a);
	printf("%u\n", ret);
	system("pause");
	return 0;
}