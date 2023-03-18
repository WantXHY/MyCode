#include "seqQueue.h"


//����
struct Person
{
	char name[64];
	int age;
};

void test()
{
	//��ʼ������
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
	printf("���д�С:%d\n", size_SeqQueue(myQueue));
	while (isEmpty_SeqQueue(myQueue) == 0)
	{
		//���ʶ�ͷ
		struct Person* pFront = fornt_SeqQueue(myQueue);
		printf("��ͷԪ�� name:%s  age:%d\n", pFront->name, pFront->age);
		//���ʶ�β
		struct Person* pBack = back_SeqQueue(myQueue);
		printf("��βԪ�� name:%s  age:%d\n", pBack->name, pBack->age);
		//����
		pop_SeqQueue(myQueue);
	}
	printf("���д�С:%d\n", size_SeqQueue(myQueue));
	//���ٶ���
	destory_SeqQueue(myQueue);
}

int main()
{
	test();
	system("pause");
	return 0;
}
