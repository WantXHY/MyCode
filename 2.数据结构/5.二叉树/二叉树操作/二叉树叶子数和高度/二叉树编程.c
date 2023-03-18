#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BinaryNode
{
	char ch;//������
	//ָ����
	struct BinaryNode* lChild;
	struct BinaryNode* rChild;

};
 
//����Ҷ����
void calculateTreeLeaf(struct BinaryNode* root, int* num)
{
	if (root == NULL)
	{
		return;
	}
	//����������������Ϊ�ճ�ΪҶ��
	if (root->lChild == NULL && root->rChild == NULL)
	{ 
		(*num)++;
	}
	calculateTreeLeaf(root->lChild, num);
	calculateTreeLeaf(root->rChild, num);
}

//�������߶�
int treeHeight(struct BinaryNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	//�������߶�
	int Lheight = treeHeight(root->lChild);
	//�������߶�
	int Rheight = treeHeight(root->rChild);
	//�Ƚ���������������ȡ�ϴ�ֵ+1
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
//��������
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
//�ͷ���
void freeTree(struct BinaryNode* root)
{
	if (root == NULL)
	{
		return;
	}
	freeTree(root->lChild);
	freeTree(root->rChild);
	printf("%c���ͷ���\n", root->ch);
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
	//������ϵ
	nodeA.lChild = &nodeB;
	nodeA.rChild = &nodeF;
	nodeB.rChild = &nodeC;
	nodeC.lChild = &nodeD;
	nodeC.rChild = &nodeE;
	nodeF.rChild = &nodeG;
	nodeG.lChild = &nodeH;

	//����Ҷ����
	int num = 0;
	calculateTreeLeaf(&nodeA, &num);
	printf("Ҷ������%d\n", num);

	//�������߶�
	int height=treeHeight(&nodeA);
	printf("�߶ȣ�%d\n", height);

	//����
	struct BinaryNode* Newnode = copyTree(&nodeA);
	recursion(Newnode);

	//�ͷŶ�����
	freeTree(Newnode);
}

int main()
{
	test();
	system("pause");
	return 0;
}
