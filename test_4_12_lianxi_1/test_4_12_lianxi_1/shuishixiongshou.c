#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int count_one_bits(unsigned int value)
{
	// 返回 1的位数 
	int count = 0;
	for (int i = 0; i < 32; i++)
	{
		if ((value >> i & 1) == 1)//每一位的二进制数被移位到最右边第一位然后&1，结果是1则该位位1；否则为0。
			count++;
	}
	return count;
}
int main()
{
	printf("请输入n：\n");
	int n = 0;
	scanf("%d", &n);
	int ret=count_one_bits(n);
	printf("%d\n", ret);
	system("pause");
	return 0;
}