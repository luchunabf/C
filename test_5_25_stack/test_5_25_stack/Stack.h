#include<stdio.h>
#include<assert.h>
#include<malloc.h>

typedef int SDataType;
typedef struct Stack
{
	SDataType* _array;
	int _size;
	int _capacity;
}Stack;

void StackInit(Stack* ps);
void StackPush(Stack* ps, SDataType data);
void StackPop(Stack* ps);
SDataType StackTop(Stack* ps);
int StackSize(Stack* ps);
int StackEmpty(Stack* ps);
void StackDestroy(Stack* ps);