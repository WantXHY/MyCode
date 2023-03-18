#include "seqStack.h"


//��ʼ��
seqStack init_Stack()
{
	struct SStack* myStack = malloc(sizeof(struct SStack));
	if (myStack == NULL)
	{
		return NULL;
	}
	memset(myStack->data, 0, sizeof(void*) * Max);
	myStack->m_size = 0;
	return myStack;
}
//��ջ
void push_Stack(seqStack stack, void* data)
{
	if (stack == NULL||data == NULL)
	{
		return;
	}
	struct SStack* myStack = stack;
	if (myStack->m_size == Max)
	{
		return;
	}
	myStack->data[myStack->m_size] = data;
	myStack->m_size++;
}
//��ջ
void pop_Stack(seqStack stack)
{
	if (stack == NULL)
	{
		return;
	}
	struct SStack* myStack = stack;
	if (myStack->m_size == 0)
	{
		return;
	}
	myStack->data[myStack->m_size - 1] = NULL;
	myStack->m_size--;
}
//����ջ��Ԫ��
void* top_Stack(seqStack stack)
{
	if (stack == NULL)
	{
		return NULL;
	}
	struct SStack* myStack = stack;
	if (myStack->m_size == 0)
	{
		return NULL;
	}
	return myStack->data[myStack->m_size - 1];
}
//����ջ��С
int size_Stack(seqStack stack)
{
	if (stack == NULL)
	{
		return -1;
	}
	struct SStack* myStack = stack;
	return myStack->m_size;
}
//�ж�ջ�Ƿ�Ϊ��
int isEmpty_Stack(seqStack stack)
{
	if (stack == NULL)
	{
		return -1;
	}
	struct SStack* myStack = stack;
	if (myStack->m_size == 0)
	{
		return 1;
	}
	return 0;
}
//����ջ
void destory_Stack(seqStack stack)
{
	if (stack == NULL)
	{
		return;
	}
	free(stack);
	stack = NULL;

}