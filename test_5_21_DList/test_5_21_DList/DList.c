#define _CRT_SECURE_NO_WARNINGS 1
#include"DList.h"

//����ĳ�ʼ��
void DListInit(PDList s)
{
	assert(s);
	//�費��Ҫmalloc ���������㣺��Ҫ��
	s->_pHead = (PDNode)malloc(sizeof(DNode));//��Ҫ�ȸ�ͷ�ڵ㿪�ٺÿռ������
	if (NULL == s->_pHead)
	{
		assert(0);
		return;
	}
	s->_pHead->_pPre = s->_pHead;
	s->_pHead->_pNext = s->_pHead;
}
//�����½ڵ�
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

//β��
void DListPushBack(PDList s, DLDataType data)
{
	assert(s);
	PDNode pNewNode = BuyNewNode(data);
	pNewNode->_pNext = s->_pHead;
	pNewNode->_pPre = s->_pHead->_pPre;
	s->_pHead->_pPre->_pNext = pNewNode;
	s->_pHead->_pPre = pNewNode;//��һ��˳����Ըı���ǰ�����϶����ܸı�
}

//βɾ
void DListPopBack(PDList s)//ɾ�Ļ�Ҫ�пգ�s->_Head = s->_Head����Ҫ���
{
	assert(s);
	//if (s->_pHead->_pNext = s->_pHead)//ͷ����ͷ
	if (s->_pHead->_pNext == s->_pHead)//���� ����==
	{
		return;//ֻ��һ�������ǵ�
	}
	///���һ/////////////////////////////////////
	PDNode pDelNode = s->_pHead->_pNext;//ע���Ǵ���һ���ڵ㿪ʼ
	while (pDelNode->_pNext != s->_pHead)//�Ⱥų���ʱ�����һ��
	{
		pDelNode = pDelNode->_pNext;
	}
	////////////////////////////////////////

	///�����//////���һ���ڵ������� s->_pHead->pPre ������
	//PDNode pDelNode = s->_pHead->_pPre;

	pDelNode->_pPre->_pNext = s->_pHead;
	s->_pHead->_pPre = pDelNode->_pPre;
	free(pDelNode);
	//pDelNode = NULL;
}

//ͷ��
void DListPushFront(PDList s, DLDataType data)
{
	assert(s);
	PDNode pNewNode = BuyNewNode(data);
	pNewNode->_pNext = s->_pHead->_pNext;
	pNewNode->_pPre = s->_pHead;
	s->_pHead->_pNext->_pPre = pNewNode;
	s->_pHead->_pNext = pNewNode;//s->_pHead->_pNext Ϊ��ֵ�Ժ󣬣�������Ǳ�ǵĻ���˵������Ҫ�ı���
}

//ͷɾ
void DListPopFront(PDList s)//�費��Ҫ��ǣ��������������㣺��Ҫ
{
	assert(s);
	PDNode pur = NULL;
	/////////////////////ɾ������Ҫ�п�
	if (s->_pHead == s->_pHead->_pNext)
		return;
	///////////////////////////////////

	//���һ���������ǣ���ͨ��
	//s->_pHead->_pNext = s->_pHead->_pNext->_pNext;//����ֱ�������𣿣��������Ӻõ�ָ��ֱ��ȥ���ʣ������Ե�
	//s->_pHead->_pNext->_pPre = s->_pHead;
	//free(s->_pHead->_pNext);//�����һ����Ч�ڵ��Ѿ���ʧ���ʱ�����

	//������������ǵĻ�
	pur = s->_pHead->_pNext;//����һ����Ч�ڵ���
	s->_pHead->_pNext = pur->_pNext;
	pur->_pNext->_pPre = s->_pHead;
	free(pur);
}

