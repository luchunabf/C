#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//�Զ���strlen����
static int mystrlen(char* str)
{
	int count = 0;
	while (*str != '\0')
	{
		str++;
		count++;
	}
	return count;
}
//�������������ַ�������
static void reverse(char* start, char* end)
{

	while (start < end)
	{
		char tmp = *start;
		*start = *end;
		*end = tmp;
		start++;
		end--;
	}

}
//�������ú���
void reverse_str(char* str)
{
	int sz = mystrlen(str);//����ַ�������
	//������ת
	reverse(str, str + sz - 1);//���Ҫ��1
	//�ֲ���ת
	while (*str!='\0')
	{
		char* start = str;//��������ַ������start
		while ((*str != '\0') && (*str != ' '))//��õ��ʵĽ���
		{
			str++;//��ַ�����ƶ�
		}
		//������ת
		reverse(start, str - 1);//���Ҫ��1
		while (*str == ' ')
		{
			str++;//��strָ��ո��ʱ���ƶ�����һ�����ʵ���ʼλ��
		}
	}
}
int main()
{
	char arr[100] = { 0 };
	printf("������һ����ո���ַ�����\n");
	//
	//�ַ����������ܱ��޸�
	//char* str1 = "12345 6789";
	//char str[100];
	//scanf: �����ո���߻��н���
	//scanf("%s", str);
	//gets����ȡһ�����ݣ��������н���
	gets(arr);
	reverse_str(arr);
	printf("%s\n", arr);
	system("pause");
	return 0;
}