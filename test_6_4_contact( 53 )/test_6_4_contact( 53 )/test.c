#include "contact.h"

//int main()
//{
//	ContactBook cb;
//	ContactBookInit(&cb);
//	Contact con1;
//	strcpy(con1._name, "peter");
//	strcpy(con1._address, "����δ������屰뵺");
//	strcpy(con1._tel, "18241321212");
//	con1._age = 18;
//	ContactBookAppend(&cb, &con1);
//
//	Contact con2;
//	strcpy(con2._name, "Сʱ");
//	strcpy(con2._address, "����δ������屰뵺");
//	strcpy(con2._tel, "18241321214");
//	con2._age = 19;
//	ContactBookAppend(&cb, &con2);
//
//	ContactPrint(&cb);
//	ContactBookSave(&cb, "contactbookbin.txt");
//
//	ContactBookDestory(&cb);
//
//	return 0;
//}
void menu()
{
	printf("********************************************\n");
	printf("1.�����ϵ�ˣ� 2.ɾ����ϵ��\n");
	printf("3.������ϵ�ˣ� 4.�޸���ϵ��\n");
	printf("5.���浽�ļ��� 6.���ļ�����\n");
	printf("7.��ӡͨѶ¼�� 0.�˳�\n");
	printf("********************************************\n");
}

int main()
{
	ContactBook cb;
	ContactBookInit(&cb);
	Contact con;
	//ContactBookLoad(&cb, "contactbookbin.txt");
	ContactBookLoad(&cb, "53.txt");
	int option = -1;
	while (option != 0)
	{
		menu();
		scanf("%d", &option);
		if (option == 1)
		{
			printf("�����������������绰����ͥסַ������:\n");
			scanf("%s", con._name);
			scanf("%s", con._tel);
			scanf("%s", con._address);
			scanf("%d", &con._age);
			ContactBookAppend(&cb, &con);
		}
		else if (option == 2)
		{
			const char name[24];
			printf("��������ϵ�˵�����:");
			scanf("%s", name);
			ContactBookDelete(&cb, name);
		}
		else if (option == 3)
		{
			const char name[24];
			printf("��������ϵ�˵�����:");
			scanf("%s", name);
			Contact* pcon = ContactBookFind(&cb, name);
			if (pcon == NULL)
			{
				printf("û���ҵ���ϵ��\n");
			}
			else
			{
				printf("����:%s,�绰:%s,��ͥסַ:%s,����:%d\n", pcon->_name, pcon->_tel, pcon->_address, pcon->_age);
			}
		}
		else if (option == 5)
		{
			ContactBookSave(&cb, "53.txt");
		}
		else if (option == 6)
		{
			ContactBookLoad(&cb, "53.txt");
		}
		else if (option == 7)
		{
			ContactPrint(&cb);
		}
		else if (option == 0)
		{
			break;
		}
	}

	ContactBookDestory(&cb);

	return 0;
}