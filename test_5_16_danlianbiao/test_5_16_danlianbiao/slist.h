#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include<stdlib.h>


typedef int SDataType;

// ����Ľڵ� 
typedef struct SListNode
{
	SDataType _data;
	struct SListNode* _pNext;
}Node, *PNode;


// ����Ľṹ����һ��ͷָ�뱣�������һ���ڵ�ĵ�ַ 
typedef struct SList
{
	PNode _pHead; // ָ�������еĵ�һ���ڵ� 
}SList, *PSList;


// ����ĳ�ʼ�� 
void SListInit(SList* s);

// ������s���һ���ڵ�����ֵΪdata�Ľڵ� 
void SListPushBack(SList* s, SDataType data);

// ɾ������s���һ���ڵ� 
void SListPopBack(SList* s);

// ������s��һ���ڵ�ǰ����ֵΪdata�Ľڵ� 
void SListPushFront(SList* s, SDataType data);

// ɾ������s�ĵ�һ���ڵ� 
void SListPopFront(SList* s);

// �������posλ�ú����ֵΪdata�Ľڵ� 
void SListInsert(PNode pos, SDataType data);

// ɾ������s��posλ�õĽڵ� 
void SListErase(SList* s, PNode pos);

// �������в���ֵΪdata�Ľڵ㣬�ҵ����ظýڵ�ĵ�ַ�����򷵻�NULL 
PNode SListFind(SList* s, SDataType data);

// ��ȡ��������Ч�ڵ�ĸ��� 
size_t SListSize(SList* s);

// ��������Ƿ�Ϊ�� 
int SListEmpty(SList* s);

// ����������Ч�ڵ���� 
void SListClear(SList* s);

// �������� 
void SListDestroy(SList* s);

//��ӡ������
void SListPrint(SList* s);

//���Ե�����
void TestSlist();


////����Ľڵ�
//typedef int SDataType;
//typedef struct SListNode
//{
//	SDataType _data;
//	struct SListNode* _pNext;
//}Node,*pNode;
////��װ����
//typedef struct SList
//{
//	pNode _pHead;
//}SList,*pSList;
//����Ľڵ�
//typedef int SDateType;
//typedef struct SListNode
//{
//	SDataType _data;
//	struct SListNode* _pNext;
//}sNode, *pSNode;
////����İ�װ
//typedef struct SList
//{
//	PNode _pHead;
//}SList,*pSList;