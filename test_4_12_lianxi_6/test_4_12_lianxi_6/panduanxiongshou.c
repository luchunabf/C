#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//����ɱ��������
int main()
{
	/*int a, b, c, d = 0;*/
	int killer;
	for (killer = 'A'; killer <= 'D'; killer++)
	{
		if ((killer != 'A')
			+ (killer == 'C')
			+ (killer == 'D')
			+ (killer != 'D') == 3)
			printf("�����ǣ�%c\n", killer);
	}
	system("pause");
	return 0;
}