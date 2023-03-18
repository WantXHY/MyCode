#include "seqStack.h"

struct BinaryNode
{
	//数据域
	char ch;
	//指针域
	struct BinaryNode* lChild;
	struct BinaryNode* rChild;
	//标志位
	int flag;

};

void nonRecoursion(struct BinaryNode* root)
{
	seqStack myStack = init_Stack();
	push_Stack(myStack, root);
	while (size_Stack(myStack) > 0)
	{
		//返回栈顶元素
		struct BinaryNode* topNode = top_Stack(myStack);
		//出栈
		pop_Stack(myStack);
		//如果标志位为真，输出元素,执行下次循环
		if (topNode->flag == 1)
		{
			printf("%c ", topNode->ch);
			continue;
		}
		topNode->flag = 1;
		//将右子树、左子树、根 入栈
		if (topNode->rChild != NULL)
		{
			push_Stack(myStack, topNode->rChild);
		}
		if (topNode->lChild != NULL)
		{
			push_Stack(myStack, topNode->lChild);
		}
		push_Stack(myStack, topNode);
	}
	destory_Stack(myStack);
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

	//非递归遍历
	nonRecoursion(&nodeA);
}

int main()
{
	test();
	system("pause");
	return 0;
}
