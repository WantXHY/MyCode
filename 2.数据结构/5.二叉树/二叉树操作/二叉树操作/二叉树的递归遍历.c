#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BinaryNode
{
	//数据域
	char ch;
	//指针域
	struct BinaryNode* lChild;
	struct BinaryNode* rChild;
};

void recursion(struct BinaryNode* root)
{
	//判断结束条件
	if (root == NULL)
	{
		return;
	}
	//先序遍历ABCDEFGH
	//printf("%c ", root->ch);
	//recursion(root->lChild);
	//recursion(root->rChild);
	
	//中序遍历BDCEAFHG
	//recursion(root->lChild);
	//printf("%c ", root->ch);
	//recursion(root->rChild);
	
	//后序遍历DECBHGFA
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

	//建立关系
	nodeA.lChild = &nodeB;
	nodeA.rChild = &nodeF;
	
	nodeB.rChild = &nodeC;

	nodeC.lChild = &nodeD;
	nodeC.rChild = &nodeE;

	nodeF.rChild = &nodeG;
	nodeG.lChild = &nodeH;

	//递归遍历
	recursion(&nodeA);
}

int main()
{
	test();
	system("pause");
	return 0;
}
