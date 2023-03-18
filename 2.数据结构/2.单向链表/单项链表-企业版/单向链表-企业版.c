#include "LinkNode.h"


//����
struct Person
{
	void* node;
	char name[64];
	int age;
};

void myForeach(void* data)
{
	struct Person* p = data;
	printf("name: %s  age: %d\n", p->name, p->age);
}

int myCompare(void* data1, void* data2)
{
	struct Person* p1 = data1;
	struct Person* p2 = data2;

	return (strcmp(p1->name, p2->name) == 0 && p1->age == p2->age);
}

void test()
{
	//��ʼ��
	LinkList mylist = init_LinkList();

	struct Person p1 = { NULL,"һ",10 };
	struct Person p2 = { NULL,"��",11 };
	struct Person p3 = { NULL,"��",12 };
	struct Person p4 = { NULL,"��",15 };
	struct Person p5 = { NULL,"��",17 };
	struct Person p6 = { NULL,"��",12 };


	//��������,�ġ��塢����һ��������
	insert_LinkList(mylist, 0, &p1);
	insert_LinkList(mylist, 1, &p2);
	insert_LinkList(mylist, -1, &p3);
	insert_LinkList(mylist, 0, &p4);
	insert_LinkList(mylist, 1, &p5);
	insert_LinkList(mylist, 2, &p6);

	//��������
	foreach_LinkList(mylist, myForeach);
	printf("\n");

	//��λ��ɾ������
	DelByPos_LinkList(mylist, 1);
	foreach_LinkList(mylist, myForeach);
	printf("\n");

	//��ֵɾ������
	struct Person pdel1 = { NULL,"��",15 };
	DelByValue_LinkList(mylist, &pdel1, myCompare);
	foreach_LinkList(mylist, myForeach);
	printf("\n");

	//��������
	destory_LinkList(mylist);
	
}

int main()
{
	test();
	system("pause");
	return 0;
}