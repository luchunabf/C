#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<assert.h>
char *left_switch(char *str, int n)
{
	assert(str);
	assert(n > 0);
	int len = strlen(str);
	int top = n%len;
	for (int i = 0; i < top; i++){
		char first = str[0];  //先取出第一个
		int j = 0;
		for (; j < len - 1; j++){
			str[j] = str[j + 1];
		}
		str[j] = first;     //加到最后面
	}
	return str;
}
int main(){
	char str[] = "ABCD";
	int n = 3;
	char *p = left_switch(str, n);
	printf("%s", p);
	system("pause");
	return 0;
}