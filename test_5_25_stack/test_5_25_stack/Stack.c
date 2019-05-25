#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"

void CheckCapacity(Stack* ps)
{
	assert(ps);
	int NewCapacity = ps->_capacity * 2;
	if (ps->_size == ps->_capacity)
	{
		//�����¿ռ�
		SDataType* ptmp = (SDataType*)malloc(sizeof(SDataType)* NewCapacity);
		if (NULL == ptmp)
		{
			assert(0);
			return;
		}
		//����Ԫ�ص��¿�������ռ�
		for (int i = 0; i < ps->_size; ++i)
			ptmp[i] = ps->_array[i];
		//�ͷž�����
		free(ps->_array);
		ps->_array = ptmp;////////////////////�ֵð�ptmp�������飩�Ž�ջ
		ps->_capacity = NewCapacity;//size���ù�
	}
}
void StackInit(Stack* ps)
{
	assert(ps);
	ps->_array = (SDataType*)malloc(sizeof(SDataType)* 10);//ע����ֵ��Ҫ��ʼ����ջ�е�����
										////��ʼ��ҲҪ�����¿ռ䣬��ʼ����һ��������ٿռ�Ĵ�Сcapacity��ֵ
	if (NULL == ps->_array)
	{
		assert(0);
		return;
	}
	ps->_capacity = 10;
	ps->_size = 0;
}
void StackPush(Stack* ps, SDataType data)
{
	assert(ps);
	//����֮��
	CheckCapacity(ps);//������Ԫ�ر����ж�ԭ���ռ��Ƿ���
	ps->_array[ps->_size] = data;
	ps->_size++;
}
void StackPop(Stack* ps)
{
	assert(ps);
	//if (NULL == ps->_array)//�����Ǿ仰����β��ɾ������Ҫ���п�
	if(0 == ps->_size)  //������һ���𣿣��� ��һ����size = 0��˵������ռ俪�ٳɹ���ֻ��������Ԫ��
								//�� NULL == ps->_array	 ��������δ���ٳɹ��ռ䣬�ڳ�ʼ��ʱ����ֹ				
		return;
	ps->_size--;//��ô�е����֣�Ҳ�����ͷţ�ֻ��Ҫsize--��ok���ǵ�
}
SDataType StackTop(Stack* ps)//ջ��top ��ʵ����size��size����ЧԪ�ظ�����ֻ������ջ���������±���size-1
{
	assert(ps);
	return ps->_array[ps->_size - 1];
}
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_size;
}
int StackEmpty(Stack* ps)
{
	assert(ps);
	return 0 == ps->_size;//��ջ��capacity����size��
}
void StackDestroy(Stack* ps)
{
	assert(ps);
	if (NULL == ps->_array)//////////////////��Ҫ���
	{
		return;
	}
	free(ps->_array);
	ps->_capacity = 0;//capacity��Ϊ0�˻���ҪsizeΪ0��
	ps->_size = 0;//������������Ҫ�������ٵ�ʱ��capacity = 0��size = 0����������ע�⣩��
}

void TestStack()
{
	Stack s;
	StackInit(&s);

	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	printf("size = %d\n", StackSize(&s));
	printf("top = %d\n", StackTop(&s));

	StackPush(&s, 4);
	StackPush(&s, 5);
	printf("size = %d\n", StackSize(&s));
	printf("top = %d\n", StackTop(&s));

	StackPop(&s);
	StackPop(&s);
	printf("size = %d\n", StackSize(&s));
	printf("top = %d\n", StackTop(&s));

	StackDestroy(&s);
}
int main()
{
	TestStack();
	return 0;
}