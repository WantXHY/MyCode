#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Parray.h"

#define MAX 1024

typedef void* SeqQueue;

//初始化队列
SeqQueue Init_SeqQueue();
//入队
void push_SeqQueue(SeqQueue queue,void* data);
//出队
void pop_SeqQueue(SeqQueue queue);
//返回队列大小
int size_SeqQueue(SeqQueue queue);
//判断队列是否为空
int isEmpty_SeqQueue(SeqQueue queue);
//返回队头元素
void* fornt_SeqQueue(SeqQueue queue);
//返回队尾元素
void* back_SeqQueue(SeqQueue queue);
//销毁队列
void destory_SeqQueue(SeqQueue queue);