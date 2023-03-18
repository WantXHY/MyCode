#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//节点结构体
struct LinkNode
{
	struct LinkNode* next;
};

//链表结构体
struct LList
{
	struct LinkNode pHeader;
	int m_size;
};

//接口
typedef void* LinkList;

//初始化
LinkList init_LinkList();

//插入链表
void insert_LinkList(LinkList list, int pos, void* data);

//遍历链表
void foreach_LinkList(LinkList list, void(*myForeach)(void*));

//按位置删除链表
void DelByPos_LinkList(LinkList list,int pos);

//按数值删除链表
void DelByValue_LinkList(LinkList list, void* data, int(*myCompare)(void*, void*));

//销毁链表
void destory_LinkList(LinkList list);