#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>

#pragma once
typedef int HPDataType;

typedef int(*PCOM)(HPDataType, HPDataType);

// ����Ԫ�ؽ���С�ڱȽ� 
int Less(HPDataType left, HPDataType right);

// ����Ԫ�ؽ��д��ڱȽ� 
int Greater(HPDataType left, HPDataType right);


typedef struct Heap
{
	HPDataType* _array;
	int _size;
	int _capacity;
	PCOM Compare;
}Heap, *pHeap;

// �������ʼ���� 
void InitHeap(Heap* hp, HPDataType* array, int size, PCOM compare);

// ��ʼ��һ���ն� 
void InitEmptyHeap(Heap* hp, int capacity, PCOM compare);

// �ڶ��в���ֵΪdata��Ԫ�� 
void InsertHeap(Heap* hp, HPDataType data);

// ɾ���Ѷ�Ԫ�� 
void EraseHeap(Heap* hp);

// ��ȡ������ЧԪ�ظ��� 
int HeapSize(Heap* hp);

// �����Ƿ�Ϊ�ն� 
int HeapEmpty(Heap* hp);

// ��ȡ�Ѷ�Ԫ�� 
HPDataType HeapTop(Heap* hp);

// ���ٶ� 
void DestroyHeap(Heap* hp);
