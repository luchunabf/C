#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"

void CheckCapacity(Stack* ps)
{
	assert(ps);
	int NewCapacity = ps->_capacity * 2;
	if (ps->_size == ps->_capacity)
	{
		//开辟新空间
		SDataType* ptmp = (SDataType*)malloc(sizeof(SDataType)* NewCapacity);
		if (NULL == ptmp)
		{
			assert(0);
			return;
		}
		//拷贝元素到新开辟数组空间
		for (int i = 0; i < ps->_size; ++i)
			ptmp[i] = ps->_array[i];
		//释放旧数组
		free(ps->_array);
		ps->_array = ptmp;////////////////////又得把ptmp（新数组）放进栈
		ps->_capacity = NewCapacity;//size不用管
	}
}
void StackInit(Stack* ps)
{
	assert(ps);
	ps->_array = (SDataType*)malloc(sizeof(SDataType)* 10);//注意左值是要初始化的栈中的数组
										////初始化也要开辟新空间，开始给定一个最初开辟空间的大小capacity的值
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
	//忽略之处
	CheckCapacity(ps);//插入新元素必须判断原来空间是否够用
	ps->_array[ps->_size] = data;
	ps->_size++;
}
void StackPop(Stack* ps)
{
	assert(ps);
	//if (NULL == ps->_array)//还是那句话，（尾）删除就需要先判空
	if(0 == ps->_size)  //这两个一样吗？？？ 不一样，size = 0；说明数组空间开辟成功，只是里面无元素
								//而 NULL == ps->_array	 则是数组未开辟成功空间，在初始化时即中止				
		return;
	ps->_size--;//怎么有点儿奇怪？也不用释放？只需要size--就ok？是的
}
SDataType StackTop(Stack* ps)//栈顶top 其实就是size（size是有效元素个数）只不过在栈的数组中下标是size-1
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
	return 0 == ps->_size;//空栈是capacity还是size？
}
void StackDestroy(Stack* ps)
{
	assert(ps);
	if (NULL == ps->_array)//////////////////重要理解
	{
		return;
	}
	free(ps->_array);
	ps->_capacity = 0;//capacity都为0了还需要size为0？
	ps->_size = 0;//这里两个都需要处理（销毁的时候，capacity = 0；size = 0（容易忘，注意））
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