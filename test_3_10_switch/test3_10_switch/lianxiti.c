#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include<stdlib.h>
int main()
{
	//int n = 1;
	//int m = 2;
	//switch (n)
	//{
	//case 1:
	//	m++;
	//case 2:
	//	n++;
	//case 3:
	//	switch (n)
	//	{//switch‘ –Ì«∂Ã◊ π”√
	//	case 1:
	//		n++;
	//	case 2:
	//		m++;
	//		n++;
	//		break;
	//	}
	//case 4:
	//	m++;
	//	break;
	//default:
	//	break;
	//}
	//printf("m = %d, n = %d\n", m, n);
	/*int i = 0;
	while (i <= 10)
	{
		i = i + 1;
		if (i == 5)
			continue;
		printf("%d", i);
	}*/
	int x, y;
	for (x = 1, y = 1; x < 2 && y < 5; ++x, y++)
	{
		printf("hehe\n");
	}
	system("pause");
	return 0;
}