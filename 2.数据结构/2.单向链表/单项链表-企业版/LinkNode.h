#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//�ڵ�ṹ��
struct LinkNode
{
	struct LinkNode* next;
};

//����ṹ��
struct LList
{
	struct LinkNode pHeader;
	int m_size;
};

//�ӿ�
typedef void* LinkList;

//��ʼ��
LinkList init_LinkList();

//��������
void insert_LinkList(LinkList list, int pos, void* data);

//��������
void foreach_LinkList(LinkList list, void(*myForeach)(void*));

//��λ��ɾ������
void DelByPos_LinkList(LinkList list,int pos);

//����ֵɾ������
void DelByValue_LinkList(LinkList list, void* data, int(*myCompare)(void*, void*));

//��������
void destory_LinkList(LinkList list);