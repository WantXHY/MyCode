#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void selectSort(void* pArray,int elesize,int len,int(*myCompare)(void*,void*))
{
	//������ʱ����Ԫ��������ʱ����
	char* temp = malloc(elesize);

	for (int i = 0; i < len; i++)
	{
		int MinOrMax = i;//������Сֵ�����ֵ�±�

		for (int j = i+1; j < len; j++)
		{
			char* p1 = (char*)pArray + elesize * j;
			char* p2 = (char*)pArray + elesize * MinOrMax;
			if (myCompare(p1, p2))
			{
				MinOrMax = j;//������Сֵ�����ֵ�±�
			}

		}

		if (i != MinOrMax)
		{
			//����i��MinOrMax�±�Ԫ��
			char* pI = (char*)pArray + elesize * i;
			char* p2 = (char*)pArray + elesize * MinOrMax;

			//����Ԫ�ص�ַ
			memcpy(temp, pI, elesize);
			memcpy(pI, p2, elesize);
			memcpy(p2, temp, elesize);
		}
	}

	if (temp != NULL)
	{
		free(temp);
		temp = NULL;
	}
}

//������������ת������
int myCompare_Array(void* data1, void* data2)
{
	int* num1 = data1;
	int* num2 = data2;

	if (*num1 > *num2)
	{
		return 1;
	}
	return 0;
}

void test01()
{
	int arr[] = { 1,4,3,2,5,6,7 };
	//���鳤��
	int len = sizeof(arr) / sizeof(int);

	selectSort(arr, sizeof(int), len, myCompare_Array);

	//��ӡ
	for (int i = 0; i < len; i++)
	{
		printf("%d\n", arr[i]);
	}
	
}

struct Person
{
	char name[20];
	int age;
};

//�ṹ����������ת������
int myCompare_person(void* data1, void* data2)
{
	struct Person* p1 = data1;
	struct Person* p2 = data2;

	if (p1->age > p2->age)
	{
		return 1;
	}
	return 0;
}

void test02()
{
	struct Person p[] = { {"a",10},{"c",20},{"b",15} };

	int len = sizeof(p) / sizeof(struct Person);

	selectSort(p, sizeof(struct Person), len, myCompare_person);

	//��ӡ
	for (int i = 0; i < len; i++)
	{
		printf("%s %d\n", p[i].name,p[i].age);
	}
}

int main()
{
	//����
	test01();

	//�ṹ��
	test02();

	system("pause");
	return 0;
}
