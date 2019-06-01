#define _CRT_SECURE_NO_WARNINGS 1
#include "BinTree.h"

BTNode* BuyBinNode(BTDataType data)
{
	BTNode* pNewNode = (BTNode*)malloc(sizeof(BTNode));
	if (NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}
	pNewNode->_data = data;
	pNewNode->_pLeft = NULL; 
	pNewNode->_pRight = NULL;
	return pNewNode;
}
BTNode* _CreateBinTree(BTDataType* array, int size, int* index, BTDataType invalid)
{
	/*if (array = NULL)
		return NULL;*/
	BTNode* pRoot = NULL;
	if ((*index) < size && array[*index] != invalid)
	{
		// ���ڵ�
		pRoot = BuyBinNode(array[*index]);//���ĸ��ڵ�
		// ����������
		++(*index);
		pRoot->_pLeft = _CreateBinTree(array, size, index, invalid);
		// ����������
		++(*index);
		pRoot->_pRight = _CreateBinTree(array, size, index, invalid);
	}
	return pRoot;
}


// �������Ĵ��� 
BTNode* CreateBinTree(BTDataType* array, int size, BTDataType invalid)
{
	int index = 0;//Ҫ�Ǻ���������һ���Ļ�����װһ�ξ�OK
	return _CreateBinTree(array, size, &index, invalid);
}

// �������Ŀ��� 
BTNode* CopyBinTree(BTNode* pRoot)
{
	BTNode* pNewroot = NULL;
	if (pRoot)
	{
		pNewroot = BuyBinNode(pRoot->_data);
		pNewroot->_pLeft = CopyBinTree(pRoot->_pLeft);
		pNewroot->_pRight = CopyBinTree(pRoot->_pRight);
	}
	return pNewroot;
}

// ������������ 
void DestroyBinTree(BTNode** pRoot)//ΪʲôҪ������ָ��
{
	//assert(pRoot);
	if (*pRoot)
	{
		DestroyBinTree(&(*pRoot)->_pLeft);
		DestroyBinTree(&(*pRoot)->_pRight);
		free(*pRoot);
		*pRoot = NULL;
	}
}

// �ݹ飺ǰ����� 
void PreOrder(BTNode* pRoot)
{
	//assert(pRoot);
	if (pRoot)//��������������
	{
		printf("%c ", pRoot->_data);
		PreOrder(pRoot->_pLeft);
		PreOrder(pRoot->_pRight);
	}
}

// �ݹ飺������� 
void InOrder(BTNode* pRoot)
{
	//assert(pRoot);
	if (pRoot)
	{
		InOrder(pRoot->_pLeft);
		printf("%c ", pRoot->_data);
		InOrder(pRoot->_pRight);
	}
}

// �ݹ飺������� 
void PostOrder(BTNode* pRoot)
{
	//assert(pRoot);
	if (pRoot)
	{
		PostOrder(pRoot->_pLeft);
		PostOrder(pRoot->_pRight);
		printf("%c ", pRoot->_data);
	}
}

// ������� 
void LevelOrder(BTNode* pRoot)
{
	Queue q;
	if (NULL == pRoot)
		return;
	QueueInit(&q);
	QueuePush(&q, pRoot);//��������ŵ������ڵ�
	while (!QueueEmpty(&q))
	{
		BTNode* pCur = QueueFront(&q);
		printf("%c ", pCur->_data);

		// ������Ӵ��ڣ����浱ǰ�ڵ������
		if (pCur->_pLeft)//�пգ�ע�⣩
		QueuePush(&q, pCur->_pLeft);

		// ����Һ��Ӵ��ڣ����浱ǰ�ڵ���Һ���
		if (pCur->_pRight)//�пգ�ע�⣩
		QueuePush(&q, pCur->_pRight);

		QueuePop(&q);//����ɾ������ʵ��ͷɾ
	}
	QueueDestroy(&q);//�ǵ����ٶ���
	printf("\n");
}

// ��ȡ�������нڵ���� 
int GetBinTreeSize(BTNode* pRoot)//////////////////////////////
{
	//assert(pRoot);
	if (NULL == pRoot)
		return 0;
	//if (pRoot)
		//return 1;
	return 1 + GetBinTreeSize(pRoot->_pLeft) + GetBinTreeSize(pRoot->_pRight);
}

// ��ȡ�������е�K��ڵ���� 
int GetKLevelNodeCount(BTNode* pRoot, int K)
{
	if (NULL == pRoot || K < 0)
		return 0;
	if (K == 1)
		return 1;
	return GetKLevelNodeCount(pRoot->_pLeft, K - 1) + GetKLevelNodeCount(pRoot->_pRight, K - 1);
}

