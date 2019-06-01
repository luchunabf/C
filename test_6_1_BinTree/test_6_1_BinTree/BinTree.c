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
		// 根节点
		pRoot = BuyBinNode(array[*index]);//树的根节点
		// 根的左子树
		++(*index);
		pRoot->_pLeft = _CreateBinTree(array, size, index, invalid);
		// 根的右子树
		++(*index);
		pRoot->_pRight = _CreateBinTree(array, size, index, invalid);
	}
	return pRoot;
}


// 二叉树的创建 
BTNode* CreateBinTree(BTDataType* array, int size, BTDataType invalid)
{
	int index = 0;//要是函数参数少一个的话，封装一次就OK
	return _CreateBinTree(array, size, &index, invalid);
}

// 二叉树的拷贝 
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

// 二叉树的销毁 
void DestroyBinTree(BTNode** pRoot)//为什么要传二级指针
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

// 递归：前序遍历 
void PreOrder(BTNode* pRoot)
{
	//assert(pRoot);
	if (pRoot)//结束条件不能忘
	{
		printf("%c ", pRoot->_data);
		PreOrder(pRoot->_pLeft);
		PreOrder(pRoot->_pRight);
	}
}

// 递归：中序遍历 
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

// 递归：后序遍历 
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

// 层序遍历 
void LevelOrder(BTNode* pRoot)
{
	Queue q;
	if (NULL == pRoot)
		return;
	QueueInit(&q);
	QueuePush(&q, pRoot);//队列里面放的是树节点
	while (!QueueEmpty(&q))
	{
		BTNode* pCur = QueueFront(&q);
		printf("%c ", pCur->_data);

		// 如果左孩子存在，保存当前节点的左孩子
		if (pCur->_pLeft)//判空（注意）
		QueuePush(&q, pCur->_pLeft);

		// 如果右孩子存在，保存当前节点的右孩子
		if (pCur->_pRight)//判空（注意）
		QueuePush(&q, pCur->_pRight);

		QueuePop(&q);//队列删除，其实是头删
	}
	QueueDestroy(&q);//记得销毁队列
	printf("\n");
}

// 获取二叉树中节点个数 
int GetBinTreeSize(BTNode* pRoot)//////////////////////////////
{
	//assert(pRoot);
	if (NULL == pRoot)
		return 0;
	//if (pRoot)
		//return 1;
	return 1 + GetBinTreeSize(pRoot->_pLeft) + GetBinTreeSize(pRoot->_pRight);
}

// 获取二叉树中第K层节点个数 
int GetKLevelNodeCount(BTNode* pRoot, int K)
{
	if (NULL == pRoot || K < 0)
		return 0;
	if (K == 1)
		return 1;
	return GetKLevelNodeCount(pRoot->_pLeft, K - 1) + GetKLevelNodeCount(pRoot->_pRight, K - 1);
}

// 获取二叉树中叶子节点个数 
int GetLeafCount(BTNode* pRoot)
{
	if (NULL == pRoot)
		return 0;
	if (pRoot->_pLeft == NULL && pRoot->_pRight == NULL)
		return 1;
	return GetLeafCount(pRoot->_pLeft) + GetLeafCount(pRoot->_pRight);
}

// 获取二叉树深度(高度) 
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

// 检测值为x的元素是否在二叉树中，在返回该节点的地址，否则返回NULL 
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

// 二叉树的镜像 
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

// 判断二叉树是否是完全二叉树 
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
	printf("前序遍历结果：");
	PreOrder(pRoot);
	printf("\n");

	printf("中序遍历结果：");
	InOrder(pRoot);
	printf("\n");

	printf("后序遍历结果：");
	PostOrder(pRoot);
	printf("\n");

	printf("层序遍历结果：");
	LevelOrder(pRoot);
	printf("\n");
	int size = GetBinTreeSize(pRoot);
	printf("该二叉树的节点个数为：%d\n", size);

	int count = GetKLevelNodeCount(pRoot, 3);
	printf("第3层的节点个数为：%d\n", count);

	int leave = GetLeafCount(pRoot);
	printf("该二叉树中的叶子结点的个数为：%d\n", leave);

	int height = GetBinTreeHeight(pRoot);
	printf("该二叉树的深度为：%d\n", height);

	//判断是否为完全二叉树，a = 0 不是，  a = 1 是
	/*int a = BinaryTreeComplete(pRoot);
	if (a == 1)
		printf("是完全二叉树\n");
	else
		printf("不是完全二叉树\n");*/

	//判断E是否在二叉树内
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