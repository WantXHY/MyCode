#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//节点的链表
struct LinkNode
{
	void* data;
	struct LinkNode* next;
};

//链表的结构体
struct LList
{
	struct LinkNode pHeader;//头节点
	int m_size;//长度
};

typedef void* LinkList;

//初始化
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
	//将list还原为struct LList类型
	struct LList* mylist = list;

	if (pos<0 || pos>mylist->m_size)
	{
		//无效位置，强制插尾
		pos = mylist->m_size;
	}
	//插入节点的前置节点
	struct LinkNode* pCurrent = &mylist->pHeader;

	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}
	//创建新节点
	struct LinkNode* newNode = malloc(sizeof(struct LinkNode));
	newNode->data = data;
	newNode->next = NULL;

	//建立节点关系
	newNode->next = pCurrent->next;
	pCurrent->next = newNode;

	//更新大小
	mylist->m_size++;
}

//遍历链表
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

//按位置删除链表
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

	//找到要删除节点的前驱节点
	struct LinkNode* pCurrent = &mylist->pHeader;
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}
	//记录删除的节点
	struct LinkNode* pDel = pCurrent->next;
	pCurrent->next = pDel->next;
	//释放内存
	free(pDel);
	pDel = NULL;

	//更新链表长度
	mylist->m_size--;
}

//按值删除链表
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
		//指针的比较利用回调函数交给用户
		if (myCompare(pCurrent->data, data))
		{
			pPrev->next = pCurrent->next;
			free(pCurrent);
			pCurrent = NULL;

			mylist->m_size--;
			break;
		}
		//找不到指针后移
		pPrev = pCurrent;
		pCurrent = pCurrent->next;
	}
}

//清空链表
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

//链表长度
int lenghtLinkList(LinkList list)
{
	if (list == NULL)
	{
		return -1;
	}
	struct LList* mylist = list;
	return mylist->m_size;
}

//销毁链表
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


//测试
struct Person
{
	char name[64];
	int age;
};
//遍历链表用户自定义
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
	struct Person p1 = { "一",10 };
	struct Person p2 = { "二",11 };
	struct Person p3 = { "三",12 };
	struct Person p4 = { "四",15 };
	struct Person p5 = { "五",17 };
	struct Person p6 = { "六",12 };

	//初始化
	LinkList mylist = Init_LinkList();

	//插入数据,四、五、六、一、二、三
	insert_LinkList(mylist, 0, &p1);
	insert_LinkList(mylist, 1, &p2);
	insert_LinkList(mylist, -1, &p3);
	insert_LinkList(mylist, 0, &p4);
	insert_LinkList(mylist, 1, &p5);
	insert_LinkList(mylist, 2, &p6);

	//遍历数据
	foreach_LinkList(mylist, myForeach);
	printf("长度：%d\n", lenghtLinkList(mylist));
	
	//按位置删除链表
	removeLinkList(mylist, 1);
	foreach_LinkList(mylist, myForeach);
	printf("长度：%d\n", lenghtLinkList(mylist));

	//按值删除链表
	struct Person pdel = { "四",15 };
	removeByValueLinkList(mylist, &pdel, myCompare);
	foreach_LinkList(mylist, myForeach);
	printf("长度：%d\n", lenghtLinkList(mylist));

	//清空链表
	clearLinkList(mylist);
	printf("长度：%d\n", lenghtLinkList(mylist));



	//销毁链表
	///*DestoryLinkList(mylist);*/
}



int main()
{
	test01();

	system("pause");
	return 0;
}
