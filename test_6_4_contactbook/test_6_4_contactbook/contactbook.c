#define _CRT_SECURE_NO_WARNINGS 1
#include"contactbook.h"

void contactbookInit(contactbook* pbook)
{
	assert(pbook);
	pbook->_array = (contact*)malloc(sizeof(contact)* 8);
	if (pbook->_array == NULL)
	{
		assert(0);
		return;
	}
	pbook->_capacity = 8;
	pbook->_size = 0;
}
void contactbookDestory(contactbook* pbook)
{
	assert(pbook);
	free(pbook->_array);
	pbook->_array = NULL;
	pbook->_capacity = pbook->_size = 0;
}
void contactbookAppend(contactbook* pbook, contact* pcon)
{
	assert(pbook && pcon);
	if (pbook->_size == pbook->_capacity)//其实就是checkcapacity
	{
		pbook->_capacity *= 2;
		contact* newarray = realloc(pbook->_array, sizeof(contact)* pbook->_capacity);
		if (NULL == newarray)
		{
			assert(0);
			return;
		}
		pbook->_array = newarray;
	}
	contact* array = pbook->_array;//标记
	size_t i = pbook->_size;
	strcpy(array[i]._name, pcon->_name);
	strcpy(array[i]._tel, pcon->_tel);
	strcpy(array[i]._adr, pcon->_adr);
	array->_age = pcon->_age;
	pbook->_size++;
}

contact* contactbookFind(contactbook* pbook, const char* name)
{
	assert(pbook && name);
	for (int i = 0; i < pbook->_size; ++i)
	{
		if (strcmp(name, pbook->_array[i]._name) == 0)//注意array[i]
			return &pbook->_array[i];
	}
	return NULL;
}
void contactbookDelete(contactbook* pbook, const char* name)
{
	contact* pcon = contactbookFind(pbook, name);
	if (pcon == NULL)
	{
		printf("要删除的联系人不存在\n");
		return;
	}
	while (pcon < (pbook->_array + (pbook->_size - 1)))
	{
		memcpy(pcon, pcon + 1, sizeof(contact));
		pcon++;
	}
	pbook->_size--;
}
void contactbookSave(contactbook* pbook, const char* file)
{
	FILE* pf = fopen(file, "wb");
	if (NULL == pf)
	{
		printf("打开文件失败\n");
		exit(-1);
	}
	contact* array = pbook->_array;//标记  为什么要标记？
	for (int i = 0; i < pbook->_size; ++i)
	{
		fwrite(&array[i], sizeof(contact), 1, pf);
	}
	fclose(pf);
}
void contactbookLoad(contactbook* pbook, const char* file)
{
	FILE* pf = fopen(file, "rb");
	if (NULL == pf)
	{
		printf("打开文件失败\n");
		exit(-1);
	}
	contact con;////////////////////////
	while (fread(&con, sizeof(contact), 1, pf) == 1)
	{
		contactbookAppend(pbook, &con);
	}
	fclose(pf);
}
void contactbookPrint(contactbook* pbook)
{
	assert(pbook);
	for (int i = 0; i < pbook->_size; ++i)
	{
		printf("===================================\n");
		printf("姓名：%s\n", pbook->_array[i]._name);
		printf("电话：%s\n", pbook->_array[i]._tel);
		printf("地址：%s\n", pbook->_array[i]._adr);
		printf("年龄：%d\n", pbook->_array[i]._age);
		printf("===================================\n");
	}
}

