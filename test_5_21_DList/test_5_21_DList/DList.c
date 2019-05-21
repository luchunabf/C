#define _CRT_SECURE_NO_WARNINGS 1
#include"DList.h"

//链表的初始化
void DListInit(PDList s)
{
	assert(s);
	//需不需要malloc 大声告诉你：需要的
	s->_pHead = (PDNode)malloc(sizeof(DNode));//需要先给头节点开辟好空间来存放
	if (NULL == s->_pHead)
	{
		assert(0);
		return;
	}
	s->_pHead->_pPre = s->_pHead;
	s->_pHead->_pNext = s->_pHead;
}
//创建新节点
PDNode BuyNewNode(DLDataType data)
{
	PDNode pNewNode = (PDNode)malloc(sizeof(DNode));
	if (NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}
	pNewNode->data = data;
	pNewNode->_pNext = NULL;
	pNewNode->_pPre = NULL;
	return pNewNode;
}

//尾插
void DListPushBack(PDList s, DLDataType data)
{
	assert(s);
	PDNode pNewNode = BuyNewNode(data);
	pNewNode->_pNext = s->_pHead;
	pNewNode->_pPre = s->_pHead->_pPre;
	s->_pHead->_pPre->_pNext = pNewNode;
	s->_pHead->_pPre = pNewNode;//测一测顺序可以改变吗？前两个肯定不能改变
}

//尾删
void DListPopBack(PDList s)//删的话要判空（s->_Head = s->_Head），要标记
{
	assert(s);
	//if (s->_pHead->_pNext = s->_pHead)//头连接头
	if (s->_pHead->_pNext == s->_pHead)//错误处 需用==
	{
		return;//只有一个？？是的
	}
	///情况一/////////////////////////////////////
	PDNode pDelNode = s->_pHead->_pNext;//注意标记从哪一个节点开始
	while (pDelNode->_pNext != s->_pHead)//等号成立时是最后一个
	{
		pDelNode = pDelNode->_pNext;
	}
	////////////////////////////////////////

	///情况二//////最后一个节点我们用 s->_pHead->pPre 来访问
	//PDNode pDelNode = s->_pHead->_pPre;

	pDelNode->_pPre->_pNext = s->_pHead;
	s->_pHead->_pPre = pDelNode->_pPre;
	free(pDelNode);
	//pDelNode = NULL;
}

//头插
void DListPushFront(PDList s, DLDataType data)
{
	assert(s);
	PDNode pNewNode = BuyNewNode(data);
	pNewNode->_pNext = s->_pHead->_pNext;
	pNewNode->_pPre = s->_pHead;
	s->_pHead->_pNext->_pPre = pNewNode;
	s->_pHead->_pNext = pNewNode;//s->_pHead->_pNext 为左值以后，（如果不是标记的话）说明它就要改变了
}

//头删
void DListPopFront(PDList s)//需不需要标记？？？大声告诉你：需要
{
	assert(s);
	PDNode pur = NULL;
	/////////////////////删除就需要判空
	if (s->_pHead == s->_pHead->_pNext)
		return;
	///////////////////////////////////

	//情况一：如果不标记（不通）
	//s->_pHead->_pNext = s->_pHead->_pNext->_pNext;//可以直接这样吗？（用新连接好的指针直接去访问）：可以的
	//s->_pHead->_pNext->_pPre = s->_pHead;
	//free(s->_pHead->_pNext);//这里第一个有效节点已经丢失，故必须标记

	//情况二：如果标记的话
	pur = s->_pHead->_pNext;//将第一个有效节点标记
	s->_pHead->_pNext = pur->_pNext;
	pur->_pNext->_pPre = s->_pHead;
	free(pur);
}

//pos节点“前”插入data的节点 （与单链表区分）
void DListInsert(PDNode pos, DLDataType data)/////////需不需要判断pos:大声告诉你需要
{													//需不需要标记pos前一个节点:不需要
	PDNode pNewNode = NULL;								
	//////////////pos 不能为NULL
	if (NULL == pos)
		return;
	////////////////////////////
	//pos节点给你了，相当于已经标记了
	pNewNode = BuyNewNode(data);
	//需不需要标记pos前一个节点:不需要
	//不标记的话
	pNewNode->_pNext = pos;
	pNewNode->_pPre = pos->_pPre;
	pos->_pPre->_pNext = pNewNode;
	pos->_pPre = pNewNode;
	//标记的话		///////如果不标记都能成功，那么标记一定也会成功
	//PDNode pcur = pos->_pPre;//标记pos的前一个节点
	//pNewNode->_pNext = pos;
	//pNewNode->_pPre = pcur;
	//pcur->_pNext = pNewNode;//这里不需要修改顺序吧，因为已经标记了
	//						//如果没有标记，这一步必须放至最后
	//pos->_pPre = pNewNode;
}

