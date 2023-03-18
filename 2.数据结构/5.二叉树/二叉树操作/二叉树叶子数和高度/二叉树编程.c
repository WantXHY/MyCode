#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BinaryNode
{
	char ch;//数据域
	//指针域
	struct BinaryNode* lChild;
	struct BinaryNode* rChild;

};
 
//计算叶子数
void calculateTreeLeaf(struct BinaryNode* root, int* num)
{
	if (root == NULL)
	{
		return;
	}
	//左子树、右子树都为空称为叶子
	if (root->lChild == NULL && root->rChild == NULL)
	{ 
		(*num)++;
	}
	calculateTreeLeaf(root->lChild, num);
	calculateTreeLeaf(root->rChild, num);
}

//计算树高度
int treeHeight(struct BinaryNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	//左子树高度
	int Lheight = treeHeight(root->lChild);
	//右子树高度
	int Rheight = treeHeight(root->rChild);
	//比较左子树和右子树取较大值+1
	int height = Lheight > Rheight ? Lheight + 1 : Rheight + 1;
	return height;
}
struct BinaryNode* copyTree(struct BinaryNode* root)
{
	if (root == NULL)
	{
		return NULL;
	}
	struct BinaryNode* Lheight = copyTree(root->lChild);
	struct BinaryNode* Rheight = copyTree(root->rChild);
	struct BinaryNode* Newnode = malloc(sizeof(struct BinaryNode));
	Newnode->ch = root->ch;
	Newnode->lChild = Lheight;
	Newnode->rChild = Rheight;
	return Newnode;
}
//拷贝遍历
void recursion(struct BinaryNode* root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%c ", root->ch);
	recursion(root->lChild);
	recursion(root->rChild);
}
//释放树
void freeTree(struct BinaryNode* root)
{
	if (root == NULL)
	{
		return;
	}
	freeTree(root->lChild);
	freeTree(root->rChild);
	printf("%c被释放了\n", root->ch);
	free(root);
}

void test()
{
	struct BinaryNode nodeA = { 'A',NULL,NULL };
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

	//计算叶子数
	int num = 0;
	calculateTreeLeaf(&nodeA, &num);
	printf("叶子数：%d\n", num);

	//计算树高度
	int height=treeHeight(&nodeA);
	printf("高度：%d\n", height);

	//拷贝
	struct BinaryNode* Newnode = copyTree(&nodeA);
	recursion(Newnode);

	//释放二叉树
	freeTree(Newnode);
}

int main()
{
	test();
	system("pause");
	return 0;
}
