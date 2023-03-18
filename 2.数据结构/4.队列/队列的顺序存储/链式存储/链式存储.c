#include "linkQueue.h"

//����
struct Person
{
	void* node;
	char name[64];
	int age;
};
void test()
{
	//��ʼ������
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
	printf("���д�С:%d\n", size_Queue(myQueue));
	while (isEmpty_Queue(myQueue) == 0)
	{
		//���ʶ�ͷ
		struct Person* pFront = fornt_Queue(myQueue);
		printf("��ͷԪ�� name:%s  age:%d\n", pFront->name, pFront->age);
		//���ʶ�β
		struct Person* pBack = back_Queue(myQueue);
		printf("��βԪ�� name:%s  age:%d\n", pBack->name, pBack->age);
		//����
		pop_Queue(myQueue);
	}
	printf("���д�С:%d\n", size_Queue(myQueue));
	//���ٶ���
	destory_Queue(myQueue);
}

int main()
{
	test();
	system("pause");
	return 0;
}
