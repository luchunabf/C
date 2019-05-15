#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char password[] = "123456";
	char arr[10];
	int i = 0;
	for (i = 0; i < 3;i++)
	{
		printf("ÇëÊäÈëÃÜÂë£º");
		scanf("%s", arr);
		if (strcmp(password,arr) == 0)
			break;
		else
			printf("ÃÜÂë´íÎó£¬ÇëÖØÐÂÊäÈë£º");
	}
	if (i == 3)
		printf("ÍË³ö³ÌÐò\n");
	else
		printf("µÇÂ¼³É¹¦\n");


	system("pause");
	return 0;
}
