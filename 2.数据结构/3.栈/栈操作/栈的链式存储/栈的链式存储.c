#include "linkStack.h"


struct Person
{
	void* node;
	char name[64];
	int age;
};

void test()
{
	//初始化栈
	LinkStack myStack = init_Stack();

	struct Person p1 = {NULL, "a",11 };
	struct Person p2 = {NULL, "b",21 };
	struct Person p3 = {NULL, "c",31 };
	struct Person p4 = {NULL, "d",41 };
	struct Person p5 = {NULL, "e",51 };
	struct Person p6 = {NULL, "f",61 };

	//入栈
	push_Stack(myStack, &p1);
	push_Stack(myStack, &p2);
	push_Stack(myStack, &p3);
	push_Stack(myStack, &p4);
	push_Stack(myStack, &p5);
	push_Stack(myStack, &p6);
	printf("栈元素个数：%d\n", size_Stack(myStack));

	while (isEmpty_Stack(myStack) == 0)
	{
		//返回栈顶元素
		struct Person* p = top_Stack(myStack);
		printf("name:%s  age:%d\n", p->name, p->age);

		//出栈
		pop_Stack(myStack);
	}
	printf("栈元素个数：%d\n", size_Stack(myStack));

	//销毁栈
	destory_Stack(myStack);
}

int main()
{
	test();
	system("pause");
	return 0;
}
