#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include<stdlib.h>

char *turn_one(char *str) //ÿ�ε��ý��ַ�������ߵ�ֵ�ŵ����ұ�
{
	char *get = str;
	char *get_get = get;
	char tmp = *str;
	str++;
	while (*str != '\0')
		*(get++) = *(str++);
	*get = tmp;
	return get_get;
}
char *turn_left(char *str, int num) //�����������ַ�����
{
	int i = 0;
	for (i = 0; i<num - 1; i++)
		turn_one(str);
	return turn_one(str);
}

int jude_same(char *str1, char *str2, int len1) //�ж��Ƿ�Ϊ��ת֮���ַ���
{
	int i = 0;
	for (i = 0; i<len1; i++){                   //������һ���ַ���ÿ������һ���ַ���Ȼ������һ���ַ����Ƚ�
		if (strcmp(turn_left(str1, i), str2) == 0)
			return 1;
	}
	return 0;
}
int main()
{
	char str1[] = "hello";                  //str1��str2Ϊ��������
	int len1 = strlen(str1);
	char str2[] = "llohe";
	int len2 = strlen(str2);
	if (len1 == len2)                        //�������ַ�����С��Ƚ���Ƚ�
	{
		if (jude_same(str1, str2, len1))
			printf("��\n");
		else printf("����");
	}
	else printf("����\n");
	system("pause");
	return 0;
}