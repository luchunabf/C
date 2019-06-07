#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int count = 3;
	char password[] = { "123456" };//必须用双引号赋值
	char input[] = {0};//方括号别忘记
	while (count)
	{
		printf("请输入密码");
		scanf("%s", &input);
		if (strcmp(password, input) == 0)
		{
			printf("恭喜你，登录成功\n");
			break;
		}
		else if (count!=1)//最后一次输错不提醒重新输入
		{
			printf("密码错误，请重新输入\n");
		}
		count--;
	}
	if (count == 0)
	{
		printf("退出程序\n");
	}


	system("pause");
	return 0;
}