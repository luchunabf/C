#define _CRT_SECURE_NO_WARNINGS 1
#include"seqlist.h"


// ˳���ĳ�ʼ�� 
void SeqListInit(PSeq ps, int capacity)
{
	assert(ps);
	ps->_array = (DataType*)malloc(sizeof(DataType)* capacity);
	if (NULL == ps->_array)
	{
		assert(0);
		return;
	}
	//ps->_array
	ps->_capacity = capacity;
	ps->_size = 0;
}

// ��˳����β������ֵΪdata��Ԫ�� 
void SeqListPushBack(PSeq ps, DataType data)
{
	assert(ps);
	CheckCapacity(ps);
	ps->_array[ps->_size] = data;
	ps->_size++;
}

// ɾ��˳������һ��Ԫ�� 
void SeqListPopBack(PSeq ps)
{
	assert(ps);
	if (SeqListEmpty(ps))/////////0?
	{
		return;
	}
	else
	{
		ps->_size--;
	}
}

// ��˳����ͷ������ֵΪdata��Ԫ��
void SeqListPushFront(PSeq ps, DataType data)
{
	assert(ps);
	CheckCapacity(ps);
	for (int i = (ps->_size - 1); i >= 0; i--)
	{
		ps->_array[i + 1] = ps->_array[i];
	}
	ps->_array[0] = data;
	ps->_size++;
}

// ɾ��˳���ͷ����Ԫ��
void SeqListPopFront(PSeq ps)
{
	assert(ps);
	if (SeqListEmpty(ps))//////////0?
	{
		return;
	}
	else
	{
		for (int i = 1; i < ps->_size; i++)
		{
			ps->_array[i - 1] = ps->_array[i];
		}
		ps->_size--;
	}
}

// ��˳���posλ�ò���ֵΪdata��Ԫ��
void SeqListInsert(PSeq ps, int pos, DataType data)
{
	assert(ps);
	if (pos < 0 || pos > ps->_size)
	{
		return;
	}
	CheckCapacity(ps);
	for (int i = ps->_size - 1; i >= pos; i--)
	{
		ps->_array[i + 1] = ps->_array[i];
	}
	ps->_array[pos] = data;
	ps->_size++;
}

// ɾ��˳�����posλ���ϵ�Ԫ��
void SeqListErase(PSeq ps, int pos)
{
	assert(ps);
	if (pos < 0 || pos > ps->_size)
		return;
	else
	{
		for (int i = pos; i < (ps->_size - 1); i++)
		{
			ps->_array[i] = ps->_array[i + 1];
		}
		ps->_size--;
	}
}

// ��˳����в���ֵΪdata��Ԫ�أ��ҵ����ظ�Ԫ����˳����е��±꣬���򷵻�-1 
int SeqListFind(PSeq ps, DataType data)
{
	assert(ps);
	/*if (SeqListEmpty(ps))
		return -1;
	else*/
	{
		for (int i = 0; i < ps->_size; i++)
		{
			if (ps->_array[i] == data)
				return i;
		}
		return -1;
	}
}

// ���˳����Ƿ�Ϊ�գ����Ϊ�շ��ط�0ֵ���ǿշ���0 
int SeqListEmpty(PSeq ps)
{
	assert(ps);
	return 0 == ps->_size;////////�ص����
}

// ����˳�������ЧԪ�صĸ���
int SeqListSize(PSeq ps)
{
	assert(ps);
	return ps->_size;
}

// ����˳����������С 
int SeqListCapacity(PSeq ps)
{
	assert(ps);
	return ps->_capacity;
}

// ��˳����е�Ԫ�����
void SeqListClear(PSeq ps)
{
	assert(ps);
	ps->_size = 0;
}

// ɾ��˳����е�һ��ֵΪdata��Ԫ��
void SeqListRemove(PSeq ps, DataType data)
{
	assert(ps);
	//SeqListErase(ps, SeqListFind(ps, data));
	if (SeqListEmpty(ps))
		return;
	else
	{
		int pos = 0;
		for (int i = 0; i < ps->_size; i++)
		{
			if (ps->_array[i] == data)
			{
				pos = i;
				break;
			}
		}
		for (int i = pos + 1; i < ps->_size; i++)
		{
			ps->_array[i - 1] = ps->_array[i];
		}
		ps->_size--;
	}
}

// ����˳���
void SeqListDestroy(PSeq ps)
{
	assert(ps);
	if (ps->_array)
	{
		free(ps->_array);
		ps->_array = NULL;
		ps->_size = 0;
		ps->_capacity = 0;
	}
}

// ˳�������� 
void CheckCapacity(PSeq ps)
{
	assert(ps);
	if (ps->_capacity == ps->_size)
	{
		DataType* pTmp = (DataType*)malloc(sizeof(DataType)*(ps->_capacity * 2));
		if (NULL == pTmp)
		{
			assert(0);
			return;
		}
		else
		{
			for (int i = 0; i < ps->_size; i++)
				pTmp[i] = ps->_array[i];
			free(ps->_array);
			ps->_array = pTmp;////////////////////////
			ps->_capacity = ps->_capacity * 2;
		}
	}
}

//��ӡ˳���
void SeqListPrint(PSeq ps)
{
	assert(ps);
	for (int i = 0; i < ps->_size; i++)
	{
		printf("%d ", ps->_array[i]);
	}
	printf("\n");
}

//����˳���
//int SeqListTest()
int main()
{
	int pos = -1;
	SeqList s ;
	SeqListInit(&s, 10);
	SeqListPushBack(&s, 0);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPrint(&s);
	SeqListPopBack(&s);
	SeqListPrint(&s);
	SeqListPushFront(&s, 10);
	SeqListPrint(&s);
	SeqListPopFront(&s);
	SeqListPrint(&s);
	SeqListInsert(&s, 3, 10);
	SeqListPrint(&s);
	SeqListErase(&s, 1);
	SeqListPrint(&s);
	pos = SeqListFind(&s, 10);
	printf("pos==%d\n", pos);
	int empty = SeqListEmpty(&s);
	printf("empty==%d\n", empty);
	SeqListPrint(&s);
	int num = SeqListSize(&s);
	printf("num==%d\n", num);
	int capacity = SeqListCapacity(&s);
	printf("capacity==%d\n", capacity);
	SeqListRemove(&s, 10);
	SeqListPrint(&s);
	SeqListPushFront(&s, 1);
	SeqListPushFront(&s, 1);
	SeqListPushFront(&s, 1);
	SeqListPushFront(&s, 1);
	SeqListPushFront(&s, 1);
	SeqListPushFront(&s, 1);
	SeqListPrint(&s);
	CheckCapacity(&s);
	int capacity1 = SeqListCapacity(&s);
	printf("capacity1==%d\n", capacity1);
	SeqListClear(&s);
	SeqListPrint(&s);
	SeqListDestroy(&s);

	system("pause");
	return 0;
}