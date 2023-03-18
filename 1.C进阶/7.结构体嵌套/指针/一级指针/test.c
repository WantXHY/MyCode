#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Person
{
	char* name;
	int age;
};

struct Person** allocateSpace()
{
	struct Person** temp = malloc(sizeof(struct Person*) * 3);

	for (int i = 0; i < 3; i++)
	{
		//创建接收(struct Person*)的内存
		temp[i] = malloc(sizeof(struct Person));

		//将结构体姓名创建在堆区
		temp[i]->name = malloc(sizeof(char) * 64);
		//给姓名赋值
		sprintf(temp[i]->name, "name_%d", i + 1);
		//给年龄赋值
		temp[i]->age = 18 + i;
	}

	return temp;
}

void PrintPerson(struct Person** parray, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("name：%s  年龄：%d", parray[i]->name, parray[i]->age);
	}
}

void freeSpace(struct Person** parray, int len)
{
	if (parray == NULL)
	{
		return;
	}
	if (len <= 0)
	{
		return;
	}
	for (int i = 0; i < 3; i++)
	{
		if (parray[i]->name != NULL)
		{
			printf("释放");
			free(parray[i]->name);
			parray[i]->name = NULL;
		}
		free(parray[i]);
		parray[i] = NULL;
	}
	free(parray);
	parray = NULL;
}
void test01()
{
	struct Person** parray = NULL;

	parray = allocateSpace();//若传值则需要三级指针接受

	PrintPerson(parray, 3);

	freeSpace(parray,3);//打印

	parray = NULL;//制空freeSpace中的parray
}

int main()
{
	test01();

	system("pause");
	return 0;
}
