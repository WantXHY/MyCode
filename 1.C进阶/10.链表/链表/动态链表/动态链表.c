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
	struct LinkNode* node1 = malloc(sizeof(struct LinkNode));
	struct LinkNode* node2 = malloc(sizeof(struct LinkNode));
	struct LinkNode* node3 = malloc(sizeof(struct LinkNode));
	struct LinkNode* node4 = malloc(sizeof(struct LinkNode));
	struct LinkNode* node5 = malloc(sizeof(struct LinkNode));

	node1->num = 100;
	node2->num = 200;
	node3->num = 300;
	node4->num = 400;
	node5->num = 500;

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = NULL;

	struct LinkNode* pCurrent = node1;
	while (pCurrent != NULL)
	{
		printf("%d\n", pCurrent->num);
		pCurrent = pCurrent->next;
	}
	free(node1);
	node1 = NULL;
	free(node2);
	node2 = NULL;
	free(node3);
	node3 = NULL;
	free(node4);
	node4 = NULL;
	free(node5);
	node5 = NULL;
}

int main()
{
	test01();
	system("pause");
	return 0;
}
