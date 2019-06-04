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
	contactbookLoad(&cb, "我的通讯录.txt");
	int option = -1;
	while (option != 0)
	{
		menu();
		printf("请选择：");
		printf("\n");
		scanf("%d", &option);
		if (option == 1)
		{
			printf("请依次输入：姓名，电话，住址，年龄\n");
			scanf("%s", con._name);
			scanf("%s", con._tel);
			scanf("%s", con._adr);
			scanf("%d", con._age);
			contactbookAppend(&cb, &con);
		}
		else if (option == 2)
		{
			const char name[20];
			printf("请输入要删除的人的姓名：");
			scanf("%s", name);
			contactbookDelete(&cb, name);
		}
		else if (option == 3)
		{
			const char name[20];
			printf("请输入要查找的人的姓名：");
			scanf("%s", name);
			contact* pcon = contactbookFind(&cb, name);
			if (pcon == NULL)
			{
				printf("无该联系人\n");
			}
			else
			{
				printf("姓名：%s，电话：%s，住址：%s，年龄：%d", pcon->_name, pcon->_tel, pcon->_adr, pcon->_age);
			}
		}
		else if (option == 5)
		{
			contactbookSave(&cb, "我的通讯录.txt");
		}
		else if (option == 6)
		{
			contactbookLoad(&cb, "我的通讯录.txt");
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