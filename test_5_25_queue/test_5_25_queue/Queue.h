#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#include<stdlib.h>
typedef int QDataType;
typedef struct QNode
{
	QDataType _data;
	struct QNode* _pNext;
}QNode,*pQNode;
typedef struct Queue
{
	pQNode _front;
	pQNode _back;
}Queue;

void QueueInit(Queue* q);
void QueuePush(Queue* q, QDataType data);
void QueuePop(Queue* q);
QDataType QueueFront(Queue* q);
QDataType QueueBack(Queue* q);
int QueueSize(Queue* q);
int QueueEmpty(Queue* q);
void QueueDestroy(Queue* q);
//void TestQueue();