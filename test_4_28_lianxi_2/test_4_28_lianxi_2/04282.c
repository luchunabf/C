#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	char* c[] = { "ENTER", "NEW", "POINT", "FIRST" };//һ���ַ�ָ�����飬���������Ԫ����E,N,P,F���׸��ַ����ĵ�ַ����ַָ��"ENTER", "NEW", "POINT", "FIRST"
	///////����ֱ�Ӵ��"ENTER", "NEW", "POINT", "FIRST"����������ǵĵ�ַ
	char** cp[] = { c + 3, c + 2, c + 1, c };//�����ַ�ָ�����飬����ͬ��
	char*** cpp = cp;//����ָ�룬ָ��ĵ�ַ�ĵ�ַ
	printf("%s\n", **++cpp);//POINT   ��ָ�������(*)��ʱ��ֱ�Ӿ�ָ����ָ���Ԫ��
	printf("%s\n", *--*++cpp + 3);//ER  ++cpp��ʱ��cpp������ָ�룺ָ���ָ���ָ�룩�Ѿ��ı䣬Ҫ�ر�ע�⣬����ע�����ȼ���*�����ȼ�����+���ӣ�
	printf("%s\n", *cpp[-2] + 3);//ST  cpp[-2]��(*(cpp-2)),��������cppָ��û�б� 
	printf("%s\n", cpp[-1][-1] + 1);//EW �������Ҫ�ǰ�ͼ���������û������
	system("pause");
	return 0;
}