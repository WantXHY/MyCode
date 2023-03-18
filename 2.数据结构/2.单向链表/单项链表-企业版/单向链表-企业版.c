#include "LinkNode.h"


//测试
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
	//初始化
	LinkList mylist = init_LinkList();

	struct Person p1 = { NULL,"一",10 };
	struct Person p2 = { NULL,"二",11 };
	struct Person p3 = { NULL,"三",12 };
	struct Person p4 = { NULL,"四",15 };
	struct Person p5 = { NULL,"五",17 };
	struct Person p6 = { NULL,"六",12 };


	//插入数据,四、五、六、一、二、三
	insert_LinkList(mylist, 0, &p1);
	insert_LinkList(mylist, 1, &p2);
	insert_LinkList(mylist, -1, &p3);
	insert_LinkList(mylist, 0, &p4);
	insert_LinkList(mylist, 1, &p5);
	insert_LinkList(mylist, 2, &p6);

	//遍历数据
	foreach_LinkList(mylist, myForeach);
	printf("\n");

	//按位置删除链表
	DelByPos_LinkList(mylist, 1);
	foreach_LinkList(mylist, myForeach);
	printf("\n");

	//按值删除链表
	struct Person pdel1 = { NULL,"四",15 };
	DelByValue_LinkList(mylist, &pdel1, myCompare);
	foreach_LinkList(mylist, myForeach);
	printf("\n");

	//销毁链表
	destory_LinkList(mylist);
	
}

int main()
{
	test();
	system("pause");
	return 0;
}