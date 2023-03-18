#include "linkStack.h"

//��ʼ��ջ
LinkStack init_Stack()
{
	struct LStack* myStack = malloc(sizeof(struct LStack));
	if (myStack == NULL)
	{
		return NULL;
	}
	myStack->pHeader.next = NULL;
	myStack->m_size = 0;
	return myStack;
}
//��ջ
void push_Stack(LinkStack stack, void* data)
{
	//��ջ���ʣ�ͷ��
	if (stack == NULL || data == NULL)
	{
		return;
	}
	struct LStack* myStack = stack;
	struct stackNode* myNode = data;//�����û�ǰ�ĸ��ֽ�
	//����ָ��ָ��
	myNode->next = myStack->pHeader.next;
	myStack->pHeader.next = myNode;
	myStack->m_size++;
}
//��ջ
void pop_Stack(LinkStack stack)
{
	if (stack == NULL)
	{
		return;
	}
	struct LStack* myStack = stack;
	if (myStack->m_size == 0)
	{
		return;
	}
	//������һ��Ԫ�ؽڵ�
	struct stackNode* First = myStack->pHeader.next;
	//����ָ��ָ�򣬱���ͷɾ
	myStack->pHeader.next = First->next;
	myStack->m_size--;
}
//����ջ�Ĵ�С
int size_Stack(LinkStack stack)
{
	if (stack == NULL)
	{
		return -1;
	}
	struct LStack* myStack = stack;
	return myStack->m_size;
}
//����ջ��Ԫ��
void* top_Stack(LinkStack stack)
{
	if (stack == NULL)
	{
		return NULL;
	}
	struct LStack* myStack = stack;
	if (myStack->m_size == 0)
	{
		return NULL;
	}
	return myStack->pHeader.next;
}
//�ж�ջ�Ƿ�Ϊ��
int isEmpty_Stack(LinkStack stack)
{
	if (stack == NULL)
	{
		return -1;
	}
	struct LStack* myStack = stack;
	if (myStack->m_size == 0)
	{
		return 1;
	}
	return 0;
}
//����ջ
void destory_Stack(LinkStack stack)
{
	if (stack == NULL)
	{
		return;
	}
	free(stack);
	stack = NULL;
}