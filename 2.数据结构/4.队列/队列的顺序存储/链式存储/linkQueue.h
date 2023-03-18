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
//接口
typedef void* LinkQueue;

//初始化
LinkQueue init_Queue();
//入队
void push_Queue(LinkQueue queue, void* data);
//出队
void pop_Queue(LinkQueue queue);
//返回队列大小
int size_Queue(LinkQueue queue);
//判断是否为空
int isEmpty_Queue(LinkQueue queue);
//返回队头元素
void* fornt_Queue(LinkQueue queue);
//返回队尾元素
void* back_Queue(LinkQueue queue);
//销毁队列
void destory_Queue(LinkQueue queue);