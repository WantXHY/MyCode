#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BinaryNode
{
	//������
	char ch;
	//ָ����
	struct BinaryNode* lChild;
	struct BinaryNode* rChild;
};

void recursion(struct BinaryNode* root)
{
	//�жϽ�������
	if (root == NULL)
	{
		return;
	}
	//�������ABCDEFGH
	//printf("%c ", root->ch);
	//recursion(root->lChild);
	//recursion(root->rChild);
	
	//�������BDCEAFHG
	//recursion(root->lChild);
	//printf("%c ", root->ch);
	//recursion(root->rChild);
	
	//�������DECBHGFA
	recursion(root->lChild);
	recursion(root->rChild);
	printf("%c ", root->ch);
}

void test()
{
	struct BinaryNode nodeA = { 'A',NULL,NULL};
	struct BinaryNode nodeB = { 'B',NULL,NULL };
	struct BinaryNode nodeC = { 'C',NULL,NULL };
	struct BinaryNode nodeD = { 'D',NULL,NULL };
	struct BinaryNode nodeE = { 'E',NULL,NULL };
	struct BinaryNode nodeF = { 'F',NULL,NULL };
	struct BinaryNode nodeG = { 'G',NULL,NULL };
	struct BinaryNode nodeH = { 'H',NULL,NULL };

	//������ϵ
	nodeA.lChild = &nodeB;
	nodeA.rChild = &nodeF;
	
	nodeB.rChild = &nodeC;

	nodeC.lChild = &nodeD;
	nodeC.rChild = &nodeE;

	nodeF.rChild = &nodeG;
	nodeG.lChild = &nodeH;

	//�ݹ����
	recursion(&nodeA);
}

int main()
{
	test();
	system("pause");
	return 0;
}
