#include "LinkNode.h"

//初始化
LinkList init_LinkList()
{
	struct LList* myList = malloc(sizeof(struct LList));
	if (myList == NULL)
	{
		return NULL;
	}
	myList->pHeader.next = NULL;
	myList->m_size = 0;
	return myList;
}

//插入链表
void insert_LinkList(LinkList list, int pos, void* data)
{
	if (list == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	struct LList* myList = list;
	if (pos < 0 || pos > myList->m_size-1)
	{
		pos = myList->m_size;
	}
	//对用户数据前四个字节进行操作
	struct LinkNode* newNode = data;
	//找到插入节点的前驱节点
	struct LinkNode* pCurrent = &myList->pHeader;
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;//pCurrent为前驱节点
	}
	//更改指针指向
	newNode->next = pCurrent->next;
	pCurrent->next = newNode;
	//更新链表长度
	myList->m_size++;
}

//遍历链表
void foreach_LinkList(LinkList list, void(*myForeach)(void*))
{
	if (list == NULL)
	{
		return;
	}
	struct LList* myList = list;
	struct LinkNode* newNode = myList->pHeader.next;//存放第一个数据的节点
	for (int i = 0; i < myList->m_size; i++)
	{
		myForeach(newNode);//交还给用户自行输出
		newNode = newNode->next;
	}
}

//按位置删除链表
void DelByPos_LinkList(LinkList list,int pos)
{
	if (list == NULL)
	{
		return;
	}
	struct LList* myList = list;
	if (pos<0 || pos>myList->m_size - 1)
	{
		return;
	}
	//找到删除位置的前驱节点
	struct LinkNode* pCurrent = &myList->pHeader;
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}
	//要删除的节点
	struct LinkNode* pDel = pCurrent->next;
	//删除
	pCurrent->next = pDel->next;
	myList->m_size--;
}

//按数值删除链表
void DelByValue_LinkList(LinkList list, void* data,int(*myCompare)(void*,void*))
{
	if (list == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	struct LList* myList = list;
	struct LinkNode* myNode = &myList->pHeader;

	for (int i = 0; i < myList->m_size; i++)
	{
		struct LinkNode* pPrevious = myNode;
		myNode = myNode->next;
		if (myCompare(myNode, data))
		{
			pPrevious->next = myNode->next;
			myNode = pPrevious;
			myList->m_size--;
			break;
		}


	}
}

//销毁链表
void destory_LinkList(LinkList list)
{
	if (list == NULL)
	{
		return;
	}
	free(list);
	list = NULL;
}