// ��ȡ��������Ҷ�ӽڵ���� 
int GetLeafCount(BTNode* pRoot)
{
	if (NULL == pRoot)
		return 0;
	if (pRoot->_pLeft == NULL && pRoot->_pRight == NULL)
		return 1;
	return GetLeafCount(pRoot->_pLeft) + GetLeafCount(pRoot->_pRight);
}

// ��ȡ���������(�߶�) 
int GetBinTreeHeight(BTNode* pRoot)
{
	BTNode* pTmp = pRoot;
	int deep = 0;
	if (pTmp)
	{
		int leftdeep = GetBinTreeHeight(pTmp->_pLeft);
		int rightdeep = GetBinTreeHeight(pTmp->_pRight);
		deep = leftdeep >= rightdeep ? leftdeep + 1 : rightdeep + 1;
	}
	return deep;
}

// ���ֵΪx��Ԫ���Ƿ��ڶ������У��ڷ��ظýڵ�ĵ�ַ�����򷵻�NULL 
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	BTNode* pRet = NULL;
	if (root == NULL)
		return NULL;
	if (root->_data == x)
		return root;
	if (pRet = BinaryTreeFind(root->_pLeft, x))
		return pRet;
	return BinaryTreeFind(root->_pRight, x);
}

void Swap(BTNode** pleft, BTNode** pright)
{
	BTNode* pTmp = *pleft;
	*pleft = *pright;
	*pright = pTmp;
}

// �������ľ��� 
void Mirror(BTNode* pRoot)
{
	if (pRoot)
	{
		Swap(&pRoot->_pLeft, &pRoot->_pRight);
		Mirror(pRoot->_pLeft);
		Mirror(pRoot->_pRight);
	}
}

void MirrorNor(BTNode* pRoot)
{
	Queue q;
	if (NULL == pRoot)
		return;
	QueueInit(&q);
	QueuePush(&q, pRoot);
	while (!QueueEmpty(&q))
	{
		BTNode* pCur = QueueFront(&q);
		Swap(&pCur->_pLeft, &pCur->_pRight);
		if (pCur->_pLeft)
			QueuePush(&q, pCur->_pLeft);
		if (pCur->_pRight)
			QueuePush(&q, pCur->_pRight); 
		QueuePop(&q);
	}
	QueueDestroy(&q);
}

// �ж϶������Ƿ�����ȫ������ 
int BinaryTreeComplete(BTNode* root)
{
	if (NULL == root)
		return 1;
	int left = GetBinTreeHeight(root->_pLeft);
	int right = GetBinTreeHeight(root->_pRight);
	int diff = left - right;
	if (diff < -1 || diff > 1)
		return 0;
	return BinaryTreeComplete(root->_pLeft) || BinaryTreeComplete(root->_pRight);
}

void TestBinTree()
{
	char* str = "ABD$$$CE$$F";
	BTNode* pRoot = CreateBinTree(str, strlen(str), '$');
	Mirror(pRoot);
	MirrorNor(pRoot);
	printf("ǰ����������");
	PreOrder(pRoot);
	printf("\n");

	printf("������������");
	InOrder(pRoot);
	printf("\n");

	printf("������������");
	PostOrder(pRoot);
	printf("\n");

	printf("������������");
	LevelOrder(pRoot);
	printf("\n");
	int size = GetBinTreeSize(pRoot);
	printf("�ö������Ľڵ����Ϊ��%d\n", size);

	int count = GetKLevelNodeCount(pRoot, 3);
	printf("��3��Ľڵ����Ϊ��%d\n", count);

	int leave = GetLeafCount(pRoot);
	printf("�ö������е�Ҷ�ӽ��ĸ���Ϊ��%d\n", leave);

	int height = GetBinTreeHeight(pRoot);
	printf("�ö����������Ϊ��%d\n", height);

	//�ж��Ƿ�Ϊ��ȫ��������a = 0 ���ǣ�  a = 1 ��
	/*int a = BinaryTreeComplete(pRoot);
	if (a == 1)
		printf("����ȫ������\n");
	else
		printf("������ȫ������\n");*/

	//�ж�E�Ƿ��ڶ�������
	if (BinaryTreeFind(pRoot, 'E'))
	{
		printf("E is in BTree!!!\n");
	}
	else
	{
		printf("E is not in BTree!!!\n");
	}
	DestroyBinTree(&pRoot);
}

int main()
{
	TestBinTree();
	system("pause");
	return 0;
}