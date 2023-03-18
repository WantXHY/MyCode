#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//�ڵ�ṹ��
struct stackNode
{
	struct stackNode* next;
};
//ջ�Ľṹ��
struct LStack
{
	struct stackNode pHeader;
	int m_size;
};

//�ڵ�
typedef void* LinkStack;

//��ʼ��ջ
LinkStack init_Stack();
//��ջ
void push_Stack(LinkStack stack, void* data);
//��ջ
void pop_Stack(LinkStack stack);
//����ջ�Ĵ�С
int size_Stack(LinkStack stack);
//����ջ��Ԫ��
void* top_Stack(LinkStack stack);
//�ж�ջ�Ƿ�Ϊ��
int isEmpty_Stack(LinkStack stack);
//����ջ
void destory_Stack(LinkStack stack);