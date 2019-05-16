#define _CRT_SECURE_NO_WARNINGS 1

#include<malloc.h>
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
// ��̬��˳��� 
//typedef int DataType;
//typedef struct SeqList
//{
//	DataType* _array;
//	int _capacity; // ˳�����ܴ�С 
//	int _size; // ˳�������ЧԪ�صĸ��� 
//}SeqList, *PSeq;

# pragma once
typedef int DataType;
typedef struct seqlist
{
	DataType* _array;
	int _size;
	int _capacity;
}SeqList, *PSeq;


//typedef struct SeqList SeqList; 
//typedef struct SeqList* PSeqList; 

// ˳���ĳ�ʼ�� 
void SeqListInit(PSeq ps, int capacity);

// ��˳����β������ֵΪdata��Ԫ�� 
void SeqListPushBack(PSeq ps, DataType data);

// ɾ��˳������һ��Ԫ�� 
void SeqListPopBack(PSeq ps);

// ��˳����ͷ������ֵΪdata��Ԫ�� 
void SeqListPushFront(PSeq ps, DataType data);

// ɾ��˳���ͷ����Ԫ�� 
void SeqListPopFront(PSeq ps);

// ��˳���posλ�ò���ֵΪdata��Ԫ�� 
void SeqListInsert(PSeq ps, int pos, DataType data);

// ɾ��˳�����posλ���ϵ�Ԫ�� 
void SeqListErase(PSeq ps, int pos);

// ��˳����в���ֵΪdata��Ԫ�أ��ҵ����ظ�Ԫ����˳����е��±꣬���򷵻�-1 
int SeqListFind(PSeq ps, DataType data);

// ���˳����Ƿ�Ϊ�գ����Ϊ�շ��ط�0ֵ���ǿշ���0 
int SeqListEmpty(PSeq ps);

// ����˳�������ЧԪ�صĸ��� 
int SeqListSize(PSeq ps);

// ����˳����������С 
int SeqListCapacity(PSeq ps);

// ��˳����е�Ԫ����� 
void SeqListClear(PSeq ps);

// ɾ��˳����е�һ��ֵΪdata��Ԫ�� 
void SeqListRemove(PSeq ps, DataType data);

// ����˳��� 
void SeqListDestroy(PSeq ps);

// ˳�������� 
void CheckCapacity(PSeq ps);

//��ӡ˳���
void SeqListPrint(PSeq ps);