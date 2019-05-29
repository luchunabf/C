#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>

#pragma once
typedef int HPDataType;

typedef int(*PCOM)(HPDataType, HPDataType);

// 堆中元素进行小于比较 
int Less(HPDataType left, HPDataType right);

// 堆中元素进行大于比较 
int Greater(HPDataType left, HPDataType right);


typedef struct Heap
{
	HPDataType* _array;
	int _size;
	int _capacity;
	PCOM Compare;
}Heap, *pHeap;

// 用数组初始化堆 
void InitHeap(Heap* hp, HPDataType* array, int size, PCOM compare);

// 初始化一个空堆 
void InitEmptyHeap(Heap* hp, int capacity, PCOM compare);

// 在堆中插入值为data的元素 
void InsertHeap(Heap* hp, HPDataType data);

// 删除堆顶元素 
void EraseHeap(Heap* hp);

// 获取堆中有效元素个数 
int HeapSize(Heap* hp);

// 检测堆是否为空堆 
int HeapEmpty(Heap* hp);

// 获取堆顶元素 
HPDataType HeapTop(Heap* hp);

// 销毁堆 
void DestroyHeap(Heap* hp);
