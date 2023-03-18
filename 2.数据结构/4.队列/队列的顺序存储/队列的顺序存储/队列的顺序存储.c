#include "seqQueue.h"


//测试
struct Person
{
	char name[64];
	int age;
};

void test()
{
	//初始化队列
	SeqQueue myQueue = Init_SeqQueue();

	struct Person p1 = { "a",10 };
	struct Person p2 = { "b",20 };
	struct Person p3 = { "c",30 };
	struct Person p4 = { "d",40 };
	//struct Person p5 = { "e",50 };
	//a,e,b,d,c
	push_SeqQueue(myQueue, &p1);
	push_SeqQueue(myQueue, &p2);
	push_SeqQueue(myQueue, &p3);
	push_SeqQueue(myQueue, &p4);
	//push_SeqQueue(myQueue, &p5);
	printf("队列大小:%d\n", size_SeqQueue(myQueue));
	while (isEmpty_SeqQueue(myQueue) == 0)
	{
		//访问队头
		struct Person* pFront = fornt_SeqQueue(myQueue);
		printf("队头元素 name:%s  age:%d\n", pFront->name, pFront->age);
		//访问队尾
		struct Person* pBack = back_SeqQueue(myQueue);
		printf("队尾元素 name:%s  age:%d\n", pBack->name, pBack->age);
		//出队
		pop_SeqQueue(myQueue);
	}
	printf("队列大小:%d\n", size_SeqQueue(myQueue));
	//销毁队列
	destory_SeqQueue(myQueue);
}

int main()
{
	test();
	system("pause");
	return 0;
}
