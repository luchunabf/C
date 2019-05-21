#pragma once
#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#include<stdlib.h>

typedef int DLDataType;
typedef struct DNode
{
	DLDataType data;
	struct DNode* _pPre;
	struct DNode* _pNext;
}DNode, *PDNode;

typedef struct DList
{
	PDNode _pHead;
}DList, *PDList;

void DListInit(PDList s);
void DListPushBack(PDList s, DLDataType data);
void DListPopBack(PDList s);
void DListPushFront(PDList s, DLDataType data);
void DListPopFront(PDList s);
void DListInsert(PDNode pos, DLDataType data);
void DListErase(PDNode pos);
void DListClear(PDList s);
void DListDestroy(PDList s);
void DListPrint(PDList s);


PDNode DListFind(PDList s, DLDataType data);
void DListRemove(PDList s, DLDataType data);