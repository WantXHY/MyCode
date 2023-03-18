#include "seqStack.h"

//初始化栈
seqStack init_Stack()
{
	struct sStack* myStack = malloc(sizeof(struct sStack));
	if (myStack == NULL)
	{
		return NULL;
	}
	memset(myStack->data, 0, sizeof(void*) * Max);
	myStack->m_size = 0;
	return myStack;
}
//入栈
void push_Stack(seqStack stack, void* data)
{
	if (stack == NULL||data==NULL)
	{
		return;
	}
	//本质是尾插
	struct sStack* myStack = stack;
	if (myStack->m_size == Max)
	{
		return;
	}
	myStack->data[myStack->m_size] = data;
	myStack->m_size++;
}
//出栈
void pop_Stack(seqStack stack)
{
	if (stack == NULL)
	{
		return;
	}
	struct sStack* myStack = stack;
	if (myStack->m_size == 0)
	{
		return;
	}
	myStack->data[myStack->m_size - 1] = NULL;
	myStack->m_size--;
}
//返回栈顶元素
void* top_Stack(seqStack stack)
{
	if (stack == NULL)
	{
		return NULL;
	}
	struct sStack* myStack = stack;
	if (myStack->m_size == 0)
	{
		return NULL;
	}
	return myStack->data[myStack->m_size-1];
}
//返回栈大小
int size_Stack(seqStack stack)
{
	if (stack == NULL)
	{
		return -1;
	}
	struct sStack* myStack = stack;
	return myStack->m_size;
}
//判断栈是否为空
int isEmpty_Stack(seqStack stack)
{
	if (stack == NULL)
	{
		return -1;
	}
	struct sStack* myStack = stack;
	if (myStack->m_size == 0)
	{
		return 1;
	}
	return 0;
}
//销毁栈
void destory_Stack(seqStack stack)
{
	if (stack == NULL)
	{
		return;
	}
	free(stack);
	stack = NULL;
}