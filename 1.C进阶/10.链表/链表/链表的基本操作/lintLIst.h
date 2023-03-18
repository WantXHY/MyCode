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

//链表初始化
struct linkNode* InitlinList();

//遍历链表
void foreach_LinkList(struct linkNode* Header);

//插入链表
void insert_linkNode(struct linkNode* Header, int oldflag, int newflag);

//删除链表
void delete_linkNode(struct linkNoe* Header, int flag);

//清空链表
void clear_linkNode(struct linkNode* Header);

//销毁链表
void destory_linkNode(struct linkNode* Header);

//位置插入链表
void insertByPos_linkNode(struct linkNode* Header, int pos, int flag);

void deleteByPos_linkNode(struct linkNoe* Header, int flag);
//反转链表
void reverse_linkNode(struct linkNode* Header);

//返回链表节点个数
int size_linkNode(struct linkNode* Header);
