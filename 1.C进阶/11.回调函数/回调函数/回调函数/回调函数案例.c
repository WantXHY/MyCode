#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void printAllArray(void* parray, int arr_sizeof, int len,void (*MyPrint)(void*))
{
	char* p = parray;
	for (int i = 0; i < len; i++)
	{
		char* eleAddr = p + arr_sizeof * i;
		MyPrint(eleAddr);
	}
}
//��ӡ
void MyPrint(void* data)
{
	int* num = data;
	printf("%d\n", *num);
}

void test()
{
	int arr[5] = { 1,2,3,4,5 };
	int len = sizeof(arr) / sizeof(arr[0]);
	printAllArray(arr, sizeof(arr[0]), len,MyPrint);
}

struct Person
{
	char name[20];
	int age;
};

//��ӡ�ṹ��Ԫ��
void MyPrint_person(void* data)
{
	struct Person* num = data;
	printf("������%s  ����: %d\n", num->name, num->age);

}

//Ԫ�ضԱ�
int myCompare(void* data1, void* data2)
{
	struct Person* p1 = data1;
	struct Person* p2 = data2;

	if (strcmp(p1->name, p2->name) == 0 && p1->age == p2->age)
	{
		return 1;
	}
	return 0;
}

//����ָ����Ԫ��
int findPerson(void* parray, int eleSizeof, int len,void* data,int(*myCompare)(void*,void*))
{
	char* temp = parray;
	for (int i = 0; i < len; i++)
	{
		char* eleAddr = eleSizeof * i + temp;//ÿ��Ԫ�ص��׵�ַ
		if (myCompare(eleAddr, data))
		{
			return 1;
		}
	}
	return 0;
}


void test01()
{
	struct Person person[] = { {"a",10},{"b",20},{"c",30} };
	int len = sizeof(person) / sizeof(struct Person);
	printAllArray(person, sizeof(struct Person), len, MyPrint_person);

	//����ָ����Ԫ��
	struct Person p = { "a",10 };
	int ret= findPerson(person, sizeof(struct Person), len,&p, myCompare);
	if (ret == 1)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}

int main()
{
	test();
	test01();

	system("pause");
	return 0;
}
