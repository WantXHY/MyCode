#include "seqStack.h"

struct BinaryNode
{
	//������
	char ch;
	//ָ����
	struct BinaryNode* lChild;
	struct BinaryNode* rChild;
	//��־λ
	int flag;

};

void nonRecoursion(struct BinaryNode* root)
{
	seqStack myStack = init_Stack();
	push_Stack(myStack, root);
	while (size_Stack(myStack) > 0)
	{
		//����ջ��Ԫ��
		struct BinaryNode* topNode = top_Stack(myStack);
		//��ջ
		pop_Stack(myStack);
		//�����־λΪ�棬���Ԫ��,ִ���´�ѭ��
		if (topNode->flag == 1)
		{
			printf("%c ", topNode->ch);
			continue;
		}
		topNode->flag = 1;
		//�������������������� ��ջ
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
	//������ϵ
	nodeA.lChild = &nodeB;
	nodeA.rChild = &nodeF;
	nodeB.rChild = &nodeC;
	nodeC.lChild = &nodeD;
	nodeC.rChild = &nodeE;
	nodeF.rChild = &nodeG;
	nodeG.lChild = &nodeH;

	//�ǵݹ����
	nonRecoursion(&nodeA);
}

int main()
{
	test();
	system("pause");
	return 0;
}