//删除pos处节点
void DListErase(PDNode pos)
{
	//需不需要标记pos的前后节点:不需要
	if (pos == NULL)//??? yes yes yes需要判断pos是都有效（!NULL）
		return;
	pos->_pPre->_pNext = pos->_pNext;
	pos->_pNext->_pPre = pos->_pPre;
	free(pos);
	//pos = NULL;
}

//清空链表
void DListClear(PDList s)
{
	assert(s);
	//什么时候需要标记？
	//如果不标记1（显然是行不通的）
	//while (s->_pHead->_pNext != s->_pHead)
	//{
	//	s->_pHead->_pNext = s->_pHead->_pNext->_pNext;
	//	free(s->_pHead->_pNext);
	//	s->_pHead->_pNext = s->_pHead->_pNext->_pNext;
	//}
	//如果不标记2（显然是行不通的）
	//while (s->_pHead->_pNext != s->_pHead)
	//{
	//	s->_pHead->_pNext->_pNext->_pPre = s->_pHead;
	//	s->_pHead->_pNext = s->_pHead->_pNext->_pNext;
	//	//此时第一个有效节点两边的指针全部丢失，故必须提前标记它才能free它
	//}
	//如果标记
	PDNode pcur = s->_pHead->_pNext;
	while (pcur != s->_pHead)
	{
		s->_pHead->_pNext = pcur->_pNext;//这里只用一个单向指针去访问下一个，并没有管回来的
		free(pcur);
		pcur = s->_pHead->_pNext;
	}
	s->_pHead->_pNext = s->_pHead;
	s->_pHead->_pPre = s->_pHead;
}

//销毁链表
void DListDestroy(PDList s)
{
	DListClear(s);
	free(s->_pHead);
	s->_pHead = NULL;
}

//打印链表
void DListPrint(PDList s)
{
	assert(s);
	if (s->_pHead->_pNext == s->_pHead)
		printf("Head <===> Head\n");
	else
	{
		printf("Head <===> ");
		PDNode pcur = s->_pHead->_pNext;
		while (pcur != s->_pHead)
		{
			printf("%d <===> ", pcur->data);
			pcur = pcur->_pNext;
		}
		printf("Head\n");
	}
}

//查找第一个值为data的节点
PDNode DListFind(PDList s, DLDataType data)
{
	assert(s);
	if (s->_pHead->_pNext == s->_pHead)//判空
	{
		return NULL;
	}
	PDNode pcur = s->_pHead->_pNext;
	while (pcur != s->_pHead)
	{
		if (pcur->data == data)
			return pcur;
		pcur = pcur->_pNext;
	}
	return NULL;
}
//删除pos处节点
//void DListErase(PDNode pos)
//{
//	//需不需要标记pos的前后节点:不需要
//	if (pos == NULL)//??? yes yes yes需要判断pos是都有效（!NULL）
//		return;
//	pos->_pPre->_pNext = pos->_pNext;
//	pos->_pNext->_pPre = pos->_pPre;
//	free(pos);
//	//pos = NULL;
//}

//删除所有data元素
void DListRemove(PDList s, DLDataType data)
{
	assert(s);
	//判空
	if (s->_pHead->_pNext == s->_pHead)
	{
		return;
	}
	//需要分情况
	//情况1 只有一个有效节点
	PDNode pcur = s->_pHead->_pNext;
	if (pcur->_pNext == s->_pHead)
	{
		if (pcur->data == data)
			DListErase(pcur);
		else
			return;
	}
	else
		//情况2 链表有效节点个数大于1
	{
		//PDNode pcur = s->_pHead->_pNext;
		while (pcur != s->_pHead)
		{
			PDNode pData = DListFind(s, data);
			DListErase(pData);
			pcur = pcur->_pNext;
		}
	}
}



void TestDList()
{
	DList s;
	DListInit(&s);
	DListPushBack(&s, 1);
	DListPushBack(&s, 2);
	DListPushBack(&s, 1);
	DListPushBack(&s, 2);
	DListPushBack(&s, 3);
	DListPushBack(&s, 4);
	DListPushBack(&s, 4);
	DListPushBack(&s, 5);
	DListPushBack(&s, 6);
	DListPushBack(&s, 7);
	DListPrint(&s);

	DListPushFront(&s, 0);
	DListPrint(&s);

	DListPopBack(&s);
	DListPrint(&s);

	DListPopFront(&s);
	DListPrint(&s);

	DListInsert(DListFind(&s, 5), 20);
	DListPrint(&s);
	DListErase(DListFind(&s, 20));
	DListPrint(&s);

	DListRemove(&s, 4);
	//DListRemove(&s, 1);//有问题
	DListPrint(&s);

	DListClear(&s);
	DListPrint(&s);

	DListDestroy(&s);

}

int main()
{
	TestDList();
	system("pause");
	return 0;
}