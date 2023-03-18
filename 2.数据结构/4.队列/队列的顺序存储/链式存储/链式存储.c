#include "linkQueue.h"

//测试
struct Person
{
	void* node;
	char name[64];
	int age;
};
void test()
{
	//初始化队列
	LinkQueue myQueue = init_Queue();

	struct Person p1 = { NULL,"a",10 };
	struct Person p2 = { NULL,"b",20 };
	struct Person p3 = { NULL,"c",30 };
	struct Person p4 = { NULL,"d",40 };
	/*struct Person p5 = { NULL,"e",50 };*/
	//a,e,b,d,c
	push_Queue(myQueue, &p1);
	push_Queue(myQueue, &p2);
	push_Queue(myQueue, &p3);
	push_Queue(myQueue, &p4);
	//push_Queue(myQueue, &p5);
	printf("队列大小:%d\n", size_Queue(myQueue));
	while (isEmpty_Queue(myQueue) == 0)
	{
		//访问队头
		struct Person* pFront = fornt_Queue(myQueue);
		printf("队头元素 name:%s  age:%d\n", pFront->name, pFront->age);
		//访问队尾
		struct Person* pBack = back_Queue(myQueue);
		printf("队尾元素 name:%s  age:%d\n", pBack->name, pBack->age);
		//出队
		pop_Queue(myQueue);
	}
	printf("队列大小:%d\n", size_Queue(myQueue));
	//销毁队列
	destory_Queue(myQueue);
}

int main()
{
	test();
	system("pause");
	return 0;
}
