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
void SListPushBack(SList* s, SDataType data)//β��Ҫ1.�пգ������Ƿ�Ϊ�գ�2.��ͨ���
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
		//////////////////////////////////////�������
		PNode pcur = s->_pHead;///////////////�� pcur ��� s->_pHead ��pcurΪ��ֵ��s->_pHeadΪ��ֵ
		while (pcur->_pNext)
		{
			pcur = pcur->_pNext;//////////////pcur��Ҫ�����ߣ�Ϊ��ֵ����������˵�����Ǳ�ǣ�
		}
		pcur->_pNext = pNewNode;//////////////pcur->_pNext ��Ҫ�������� pNewNode��pcur->_pNextΪ��ֵ��pNewNodeΪ��ֵ
	}
	
}



// ɾ������s���һ���ڵ� 
void SListPopBack(SList* s)//βɾ��Ҫ 1.�п� 2.�ж������Ƿ�ֻ��һ���ڵ� 3.��ͨ�������Ҫ��¼ǰһ���ڵ㣩
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
void SListPushFront(SList* s, SDataType data)//ͷ��
{
	assert(s);
	PNode pNewNode = NULL;
	//�м�ʲô���ţ���
	pNewNode = BuyNewNode(data);//����������һ���½ڵ㣬��pPrecurֻ�ǣ�pNode���ͣ���ǽڵ�   //pPrecur = pcur;///////�ص���� ����ҪpPrecur->pNext = pcur;
	pNewNode->_pNext = s->_pHead;//���½ڵ�������ͷһ��
	s->_pHead = pNewNode;//�������ͷ���£���ֵ���Ƶ���ǰ��
	//s->pHead ֻ������ͷ�ڵ�ı�ǣ�����ľ�������ͷ���
}

// ɾ������s�ĵ�һ���ڵ� 
void SListPopFront(SList* s)//ͷɾ��Ҫ��Ǵ�ɾ�ڵ�/////PNode pDelNode = NULL
							//ͷɾ��Ҫ 1.�п� 2.��ͨ��������ͷ�ڵ㣩
							//βɾ����Ҫ 1.�п� 2.�ж������Ƿ�ֻ��һ���ڵ� 3.��ͨ�������Ҫ��¼ǰһ���ڵ㣩
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
									 //ͷ�ڵ������ߵ�ʱ��ͷ�ڵ�Ϊ��ֵ ����s->pHead = pcur->_pNext
		free(pDelNode);
		//pDelNode = NULL;
	}
}

// �������posλ�á��󡱲���ֵΪdata�Ľڵ� 
void SListInsert(PNode pos, SDataType data)//posλ�ò��루��ͷ��ѭ���������ǽ��½ڵ���뵽pos�ڵ�ĺ���
										   //��Ҫ�ж�pos�ڵ㴦�Ƿ�Ϊ��
										   //pos��Ҫ������Χ�ڲſɲ��룬����ֱ��return;
{
	PNode pNewNode = NULL;
	if (NULL == pos)///////////////////////////pos��Ҫ������Χ�ڲſɲ��룬����ֱ��return;
		return;
	pNewNode = BuyNewNode(data);
	pNewNode->_pNext = pos->_pNext;
	pos->_pNext = pNewNode;
}

// ɾ������s��posλ�õĽڵ� 
void SListErase(SList* s, PNode pos)//ɾ��pos�ڵ㴦�Ľڵ�
									//1.��ɾ������Ҫ���п� 2.pos�ڵ��Ƿ���Ч����Ϊ NULL�� 
									//3.pos����Ҫɾ�������Ƿ�Ϊͷ�ڵ� 
									//4. ��ͨ�������ҪȥѰ��posǰһ���Ľڵ㣺��PNode pPreNode = s->_pHead���ͷ�ڵ㣬Ȼ�������ߣ��ߵ�pos��ǰһ���ڵ㴦��
{
	assert(s);
	if ((NULL == pos) || (NULL == s->_pHead))/////////////////////pos��Ҫ������Χ�ڲſɲ��룬����ֱ��return;
  //pos��λ����Ч�����   ����������
		return;
	//ȱ��ֻ��ͷ�ڵ�����
	if (pos == s->_pHead)//////���׺��Ե������pos����Ҫɾ��������ͷ�ڵ�
		s->_pHead = pos->_pNext;
	    //free(pos);//���·��ϲ�
	else
	{
		PNode pPreNode = s->_pHead;//���
		//while (pPreNode->_pNext != pos)����
		while (pPreNode && pPreNode->_pNext != pos)//��Ҫ�ж� pPreNode �Ƿ���Ч����Ϊ�գ�/////////////////
		{
			pPreNode = pPreNode->_pNext;
		}
		//ȱ��
		if (pPreNode)//��Ҫ�ж� pPreNode �Ƿ���Ч����Ϊ�գ�////////////////////////////////////////
		pPreNode->_pNext = pos->_pNext;
		//free(pos);//���·��ϲ�
	}
	free(pos);//�ҵĺ���֮��
	//pos = NULL;
}

// �������в���ֵΪdata�Ľڵ㣬�ҵ����ظýڵ�ĵ�ַ�����򷵻�NULL 
PNode SListFind(SList* s, SDataType data)//����data�Ľڵ㣬�з���ֵ��pNode���ͣ�
										 //1.�п� 2. ��ͨ�����ѭ������ȥѰ��data��
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
void SListPrint(SList* s)//��ӡ���� 1.���п� 2.��ӡ
{
	assert(s);
	if (NULL == s->_pHead)
		printf("NULL\n");
	else
	{
		PNode pcur = s->_pHead;//pcur���ͷ�ڵ�
		while (pcur)
		{
			printf("%d ----> ", pcur->_data);//��ӡ
			pcur = pcur->_pNext;//pcur������
		}
		printf("NULL \n");
	}
}


// ����������Ч�ڵ���� 
void SListClear(SList* s)//��� 1. �п� 2. ���
{
	assert(s);
	if (NULL == s->_pHead)
		return;
	else
	{
		PNode pcur = s->_pHead;//���ͷ�ڵ�
		while (pcur)
		{
			//pcur->_pNext = s->_pHead;  ��ʱ�Ǹ����(��û��������)������buyNewNode�½ڵ�������ӣ���û�����ӣ��ʻᵼ��head��ʧ
			//free(pcur);        //�ͷ�ͷ�ڵ㵼������ʧ
			//pcur = s->_pHead;  //�������
			s->_pHead = s->_pHead->_pNext;// ͷ�ڵ������ߵ�����ڶ����ڵ㴦:��һ
			//s->_pHead = pcur->_pNext;  //  ͷ�ڵ������ߵ�����ڶ����ڵ㴦:����  
			free(pcur);			     // �ͷŵ�һ���ڵ�
			pcur = s->_pHead;		 // �� pcur ���±��ͷ�ڵ�
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