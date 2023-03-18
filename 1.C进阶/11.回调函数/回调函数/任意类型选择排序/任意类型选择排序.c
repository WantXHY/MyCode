#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void selectSort(void* pArray,int elesize,int len,int(*myCompare)(void*,void*))
{
	//开辟临时交换元素所用临时变量
	char* temp = malloc(elesize);

	for (int i = 0; i < len; i++)
	{
		int MinOrMax = i;//定义最小值或最大值下标

		for (int j = i+1; j < len; j++)
		{
			char* p1 = (char*)pArray + elesize * j;
			char* p2 = (char*)pArray + elesize * MinOrMax;
			if (myCompare(p1, p2))
			{
				MinOrMax = j;//更新最小值或最大值下标
			}

		}

		if (i != MinOrMax)
		{
			//交换i与MinOrMax下标元素
			char* pI = (char*)pArray + elesize * i;
			char* p2 = (char*)pArray + elesize * MinOrMax;

			//交换元素地址
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

//数组类型数据转换排序
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
	//数组长度
	int len = sizeof(arr) / sizeof(int);

	selectSort(arr, sizeof(int), len, myCompare_Array);

	//打印
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

//结构体类型数据转换排序
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

	//打印
	for (int i = 0; i < len; i++)
	{
		printf("%s %d\n", p[i].name,p[i].age);
	}
}

int main()
{
	//数组
	test01();

	//结构体
	test02();

	system("pause");
	return 0;
}