//pos�ڵ㡰ǰ������data�Ľڵ� ���뵥�������֣�
void DListInsert(PDNode pos, DLDataType data)/////////�費��Ҫ�ж�pos:������������Ҫ
{													//�費��Ҫ���posǰһ���ڵ�:����Ҫ
	PDNode pNewNode = NULL;								
	//////////////pos ����ΪNULL
	if (NULL == pos)
		return;
	////////////////////////////
	//pos�ڵ�����ˣ��൱���Ѿ������
	pNewNode = BuyNewNode(data);
	//�費��Ҫ���posǰһ���ڵ�:����Ҫ
	//����ǵĻ�
	pNewNode->_pNext = pos;
	pNewNode->_pPre = pos->_pPre;
	pos->_pPre->_pNext = pNewNode;
	pos->_pPre = pNewNode;
	//��ǵĻ�		///////�������Ƕ��ܳɹ�����ô���һ��Ҳ��ɹ�
	//PDNode pcur = pos->_pPre;//���pos��ǰһ���ڵ�
	//pNewNode->_pNext = pos;
	//pNewNode->_pPre = pcur;
	//pcur->_pNext = pNewNode;//���ﲻ��Ҫ�޸�˳��ɣ���Ϊ�Ѿ������
	//						//���û�б�ǣ���һ������������
	//pos->_pPre = pNewNode;
}

//ɾ��pos���ڵ�
void DListErase(PDNode pos)
{
	//�費��Ҫ���pos��ǰ��ڵ�:����Ҫ
	if (pos == NULL)//??? yes yes yes��Ҫ�ж�pos�Ƕ���Ч��!NULL��
		return;
	pos->_pPre->_pNext = pos->_pNext;
	pos->_pNext->_pPre = pos->_pPre;
	free(pos);
	//pos = NULL;
}

//�������
void DListClear(PDList s)
{
	assert(s);
	//ʲôʱ����Ҫ��ǣ�
	//��������1����Ȼ���в�ͨ�ģ�
	//while (s->_pHead->_pNext != s->_pHead)
	//{
	//	s->_pHead->_pNext = s->_pHead->_pNext->_pNext;
	//	free(s->_pHead->_pNext);
	//	s->_pHead->_pNext = s->_pHead->_pNext->_pNext;
	//}
	//��������2����Ȼ���в�ͨ�ģ�
	//while (s->_pHead->_pNext != s->_pHead)
	//{
	//	s->_pHead->_pNext->_pNext->_pPre = s->_pHead;
	//	s->_pHead->_pNext = s->_pHead->_pNext->_pNext;
	//	//��ʱ��һ����Ч�ڵ����ߵ�ָ��ȫ����ʧ���ʱ�����ǰ���������free��
	//}
	//������
	PDNode pcur = s->_pHead->_pNext;
	while (pcur != s->_pHead)
	{
		s->_pHead->_pNext = pcur->_pNext;//����ֻ��һ������ָ��ȥ������һ������û�йܻ�����
		free(pcur);
		pcur = s->_pHead->_pNext;
	}
	s->_pHead->_pNext = s->_pHead;
	s->_pHead->_pPre = s->_pHead;
}

//��������
void DListDestroy(PDList s)
{
	DListClear(s);
	free(s->_pHead);
	s->_pHead = NULL;
}

//��ӡ����
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

//���ҵ�һ��ֵΪdata�Ľڵ�
PDNode DListFind(PDList s, DLDataType data)
{
	assert(s);
	if (s->_pHead->_pNext == s->_pHead)//�п�
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
//ɾ��pos���ڵ�
//void DListErase(PDNode pos)
//{
//	//�費��Ҫ���pos��ǰ��ڵ�:����Ҫ
//	if (pos == NULL)//??? yes yes yes��Ҫ�ж�pos�Ƕ���Ч��!NULL��
//		return;
//	pos->_pPre->_pNext = pos->_pNext;
//	pos->_pNext->_pPre = pos->_pPre;
//	free(pos);
//	//pos = NULL;
//}

//ɾ������dataԪ��
void DListRemove(PDList s, DLDataType data)
{
	assert(s);
	//�п�
	if (s->_pHead->_pNext == s->_pHead)
	{
		return;
	}
	//��Ҫ�����
	//���1 ֻ��һ����Ч�ڵ�
	PDNode pcur = s->_pHead->_pNext;
	if (pcur->_pNext == s->_pHead)
	{
		if (pcur->data == data)
			DListErase(pcur);
		else
			return;
	}
	else
		//���2 ������Ч�ڵ��������1
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
	//DListRemove(&s, 1);//������
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