#include "seqStack.h"

int isLeft(char ch)
{
	return ch == '(';
}

int isRight(char ch)
{
	return ch == ')';
}

void printError(char* str, char* errInfo, char* pos)
{
	printf("%s\n", errInfo);
	printf("%s\n", str);

	//��ӡ�ո�����
	int num = pos - str;//����λ��p��ȥ��Ԫ�ص�ַstr

	for (int i = 0; i < num; i++)
	{
		printf(" ");
	}
	printf("|\n");//��ʾ����λ��

}

void test()
{
	char* str = "5+5*(6)+9/3*2)-(1+3(";

	char* p = str;
	//��ʼ��ջ
	seqStack myStack = init_Stack();

	while (*p != '\0')
	{
		//����������ţ���ջ
		if (isLeft(*p))
		{
			push_Stack(myStack, p);
		}

		//�����������
		if (isRight(*p))
		{
			//ջ����Ԫ�أ���ջ
			if (size_Stack(myStack) > 0)
			{
				pop_Stack(myStack);
			}
			else
			{
				//������û��ƥ�䵽��Ӧ�������ţ�����ֹͣ������
				printError(str, "������û��ƥ�䵽������", p);
				break;
			}
		}
		p++;
	}
	//��������  �ж��Ƿ���������û��ƥ�䵽������
	while (size_Stack(myStack) > 0)
	{
		//û��ƥ�䵽����������ջ��
		printError(str, "������û��ƥ�䵽������", top_Stack(myStack));
		//��ջ
		pop_Stack(myStack);
	}

	//����ջ
	destory_Stack(myStack);
	myStack = NULL;
	
}


int main()
{
	test();
	system("pause");
	return 0;
}