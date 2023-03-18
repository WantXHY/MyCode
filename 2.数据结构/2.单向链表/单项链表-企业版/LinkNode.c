#include "LinkNode.h"

//��ʼ��
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

//��������
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
	//���û�����ǰ�ĸ��ֽڽ��в���
	struct LinkNode* newNode = data;
	//�ҵ�����ڵ��ǰ���ڵ�
	struct LinkNode* pCurrent = &myList->pHeader;
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;//pCurrentΪǰ���ڵ�
	}
	//����ָ��ָ��
	newNode->next = pCurrent->next;
	pCurrent->next = newNode;
	//����������
	myList->m_size++;
}

//��������
void foreach_LinkList(LinkList list, void(*myForeach)(void*))
{
	if (list == NULL)
	{
		return;
	}
	struct LList* myList = list;
	struct LinkNode* newNode = myList->pHeader.next;//��ŵ�һ�����ݵĽڵ�
	for (int i = 0; i < myList->m_size; i++)
	{
		myForeach(newNode);//�������û��������
		newNode = newNode->next;
	}
}

//��λ��ɾ������
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
	//�ҵ�ɾ��λ�õ�ǰ���ڵ�
	struct LinkNode* pCurrent = &myList->pHeader;
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}
	//Ҫɾ���Ľڵ�
	struct LinkNode* pDel = pCurrent->next;
	//ɾ��
	pCurrent->next = pDel->next;
	myList->m_size--;
}

//����ֵɾ������
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

//��������
void destory_LinkList(LinkList list)
{
	if (list == NULL)
	{
		return;
	}
	free(list);
	list = NULL;
}