#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Parray.h"

#define MAX 1024

typedef void* SeqQueue;

//��ʼ������
SeqQueue Init_SeqQueue();
//���
void push_SeqQueue(SeqQueue queue,void* data);
//����
void pop_SeqQueue(SeqQueue queue);
//���ض��д�С
int size_SeqQueue(SeqQueue queue);
//�ж϶����Ƿ�Ϊ��
int isEmpty_SeqQueue(SeqQueue queue);
//���ض�ͷԪ��
void* fornt_SeqQueue(SeqQueue queue);
//���ض�βԪ��
void* back_SeqQueue(SeqQueue queue);
//���ٶ���
void destory_SeqQueue(SeqQueue queue);