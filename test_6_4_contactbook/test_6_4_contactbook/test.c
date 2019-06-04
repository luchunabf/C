#define _CRT_SECURE_NO_WARNINGS 1
#include "contactbook.h"

void menu()
{
	printf("*****************************\n");
	printf("***** 1.add      2.delete ***\n");
	printf("***** 3.find     4.change ***\n");
	printf("***** 5.save     6.load   ***\n");
	printf("***** 7.print    0.exit   ***\n");
	printf("*****************************\n");
}

int main()
{
	contactbook cb;
	contactbookInit(&cb);
	contact con;
	//contactbookLoad(&cb, file);
	contactbookLoad(&cb, "�ҵ�ͨѶ¼.txt");
	int option = -1;
	while (option != 0)
	{
		menu();
		printf("��ѡ��");
		printf("\n");
		scanf("%d", &option);
		if (option == 1)
		{
			printf("���������룺�������绰��סַ������\n");
			scanf("%s", con._name);
			scanf("%s", con._tel);
			scanf("%s", con._adr);
			scanf("%d", con._age);
			contactbookAppend(&cb, &con);
		}
		else if (option == 2)
		{
			const char name[20];
			printf("������Ҫɾ�����˵�������");
			scanf("%s", name);
			contactbookDelete(&cb, name);
		}
		else if (option == 3)
		{
			const char name[20];
			printf("������Ҫ���ҵ��˵�������");
			scanf("%s", name);
			contact* pcon = contactbookFind(&cb, name);
			if (pcon == NULL)
			{
				printf("�޸���ϵ��\n");
			}
			else
			{
				printf("������%s���绰��%s��סַ��%s�����䣺%d", pcon->_name, pcon->_tel, pcon->_adr, pcon->_age);
			}
		}
		else if (option == 5)
		{
			contactbookSave(&cb, "�ҵ�ͨѶ¼.txt");
		}
		else if (option == 6)
		{
			contactbookLoad(&cb, "�ҵ�ͨѶ¼.txt");
		}
		else if (option == 7)
		{
			contactbookPrint(&cb);
		}
		else if (option == 0)
		{
			break;
		}
	}
	contactbookDestory(&cb);
	return 0;
}