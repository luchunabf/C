#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"
//建大堆
void Swap(HPDataType* pleft, HPDataType* pright)
{
	HPDataType tmp = *pleft;
	*pleft = *pright;
	*pright = tmp;
}

void adjustDown(HPDataType* array, int size, int parent)//向下调整将所传节点（这次传的是根节点）排到相应位置
{
	// 默认让child标记parent的左孩子，因为：完全二叉树某个节点如果只有一个孩子，该孩子一定是其双亲的左孩子
	int child = 2 * parent + 1;
	while (child < size)
	{
		//if (child + 1 < size && array[child + 1] < array[child])
		if (child + 1 < size && array[child + 1] > array[child])//建大堆向下调整时找两个孩子中较大的，小堆找较小的（牢记呀兄dei）
		{
			child += 1;
		}
		if (array[child] > array[parent])
		{
			Swap(&array[child], &array[parent]);
			parent = child;//parent 这一次是要调整根节点，根节点从上往下依次走，再去和下一个子节点进行比较进而判断是否调整
			child = parent * 2 + 1;
		}
		else
			return;
	}
}

void adjustUp(HPDataType* array, int size, int child)
{
	int parent = (child - 1) / 2;
	//对比向下调整，不需要判断寻找较小的节点，因为根节点唯一
	while (child)
	{
		if (child < size && array[child] > array[parent])//注意：向上调整时child不需要和他的兄弟节点来比较
					//重要：向上调整时，建大堆，child比parent根节点大的的话，向上调整交换，
					//反之，建小堆的话，child比parent根节点小的的话，向上调整交换
		{
			Swap(&array[child], &array[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			return;
	}
}

void checkCapacity(pHeap hp)
{
	assert(hp);
	if (hp->_size == hp->_capacity)
	{
		int newcapacity = hp->_capacity * 2;
		// 申请新空间
		HPDataType* ptmp = (HPDataType*)malloc(sizeof(HPDataType)* newcapacity);
		if (NULL == ptmp)
		{
			assert(0);
			return;
		}
		// 拷贝元素
		for (int i = 0; i < hp->_size; ++i)
			ptmp[i] = hp->_array[i];
		// 释放旧空间
		free(hp->_array);
		hp->_array = ptmp;
		hp->_capacity = newcapacity;
	}
}

// 用数组初始化堆 
void InitHeap(Heap* hp, HPDataType* array, int size)//是要把array数组（大小是size）放进堆hp中使其初始化
													//用数组初始化堆，传的是数组的大小size
{
	assert(hp);
	hp->_array = (HPDataType*)malloc(sizeof(HPDataType)* size);//牢记，初始化需要给堆里面的数组malloc
	if (NULL == hp->_array)
	{
		assert(0);
		return;
	}
	hp->_capacity = size;//数组直接就放满了
	//需不需要循环？需要的
	for (int i = 0; i < size; ++i)
	{
		hp->_array[i] = array[i];
	}
	hp->_size = size;//数组直接就放满了

	//调整为堆
	int root = (size - 2) >> 1;// 找完全二叉数中倒数第一个非叶子节点
	for (; root >= 0; --root)
	{
		adjustDown(hp->_array, hp->_size, root);//这里是向下调整
	}
}
// 初始化一个空堆 
void InitEmptyHeap(Heap* hp, int capacity)//初始化空堆，传的是capacity，并不是size
{
	assert(hp);
	hp->_array = (HPDataType*)malloc(sizeof(HPDataType)* capacity);//只要初始化就需要开辟空间malloc
	if (NULL == hp->_array)
	{
		assert(0);
		return;
	}
	hp->_capacity = capacity;
	hp->_size = 0;
}

// 在堆中插入值为data的元素 
void InsertHeap(Heap* hp, HPDataType data)
{
	assert(hp);
	checkCapacity(hp);
	hp->_array[hp->_size] = data;
	hp->_size++;
	adjustUp(hp->_array, hp->_size, hp->_size - 1);//什么时候向上调整，什么时候向下，向上向下的区别
	//size是堆的大小，size-1是要调整的元素下标（这里是最后一个）
}

// 删除堆顶元素 
void EraseHeap(Heap* hp)//为什么不直接删除最后一个元素？只能删除堆顶元素
{
	assert(hp);
	if (NULL == hp->_array)
		return;
	Swap(&hp->_array[0], &hp->_array[hp->_size - 1]);//交换堆顶元素和堆末尾元素
	hp->_size--;//size往前走一个
	adjustDown(hp->_array, hp->_size, 0);//再将堆顶放的交换过去的堆末尾元素向下调整到对应位置
}

// 获取堆中有效元素个数 
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}

// 检测堆是否为空堆 
int HeapEmpty(Heap* hp)
{
	assert(hp);
	//return NULL == hp->_array;
	return 0 == hp->_size;//牢记：注意这两个的区别
						  //这里判空用size
}

// 获取堆顶元素 
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	return hp->_array[0];
}

// 销毁堆 
void DestroyHeap(Heap* hp)
{
	assert(hp);
	if (hp->_array)
	{
		free(hp ->_array);
		hp->_capacity = 0;
		hp->_size = 0; //是需要的，不能忘
	}
}

void TestHeap1()
{
	Heap hp;
	int array[] = { 2, 3, 8, 0, 9, 1, 7, 4, 6, 5 };
	InitHeap(&hp, array, sizeof(array) / sizeof(array[0]));
	printf("%d\n", HeapSize(&hp));
	printf("%d\n", HeapTop(&hp));

	EraseHeap(&hp);
	printf("%d\n", HeapTop(&hp));

	InsertHeap(&hp, 0);
	printf("%d\n", HeapTop(&hp));
	DestroyHeap(&hp);
}

int main()
{
	TestHeap1();
	system("pause");
	return 0;
}