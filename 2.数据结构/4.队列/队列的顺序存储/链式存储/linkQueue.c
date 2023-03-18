#include "linkQueue.h"

//初始化
LinkQueue init_Queue()
{
	struct LQueue* myQueue = malloc(sizeof(struct LQueue));
	if (myQueue == NULL)
	{
		return NULL;
	}
	myQueue->pHeader.next = NULL;
	myQueue->pTail = &myQueue->pHeader;
	myQueue->m_size = 0;
}
//入队
void push_Queue(LinkQueue queue, void* data)
{
	if (queue == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	struct LQueue* myQueue = queue;
	struct QueueNode* myNode = data;
	//更改指针指向
	myQueue->pTail->next = myNode;
	myNode->next = NULL;
	myQueue->pTail = myNode;
	myQueue->m_size++;
}
//出队
void pop_Queue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return;
	}
	struct LQueue* myQueue = queue;
	if (myQueue->m_size == 0)
	{
		return;
	}
	//只有一个元素时，无法使用First跳过
	if (myQueue->m_size == 1)
	{
		myQueue->pHeader.next = NULL;
		myQueue->pTail = &myQueue->pHeader;
		myQueue->m_size--;
		return;
	}
	//创建头节点
	struct QueueNode* First = myQueue->pHeader.next;
	myQueue->pHeader.next = First->next;
	myQueue->m_size--;
}
//返回队列大小
int size_Queue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return -1;
	}
	struct LQueue* myQueue = queue;

	return myQueue->m_size;
}
//判断是否为空
int isEmpty_Queue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return -1;
	}
	struct LQueue* myQueue = queue;
	if (myQueue->m_size == 0)
	{
		return 1;
	}
	return 0;
}
//返回队头元素
void* fornt_Queue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return NULL;
	}
	struct LQueue* myQueue = queue;
	return myQueue->pHeader.next;
}
//返回队尾元素
void* back_Queue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return NULL;
	}
	struct LQueue* myQueue = queue;
	return myQueue->pTail;
}
//销毁队列
void destory_Queue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return;
	}
	free(queue);
	queue = NULL;
}