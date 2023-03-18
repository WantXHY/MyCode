#include "lintLIst.h"

//�����ʼ��
struct linkNode* InitlinList()
{
	//����ͷ�ڵ�
	struct linkNode* Header = malloc(sizeof(struct linkNode));
	if (Header == NULL)
	{
		return NULL;
	}
	//��ʼ��ͷ�ڵ�
	Header->next=NULL;

	//����β�ڵ�ָ��
	struct linkNode* Tail = Header;
	int flag = -1;
	printf("��ʼ������-1�˳�����\n");
	while (1)
	{
		//���û���ʼ�������ڵ㣬����û�����-1������������
		scanf("%d", &flag);
		if (flag == -1)
		{
			printf("�˳�\n");
			break;
		}

		//������벻��-1������ڵ㵽����
		struct linkNode* newNode = malloc(sizeof(struct linkNode));
		newNode->num = flag;
		newNode->next = NULL;

		//����ָ��ָ��
		Tail->next = newNode;

		//�����µ�β�ڵ�
		Tail = newNode;
	}

	return Header;
}

//��������
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
//��������
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
		//û���ҵ���Ӧλ�ã�ָ�����
		pPrve = pCurrent;
		pCurrent = pCurrent->next;
	}
	//��Ҫ�������ֿ����ڴ�
	struct linkNode* newNode = malloc(sizeof(struct linkNode));
	newNode->num = newflag;
	newNode->next = NULL;

	//������ϵ
	newNode->next = pCurrent;
	pPrve->next = newNode;
}
//ɾ������
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
			break;//�ҵ�ʱָ��ͣ��
		}
		//û���ҵ���Ӧλ�ã�ָ�����
		pPrve = pCurrent;
		pCurrent = pCurrent->next;
	}
	if (pCurrent == NULL)
	{
		return;
	}
	//����ָ��ָ�����ɾ������
	pPrve->next = pCurrent->next;
	//ɾ��ָ��
	free(pCurrent);
	pCurrent = NULL;
}


//�������
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

//��������
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
	//���ڱ�ͷ
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
		//����ָ��ָ�����ɾ������
		pPrve->next = pCurrent->next;
		//ɾ��ָ��
		free(pCurrent);
		pCurrent = NULL;
	}
}
//��ת����
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

//��������ڵ����
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