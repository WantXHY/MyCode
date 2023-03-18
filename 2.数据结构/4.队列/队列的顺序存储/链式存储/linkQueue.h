#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct QueueNode
{
	struct QueueNode* next;
};
struct LQueue
{
	struct QueueNode pHeader;
	int m_size;
	struct QueueNode* pTail;
};
//�ӿ�
typedef void* LinkQueue;

//��ʼ��
LinkQueue init_Queue();
//���
void push_Queue(LinkQueue queue, void* data);
//����
void pop_Queue(LinkQueue queue);
//���ض��д�С
int size_Queue(LinkQueue queue);
//�ж��Ƿ�Ϊ��
int isEmpty_Queue(LinkQueue queue);
//���ض�ͷԪ��
void* fornt_Queue(LinkQueue queue);
//���ض�βԪ��
void* back_Queue(LinkQueue queue);
//���ٶ���
void destory_Queue(LinkQueue queue);