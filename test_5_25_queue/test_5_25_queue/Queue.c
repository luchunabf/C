#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

pQNode BuyNewNode(QDataType data)//ע������Ͷ����޹أ����ٴ�����,����QDataType data��QDataType����������
{
	pQNode pNewNode = (pQNode)malloc(sizeof(QNode));
	if (NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}
	pNewNode->_data = data;
	pNewNode->_pNext = NULL;//����data? ���У������
	return pNewNode;
}
void QueueInit(Queue* q)
{
	assert(q);//�Ա�ջ��˳����������ʼ������Ҫ�����¿ռ䣨����һ���ڵ㣩
	q->_front = q->_back = NULL;//����data���������ʼ������Ҫ��data
}
void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	pQNode pNewNode = BuyNewNode(data);
	if (NULL == q->_front)//������Ҫ�п�,��ͷ��β���һ���жϣ��ǵģ��������ͷ
	{
		q->_front = q->_back = pNewNode;//��ΪΪ�գ����Բ���ҪpNext
	}
	q->_back->_pNext = pNewNode;//����
	q->_back = pNewNode;//����β������һ����Ҳ�������Ϊ��ǣ�
}
void QueuePop(Queue* q)//���룺���������1.�п� 2.��ͨ��
					   //ɾ�������������1.�п� 2.�ж��Ƕ�ֻ��һ���ڵ� 3.��ͨ��
{
	//assert(q);
	pQNode pDelNode = NULL;//�������ͷ�ڵ�
	if (NULL == q->_front)
	{
		return;
	}
	//pDelNode = q->_front; //���ͷ�ڵ㣨��ʦ���������ǵģ�
	//if (NULL == pDelNode->_pNext)//�ж��Ƿ�ֻ��һ���ڵ㣨��ʦ��
	if (q->_front == q->_back)//�ж��Ƿ�ֻ��һ���ڵ㣨�ң�
	{
		q->_front = q->_back = NULL;//�ǲ����������ǵ�
		free(q->_front);//�����ǰ�棿�����ں��棨��⣩����ǰ�ͷ�ָ��ᶪʧ
		/////ֻҪɾ������Ҫfree
		//free(pDelNode);
	}
	else
	{
		pDelNode = q->_front; //���ͷ�ڵ�
		q->_front = q->_front->_pNext;
		free(pDelNode);//ע��һ��
		//pDelNode = NULL;//����Ҫ
	}
	
}
QDataType QueueFront(Queue* q)
{
	assert(q);
	return q->_front->_data;
}
QDataType QueueBack(Queue* q)
{
	assert(q);
	return q->_back->_data;
}
int QueueSize(Queue* q)
{
	int count = 0;
	pQNode pCur = NULL;
	pCur = q->_front;
	while (pCur)
	{
		++count;
		pCur = pCur->_pNext;
	}
	return count;
}
int QueueEmpty(Queue* q)
{
	assert(q);
	return NULL == q->_front;//�пվ����ж��Ƿ��ǳ�ʼ��״̬
}
void QueueDestroy(Queue* q)//�費��Ҫ�п�
{
	assert(q);
	pQNode pCur = NULL;
	pCur = q->_front;
	if (NULL == q->_front)
		return;
	if (q->_front == q->_back)
		q->_front = q->_back = NULL;
	while (pCur)
	{
		q->_front = q->_front->_pNext;
		free(pCur);
		pCur = q->_front;
	}
	//ѭ����������һ�����ö���βbackָ��գ�������������
	q->_front = q->_back = NULL;//���Աȵ���������һ��������������
								//�����࣬��һ��Ŀ�������� q->_back = NULL;
	//���к͵������������� ���л��и���βָ�룬ǧ������Ǵ���
}
void TestQueue()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	printf("front = %d\n", QueueFront(&q));
	printf("back = %d\n", QueueBack(&q));
	printf("size = %d\n", QueueSize(&q));

	QueuePop(&q);
	printf("front = %d\n", QueueFront(&q));
	printf("back = %d\n", QueueBack(&q));
	printf("size = %d\n", QueueSize(&q));

	QueuePop(&q);
	QueuePop(&q);
	printf("front = %d\n", QueueFront(&q));
	printf("back = %d\n", QueueBack(&q));
	printf("size = %d\n", QueueSize(&q));

	QueuePop(&q);
	printf("size = %d\n", QueueSize(&q));
	QueueDestroy(&q);
}
int main()
{
	TestQueue();
	system("pause");
	return 0;
}
