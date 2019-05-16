#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char x;
	char y;
	printf("Çë¼üÅÌÊäÈëÈÎÒâ×ÖÄ¸£º");
	scanf("%c", &x);
	y = 'a' - 'A';
	if ((x >= 'a')&&(x <= 'z'))
	{
		x = x - y;
		printf("%c\n", x); 
	}
	else if ((x >= 'A')&&(x <= 'Z'))
	{
		x = x + y; 
		printf("%c\n", x);
	}
	else
		printf("%c\n", x);
	
	system("pause");
	return 0;
}

