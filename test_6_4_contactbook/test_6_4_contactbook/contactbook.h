#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<errno.h>
#include<string.h>

typedef struct contact
{
	char _name[20];
	char _tel[13];
	char _adr[30];
	int _age;
}contact;

typedef struct contactbook
{
	contact* _array;
	int _size;
	int _capacity;
}contactbook;

void contactbookInit(contactbook* pbook);
void contactbookDestory(contactbook* pbook);
void contactbookAppend(contactbook* pbook, contact* pcon);
void contactbookDelete(contactbook* pbook, const char* name);
contact* contactbookFind(contactbook* pbook, const char* name);
void contactbookSave(contactbook* pbook, const char* file);
void contactbookLoad(contactbook* pbook, const char* file);
void contactbookPrint(contactbook* pbook);