#include "lintLIst.h"

//链表初始化
struct linkNode* InitlinList()
{
	//创建头节点
	struct linkNode* Header = malloc(sizeof(struct linkNode));
	if (Header == NULL)
	{
		return NULL;
	}
	//初始化头节点
	Header->next=NULL;

	//创建尾节点指针
	struct linkNode* Tail = Header;
	int flag = -1;
	printf("初始化链表，-1退出链表\n");
	while (1)
	{
		//让用户初始化几个节点，如果用户输入-1，代表插入结束
		scanf("%d", &flag);
		if (flag == -1)
		{
			printf("退出\n");
			break;
		}

		//如果输入不是-1，插入节点到链表
		struct linkNode* newNode = malloc(sizeof(struct linkNode));
		newNode->num = flag;
		newNode->next = NULL;

		//更改指针指向
		Tail->next = newNode;

		//更新新的尾节点
		Tail = newNode;
	}

	return Header;
}

//遍历链表
void foreach_LinkList(struct linkNode* Header)
{
	if (Header == NULL)
	{
		return;
	}
	struct linkNode* pCurrent = Header->next;
	while (pCurrent != NULL)
	{
		printf("%d\n", pCurrent->num);
		pCurrent = pCurrent->next;
	}
}
//插入链表
void insert_linkNode(struct linkNode* Header, int oldflag, int newflag)
{
	if (Header == NULL)
	{
		return;
	}
	struct linkNode* pPrve = Header;
	struct linkNode* pCurrent = Header->next;
	while (pCurrent != NULL)
	{
		if (pCurrent->num == oldflag)
		{
			break;
		}
		//没有找到相应位置，指针后移
		pPrve = pCurrent;
		pCurrent = pCurrent->next;
	}
	//给要插入数字开辟内存
	struct linkNode* newNode = malloc(sizeof(struct linkNode));
	newNode->num = newflag;
	newNode->next = NULL;

	//建立关系
	newNode->next = pCurrent;
	pPrve->next = newNode;
}
//删除链表
void delete_linkNode(struct linkNode* Header, int flag)
{
	if (Header == NULL)
	{
		return;
	}
	struct linkNode* pPrve = Header;
	struct linkNode* pCurrent = Header->next;
	while (pCurrent != NULL)
	{
		if (pCurrent->num == flag)
		{
			break;//找到时指针停留
		}
		//没有找到相应位置，指针后移
		pPrve = pCurrent;
		pCurrent = pCurrent->next;
	}
	if (pCurrent == NULL)
	{
		return;
	}
	//更改指针指向进行删除数据
	pPrve->next = pCurrent->next;
	//删除指针
	free(pCurrent);
	pCurrent = NULL;
}


//清空链表
void clear_linkNode(struct linkNode* Header)
{
	if (Header == NULL)
	{
		return;
	}
	struct linkNode* pCurrent = Header->next;
	while (pCurrent != NULL)
	{
		struct linkNode* nextNode = pCurrent->next;
		free(pCurrent);
		pCurrent = nextNode;
	}
	Header->next = NULL;
}

//销毁链表
void destory_linkNode(struct linkNode* Header)
{
	if (Header == NULL)
	{
		return;
	}
	clear_linkNode(Header);
	free(Header);
	Header = NULL;
}

void insertByPos_linkNode(struct linkNode* Header, int pos, int flag)
{
	if (Header == NULL|| pos < 0)
	{
		return;
	}
	struct linkNode* newNode = malloc(sizeof(struct linkNode));
	int i = 0;
	//插在表头
	if (pos == 0)
	{
		newNode->num = flag;
		newNode->next = Header;
		Header = newNode;
	}
	else
	{
		struct linkNode* pPrve;
		while (i < pos )
		{
			Header = Header->next;
			i++;
		}
		pPrve = Header;
		newNode->num = flag;
		newNode->next = pPrve->next;
		pPrve->next = newNode;
	}
}

void deleteByPos_linkNode(struct linkNode* Header, int pos)
{
	if (Header == NULL || pos < 0)
	{
		return;
	}
	struct linkNode* pPrve = Header;
	struct linkNode* pCurrent = Header->next;
	int i = 0;
	if (pos == 0)
	{
		Header = pCurrent->next;
		free(pCurrent);
	}
	else
	{
		
		while (i < pos)
		{
			pPrve = pCurrent;
			pCurrent = pCurrent->next;
			i++;
		}
		//更改指针指向进行删除数据
		pPrve->next = pCurrent->next;
		//删除指针
		free(pCurrent);
		pCurrent = NULL;
	}
}
//反转链表
void reverse_linkNode(struct linkNode* Header)
{
	if (Header == NULL)
	{
		return;
	}
	struct linkNode* pPrev = NULL;
	struct linkNode* pCurrent = Header->next;
	struct linkNode* pNext = NULL;

	while (pCurrent != NULL)
	{
		pNext = pCurrent->next;
		pCurrent->next = pPrev;

		pPrev = pCurrent;
		pCurrent = pNext;
	}
	Header->next = pPrev;
}

//返回链表节点个数
int size_linkNode(struct linkNode* Header)
{
	if (Header == NULL)
	{
		return -1;
	}
	struct linkNode* pCurrent = Header->next;
	int num = 0;
	while (pCurrent != NULL)
	{
		num++;
		pCurrent = pCurrent->next;
	}
	return num;
}