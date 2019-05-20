#define _CRT_SECURE_NO_WARNINGS 1
#include "slist.h"

// 链表的初始化 
void SListInit(SList* s)
{
	assert(s);
	s->_pHead = NULL;
}

PNode BuyNewNode(SDataType data)
{
	PNode pNewNode = (PNode)malloc(sizeof(Node));//要建立一个新节点，故开辟内存的大小是节点（结构体）的大小，开辟的类型（强制类型转换）为节点的类型（PNode）
	///////////////////////////////////sizeof(不能加*)，加* 是指针
	if (NULL == pNewNode)
	{
		assert(0);
		return NULL;//函数类型是PNode，故必须有返回值NULL;
	}
	else
	{
		pNewNode->_data = data;
		pNewNode->_pNext = NULL;
		return pNewNode;
	}
}
// 在链表s最后一个节点后插入值为data的节点 
void SListPushBack(SList* s, SDataType data)
{
	assert(s);
	PNode pNewNode = BuyNewNode(data);
	//中间有啥来着,中间要判空
	if (NULL == s->_pHead)//////////////这一步必须得有，不然程序在下一步崩溃，因为头节点为NULL，再去调用s->_pHead->_pNext就是非法访问
	{
		s->_pHead = pNewNode;
	}
	else
	{
		
		PNode pcur = s->_pHead;
		while (pcur->_pNext)
		{
			pcur = pcur->_pNext;
		}
		pcur->_pNext = pNewNode;
	}
	
}



// 删除链表s最后一个节点 
void SListPopBack(SList* s)
{
	assert(s);
	if (NULL == s->_pHead)
		return;
	else if (NULL == s->_pHead->_pNext)// 只有一个节点
	{
		free(s->_pHead);
		s->_pHead = NULL;
	}
	else
	{
		PNode pPrecur = NULL;
		PNode pcur = s->_pHead;
		while (pcur->_pNext)//并不是while (pcur)
		{//这里找的是最后一个节点
		 //pPre是倒数第二个节点
		 //pCur走到最后一个节点处，并不是最后的NULL，故要用while (pcur->_pNext)来作为循环结束的判断条件
			pPrecur = pcur;///////重点理解 不需要pPrecur->pNext = pcur;
			pcur = pcur->_pNext;
		}
		free(pcur);//删除就需要free，小心容易忘记
		pPrecur->_pNext = NULL;
	}
}

// 在链表s第一个节点前插入值为data的节点 
void SListPushFront(SList* s, SDataType data)
{
	assert(s);
	PNode pNewNode = NULL;
	//中间什么来着？
	pNewNode = BuyNewNode(data);
	pNewNode->_pNext = s->_pHead;//用新节点把链表的头一连
	s->_pHead = pNewNode;//将链表的头重新（赋值）移到最前面
	//s->pHead 只是链表头节点的标记，代表的就是链表头结点
}

// 删除链表s的第一个节点 
void SListPopFront(SList* s)
{
	assert(s);
	PNode pDelNode = NULL;//头删需要用待删除的节点标记头节点
	if (NULL == s->_pHead)
		return;
	//头删不需要考虑链表只有一个节点的情况
	else 
	{/////////////////////////////////////
		pDelNode = s->_pHead;//头删需要用待删除的节点标记头节点
		//s->_pHead = s->_pHead->_pNext;//让头节点（的标记）往后走一个
		s->_pHead = pDelNode->_pNext;//注意别再写错了
		free(pDelNode);
		//pDelNode = NULL;
	}
}

// 在链表的pos位置“后”插入值为data的节点 
void SListInsert(PNode pos, SDataType data)
{
	PNode pNewNode = NULL;
	if (NULL == pos)/////////////////////////
		return;
	pNewNode = BuyNewNode(data);
	pNewNode->_pNext = pos->_pNext;
	pos->_pNext = pNewNode;
}

// 删除链表s中pos位置的节点 
void SListErase(SList* s, PNode pos)
{
	assert(s);
	if ((NULL == pos) || (NULL == s->_pHead))///////////////////
		//pos的位置无效的情况   空链表的情况
		return;
	//缺少只有头节点的情况
	if (pos == s->_pHead)//////容易忽略的情况
		s->_pHead = pos->_pNext;
	//
	else
	{
		PNode pPreNode = s->_pHead;//标记
		//while (pPreNode->_pNext != pos)错误处
		while (pPreNode && pPreNode->_pNext != pos)
		{
			pPreNode = pPreNode->_pNext;
		}
		//缺少
		if (pPreNode)
		pPreNode->_pNext = pos->_pNext;
		
	}
	free(pos);//忽略之处
	//pos = NULL;
}

// 在链表中查找值为data的节点，找到返回该节点的地址，否则返回NULL 
PNode SListFind(SList* s, SDataType data)
{
	assert(s);
	PNode pcur = NULL;
	if (NULL == s->_pHead)
		return NULL;//pNode 函数必须有返回值，故返回NULL
	pcur = s->_pHead;
	while (pcur)
	{
		if (pcur->_data == data)
			return pcur;
		else
		{
			pcur = pcur->_pNext;
		}
	}
	return NULL;
}

// 获取链表中有效节点的个数 
size_t SListSize(SList* s)
{
	assert(s);
	size_t count = 0;
	PNode pcur = s->_pHead;//标记
	while (pcur)
	{
		++count;
		pcur = pcur->_pNext;
	}
	return count;
}

// 检测链表是否为空 
int SListEmpty(SList* s)
{
	assert(s);
	return NULL == s->_pHead;
}

//打印单链表
void SListPrint(SList* s)
{
	assert(s);
	if (NULL == s->_pHead)
		printf("NULL\n");
	else
	{
		PNode pcur = s->_pHead;//标记
		while (pcur)
		{
			printf("%d ----> ", pcur->_data);
			pcur = pcur->_pNext;
		}
		printf("NULL \n");
	}
}


// 将链表中有效节点清空 
void SListClear(SList* s)
{
	assert(s);
	if (NULL == s->_pHead)
		return;
	else
	{
		PNode pcur = s->_pHead;//标记
		while (pcur)
		{
			//pcur->_pNext = s->_pHead;  导致head丢失
			//free(pcur);
			//pcur = s->_pHead;  
			s->_pHead = pcur->_pNext;
			free(pcur);
			pcur = s->_pHead;
		}
	}
}

// 销毁链表 
void SListDestroy(SList* s)
{
	SListClear(s);
}

//测试
void TestSlist()
{
	SList s;
	SListInit(&s);
	SListPushBack(&s, 1);
	SListPushBack(&s, 2);
	SListPushBack(&s, 3);
	SListPushBack(&s, 4);
	SListPushBack(&s, 5);
	SListPrint(&s);

	SListInsert(SListFind(&s, 4), 8);
	SListPrint(&s);
	SListPopBack(&s);
	SListPrint(&s);
	SListPopFront(&s);
	SListPrint(&s);
	size_t size = SListSize(&s);
	printf("%d\n", size);
	SListClear(&s);
	SListPrint(&s);

}

int main()
{
	TestSlist();
	system("pause");
	return 0;
}