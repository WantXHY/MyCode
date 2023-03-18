#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Max 1024

struct SStack
{
	void* data[Max];
	int m_size;
};

typedef void* seqStack;

//初始化
seqStack init_Stack();
//入栈
void push_Stack(seqStack stack, void* data);
//出栈
void pop_Stack(seqStack stack);
//返回栈顶元素
void* top_Stack(seqStack stack);
//返回栈大小
int size_Stack(seqStack stack);
//判断栈是否为空
int isEmpty_Stack(seqStack stack);
//销毁栈
void destory_Stack(seqStack stack);