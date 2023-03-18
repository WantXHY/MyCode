#include "lintLIst.h"


void test()
{
	//初始化
	struct linkNode* Header = InitlinList();
	printf("链表节点：%d\n", size_linkNode(Header));
	printf("遍历链表结果为: \n");
	foreach_LinkList(Header);
	

	//20前插入1000，500  尾插100
	insert_linkNode(Header, 20, 1000);
	insert_linkNode(Header, 20, 500);
	insert_linkNode(Header, -1, 100);
	printf("插入链表后，遍历链表结果为: \n");
	foreach_LinkList(Header);

	//删除插入的数字500，1000，100
	delete_linkNode(Header, 500);
	delete_linkNode(Header, 1000);
	delete_linkNode(Header, 100);
	printf("删除链表后，遍历链表结果为: \n");
	foreach_LinkList(Header);

	//反转链表
	reverse_linkNode(Header);
	printf("反转链表后，遍历链表结果为: \n");
	foreach_LinkList(Header);

	//clear_linkNode(Header);
	//printf("清空删除链表后，遍历链表结果为: \n");
	//foreach_LinkList(Header);

	

	////在下标为2的数字前插入500，1000，为1的前插入100
	//insertByPos_linkNode(Header, 2, 1000);
	//insertByPos_linkNode(Header, 2, 500);
	//insertByPos_linkNode(Header, 1, 100);
	//printf("插入链表后，遍历链表结果为: \n");
	//foreach_LinkList(Header);
	//
	////删除下标为2的数字，以及下标为1的数字
	//deleteByPos_linkNode(Header, 2);
	//deleteByPos_linkNode(Header, 1);
	//printf("删除链表后，遍历链表结果为: \n");
	//foreach_LinkList(Header);



	////destory_linkNode(Header);//销毁链表后链表无法使用
}

int main()
{
	test();
	system("pause");
	return 0;
}
