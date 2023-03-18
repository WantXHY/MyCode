#include "linkQueue.h"

//��ʼ��
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
//���
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
	//����ָ��ָ��
	myQueue->pTail->next = myNode;
	myNode->next = NULL;
	myQueue->pTail = myNode;
	myQueue->m_size++;
}
//����
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
	//ֻ��һ��Ԫ��ʱ���޷�ʹ��First����
	if (myQueue->m_size == 1)
	{
		myQueue->pHeader.next = NULL;
		myQueue->pTail = &myQueue->pHeader;
		myQueue->m_size--;
		return;
	}
	//����ͷ�ڵ�
	struct QueueNode* First = myQueue->pHeader.next;
	myQueue->pHeader.next = First->next;
	myQueue->m_size--;
}
//���ض��д�С
int size_Queue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return -1;
	}
	struct LQueue* myQueue = queue;

	return myQueue->m_size;
}
//�ж��Ƿ�Ϊ��
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
//���ض�ͷԪ��
void* fornt_Queue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return NULL;
	}
	struct LQueue* myQueue = queue;
	return myQueue->pHeader.next;
}
//���ض�βԪ��
void* back_Queue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return NULL;
	}
	struct LQueue* myQueue = queue;
	return myQueue->pTail;
}
//���ٶ���
void destory_Queue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return;
	}
	free(queue);
	queue = NULL;
}