#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

typedef struct Contact
{
	char _name[24];
	char _tel[16];
	char _address[64];
	int  _age;
}Contact;

//typedef struct Contact Contact;

// ͨѶ¼
typedef struct ContactBook
{
	Contact* _con_array;
	size_t _size;		// ��ϵ�˸���
	size_t _capacity;	// ����
}ContactBook;

void ContactBookInit(ContactBook* pbook);
void ContactBookDestory(ContactBook* pbook);
void ContactBookAppend(ContactBook* pbook, Contact* con);
void ContactBookDelete(ContactBook* pbook, const char* name);
Contact* ContactBookFind(ContactBook* pbook, const char* name);
void ContactBookSave(ContactBook* pbook, const char* file);
void ContactBookLoad(ContactBook* pbook, const char* file);
void ContactPrint(ContactBook* pbook);






