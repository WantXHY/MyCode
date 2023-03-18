#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//�ڵ������
struct LinkNode
{
	void* data;
	struct LinkNode* next;
};

//����Ľṹ��
struct LList
{
	struct LinkNode pHeader;//ͷ�ڵ�
	int m_size;//����
};

typedef void* LinkList;

//��ʼ��
LinkList Init_LinkList()
{
	struct LList* mylist = malloc(sizeof(struct LList));

	if (mylist == NULL)
	{
		return NULL;
	}

	mylist->pHeader.data = NULL;
	mylist->pHeader.next = NULL;
	mylist->m_size = 0;

	return mylist;
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
	//��list��ԭΪstruct LList����
	struct LList* mylist = list;

	if (pos<0 || pos>mylist->m_size)
	{
		//��Чλ�ã�ǿ�Ʋ�β
		pos = mylist->m_size;
	}
	//����ڵ��ǰ�ýڵ�
	struct LinkNode* pCurrent = &mylist->pHeader;

	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}
	//�����½ڵ�
	struct LinkNode* newNode = malloc(sizeof(struct LinkNode));
	newNode->data = data;
	newNode->next = NULL;

	//�����ڵ��ϵ
	newNode->next = pCurrent->next;
	pCurrent->next = newNode;

	//���´�С
	mylist->m_size++;
}

//��������
void foreach_LinkList(LinkList list,void(*myForeach)(void*))
{
	if (list == NULL)
	{
		return;
	}
	struct LList* mylist = list;
	struct LinkNode* pCurrent = mylist->pHeader.next;
	for (int i = 0; i < mylist->m_size; i++)
	{
		myForeach(pCurrent->data);
		pCurrent = pCurrent->next;
	}
}

//��λ��ɾ������
void removeLinkList(LinkList list, int pos)
{
	if (list == NULL)
	{
		return;
	}
	struct LList* mylist = list;
	if (pos<0 || pos>mylist->m_size-1)
	{
		return;
	}

	//�ҵ�Ҫɾ���ڵ��ǰ���ڵ�
	struct LinkNode* pCurrent = &mylist->pHeader;
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}
	//��¼ɾ���Ľڵ�
	struct LinkNode* pDel = pCurrent->next;
	pCurrent->next = pDel->next;
	//�ͷ��ڴ�
	free(pDel);
	pDel = NULL;

	//����������
	mylist->m_size--;
}

//��ֵɾ������
void removeByValueLinkList(LinkList list, void* data,int(*myCompare)(void* , void*))
{
	if (list == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}

	struct LList* mylist = list;
	struct LinkNode* pPrev = &mylist->pHeader;
	struct LinkNode* pCurrent = mylist->pHeader.next;


	for (int i = 0; i < mylist->m_size; i++)
	{
		//ָ��ıȽ����ûص����������û�
		if (myCompare(pCurrent->data, data))
		{
			pPrev->next = pCurrent->next;
			free(pCurrent);
			pCurrent = NULL;

			mylist->m_size--;
			break;
		}
		//�Ҳ���ָ�����
		pPrev = pCurrent;
		pCurrent = pCurrent->next;
	}
}

//�������
void clearLinkList(LinkList list)
{
	if (list == NULL)
	{
		return;
	}

	struct LList* mylist = list;
	struct LinkNode* pCurrent = mylist->pHeader.next;

	for (int i = 0; i < mylist->m_size; i++)
	{
		struct LinkNode* pNext = pCurrent->next;
		free(pCurrent);
		pCurrent = pNext;
	}
	
	mylist->pHeader.next = NULL;
	mylist->m_size = 0;
}

//������
int lenghtLinkList(LinkList list)
{
	if (list == NULL)
	{
		return -1;
	}
	struct LList* mylist = list;
	return mylist->m_size;
}

//��������
void DestoryLinkList(LinkList list)
{
	if (list == NULL)
	{
		return;
	}
	clearLinkList(list);

	free(list);
	list = NULL;
}


//����
struct Person
{
	char name[64];
	int age;
};
//���������û��Զ���
void myForeach(void* data)
{
	struct Person* p = data;
	printf("%s   %d\n", p->name, p->age);
}

int myCompare(void* data1, void* data2)
{
	struct Person* p1 = data1;
	struct Person* p2 = data2;

	if (strcmp(p1->name, p2->name) == 0 && (p1->age == p2->age))
	{
		return 1;
	}
	return 0;
	/*return strcmp(p1->name, p2->name) == 0 && p1->age == p2->age;*/
}

void test01()
{
	struct Person p1 = { "һ",10 };
	struct Person p2 = { "��",11 };
	struct Person p3 = { "��",12 };
	struct Person p4 = { "��",15 };
	struct Person p5 = { "��",17 };
	struct Person p6 = { "��",12 };

	//��ʼ��
	LinkList mylist = Init_LinkList();

	//��������,�ġ��塢����һ��������
	insert_LinkList(mylist, 0, &p1);
	insert_LinkList(mylist, 1, &p2);
	insert_LinkList(mylist, -1, &p3);
	insert_LinkList(mylist, 0, &p4);
	insert_LinkList(mylist, 1, &p5);
	insert_LinkList(mylist, 2, &p6);

	//��������
	foreach_LinkList(mylist, myForeach);
	printf("���ȣ�%d\n", lenghtLinkList(mylist));
	
	//��λ��ɾ������
	removeLinkList(mylist, 1);
	foreach_LinkList(mylist, myForeach);
	printf("���ȣ�%d\n", lenghtLinkList(mylist));

	//��ֵɾ������
	struct Person pdel = { "��",15 };
	removeByValueLinkList(mylist, &pdel, myCompare);
	foreach_LinkList(mylist, myForeach);
	printf("���ȣ�%d\n", lenghtLinkList(mylist));

	//�������
	clearLinkList(mylist);
	printf("���ȣ�%d\n", lenghtLinkList(mylist));



	//��������
	///*DestoryLinkList(mylist);*/
}



int main()
{
	test01();

	system("pause");
	return 0;
}
