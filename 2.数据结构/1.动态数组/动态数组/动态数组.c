#include "Parray.h"



//����
struct Person
{
	char name[64];
	int age;
};

//�Ƚ���ֵ
int  myCompare(void* data1, void* data2)
{
	struct Person* p1 = data1;
	struct Person* p2 = data2;

	return strcmp(p1->name, p2->name) == 0 && p1->age == p2->age;
}

//��ӡ
void my_Print(void* data)
{
	struct Person* p = data;
	printf("������%s  ���䣺%d\n", p->name, p->age);
}

int main()
{
	//��ʼ����̬����
	struct Parray* array = Init_Parray(5);
	

	struct Person p1 = { "һ",10 };
	struct Person p2 = { "��",11 };
	struct Person p3 = { "��",12 };
	struct Person p4 = { "��",13 };
	struct Person p5 = { "��",14 }; 
	struct Person p6 = { "��",15 };
	printf("����ǰ��������%d  ��С��%d\n", array->capacity, array->m_size);

	//����
	insert_Parray(array, 0, &p1);
	insert_Parray(array, 0, &p2);
	insert_Parray(array, 1, &p3);
	insert_Parray(array, 2, &p4);
	insert_Parray(array, -1, &p5);
	insert_Parray(array, 3, &p6);

	//����
	foreach_Parray(array, my_Print);
	printf("�����������%d  ��С��%d\n", array->capacity, array->m_size);

	//��λ��ɾ��
	removeBypos_Parray(array, 2);
	foreach_Parray(array, my_Print);
	printf("ɾ����������%d  ��С��%d\n", array->capacity, array->m_size);

	///������ɾ��
	struct Person p = { "��",11 };
	removeByValue_parray(array, &p, myCompare);
	foreach_Parray(array, my_Print);
	printf("ɾ����������%d  ��С��%d\n", array->capacity, array->m_size);

	//////��������
	////destory_Parray(array);
	////array = NULL;

	system("pause");
	return 0;
}
