#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//节点结构体
struct stackNode
{
	struct stackNode* next;
};
//栈的结构体
struct LStack
{
	struct stackNode pHeader;
	int m_size;
};

//节点
typedef void* LinkStack;

//初始化栈
LinkStack init_Stack();
//入栈
void push_Stack(LinkStack stack, void* data);
//出栈
void pop_Stack(LinkStack stack);
//返回栈的大小
int size_Stack(LinkStack stack);
//返回栈顶元素
void* top_Stack(LinkStack stack);
//判断栈是否为空
int isEmpty_Stack(LinkStack stack);
//销毁栈
void destory_Stack(LinkStack stack);