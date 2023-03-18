#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Teacher
{
	char* name;
	char** students;
};

void allocateSpace(struct Teacher*** teacher)
{
	if (teacher == NULL)
	{
		return;
	}
	//开辟内存
	struct Teacher** temp = malloc(sizeof(struct Teacher*) * 3);

	//给老师分配内存
	for (int i = 0; i < 3; i++)
	{
		temp[i] = malloc(sizeof(struct Teacher));

		//g给老师名字分配空间
		temp[i]->name = malloc(sizeof(char) * 64);
		//给老师起名字
		sprintf(temp[i]->name, "Teacher_%d", i + 1);

		//给学生的数组分配内存
		temp[i]->students = malloc(sizeof(char*) * 4);
		//给学生的姓名内存
		for (int j = 0; j < 4; j++)
		{
			temp[i]->students[j] = malloc(sizeof(char) * 64);
			sprintf(temp[i]->students[j], "%s_Student_%d", temp[i]->name, j + 1);
		}
	}
	*teacher = temp;
}
void PrintTeacher(struct Teacher** parray)
{
	if (parray == NULL)
	{
		return;
	}
	for(int i = 0; i < 3; i++) 
	{
		printf("%s\n", parray[i]->name);
		for (int j = 0; j < 4; j++)
		{
			printf("   %s\n", parray[i]->students[j]);
		}
	}
}

void freeTeacher(struct Teacher** parray)
{
	if (parray == NULL)
	{
		return;
	}

	for (int i = 0; i < 3; i++)
	{
		//释放老师姓名
		if (parray[i]->name != NULL)
		{
			free(parray[i]->name);
			parray[i]->name = NULL;
		}
		//释放学生姓名
		for (int j = 0; j < 4; j++)
		{
			if (parray[i]->students[j] != NULL)
			{
				free(parray[i]->students[j] != NULL);
				parray[i]->students[j] = NULL;
			}
		}
		//释放学生数组
		if (parray[i]->students != NULL)
		{
			free(parray[i]->students);
			parray[i]->students = NULL;
		}
		//释放老师
		if (parray[i] != NULL)
		{
			free(parray[i]);
			parray[i] = NULL;
		}
	}
	//释放老师数组
	if (parray != NULL)
	{
		free(parray);
		parray = NULL;
	}
}

void test01()
{
	struct Teacher** parray = NULL;

	allocateSpace(&parray);

	PrintTeacher(parray);

	freeTeacher(parray);
	parray = NULL;
}
int main()
{
	test01();
	system("pause");
	return 0;
}
