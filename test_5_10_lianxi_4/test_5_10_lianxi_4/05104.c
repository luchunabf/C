#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	struct S1
	{
		char c1;
		int i;
		char c2;
	};
	printf("%d\n", sizeof(struct S1));
	struct S2
	{
		char c1;
		char c2;
		int i;
	};
	printf("%d\n", sizeof(struct S2));
	struct S3
	{
		double d;
		char c;
		int i;
	};
	printf("%d\n", sizeof(struct S3));
	struct s4
	{
		char c1;
		struct S3 s3;
		double d;
	};
	printf("%d\n", sizeof(struct s4));
	system("pause");
	return 0;
}
