#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct linkNode
{
	int num;
	struct linkNode* next;
};

//�����ʼ��
struct linkNode* InitlinList();

//��������
void foreach_LinkList(struct linkNode* Header);

//��������
void insert_linkNode(struct linkNode* Header, int oldflag, int newflag);

//ɾ������
void delete_linkNode(struct linkNoe* Header, int flag);

//�������
void clear_linkNode(struct linkNode* Header);

//��������
void destory_linkNode(struct linkNode* Header);

//λ�ò�������
void insertByPos_linkNode(struct linkNode* Header, int pos, int flag);

void deleteByPos_linkNode(struct linkNoe* Header, int flag);
//��ת����
void reverse_linkNode(struct linkNode* Header);

//��������ڵ����
int size_linkNode(struct linkNode* Header);
