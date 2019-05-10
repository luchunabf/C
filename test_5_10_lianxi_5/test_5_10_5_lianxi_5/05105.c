#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int main()
{
#pragma pack(2)
	struct S1
	{
		char c1;
		int i;
		char c2;
	};
#pragma pack()
	printf("%d\n", sizeof(struct S1));//8
	
#pragma pack(1)
	struct S2
	{
		char c1;
		int i;
		char c2;
	};
#pragma pack()
	printf("%d\n", sizeof(struct S2));//6
	system("pause");
	return 0;
}
