#include "seqQueue.h"

//��ʼ������
SeqQueue Init_SeqQueue()
{
	struct Parray* array = Init_Parray(MAX);
	return array;
}
//���
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
//����
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
//���ض��д�С
int size_SeqQueue(SeqQueue queue)
{
	if (queue == NULL)
	{
		return -1;
	}
	struct Parray* myQueue = queue;
	return myQueue->m_size;
}
//�ж϶����Ƿ�Ϊ��
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
//���ض�ͷԪ��
void* fornt_SeqQueue(SeqQueue queue)
{
	if (queue == NULL)
	{
		return NULL;
	}
	struct Parray* myQueue = queue;
	return myQueue->parray[0];
}
//���ض�βԪ��
void* back_SeqQueue(SeqQueue queue)
{
	if (queue == NULL)
	{
		return NULL;
	}
	struct Parray* myQueue = queue;
	return myQueue->parray[myQueue->m_size - 1];
}
//���ٶ���
void destory_SeqQueue(SeqQueue queue)
{
	if (queue == NULL)
	{
		return;
	} 
	destory_Parray(queue);
}