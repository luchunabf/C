#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

pQNode BuyNewNode(QDataType data)//注意参数和队列无关，别再传错了,还有QDataType data的QDataType别再忘记了
{
	pQNode pNewNode = (pQNode)malloc(sizeof(QNode));
	if (NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}
	pNewNode->_data = data;
	pNewNode->_pNext = NULL;//不管data? 不行，在哪里？
	return pNewNode;
}
void QueueInit(Queue* q)
{
	assert(q);//对比栈（顺序表），这里初始化不需要开辟新空间（给第一个节点）
	q->_front = q->_back = NULL;//不管data，在这里，初始化不需要管data
}
void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	pQNode pNewNode = BuyNewNode(data);
	if (NULL == q->_front)//插入需要判空,用头和尾随便一个判断？是的，但最后用头
	{
		q->_front = q->_back = pNewNode;//因为为空，所以不需要pNext
	}
	q->_back->_pNext = pNewNode;//连接
	q->_back = pNewNode;//队列尾往后走一个（也可以理解为标记）
}
void QueuePop(Queue* q)//插入：两种情况（1.判空 2.普通）
					   //删除：三种情况（1.判空 2.判断是都只有一个节点 3.普通）
{
	//assert(q);
	pQNode pDelNode = NULL;//用来标记头节点
	if (NULL == q->_front)
	{
		return;
	}
	//pDelNode = q->_front; //标记头节点（老师是在这里标记的）
	//if (NULL == pDelNode->_pNext)//判断是否只有一个节点（老师）
	if (q->_front == q->_back)//判断是否只有一个节点（我）
	{
		q->_front = q->_back = NULL;//是不是这样？是的
		free(q->_front);//这个在前面？必须在后面（理解），提前释放指针会丢失
		/////只要删除就需要free
		//free(pDelNode);
	}
	else
	{
		pDelNode = q->_front; //标记头节点
		q->_front = q->_front->_pNext;
		free(pDelNode);//注意一下
		//pDelNode = NULL;//不需要
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
	return NULL == q->_front;//判空就是判断是否是初始化状态
}
void QueueDestroy(Queue* q)//需不需要判空
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
	//循环结束还有一步（让队列尾back指向空），别再忘记了
	q->_front = q->_back = NULL;//（对比单链表无这一步？！）多余吗？
								//不多余，这一步目的在于让 q->_back = NULL;
	//队列和单链表区别在于 队列还有个队尾指针，千万别忘记处理
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
