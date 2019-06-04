#ifndef __CONTACT_H__
#define __CONTACT_H__

#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>



enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	EMPTY,
	SORT
};

#define MAX 1000

#define MAX_NAME 20
#define SEX_MAX 5
#define TELE_MAX 12
#define ADDR_MAX 30

#define DEFAULT_SZ 3
#define INC_SZ 2


typedef struct PeoInfo
{
	char name[MAX_NAME];
	char sex[SEX_MAX];
	short int age;
	char tele[TELE_MAX];
	char addr[ADDR_MAX];
}PeoInfo;

typedef struct Contact
{
	//PeoInfo data[MAX];//�������
	PeoInfo* data;
	int sz;//ͨѶ¼����Ч��Ϣ����
	int capacity;//���ͨѶ¼�ĵ�ǰ�������
}Contact;

void InitContact(Contact* pcon);
void DestroyContact(Contact* pcon);
void AddContact(Contact* pcon);
void ShowContact(const Contact* pcon);
void DelContact(Contact* pcon);
int  CheckCapacity(Contact* pcon);
void SaveContact(Contact* pcon);
void LoaContact(Contact* pcon);

#endif //__CONTACT_H__