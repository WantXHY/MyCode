#include "Parray.h"



//测试
struct Person
{
	char name[64];
	int age;
};

//比较数值
int  myCompare(void* data1, void* data2)
{
	struct Person* p1 = data1;
	struct Person* p2 = data2;

	return strcmp(p1->name, p2->name) == 0 && p1->age == p2->age;
}

//打印
void my_Print(void* data)
{
	struct Person* p = data;
	printf("姓名：%s  年龄：%d\n", p->name, p->age);
}

int main()
{
	//初始化动态数组
	struct Parray* array = Init_Parray(5);
	

	struct Person p1 = { "一",10 };
	struct Person p2 = { "二",11 };
	struct Person p3 = { "三",12 };
	struct Person p4 = { "四",13 };
	struct Person p5 = { "五",14 }; 
	struct Person p6 = { "六",15 };
	printf("插入前：容量：%d  大小：%d\n", array->capacity, array->m_size);

	//插入
	insert_Parray(array, 0, &p1);
	insert_Parray(array, 0, &p2);
	insert_Parray(array, 1, &p3);
	insert_Parray(array, 2, &p4);
	insert_Parray(array, -1, &p5);
	insert_Parray(array, 3, &p6);

	//遍历
	foreach_Parray(array, my_Print);
	printf("插入后：容量：%d  大小：%d\n", array->capacity, array->m_size);

	//按位置删除
	removeBypos_Parray(array, 2);
	foreach_Parray(array, my_Print);
	printf("删除后：容量：%d  大小：%d\n", array->capacity, array->m_size);

	///按数字删除
	struct Person p = { "二",11 };
	removeByValue_parray(array, &p, myCompare);
	foreach_Parray(array, my_Print);
	printf("删除后：容量：%d  大小：%d\n", array->capacity, array->m_size);

	//////销毁数组
	////destory_Parray(array);
	////array = NULL;

	system("pause");
	return 0;
}
