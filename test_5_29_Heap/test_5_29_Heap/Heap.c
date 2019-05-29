#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"
//�����
void Swap(HPDataType* pleft, HPDataType* pright)
{
	HPDataType tmp = *pleft;
	*pleft = *pright;
	*pright = tmp;
}

void adjustDown(HPDataType* array, int size, int parent)//���µ����������ڵ㣨��δ����Ǹ��ڵ㣩�ŵ���Ӧλ��
{
	// Ĭ����child���parent�����ӣ���Ϊ����ȫ������ĳ���ڵ����ֻ��һ�����ӣ��ú���һ������˫�׵�����
	int child = 2 * parent + 1;
	while (child < size)
	{
		//if (child + 1 < size && array[child + 1] < array[child])
		if (child + 1 < size && array[child + 1] > array[child])//��������µ���ʱ�����������нϴ�ģ�С���ҽ�С�ģ��μ�ѽ��dei��
		{
			child += 1;
		}
		if (array[child] > array[parent])
		{
			Swap(&array[child], &array[parent]);
			parent = child;//parent ��һ����Ҫ�������ڵ㣬���ڵ�������������ߣ���ȥ����һ���ӽڵ���бȽϽ����ж��Ƿ����
			child = parent * 2 + 1;
		}
		else
			return;
	}
}

void adjustUp(HPDataType* array, int size, int child)
{
	int parent = (child - 1) / 2;
	//�Ա����µ���������Ҫ�ж�Ѱ�ҽ�С�Ľڵ㣬��Ϊ���ڵ�Ψһ
	while (child)
	{
		if (child < size && array[child] > array[parent])//ע�⣺���ϵ���ʱchild����Ҫ�������ֵܽڵ����Ƚ�
					//��Ҫ�����ϵ���ʱ������ѣ�child��parent���ڵ��ĵĻ������ϵ���������
					//��֮����С�ѵĻ���child��parent���ڵ�С�ĵĻ������ϵ�������
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
		// �����¿ռ�
		HPDataType* ptmp = (HPDataType*)malloc(sizeof(HPDataType)* newcapacity);
		if (NULL == ptmp)
		{
			assert(0);
			return;
		}
		// ����Ԫ��
		for (int i = 0; i < hp->_size; ++i)
			ptmp[i] = hp->_array[i];
		// �ͷžɿռ�
		free(hp->_array);
		hp->_array = ptmp;
		hp->_capacity = newcapacity;
	}
}

// �������ʼ���� 
void InitHeap(Heap* hp, HPDataType* array, int size)//��Ҫ��array���飨��С��size���Ž���hp��ʹ���ʼ��
													//�������ʼ���ѣ�����������Ĵ�Сsize
{
	assert(hp);
	hp->_array = (HPDataType*)malloc(sizeof(HPDataType)* size);//�μǣ���ʼ����Ҫ�������������malloc
	if (NULL == hp->_array)
	{
		assert(0);
		return;
	}
	hp->_capacity = size;//����ֱ�Ӿͷ�����
	//�費��Ҫѭ������Ҫ��
	for (int i = 0; i < size; ++i)
	{
		hp->_array[i] = array[i];
	}
	hp->_size = size;//����ֱ�Ӿͷ�����

	//����Ϊ��
	int root = (size - 2) >> 1;// ����ȫ�������е�����һ����Ҷ�ӽڵ�
	for (; root >= 0; --root)
	{
		adjustDown(hp->_array, hp->_size, root);//���������µ���
	}
}
// ��ʼ��һ���ն� 
void InitEmptyHeap(Heap* hp, int capacity)//��ʼ���նѣ�������capacity��������size
{
	assert(hp);
	hp->_array = (HPDataType*)malloc(sizeof(HPDataType)* capacity);//ֻҪ��ʼ������Ҫ���ٿռ�malloc
	if (NULL == hp->_array)
	{
		assert(0);
		return;
	}
	hp->_capacity = capacity;
	hp->_size = 0;
}

// �ڶ��в���ֵΪdata��Ԫ�� 
void InsertHeap(Heap* hp, HPDataType data)
{
	assert(hp);
	checkCapacity(hp);
	hp->_array[hp->_size] = data;
	hp->_size++;
	adjustUp(hp->_array, hp->_size, hp->_size - 1);//ʲôʱ�����ϵ�����ʲôʱ�����£��������µ�����
	//size�ǶѵĴ�С��size-1��Ҫ������Ԫ���±꣨���������һ����
}

// ɾ���Ѷ�Ԫ�� 
void EraseHeap(Heap* hp)//Ϊʲô��ֱ��ɾ�����һ��Ԫ�أ�ֻ��ɾ���Ѷ�Ԫ��
{
	assert(hp);
	if (NULL == hp->_array)
		return;
	Swap(&hp->_array[0], &hp->_array[hp->_size - 1]);//�����Ѷ�Ԫ�غͶ�ĩβԪ��
	hp->_size--;//size��ǰ��һ��
	adjustDown(hp->_array, hp->_size, 0);//�ٽ��Ѷ��ŵĽ�����ȥ�Ķ�ĩβԪ�����µ�������Ӧλ��
}

// ��ȡ������ЧԪ�ظ��� 
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}

// �����Ƿ�Ϊ�ն� 
int HeapEmpty(Heap* hp)
{
	assert(hp);
	//return NULL == hp->_array;
	return 0 == hp->_size;//�μǣ�ע��������������
						  //�����п���size
}

// ��ȡ�Ѷ�Ԫ�� 
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	return hp->_array[0];
}

// ���ٶ� 
void DestroyHeap(Heap* hp)
{
	assert(hp);
	if (hp->_array)
	{
		free(hp ->_array);
		hp->_capacity = 0;
		hp->_size = 0; //����Ҫ�ģ�������
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