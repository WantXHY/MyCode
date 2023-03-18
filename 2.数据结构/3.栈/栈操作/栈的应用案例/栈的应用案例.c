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

	//打印空格数量
	int num = pos - str;//错误位置p减去首元素地址str

	for (int i = 0; i < num; i++)
	{
		printf(" ");
	}
	printf("|\n");//显示错误位置

}

void test()
{
	char* str = "5+5*(6)+9/3*2)-(1+3(";

	char* p = str;
	//初始化栈
	seqStack myStack = init_Stack();

	while (*p != '\0')
	{
		//如果是左括号，入栈
		if (isLeft(*p))
		{
			push_Stack(myStack, p);
		}

		//如果是右括号
		if (isRight(*p))
		{
			//栈中有元素，出栈
			if (size_Stack(myStack) > 0)
			{
				pop_Stack(myStack);
			}
			else
			{
				//右括号没有匹配到对应的左括号，立即停止，报错
				printError(str, "右括号没有匹配到左括号", p);
				break;
			}
		}
		p++;
	}
	//遍历结束  判断是否有左括号没有匹配到右括号
	while (size_Stack(myStack) > 0)
	{
		//没有匹配到的左括号在栈中
		printError(str, "左括号没有匹配到右括号", top_Stack(myStack));
		//出栈
		pop_Stack(myStack);
	}

	//销毁栈
	destory_Stack(myStack);
	myStack = NULL;
	
}


int main()
{
	test();
	system("pause");
	return 0;
}