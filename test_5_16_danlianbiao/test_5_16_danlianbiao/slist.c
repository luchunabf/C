#define _CRT_SECURE_NO_WARNINGS 1
#include "slist.h"

// ����ĳ�ʼ�� 
void SListInit(SList* s)
{
	assert(s);
	s->_pHead = NULL;
}

PNode BuyNewNode(SDataType data)
{
	PNode pNewNode = (PNode)malloc(sizeof(Node));//Ҫ����һ���½ڵ㣬�ʿ����ڴ�Ĵ�С�ǽڵ㣨�ṹ�壩�Ĵ�С�����ٵ����ͣ�ǿ������ת����Ϊ�ڵ�����ͣ�PNode��
	///////////////////////////////////sizeof(���ܼ�*)����* ��ָ��
	if (NULL == pNewNode)
	{
		assert(0);
		return NULL;//����������PNode���ʱ����з���ֵNULL;
	}
	else
	{
		pNewNode->_data = data;
		pNewNode->_pNext = NULL;
		return pNewNode;
	}
}
// ������s���һ���ڵ�����ֵΪdata�Ľڵ� 
void SListPushBack(SList* s, SDataType data)
{
	assert(s);
	PNode pNewNode = BuyNewNode(data);
	//�м���ɶ����,�м�Ҫ�п�
	if (NULL == s->_pHead)//////////////��һ��������У���Ȼ��������һ����������Ϊͷ�ڵ�ΪNULL����ȥ����s->_pHead->_pNext���ǷǷ�����
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



// ɾ������s���һ���ڵ� 
void SListPopBack(SList* s)
{
	assert(s);
	if (NULL == s->_pHead)
		return;
	else if (NULL == s->_pHead->_pNext)// ֻ��һ���ڵ�
	{
		free(s->_pHead);
		s->_pHead = NULL;
	}
	else
	{
		PNode pPrecur = NULL;
		PNode pcur = s->_pHead;
		while (pcur->_pNext)//������while (pcur)
		{//�����ҵ������һ���ڵ�
		 //pPre�ǵ����ڶ����ڵ�
		 //pCur�ߵ����һ���ڵ㴦������������NULL����Ҫ��while (pcur->_pNext)����Ϊѭ���������ж�����
			pPrecur = pcur;///////�ص���� ����ҪpPrecur->pNext = pcur;
			pcur = pcur->_pNext;
		}
		free(pcur);//ɾ������Ҫfree��С����������
		pPrecur->_pNext = NULL;
	}
}

// ������s��һ���ڵ�ǰ����ֵΪdata�Ľڵ� 
void SListPushFront(SList* s, SDataType data)
{
	assert(s);
	PNode pNewNode = NULL;
	//�м�ʲô���ţ�
	pNewNode = BuyNewNode(data);
	pNewNode->_pNext = s->_pHead;//���½ڵ�������ͷһ��
	s->_pHead = pNewNode;//�������ͷ���£���ֵ���Ƶ���ǰ��
	//s->pHead ֻ������ͷ�ڵ�ı�ǣ�����ľ�������ͷ���
}

// ɾ������s�ĵ�һ���ڵ� 
void SListPopFront(SList* s)
{
	assert(s);
	PNode pDelNode = NULL;//ͷɾ��Ҫ�ô�ɾ���Ľڵ���ͷ�ڵ�
	if (NULL == s->_pHead)
		return;
	//ͷɾ����Ҫ��������ֻ��һ���ڵ�����
	else 
	{/////////////////////////////////////
		pDelNode = s->_pHead;//ͷɾ��Ҫ�ô�ɾ���Ľڵ���ͷ�ڵ�
		//s->_pHead = s->_pHead->_pNext;//��ͷ�ڵ㣨�ı�ǣ�������һ��
		s->_pHead = pDelNode->_pNext;//ע�����д����
		free(pDelNode);
		//pDelNode = NULL;
	}
}

// �������posλ�á��󡱲���ֵΪdata�Ľڵ� 
void SListInsert(PNode pos, SDataType data)
{
	PNode pNewNode = NULL;
	if (NULL == pos)/////////////////////////
		return;
	pNewNode = BuyNewNode(data);
	pNewNode->_pNext = pos->_pNext;
	pos->_pNext = pNewNode;
}

// ɾ������s��posλ�õĽڵ� 
void SListErase(SList* s, PNode pos)
{
	assert(s);
	if ((NULL == pos) || (NULL == s->_pHead))///////////////////
		//pos��λ����Ч�����   ����������
		return;
	//ȱ��ֻ��ͷ�ڵ�����
	if (pos == s->_pHead)//////���׺��Ե����
		s->_pHead = pos->_pNext;
	//
	else
	{
		PNode pPreNode = s->_pHead;//���
		//while (pPreNode->_pNext != pos)����
		while (pPreNode && pPreNode->_pNext != pos)
		{
			pPreNode = pPreNode->_pNext;
		}
		//ȱ��
		if (pPreNode)
		pPreNode->_pNext = pos->_pNext;
		
	}
	free(pos);//����֮��
	//pos = NULL;
}

// �������в���ֵΪdata�Ľڵ㣬�ҵ����ظýڵ�ĵ�ַ�����򷵻�NULL 
PNode SListFind(SList* s, SDataType data)
{
	assert(s);
	PNode pcur = NULL;
	if (NULL == s->_pHead)
		return NULL;//pNode ���������з���ֵ���ʷ���NULL
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

// ��ȡ��������Ч�ڵ�ĸ��� 
size_t SListSize(SList* s)
{
	assert(s);
	size_t count = 0;
	PNode pcur = s->_pHead;//���
	while (pcur)
	{
		++count;
		pcur = pcur->_pNext;
	}
	return count;
}

// ��������Ƿ�Ϊ�� 
int SListEmpty(SList* s)
{
	assert(s);
	return NULL == s->_pHead;
}

//��ӡ������
void SListPrint(SList* s)
{
	assert(s);
	if (NULL == s->_pHead)
		printf("NULL\n");
	else
	{
		PNode pcur = s->_pHead;//���
		while (pcur)
		{
			printf("%d ----> ", pcur->_data);
			pcur = pcur->_pNext;
		}
		printf("NULL \n");
	}
}


// ����������Ч�ڵ���� 
void SListClear(SList* s)
{
	assert(s);
	if (NULL == s->_pHead)
		return;
	else
	{
		PNode pcur = s->_pHead;//���
		while (pcur)
		{
			//pcur->_pNext = s->_pHead;  ����head��ʧ
			//free(pcur);
			//pcur = s->_pHead;  
			s->_pHead = pcur->_pNext;
			free(pcur);
			pcur = s->_pHead;
		}
	}
}

// �������� 
void SListDestroy(SList* s)
{
	SListClear(s);
}

//����
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