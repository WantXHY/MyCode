#include "lintLIst.h"


void test()
{
	//��ʼ��
	struct linkNode* Header = InitlinList();
	printf("����ڵ㣺%d\n", size_linkNode(Header));
	printf("����������Ϊ: \n");
	foreach_LinkList(Header);
	

	//20ǰ����1000��500  β��100
	insert_linkNode(Header, 20, 1000);
	insert_linkNode(Header, 20, 500);
	insert_linkNode(Header, -1, 100);
	printf("��������󣬱���������Ϊ: \n");
	foreach_LinkList(Header);

	//ɾ�����������500��1000��100
	delete_linkNode(Header, 500);
	delete_linkNode(Header, 1000);
	delete_linkNode(Header, 100);
	printf("ɾ������󣬱���������Ϊ: \n");
	foreach_LinkList(Header);

	//��ת����
	reverse_linkNode(Header);
	printf("��ת����󣬱���������Ϊ: \n");
	foreach_LinkList(Header);

	//clear_linkNode(Header);
	//printf("���ɾ������󣬱���������Ϊ: \n");
	//foreach_LinkList(Header);

	

	////���±�Ϊ2������ǰ����500��1000��Ϊ1��ǰ����100
	//insertByPos_linkNode(Header, 2, 1000);
	//insertByPos_linkNode(Header, 2, 500);
	//insertByPos_linkNode(Header, 1, 100);
	//printf("��������󣬱���������Ϊ: \n");
	//foreach_LinkList(Header);
	//
	////ɾ���±�Ϊ2�����֣��Լ��±�Ϊ1������
	//deleteByPos_linkNode(Header, 2);
	//deleteByPos_linkNode(Header, 1);
	//printf("ɾ������󣬱���������Ϊ: \n");
	//foreach_LinkList(Header);



	////destory_linkNode(Header);//��������������޷�ʹ��
}

int main()
{
	test();
	system("pause");
	return 0;
}
