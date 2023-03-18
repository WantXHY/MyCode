#include "linkStack.h"

//初始化栈
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
//入栈
void push_Stack(LinkStack stack, void* data)
{
	//入栈本质，头插
	if (stack == NULL || data == NULL)
	{
		return;
	}
	struct LStack* myStack = stack;
	struct stackNode* myNode = data;//管理用户前四个字节
	//更新指针指向
	myNode->next = myStack->pHeader.next;
	myStack->pHeader.next = myNode;
	myStack->m_size++;
}
//出栈
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
	//创建第一个元素节点
	struct stackNode* First = myStack->pHeader.next;
	//更改指针指向，本质头删
	myStack->pHeader.next = First->next;
	myStack->m_size--;
}
//返回栈的大小
int size_Stack(LinkStack stack)
{
	if (stack == NULL)
	{
		return -1;
	}
	struct LStack* myStack = stack;
	return myStack->m_size;
}
//返回栈顶元素
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
//判断栈是否为空
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
//销毁栈
void destory_Stack(LinkStack stack)
{
	if (stack == NULL)
	{
		return;
	}
	free(stack);
	stack = NULL;
}