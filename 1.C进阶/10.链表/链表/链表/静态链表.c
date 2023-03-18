#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct LinkNode
{
	int num;
	struct LinkNode* next;
};

void test01()
{
	struct LinkNode node1 = { 10,NULL };
	struct LinkNode node2 = { 20,NULL };
	struct LinkNode node3 = { 30,NULL };
	struct LinkNode node4 = { 40,NULL };
	struct LinkNode node5 = { 50,NULL };

	//建立关系
	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;

	//遍历链表
	struct LinkNode* pCurrent = &node1;

	while (pCurrent != NULL)
	{
		printf("%d\n",pCurrent->num);
		pCurrent = pCurrent->next;
	}
}

int main()
{
	test01();
	system("pause");
	return 0;
}
