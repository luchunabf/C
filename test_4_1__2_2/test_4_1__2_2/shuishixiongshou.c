#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int main()
{
	char m = '0';
	for (m = 'A'; m <= 'D'; m++)//判断谁 谁循环
	{
		if (
			(m != 'A') +
			(m == 'C') +
			(m == 'D') +
			(m != 'D') == 3//条件为真则为1
			)
			printf("%c\n", m);
	}
	system("pause");
	return 0;
}