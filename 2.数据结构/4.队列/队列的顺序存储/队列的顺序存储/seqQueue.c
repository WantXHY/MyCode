#include "seqQueue.h"

//初始化队列
SeqQueue Init_SeqQueue()
{
	struct Parray* array = Init_Parray(MAX);
	return array;
}
//入队
void push_SeqQueue(SeqQueue queue, void* data)
{
	if (queue == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	struct Parray* myQueue = queue;
	if (myQueue->m_size == MAX)
	{
		return;
	}
	insert_Parray(myQueue, myQueue->m_size, data);
}
//出队
void pop_SeqQueue(SeqQueue queue)
{
	if (queue == NULL)
	{
		return;
	}
	struct Parray* myQueue = queue;
	if (myQueue->m_size <= 0)
	{
		return;
	}
	DelBypos_Parray(myQueue, 0);
}
//返回队列大小
int size_SeqQueue(SeqQueue queue)
{
	if (queue == NULL)
	{
		return -1;
	}
	struct Parray* myQueue = queue;
	return myQueue->m_size;
}
//判断队列是否为空
int isEmpty_SeqQueue(SeqQueue queue)
{
	if (queue == NULL)
	{
		return -1;
	}
	struct Parray* myQueue = queue;
	if (myQueue->m_size == 0)
	{
		return 1;
	}
	return 0;
}
//返回队头元素
void* fornt_SeqQueue(SeqQueue queue)
{
	if (queue == NULL)
	{
		return NULL;
	}
	struct Parray* myQueue = queue;
	return myQueue->parray[0];
}
//返回队尾元素
void* back_SeqQueue(SeqQueue queue)
{
	if (queue == NULL)
	{
		return NULL;
	}
	struct Parray* myQueue = queue;
	return myQueue->parray[myQueue->m_size - 1];
}
//销毁队列
void destory_SeqQueue(SeqQueue queue)
{
	if (queue == NULL)
	{
		return;
	} 
	destory_Parray(queue);
}